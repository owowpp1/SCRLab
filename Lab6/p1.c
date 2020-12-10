#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#define bufor 1

int main(){

    int rozmiar, znak;
    int fd, mapa;
    char *adr_mapy;
    char buforek[bufor], nazwa[20];
    struct stat staty;


    mapa=open("mapa.txt", O_RDWR);  //otwarcie pliku z mapą
    if(mapa<0){                     //błąd otwarcia pliku
        printf("Błąd otwarcia pliku mapa.txt.\n");
        return 0;
    }
    while(1){
        rozmiar=lseek(mapa, 0, SEEK_END);   //odległość od 0 do końca=rozmiar

        printf("Podaj nazwę pliku:\n");
        scanf("%s", nazwa);

        fd=open(nazwa, O_RDONLY);     //otwarcie pliku z mapą
        if(fd<0){                     //błąd otwarcia pliku
            printf("Błąd otwarcia pliku %s.\n", nazwa);
            return 0;
        }
        fstat(fd, &staty);            //pobranie statystyk pliku

        //zmapowanie:
        //  adres |  rozmiar w pamięci  |      prawa dostępu    |   flaga   |  fd | offset
        adr_mapy=mmap(NULL, staty.st_size+rozmiar, PROT_WRITE | PROT_READ, MAP_SHARED, mapa, 0);
        ftruncate(mapa, staty.st_size+rozmiar);     //rozszerzenie pamięci

        znak=0;     //wypisanych znaków: 0
        while(read(fd, buforek, bufor)){        //odczyt z pliku pod fd do buforka (0-EOF)
            adr_mapy[rozmiar+znak]=buforek[0];  //zapis po jednym znaku do adresu mapy+rozmiar+wypisane znaki
            znak++;                             //wypisane znaki
        }

    }

}
