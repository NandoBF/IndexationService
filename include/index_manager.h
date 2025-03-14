#include "file.h"

typedef struct index_manager Index_manager;

int get_fid_counter(Index_manager* i);
File* get_file_by_fid(Index_manager* i);
int index_file(Index_manager* i);
