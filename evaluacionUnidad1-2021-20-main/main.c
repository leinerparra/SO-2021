#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

char* substr(char* cadena, int comienzo, int longitud)
{
    if (longitud == 0) 
        longitud = strlen(cadena)-comienzo;
    
    char *nuevo = (char*)malloc(sizeof(char) * (longitud+1));
    nuevo[longitud] = '\0';
    strncpy(nuevo, cadena + comienzo, longitud);
    
    return nuevo;
}

int main(int argc, char *argv[]){

    if(argc!=3){
        printf("Se Esperaban 2 Argumentos, Archivo de Entrada y Archivo de Salida\n");
        return EXIT_FAILURE;
    }

    FILE *fpi, *fpo;
    char caracter, num[5], *numm, *ope, line[100], nombre[30],cc[30];
    int cont=0,cant=0, j=0,k=0, sum=0, nume=0,Ced=0;
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

            if(caracter == '\n'){ //feature5
                ope = substr(numm,0, 3);

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
                k=0;
            }
            }else if(cont==4){ //feature6
                if(caracter != '\n'){
                    line[k] = caracter;
                    k++;
                }else{
                    short x=0,y=0;
                    for(int i=0; i<k;i++){
                        if(line[i]==','){
                            x=1;
                        }
                        else if(x==0){
                            nombre[i] = line[i];
                        }else if(x==1){
                            cc[y] = line[i];
                            y++;
                        }
                    }
                    Ced = strtol(cc,&numm,0);
                    struct Obj_t Est1 = {nombre, Ced};
                    printf("%s",Est1.nombre);
                    printf("%d",Est1.cedula);
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
