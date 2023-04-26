#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#include "LongNumber.h"
#include "pq.h"

#define SIMULATION 10
#define OPEN 8
#define CLOSED 17

typedef struct {
    LongNumber A;
    LongNumber A1;
    LongNumber A2;
    int U;
    int K;
    int T1;
    int T2;
} SimulationData;

typedef struct {
    int id;
    int vip;
    int hoursLeft;
} Client;

int random_repair_time(SimulationData *data);
void *withContract(void *arg);
void *withoutContract(void *arg);
void process_clients(LongNumber *profit, SimulationData *data, int with_vip_clients);

LongNumber total1;
LongNumber total2;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: input.txt\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("Cannot open file %s\n", argv[1]);
        return 1;
    }

    srand(time(NULL));

    int A, A1, U, K, T1, T2;

    fscanf(fp, "%d", &A);
    fscanf(fp, "%d", &A1);
    fscanf(fp, "%d", &U);
    fscanf(fp, "%d", &K);
    fscanf(fp, "%d", &T1);
    fscanf(fp, "%d", &T2);

    int A2 = A - A1;

    fclose(fp);

    SimulationData data;
    data.A = longNumberCreateFromLL(A);
    data.A1 = longNumberCreateFromLL(A1);
    data.A2 = longNumberCreateFromLL(A2);
    data.U = U;
    data.K = K;
    data.T1 = T1;
    data.T2 = T2;

    pthread_t withContractThread, withoutContractThread;

    pthread_create(&withContractThread, NULL, withContract, (void *)&data);
    pthread_create(&withoutContractThread, NULL, withoutContract, (void *)&data);

    pthread_join(withContractThread, NULL);
    pthread_join(withoutContractThread, NULL);

    printf("After %d days the results were: \n", SIMULATION);
    printf("Total income with contract (VIP): %s \n", longNumberConvertToString(total1));
    printf("Total income without contract (NOT VIP): %s \n\n", longNumberConvertToString(total2));

    if (longNumberCompare(total1, total2) > 0)
    {
        printf("Total income with contract (VIP) was more beneficial\n");
    }
    else
    {
        printf("Total income without contract (NOT VIP) was more beneficial\n");
    }

    longNumberFree(data.A);
    longNumberFree(data.A1);
    longNumberFree(data.A2);
    longNumberFree(total1);
    longNumberFree(total2);

    return 0;
}

int random_repair_time(SimulationData *data)
{
    return (rand() % (data->K - data->U + 1)) + data->U;
}

void process_clients(LongNumber *profit, SimulationData *data, int with_vip_clients)
{
    int hour = 0;
    int day = 0;
    int id = 0;
    ADT *pq = createADT();
    srand(time(NULL));

    Client clients[MAX_SIZE] = {0};
    int client_count = 0;

    while (day != SIMULATION)
    {
        if (hour >= OPEN && hour <= CLOSED && !isFull(pq))
        {
            if (rand() % 100 < data->T1 && with_vip_clients)
            {
                clients[client_count].id = id++;
                clients[client_count].vip = 1;
                clients[client_count].hoursLeft = random_repair_time(data);
                *profit = longNumberAdd(*profit, longNumberSubtract(data->A, data->A1));
                insert(pq, clients[client_count].id, 0);
                client_count++;
            }
            if (rand() % 100 < data->T2)
            {
                clients[client_count].id = id++;
                clients[client_count].vip = 0;
                clients[client_count].hoursLeft = random_repair_time(data);
                *profit = longNumberAdd(*profit, data->A);
                insert(pq, clients[client_count].id, 1);
                client_count++;
            }
        }

        int workersLeft = data->K;

        while (!isEmpty(pq) && workersLeft)
        {
            char client_str[20];
            strcpy(client_str, extract(pq));

            int client_id;
            sscanf(client_str, "%*[^0-9]%d", &client_id);

            int client_index = -1;
            for (int i = 0; i < client_count; i++)
            {
                if (clients[i].id == client_id)
                {
                    client_index = i;
                    break;
                }
            }

            if (client_index == -1)
            {
                continue;
            }

            Client *client = &clients[client_index];

            if (hour >= OPEN && hour <= CLOSED && workersLeft)
            {
                --workersLeft;
                *profit = longNumberSubtract(*profit, longNumberCreateFromLL(data->U));
                client->hoursLeft--;
            }

            if (hour > CLOSED && client->vip && workersLeft)
            {
                --workersLeft;
                *profit = longNumberSubtract(*profit, longNumberCreateFromLL(data->U * 2));
                client->hoursLeft--;
            }

            if (client->hoursLeft <= 0)
            {
                client->id = -1;
            }
        }

        hour = (hour + 1) % 24;
        if (hour == 0)
        {
            ++day;
        }
    }
    doneADT(pq);
}


void *withContract(void *arg)
{
    SimulationData *data = (SimulationData *)arg;
    total1 = longNumberCreateFromLL(0);
    process_clients(&total1, data, 1);
    return NULL;
}

void *withoutContract(void *arg)
{
    SimulationData *data = (SimulationData *)arg;
    total2 = longNumberCreateFromLL(0);
    process_clients(&total2, data, 0);
    return NULL;
}