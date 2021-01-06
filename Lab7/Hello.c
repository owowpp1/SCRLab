#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define THREADY	8

void *Wypisz(void *id)
{
   long idlong;
   idlong = (long)id;
   printf("Hello SCR. Written by thread ID %d!\n", idlong+1);
   pthread_exit(NULL);
}

int main()
{
    pthread_t watki[THREADY];
    for(long i=0; i<THREADY; i++){
        printf("Created thread %d\n", i+1);
        if(pthread_create(&watki[i], NULL, Wypisz, (void *)i)){
            printf("Błąd w pthread_create() dla wątku %d\n", i+1);
            return -1;
            }
//        sleep(1);
//        pthread_join(watki[i], NULL);
    }
   pthread_exit(NULL);
}
