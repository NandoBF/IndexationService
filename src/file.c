#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_SIZE 200
#define AUTHOR_SIZE 200
#define PATH_SIZE 64

char* strdup(const char* s);

typedef struct file{
    int fid;
    char* title;
    char* authors;
    int year;
    char* path;
}File;

int get_file_fid(File* f){
    if(f) return f->fid;
    return -1;
}

char* get_file_title(File* f){
    if(f){
        char* ret = strdup(f->title);
        return ret;
    }
    return NULL;
}

char* get_file_author(File* f){
    if(f){
        char* ret = strdup(f->authors);
        return ret;
    }
    return NULL;
}

int get_file_year(File* f){
    if(f) return f->year;
    return -1;
}

char* get_file_path(File* f){
    if(f) return strdup(f->path);
    return NULL;
}


// FAZER INDEXMANAGER E METER AQUI O FID
// Fazer um skibidi parser para dar parse das inputs
// NAO TENHO STRING.H????
File* create_file(int argc, char* argv[]){

    int arg_counter = 0;
    File* new_f = malloc(sizeof(File));
    new_f->title = argv[arg_counter++];
    new_f->authors = argv[arg_counter++];
    new_f->year = atoi(argv[arg_counter++]);
    new_f->path = argv[arg_counter++];
    
    return new_f;
}

void destroy_file(File* f){
    if(!f) return;
    free(f->title);
    free(f->authors);
    free(f->path);
    free(f);
    // :)
}



