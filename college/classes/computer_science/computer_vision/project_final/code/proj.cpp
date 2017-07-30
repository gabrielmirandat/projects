#ifndef TEXTDETECTION_H
  #include "TextDetection.h"
#endif

 

 using namespace std;
 using namespace cv;


static void help()
{
    cout <<  "Modo de uso:" << endl
         <<  "Ao executar o programa, insira o nome do diretório onde se encontram os imagens."  << endl
         <<  "O diretório deve conter apenas as imagens. "<< endl;
}

 /** Function Headers */
 void detectAndDisplay( Mat frame );
 int getdir (string dir, vector<string> &files);

 /** Global variables */

 /** @function main */
 int main( int argc, const char** argv )
 {
   Mat frame;
   string dir;
   vector<string> files = vector<string>();
   
   if (argc == 2) { 
     dir = argv[1];
   }else{
     help();
     return -1;
   }
  
  //-- 1. Carregando as imagens do diretório
  if(!getdir(dir,files)) return -1;

  //-- 2. Loop 
  for (unsigned int i = 2;i < files.size();i++) {
    cout<<i-1<<endl;
    //cout<<dir+"/"+files[i]<<endl;
    string salvar = dir+"/"+files[i];
    frame = imread(salvar);
    if(frame.empty()){ cout << "\nERRO! Só contém imagens??\n"; return -1; };
    
    cvtColor(frame,frame,CV_BGR2RGB);
    
    IplImage ipl_img = frame;
    IplImage* pOut =  textDetection (&ipl_img,salvar,true);
    Mat out = Mat(pOut);
    
    string saida = salvar +"(4)";
    imwrite(saida, out );
    
    //cvReleaseImage ( IplImage );
    cvReleaseImage ( &pOut );
  }
 
  return 0;
}

/** @function getdir */
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "\nERRO! Impossível abrir diretório ou diretório vazio.\n";
	return 0;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 1;
}