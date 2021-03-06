#define _LONGITUD_MAXIMA 200

#include <stdlib.h>
#include <string.h>
#include "student.h"

void feature1(FILE *fin, FILE *fout){
    char* bufer= (char *)calloc(_LONGITUD_MAXIMA,sizeof(char));
    fgets(bufer,_LONGITUD_MAXIMA,fin);
    fprintf(fout,bufer);
    free(bufer);
}
void feature2(FILE *fin, FILE *fout){
    char* bufer = (char *)calloc(_LONGITUD_MAXIMA,sizeof(char));
    fgets(bufer,_LONGITUD_MAXIMA,fin);
    char* bufer2 = strtok(bufer,"\n");
    char* temp = (char *)calloc(1,sizeof(char));
    int lon = strlen(bufer2);
    for(int izq=0,der =lon-1;izq <(lon/2);izq++,der--){
        *temp = bufer2[izq];
        bufer2[izq] = bufer2[der];
        bufer2[der] = *temp;
    }
    fprintf(fout,bufer2);
    fprintf(fout,"\n");
    //free(bufer); si Se deja Activo, Aborta
    free(bufer2);
    free(temp);

}
void feature3(FILE *fin, FILE *fout){
    char* bufer = (char *)calloc(_LONGITUD_MAXIMA,sizeof(char));
    short* numeros = (short *)calloc(_LONGITUD_MAXIMA,sizeof(short));
    char* temp = (char *)calloc(4,sizeof(char));
    char *bash;
    fgets(bufer,_LONGITUD_MAXIMA,fin);
    short i=0;
    int sum=0;
    temp = strtok(bufer," ");
    while(temp != NULL){
        numeros[i] = strtol(temp,&bash,10);
        sum = sum + numeros[i];
        temp = strtok(NULL," ");
        i++;
    }
    fprintf(fout,"%d\n",sum);
    free(numeros);
    free(temp);
    free(bufer);
}
void feature4(FILE *fin, int **parr, int *length, char **op){
    char* bufer = (char *)calloc(_LONGITUD_MAXIMA,sizeof(char));
    char* temp = (char *)calloc(4,sizeof(char));
    *parr  = (int *)calloc(_LONGITUD_MAXIMA,sizeof(int));
    char *bash = (char *)calloc(4,sizeof(char));
    *op= (char *)calloc(4,sizeof(char));
    *length = 0;
    int i=0;
    fgets(bufer,_LONGITUD_MAXIMA,fin);
    temp = strtok(bufer," ");
    while(temp != NULL){
        (*parr)[i] = strtol(temp,&bash,10);
        temp = strtok(NULL," ");
        i++;
    }
    strncpy(*op,bash,3);
    *length = i;
    free(bufer);
    //free(numeros);
    free(temp);
    //free(bash);
    //free(ope);
    
}
void feature5(FILE *fout, int *parr, int length, char *op){
    if(strcmp(op,"avg")==0){
        int sum=0;
        for(short i=0; i < length-1;i++){
            sum = sum+parr[i];
        }
        fprintf(fout,"%d\n",(sum/(length-1)));
    }else if(strcmp(op,"min")==0){
        int min=1000;
        for(short i=0; i < length-1;i++){
            if(parr[i] < min){
                min = parr[i];
            }
        }
        fprintf(fout,"%d\n",min);
    }else if(strcmp(op,"max")==0){
        int max=-1000;
        for(short i=0; i < length-1;i++){
            if(parr[i] > max){
                max = parr[i];
            }
        }
        fprintf(fout,"%d\n",max);
    }else{
        printf("Operaci??n No reconocida");
    }
    free(parr);
    free(op);
}
void feature6(FILE *fin, struct Obj_t *pobj){
    char* bufer = (char *)calloc(_LONGITUD_MAXIMA,sizeof(char));
    char* nombre = (char *)calloc(_LONGITUD_MAXIMA,sizeof(char));
    int cedula = 0;
    pobj->nombre = (char *)calloc(_LONGITUD_MAXIMA,sizeof(char));
    char* bash;
    fgets(bufer,_LONGITUD_MAXIMA,fin);
    nombre = strtok(bufer,",");
    cedula = strtol(strtok(NULL,","),&bash,10);
    strcpy(pobj->nombre,nombre);
    pobj->cedula = cedula;
    free(bufer);
    //free(nombre);

}
void feature7(FILE *fout, struct Obj_t *pobj){
    fprintf(fout,"%d, %s\n",pobj->cedula, pobj->nombre);
    free(pobj);
}
void feature8(FILE *fin, struct _courseInfo_t **pobj,int *length){
    char* bufer = (char *)calloc(_LONGITUD_MAXIMA,sizeof(char));
    int N=0, j=0;
    char *bash;
    char *bash2;
    fgets(bufer,_LONGITUD_MAXIMA,fin);
    N = strtol(bufer,&bash,10);
    struct _courseInfo_t *parr = (struct _courseInfo_t *)calloc(N,sizeof(struct _courseInfo_t));
    printf("Ahora, Vas A ingresar la Info en el orden Curso,Creditos,Nota\n");
    for(short i=0; i<N; i++){
        j=0;
        printf("Cuso %d: ",i+1);
        fgets(bufer,_LONGITUD_MAXIMA,stdin);
        bash = strtok(bufer,",");
        while(bash!=NULL){
            if(j==0){
                strcpy(parr[i].name,bash);
            }else if(j==1){
                parr[i].credits = strtol(bash,&bash2,10);
            }
            else if(j==2){
                parr[i].grade= strtof(bash,&bash2);
            }
            j++;
            bash = strtok(NULL,",");
        }
    }
    *pobj = parr;
    *length = N;
    free(bufer);
    fclose(fin);
}
void feature9(FILE *fout, struct _courseInfo_t *pobj,int length){
    char* bufer = (char *)calloc(10,sizeof(char));
    int sumaNota = 0, sumaCredito=0;
    float promedio=0.0f;
    for(short i=0; i<length;i++){
        sumaNota = sumaNota + pobj[i].grade*pobj[i].credits;
        sumaCredito = sumaCredito + pobj[i].credits;
    }
    promedio = sumaNota/sumaCredito;
    printf("Deseas almacenar la Informacion? (s) o (n)\n");
    fgets(bufer,10,stdin);
    char *tk = strtok(bufer,"\n");
    if(strcmp(tk,"s")==0 || strcmp(tk,"S")==0){
        for(short i=0;i<length;i++){
            fprintf(fout,"%s,%d,%f\n",pobj[i].name,pobj[i].credits,pobj[i].grade);
        }
        fprintf(fout,"Promedio ponderado: %f",promedio);
    }else{
        fprintf(fout,"Promedio ponderado: %f",promedio);
    }
    free(bufer);
    free(pobj);
    fclose(fout);

}