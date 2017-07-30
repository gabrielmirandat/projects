#include <stdio.h>
#include "/home/gabriel/tinydir-master/tinydir.h"

int main(int argc, char *argv[])
{
  FILE* fp;
  fp = fopen("bg.txt", "w");
  tinydir_dir dir;
  tinydir_open(&dir, argv[1]);
  
  while (dir.has_next)
  {
    tinydir_file file;
    tinydir_readfile(&dir, &file);

    printf("%s", file.name);
    fprintf(fp,"neg/%s", file.name);
    
    if (file.is_dir)
    {
        printf("/");
    }
    printf("\n");
    fprintf(fp, "\n");

    tinydir_next(&dir);
  }
  fclose(fp);
  tinydir_close(&dir);
  
  return 0;
}
