#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "file.h"

// Provavelmente tem de ser mudado
// Acredito que simplesmente indexar num array fique uma
// bela porcaria
// :)
typedef struct index_manager{
    int fid_counter;
    File** indexed_files;
    
}Index_manager;

int get_fid_counter(Index_manager* i){
    if(i) return i->fid_counter;
    return -1;
}

File* get_file_by_fid(Index_manager* i){
    //FAZER ISTO QUANDO SE PENSAR NUMA FORMA DE INDEXAR
    return NULL;
}

int index_file(Index_manager* i){
    //FAZER ISTO QUANDO SE PENSAR NUMA FORMA DE INDEXAR
    return 1;
}
