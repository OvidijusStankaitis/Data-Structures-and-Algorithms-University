#include <stdio.h>

// Precontion: Gaunami du int tipo kintamieji ir jie sumuojami

// Postcondition: Nera
int suma(int a, int b)
{
    int c = a + b;
    return c;
}

// Precondition: Gaunami in tipo kintamieji
// Skaicius, daliklis, liekana ir dalmuo
// Skaicius dalinamas is daliklio, todel jis 
// Negali buti 0, dalindami gauname liena ir dalmeni

// Postcondition: return 0; reiskia sekme, kad f-ija suveike gerai
// return 1; reiskia, kad buvo klaida, greiciausiai blogai ivestas daliklis
int dalmuoSuLiekana(int sk, int dalik, int* liek, int* dalmuo)
{
    if(dalik == 0)
    {
        return 1;
    }

    else
    {
        *dalmuo = sk / dalik;
        *liek = sk % dalik;
        return 0;
    }
}

int main()
{
    int x = suma(10, 20);

    int a = 12, b = 0, c = 0, d = 0;

    int y = dalmuoSuLiekana(a, b, &c, &d);
    
    if(y == 1)
    {
        printf("Programa negali testi darbo, nes blogi duomenys\n");
        return 0;
    }

    return 0;
}