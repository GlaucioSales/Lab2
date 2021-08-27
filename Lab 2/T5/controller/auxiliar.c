#include "auxiliar.h"

void solicitaString(char texto[255], char *string){
    printf("%s", texto);
    gets(string);
}

int solicitaInteiro(char texto[255]){
    int valor;
    printf("%s", texto);
    scanf("%d", &valor);
    fflush(stdin); //para hambientes linux usar flush_in();
    return valor;
}

double solicitaDouble(char texto[255]){
    double valor;
    printf("%s", texto);
    scanf("%lf", &valor);
    fflush(stdin); //para hambientes linux usar flush_in();
    return valor;
}

float solicitaFloat(char texto[255]){
    float valor;
    printf("%s", texto);
    scanf("%f", &valor);
    fflush(stdin); //para hambientes linux usar flush_in();
    return valor;
}

void quebraLinha(){
    printf("\n\n");
}
