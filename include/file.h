
typedef struct file File;


int get_file_fid(File* f);
char* get_file_title(File* f);
char* get_file_author(File* f);
int get_file_year(File* f);
char* get_file_path(File* f);
File* create_file(int argc, char* argv[]);
void destroy_file(File* f);
