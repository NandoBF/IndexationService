#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define FIFO "tmp/dfifo"
#define MAX_WRITE 512


int main(int argc, char* argv[]){
    if(argc < 1) perror("Insuficient arguments on server launch.");
    char* test_arg = argv[1];
    //int cache_size = atoi(argv[2]);

    //open named pipe
    mkfifo(FIFO, 0666);

    int dfifo; //fifo pipe descriptor
    while(1){

        dfifo = open(FIFO, O_WRONLY);
        write(dfifo, test_arg, strlen(test_arg)+1);
        close(dfifo);

    }

    return 0;


}
