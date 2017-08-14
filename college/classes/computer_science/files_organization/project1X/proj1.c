#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************variaveis globais*************************/
FILE* fp1;
FILE* fp2;

/*tamanhos dos registros*/
int bytes_lista1;
int bytes_lista2;

/*palavras current do arquivo*/
char str1[50];
char str2[50];
char str3[50];
char str4[50];
char concatenado[50];

/*indices*/
int ind_prim_l1;
int ind_psec_l1;
int ind_ssec_l1;

int ind_prim_l2;
int ind_psec_l2;
int ind_ssec_l2;

/*struct*/
struct registros{
    char chave[50];
    int pos_rel;
};
typedef struct registros Registro;

/*vetores*/
Registro* vet_prim_l1;
Registro* vet_psec_l1;
Registro* vet_ssec_l1;
Registro* label_psec_l1;
Registro* label_ssec_l1;

Registro* vet_prim_l2;
Registro* vet_psec_l2;
Registro* vet_ssec_l2;
Registro* label_psec_l2;
Registro* label_ssec_l2;

/****************funcoes******************/

void bytes_registro();
void leitor_arquivo1();
void leitor_arquivo2();
void construtor_vetores_lista1();
void construtor_vetores_lista2();
void concatenador();
void liberador();

/******************************************/

/*encontra numero de bytes por registro*/
void bytes_registro(){
    char str[100];
    fp1=fopen("lista1.txt","r");
    fscanf(fp1,"%[^\n]s",str);
    bytes_lista1=strlen(str);
    fclose(fp1);

    fp2=fopen("lista2.txt","r");
    fscanf(fp2,"%[^\n]s",str);
    bytes_lista2=strlen(str);
    fclose(fp2);
}

/*encontra os elementos no arquivo.txt*/
void leitor_arquivo1(){
    int i;
    fp1=fopen("lista1.txt","r");

    while(fscanf(fp1,"%s",str2)>0){
        fseek(fp1,2,SEEK_CUR);
        fread(str1,1,41,fp1);
        for(i=0;i<38;i++){
            if (str1[i]==' ' && str1[i+1]==' '){
                str1[i]='\0';
            }
        }
        fseek(fp1,1,SEEK_CUR);
        fscanf(fp1,"%s",str3);
        fseek(fp1,12,SEEK_CUR);
        fscanf(fp1,"%s",str4);

        construtor_vetores_lista1();
    }
    fclose(fp1);
}

/*encontra os elementos no arquivo.txt*/
void leitor_arquivo2(){
    int i;
    fp2=fopen("lista2.txt","r");

    while(fscanf(fp2,"%s",str2)>0){
        fseek(fp2,2,SEEK_CUR);
        fread(str1,1,41,fp2);
        for(i=0;i<38;i++){
            if (str1[i]==' ' && str1[i+1]==' '){
                str1[i]='\0';
            }
        }
        fseek(fp2,1,SEEK_CUR);
        fscanf(fp2,"%s",str3);
        fseek(fp2,12,SEEK_CUR);
        fscanf(fp2,"%s",str4);

        construtor_vetores_lista2();
    }
    fclose(fp2);
}


/*constroi os vetores da lista1*/
void construtor_vetores_lista1(){
    int i;
    int andador,anterior;

    concatenador();

    /*Constroi o primeiro vetor de indice primario*/
    strcpy(vet_prim_l1[ind_prim_l1].chave,concatenado);
    vet_prim_l1[ind_prim_l1].pos_rel=ind_prim_l1;

    /*Constroi o primeiro label_list*/
    strcpy(label_psec_l1[ind_prim_l1].chave,concatenado);
    label_psec_l1[ind_prim_l1].pos_rel=-1;

    /*Constroi o segundo label_list*/
    strcpy(label_ssec_l1[ind_prim_l1].chave,concatenado);
    label_ssec_l1[ind_prim_l1].pos_rel=-1;

    ind_prim_l1++;

    /*Constroi o primeiro vetor de indice secundario*/
    /*sem elemento algum*/
    if(vet_psec_l1==NULL){
        vet_psec_l1 = ((Registro*) malloc(sizeof(Registro)));
        strcpy(vet_psec_l1[ind_psec_l1].chave,str3);
        vet_psec_l1[ind_psec_l1].pos_rel=0;
        ind_psec_l1++; /*ind_psec_l1=1;*/
    }else if(vet_psec_l1!=NULL){
        i=0;

        while(i<ind_psec_l1 && strcmp(vet_psec_l1[i].chave,str3)!=0){
            i++;
        }
        /*elemento repetido*/
        if(i!=ind_psec_l1){
            andador=vet_psec_l1[i].pos_rel;
            anterior=-1;
            while(andador!=-1){
                anterior=andador;
                andador=label_psec_l1[anterior].pos_rel;
            }
            label_psec_l1[anterior].pos_rel=ind_prim_l1-1;
            /*novo elemento*/
        }else if(i==ind_psec_l1){
            vet_psec_l1 =(Registro*) realloc(vet_psec_l1,sizeof(Registro));
            strcpy(vet_psec_l1[ind_psec_l1].chave,str3);
            vet_psec_l1[ind_psec_l1].pos_rel=ind_prim_l1-1;
            ind_psec_l1++;
        }
    }


    /*Constroi o segundo vetor de indice secundario*/
    /*sem elemento algum*/
    if(vet_ssec_l1==NULL){
        vet_ssec_l1 = ((Registro*) malloc(sizeof(Registro)));
        strcpy(vet_ssec_l1[ind_ssec_l1].chave,str4);
        vet_ssec_l1[ind_ssec_l1].pos_rel=0;
        ind_ssec_l1++; /*ind_ssec_l1=1;*/
    }else if(vet_ssec_l1!=NULL){
        i=0;

        while(i<ind_ssec_l1 && strcmp(vet_ssec_l1[i].chave,str4)!=0){
            i++;
        }
        /*elemento repetido*/
        if(i!=ind_ssec_l1){
            andador=vet_ssec_l1[i].pos_rel;
            anterior=-1;
            while(andador!=-1){
                anterior=andador;
                andador=label_ssec_l1[anterior].pos_rel;
            }
            label_ssec_l1[anterior].pos_rel=ind_prim_l1-1;
            /*novo elemento*/
        }else if(i==ind_ssec_l1){
            vet_ssec_l1 =(Registro*) realloc(vet_ssec_l1,sizeof(Registro));
            strcpy(vet_ssec_l1[ind_ssec_l1].chave,str4);
            vet_ssec_l1[ind_ssec_l1].pos_rel=ind_prim_l1-1;
            ind_ssec_l1++;
        }
    }
}


/*constroi os vetores da lista2*/
void construtor_vetores_lista2(){
    int i;
    int andador,anterior;

    concatenador();

    /*Constroi o primeiro vetor de indice primario*/
    strcpy(vet_prim_l2[ind_prim_l2].chave,concatenado);
    vet_prim_l2[ind_prim_l2].pos_rel=ind_prim_l2;

    /*Constroi o primeiro label_list*/
    strcpy(label_psec_l2[ind_prim_l2].chave,concatenado);
    label_psec_l2[ind_prim_l2].pos_rel=-1;

    /*Constroi o segundo label_list*/
    strcpy(label_ssec_l2[ind_prim_l2].chave,concatenado);
    label_ssec_l2[ind_prim_l2].pos_rel=-1;


    ind_prim_l2++;

    /*Constroi o primeiro vetor de indice secundario*/
    /*sem elemento algum*/
    if(vet_psec_l2==NULL){
        vet_psec_l2 = ((Registro*) malloc(sizeof(Registro)));
        strcpy(vet_psec_l2[ind_psec_l2].chave,str3);
        vet_psec_l2[ind_psec_l2].pos_rel=0;
        ind_psec_l2++; /*ind_psec_l2=1;*/
    }else if(vet_psec_l2!=NULL){
        i=0;

        while(i<ind_psec_l2 && strcmp(vet_psec_l2[i].chave,str3)!=0){
            i++;
        }
        /*elemento repetido*/
        if(i!=ind_psec_l2){
            andador=vet_psec_l2[i].pos_rel;
            anterior=-1;
            while(andador!=-1){
                anterior=andador;
                andador=label_psec_l2[anterior].pos_rel;
            }
            label_psec_l2[anterior].pos_rel=ind_prim_l2-1;
            /*novo elemento*/
        }else if(i==ind_psec_l2){
            vet_psec_l2 =(Registro*) realloc(vet_psec_l2,sizeof(Registro));
            strcpy(vet_psec_l2[ind_psec_l2].chave,str3);
            vet_psec_l2[ind_psec_l2].pos_rel=ind_prim_l2-1;
            ind_psec_l2++;
        }
    }

    /*Constroi o segundo vetor de indice secundario*/
    /*sem elemento algum*/
    if(vet_ssec_l2==NULL){
        vet_ssec_l2 = ((Registro*) malloc(sizeof(Registro)));
        strcpy(vet_ssec_l2[ind_ssec_l2].chave,str4);
        vet_ssec_l2[ind_ssec_l2].pos_rel=0;
        ind_ssec_l2++; /*ind_ssec_l2=1;*/
    }else if(vet_ssec_l2!=NULL){
        i=0;

        while(i<ind_ssec_l2 && strcmp(vet_ssec_l2[i].chave,str4)!=0){
            i++;
        }
        /*elemento repetido*/
        if(i!=ind_ssec_l2){
            andador=vet_ssec_l2[i].pos_rel;
            anterior=-1;
            while(andador!=-1){
                anterior=andador;
                andador=label_ssec_l2[anterior].pos_rel;
            }
            label_ssec_l2[anterior].pos_rel=ind_prim_l2-1;
            /*novo elemento*/
        }else if(i==ind_ssec_l2){
            vet_ssec_l2 =(Registro*) realloc(vet_ssec_l2,sizeof(Registro));
            strcpy(vet_ssec_l2[ind_ssec_l2].chave,str4);
            vet_ssec_l2[ind_ssec_l2].pos_rel=ind_prim_l2-1;
            ind_ssec_l2++;
        }
    }
}

/*cria a string concatenada*/
void concatenador(){
    int j;
    int i=0;
    while(str1[i]!='\0'){
        concatenado[i]=str1[i];
        i++;
    }
    j=i;
    i=0;
    while(str2[i]!='\0'){
        concatenado[j]=str2[i];
        i++;
        j++;
    }
    concatenado[j]='\0';
    if(j>29){
        concatenado[29]='\0';
    }
}

void liberador(){
    free(vet_prim_l1);
    free(label_psec_l1);
    free(label_ssec_l1);
    free(vet_psec_l1);
    free(vet_ssec_l1);

    free(vet_prim_l2);
    free(label_psec_l2);
    free(label_ssec_l2);
    free(vet_psec_l2);
    free(vet_ssec_l2);
}

int main(){
    /*indices lista 1*/
    ind_prim_l1=0;
    ind_psec_l1=0;
    ind_ssec_l1=0;
    /*indices lista 2*/
    ind_prim_l2=0;
    ind_psec_l2=0;
    ind_ssec_l2=0;


    bytes_registro();

    /*vetores e labels da lista 1*/
    vet_prim_l1 = ((Registro*) malloc(19*sizeof(Registro)));
    label_psec_l1 = ((Registro*) malloc(19*sizeof(Registro)));
    label_ssec_l1 = ((Registro*) malloc(19*sizeof(Registro)));

    /*vetores e labels da lista 2*/
    vet_prim_l2 = ((Registro*) malloc(22*sizeof(Registro)));
    label_psec_l2 = ((Registro*) malloc(22*sizeof(Registro)));
    label_ssec_l2 = ((Registro*) malloc(22*sizeof(Registro)));


    leitor_arquivo1();
    leitor_arquivo2();
    
    liberador();

    return 0;
}
