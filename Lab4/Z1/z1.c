#include <stdio.h>
#include <time.h>

int main(){

    int i=0;

    while(1){

        i++;

        if(i==1000000000){
            i=0;
            printf("\nJest działane.\n");
        }
    }

    return 0;
}
