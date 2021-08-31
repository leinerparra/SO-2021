#include <stdlib.h>
#include <string.h>
#include "student.h"

void feature1(FILE *fin, FILE *fout){
    char* bufer= (char *)calloc(sizeof(char),_LONGITUD_MAXIMA);
    fgets(bufer,_LONGITUD_MAXIMA,fin);
    fprintf(fout,bufer);
    free(bufer);
}
void feature2(FILE *fin, FILE *fout){
    char* bufer = (char *)calloc(sizeof(char),_LONGITUD_MAXIMA);
    fgets(bufer,_LONGITUD_MAXIMA,fin);
    char* bufer2 = strtok(bufer,"\n");
    char* temp = (char *)calloc(sizeof(char),1);
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
    char* bufer = (char *)calloc(sizeof(char),_LONGITUD_MAXIMA);
    short* numeros = (short *)calloc(sizeof(short),_LONGITUD_MAXIMA);
    char* temp = (char *)calloc(sizeof(char),4);
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
    fprintf(fout,"%d",sum);
    free(numeros);
    free(temp);
    free(bufer);
}
void feature4(FILE *fin, int **parr, int *length, char **op){}
void feature5(FILE *fout, int *parr, int length, char *op){}
void feature6(FILE *fin, struct Obj_t *pobj){}
void feature7(FILE *fout, struct Obj_t *pobj){}
void feature8(FILE *fin, struct _courseInfo_t **pobj,int *length){}
void feature9(FILE *fout, struct _courseInfo_t *pobj,int length){}