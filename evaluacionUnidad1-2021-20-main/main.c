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
    int cont=0,cant=0, j=0;
    fpi = fopen(argv[1],"r");
    fpo = fopen(argv[2], "w");
    if(fpi==NULL) {
        printf("FILE ERROR FILE DOESN'T EXISTS");
        return EXIT_FAILURE;
    }else{
        while((caracter = fgetc(fpi)) != EOF){
            if(caracter == '\n') {
                cont++;
            }
            if(cont == 1){
                cant++;
            }
        }
        cont=0;
        rewind(fpi);
        char frase[cant];
        while((caracter = fgetc(fpi)) != EOF){
            if(cont == 0){ //feature1
                fprintf(fpo,"%c",caracter);
            }else if(cont == 1){ //feature2
                if(j!=0){
                    frase[cant-j] = caracter;
                }
                j++;
                if(cant==j){
                    frase[0] = ' ';
                    fprintf(fpo,frase);
                }
            }

            if(caracter == '\n'){
                cont++;
            }
        }
        fprintf(fpo,"\n");

    }



    fclose(fpi);
    fclose(fpo);
    return EXIT_SUCCESS;
}
