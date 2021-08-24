#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[]){

    if(argc!=3){
        printf("Se Esperaban 2 Argumentos, Archivo de Entrada y Archivo de Salida\n");
        return EXIT_FAILURE;
    }

    FILE *fp;
    char caracter;
    fp = fopen(argv[1],"r");
    if(fp==NULL) {
        printf("FILE ERROR FILE DOESN'T EXISTS");
        return EXIT_FAILURE;
    }else{
        printf("Esto es un test:\n\n");
        while((caracter = fgetc(fp)) != EOF){
            printf("%c",caracter);
        }
    }



    fclose(fp);
    return EXIT_SUCCESS;
}
