#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

int j=1000000000;

void Analiza(int sygnal){

    switch(sygnal){

        case 14:
            printf("\nPrzechwycono sygnał SIGALRM.\n");
            exit(0);
        break;
        case 15:
            printf("\nPrzechwycono sygnał SIGTERM.\n");
        break;
        case 10:
            if(j==1000000000){
                printf("\nPrzechwycono sygnał SIGUSR1.\n");
                j=0;
            }
        break;
        case 12:
        break;
        default:
            printf("\nPrzechwycono sygnał %d\n", sygnal);
            exit(0);
        break;
    }
}

int main()
{
    signal(SIGINT, Analiza);
    signal(SIGALRM, Analiza);
    signal(SIGTERM, Analiza);
    signal(SIGUSR1, Analiza);
    signal(SIGUSR2, Analiza);
    int i=0;
    while (1){

        if(j<1000000000)    j++;

        i++;
        if(i==1000000000){
            i=0;
            printf("\nDziałam se\n");
        }
    }
    return 0;
}
