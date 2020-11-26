#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
//
//#define rozmiarpaki 10

int main(int argc, char *argv[]){

    if(argc<2){     //brak argumentów
        printf("Nie podano nazwy pliku. Uruchom ponownie.\n");
        return 0;
    }

    int pipe1[2];           //adresy fd pipe'a pierwszego
    int plik;               //adres pliku
    long rozmiarpaki=10;    //rozmiar paczki
    char buforek[100];      //tu zapisujemy odczytany tekst
    int pomoc=0;            //counter

    if(argc>2){             //gdy dodano dodatkowy argument
        rozmiarpaki=strtol(argv[2], NULL, 10);
    }

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
        while((pomoc=read(pipe1[0], buforek, rozmiarpaki))>0){  //odczyt z bufora w pętli
            write(STDOUT_FILENO, "#", 1);                       //STDOUT_FILENO=1-wypisanie w terminalu
            write(STDOUT_FILENO, buforek, pomoc);               //Wypisanie bufora na terminal
            write(STDOUT_FILENO, "#\n", 2);                     //Wypisanie symbolu # i nowej linii.
        }
        close(pipe1[0]);                                        //zamknięcie odczytu
    }
}
