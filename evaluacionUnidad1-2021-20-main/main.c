#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[]){

    if(argc!=3){
        printf("Se Esperaban 2 Argumentos, Archivo de Entrada y Archivo de Salida\n");
        return EXIT_FAILURE;
    }

    FILE *fpi, *fpo;
    char caracter;
    fpi = fopen(argv[1],"r");
    fpo = fopen(argv[2], "w");
    if(fpi==NULL) {
        printf("FILE ERROR FILE DOESN'T EXISTS");
        return EXIT_FAILURE;
    }else{
        printf("Revise el Archivo %s:\n\n",argv[2]);
        while((caracter = fgetc(fpi)) != EOF){
            fprintf(fpo,"%c",caracter);
        }
    }



    fclose(fpi);
    fclose(fpo);
    return EXIT_SUCCESS;
}
