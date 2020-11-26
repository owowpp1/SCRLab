#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
//
#define rozmiarpaki 1000

int main(int argc, char *argv[]){

    if(argc<2){     //brak argumentów
        printf("Nie podano nazwy pliku. Uruchom ponownie.\n");
        return 0;
    }

    int pipe1[2];           //adresy fd pipe'a pierwszego
    int plik;               //adres pliku
//    long rozmiarpaki=10;    //rozmiar paczki
    char buforek[rozmiarpaki];     //tu zapisujemy odczytany obraz
    int pomoc=0;            //counter

//    if(argc>2){             //gdy dodano dodatkowy argument
//        rozmiarpaki=strtol(argv[2], NULL, 10);
//    }

    if(pipe(pipe1)==-1){    //Błąd otwarcia pipe
        printf("Wywaliło pipa1.\n");
        return 0;
    }

    pid_t pid=fork();       //fork

    if(pid<0){              //Gdy fork() nie zadziała
        printf("Wywaliło forka.\n");
        return 0;
    }
    else if(pid>0){         //rodzic

        close(pipe1[0]);     //zamknij odczyt u rodzica

        plik=open(argv[1], O_RDONLY);   //otwarcie pliku
        if(plik<0){                     //błąd otwarcia pliku
            printf("Błąd odczytu pliku %s.\n", argv[1]);
            return 0;
        }

        while((pomoc=read(plik, buforek, rozmiarpaki))>0){  //odczyt z pliku w pętli
            if(write(pipe1[1], buforek, pomoc)<0){          //zapis z bufora do pipe
                printf("Wywaliło zapis do pipa.\n");
            }
        }
        close(plik);        //zamknij plik
        close(pipe1[1]);    //zamknij zapis
    }
    else{                   //dziecko

        close(pipe1[1]);     //zamknij zapis u dziecka

        close(0);           //zwolnienie wejścia
        dup(pipe1[0]);      //wejście przejęte przez potok

        execlp("display", "display", NULL);      //wywołanie programu display bez argumentów.
                                                 //obraz zostanie pobrany ze standardowego
                                                 //wejścia, czyli tutaj pipe.

        close(pipe1[0]);    //zamknięcie odczytu
    }
}
