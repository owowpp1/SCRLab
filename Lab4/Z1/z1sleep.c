#include <stdio.h>
#include <time.h>

int main(){

    int i=0;

    struct timespec req = {0};
    req.tv_sec = 0;
    req.tv_nsec = 100 * 1000000L;

    while(1){

        i++;
        nanosleep(&req, (struct timespec *)NULL);

        if(i==10){
            i=0;
            printf("\nJest działane.\n");
        }
    }

    return 0;
}
