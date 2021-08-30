#ifndef _STUDENT_H
#define _STUDENT_H
#define _LONGITUD_MAXIMA 300

#include <stdio.h>
#include <stdlib.h>

struct Obj_t{
    char *nombre;
    int cedula;
};

struct _courseInfo_t{
    char name[32];
    int credits;
    float grade;
};

void feature1(FILE *fin, FILE *fout){
    char bufer[_LONGITUD_MAXIMA], *tk;
    fgets(bufer, _LONGITUD_MAXIMA, fin);
    tk = strtok(bufer,"\n");
    fprintf(fout,"%s\n",tk);
}
void feature2(FILE *fin, FILE *fout){
    char *car, bufer[_LONGITUD_MAXIMA];
    char temporal;
    fgets(bufer,_LONGITUD_MAXIMA, fin);
    car = strtok(bufer,"\n");
    for(int i=0;i<_LONGITUD_MAXIMA/2; i++){
        temporal = bufer[i];
        bufer[i] = bufer[_LONGITUD_MAXIMA-i+1];
        bufer[_LONGITUD_MAXIMA -i+1] = temporal;
    }
    
    
    fprintf(fout,"%s\n",bufer);
    
}
void feature3(FILE *fin, FILE *fout){
    char bufer[_LONGITUD_MAXIMA], *token;
    int sum = 0, num[_LONGITUD_MAXIMA], i=0;
    fgets(bufer,_LONGITUD_MAXIMA,fin);
    token = strtok(bufer," ");
    while(token != NULL){
        num[i] = atoi(token);
        token = strtok(NULL," ");
        i++;
    }
    fprintf(fout,"%d",sum);
}
void feature4(FILE *fin, int **parr, int *length, char **op);
void feature5(FILE *fout, int *parr, int length, char *op);
void feature6(FILE *fin, struct Obj_t *pobj);
void feature7(FILE *fout, struct Obj_t *pobj);
void feature8(FILE *fin, struct _courseInfo_t **pobj,int *length);
void feature9(FILE *fout, struct _courseInfo_t *pobj,int length);

#endif