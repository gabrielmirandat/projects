//O caminho do diretorio deve ser passado como argumento da main.

#include <stdio.h>
//deve ser incluso tinydir.h baixado da internet. Este eh o caminho absoluto para meu pc.
#include "/home/gabriel/tinydir-master/tinydir.h"

int main(int argc, char* argv[])
{
  FILE* fp;
  //especifique o nome do arquivo texto a ser gerado.
  fp = fopen("nvnosso3.txt", "w");
  tinydir_dir dir;
  tinydir_open(&dir, argv[1]);
  
  while (dir.has_next)
  {
    tinydir_file file;
    tinydir_readfile(&dir, &file);

    printf("%s", file.name);
    //habilite um dos dois abaixo em caso do diretorio negativo ou positivo. Eh para ser de acordo com o padrao. 
    fprintf(fp,"neg/nvnosso3/%s", file.name);
    //fprintf(fp,"pos/%s  1  0 0 38 38", file.name);
    
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
