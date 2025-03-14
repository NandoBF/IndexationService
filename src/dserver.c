#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO "tmp/dfifo"
#define MAX_READ 512


int main(int argc, char* argv[]){
    //if(argc < 2) perror("Insuficient arguments on server launch.");
    //char document_folder[64] = argv[1];
    //int cache_size = atoi(argv[2]);

    //open named pipe
    mkfifo(FIFO, 0666);
    
    char fifo_in[MAX_READ];

    int dfifo; //fifo pipe descriptor
    while(1){

        dfifo = open(FIFO, O_RDONLY);
        if(read(dfifo, fifo_in, MAX_READ) < 0) continue;

        printf("SERVER READS: %s\n", fifo_in);
        close(dfifo);

    }

    return 0;
}
