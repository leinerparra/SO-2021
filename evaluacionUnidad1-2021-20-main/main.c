#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main(int argc, char *argv[]){

    if(argc!=3){
        printf("Se Esperaban 2 Argumentos, Archivo de Entrada y Archivo de Salida\n");
        return EXIT_FAILURE;
    }

    FILE *fpi, *fpo;
    char caracter, num[5], *numm, ope[3];
    int cont=0,cant=0, j=0,k=0, sum=0, nume=0;
    int numero[100];
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
                if(caracter!='\n'){
                    fprintf(fpo,"%c",caracter);
                }   
            }else if(cont == 1){ //feature2
                if(j!=0){
                    frase[cant-j] = caracter;
                }
                j++;
                if(cant==j){
                    frase[0] = ' ';
                    fprintf(fpo,frase);
                    j=0;
                    fprintf(fpo,"\n");
                }
            }else if(cont== 2){//feature3
                if(caracter!=' ' && caracter !='\n'){
                    num[j] = caracter;
                    j++;
                }else{
                    j=0;
                    nume = strtol(num, &numm,0);
                    sum = sum + nume;
                    for(int i=0; i<5; i++){
                        num[i] = ' ';
                    }
                }
                if(caracter == '\n'){
                    fprintf(fpo,"%d\n",sum);
                }
            }else if(cont==3){//feature4
                if(caracter!=' ' && caracter !='\n'){
                    num[j] = caracter;
                    j++;
                }else{
                    j=0;
                    nume = strtol(num, &numm,0);
                    numero[k] = nume;
                    k++;
            }

            if(caracter == '\n'){
                for(int i=0; i<3;i++){
                    ope[i]=numm[i];
                }
                if(strcmp(ope,"avg")==0){
                    for(int i=0; i<=k;i++){
                        sum = sum + numero[i];
                    }
                    fprintf(fpo,"%d",(sum/k));
                }else if(strcmp(ope,"max")==0){
                    int max = -500;
                    for(int i =0; i<=k ; i++){
                        if(numero[i] > max){
                            max = numero[i];
                        }
                    }
                    fprintf(fpo,"%d",max);
                }else if(strcmp(ope,"min")==0){
                    int min = 500;
                    for(int i =0; i<=k ; i++){
                        if(numero[i] > min){
                            min = numero[i];
                        }
                    }
                    fprintf(fpo,"%d",min);
                }else{
                    fprintf(fpo,"Esa operacion no es reconocida");
                }
                
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
