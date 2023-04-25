#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <math.h>

#include "LongNumber.h"
#include "PriorityQueue.h"

#define SIMULATION_COUNT 1000000

int total1 = 0;
int total2 = 0;

typedef struct {
    LongNumber A;
    LongNumber A1;
    LongNumber B;
    int U;
    int K;
    double T1;
    double T2;
    int TR_min;
    int TR_max;
} SimulationData;

void *withContract(void *arg);
void *withoutContract(void *arg);
int random_repair_time(SimulationData* data);

int main() 
{
    srand(time(NULL));

    int A = 1000;
    int A1 = 200;
    int B = 800;
    int U = 15;
    int K = 10;
    double T1 = 0.3;
    double T2 = 0.7;

    SimulationData data;
    data.A = longNumberCreateFromLL(A);
    data.A1 = longNumberCreateFromLL(A1);
    data.B = longNumberCreateFromLL(B);
    data.U = U;
    data.K = K;
    data.T1 = T1;
    data.T2 = T2;
    data.TR_min = 1;
    data.TR_max = 5 * K;

    pthread_t withContractThread, withoutContractThread;

    // Create the threads for each strategy
    pthread_create(&withContractThread, NULL, withContract, (void *)&data);
    pthread_create(&withoutContractThread, NULL, withoutContract, (void *)&data);

    // Wait for both threads to finish
    pthread_join(withContractThread, NULL);
    pthread_join(withoutContractThread, NULL);

    printf("After 1000000 clients the results were: \n");
    printf("Total income with contract: %d \n", total1);
    printf("Total income without contract: %d \n\n", total2);

    if(total1 > total2)
    {
        printf("Total income with contract was more beneficial\n");
    }

    else
    {
        printf("Total income without contract was more beneficial\n");
    }

    return 0;
}

int random_repair_time(SimulationData* data) {
    return (rand() % (data->TR_max - data->TR_min + 1)) + data->TR_min;
}

void *withContract(void *arg) 
{
    SimulationData *data = (SimulationData *)arg;
    double total_income = 0;

    for(int i = 0; i < SIMULATION_COUNT * data->T1; i++) 
    {   
        int repair_time = random_repair_time(data);
        total_income += longNumberConvertToLL(data->A);
        total_income -= longNumberConvertToLL(data->A1);
        total_income -= data->U * repair_time * 2;
    }

    total1 = total_income;
    return NULL;
}

void *withoutContract(void *arg) 
{
    SimulationData *data = (SimulationData *)arg;
    double total_income = 0;

    for(int i = 0; i < SIMULATION_COUNT * data->T2; i++) 
    {
        int repair_time = random_repair_time(data);
        total_income += longNumberConvertToLL(data->B);
        total_income -= data->U * repair_time;
    }

    total2 = total_income;
    return NULL;
}
