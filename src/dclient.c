#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define FIFO "tmp/dfifo"
#define MAX_WRITE 512


int is_fifo_open(){
    int dfifo = open(FIFO, O_WRONLY | O_NONBLOCK);
    if(dfifo == -1){
        return 1;
    }
    close(dfifo);
    return 0;
}


void write_to_pipe(char* message){
    int dfifo;
    dfifo = open(FIFO, O_WRONLY);
    write(dfifo, message, strlen(message)+1);
    close(dfifo);
}

int main(int argc, char* argv[]){
    if(is_fifo_open()){
        printf("OOPS! Parece que nao tenho conexao com o servidor!\nTalvez te tenhas esquecido de abrir o servidor?\n");
        return -1;
    }
    if(argc < 2) {
        printf("Sem argumentos! Usa -h\n");
        return 0;
    }
    
    if(!strcmp(argv[1], "-a")){
        if(argc < 6){
            perror("Insuficientes argumentos para adicionar ficheiro!");
            return -1;
        }

        char pipe_send[MAX_WRITE];
        //separador bem fancy porque sim
        //bite me
        // :)
        snprintf(pipe_send, MAX_WRITE, "%s<>%s<>%s<>%s<>%s", 
                argv[1], argv[2], argv[3], argv[4], argv[5]);

        write_to_pipe(pipe_send);
        return 0;

    } else if(!strcmp(argv[1], "-c") || !strcmp(argv[1], "-d") || !strcmp(argv[1], "-s")){
        if(argc < 3){
            perror("Insuficientes argumentos para realizar a operacao!");
            return -1;
        }
        char pipe_send[MAX_WRITE];

        snprintf(pipe_send, MAX_WRITE, "%s<>%s",
                argv[1], argv[2]);

        write_to_pipe(pipe_send);
        return 0;
    } else if (!strcmp(argv[1], "-l")){
        if(argc < 4){
            perror("Insuficientes argumentos para a operacao!");
            return -1;
        }
        char pipe_send[MAX_WRITE];
        
        snprintf(pipe_send, MAX_WRITE, "%s<>%s<>%s",
                argv[1], argv[2], argv[3]);

        write_to_pipe(pipe_send);
        return 0;
     
    }else if(!strcmp(argv[1], "-h")){
        printf("Para anexar um fichero\n    -> dclient -a 'title' 'authors' 'year' 'path'\n");
        printf("Para consultar um fichero\n    -> dclient -c 'key'\n");
        printf("Para remover um fichero\n    -> dclient -d 'key'\n");
        printf("Para listar um fichero\n    -> dclient -l 'key' 'keyword'\n");
        printf("Para listar ficheros\n    -> dclient -s 'keyword'\n");
        return 0;

    }

    char* test_arg = argv[1];
    //int cache_size = atoi(argv[2]);

    //open named pipe
    mkfifo(FIFO, 0666);

    int dfifo; //fifo pipe descriptor

    // ESCREVE PARA O PIPE
    dfifo = open(FIFO, O_WRONLY);
    write(dfifo, test_arg, strlen(test_arg)+1);
    close(dfifo);


    return 0;


}
