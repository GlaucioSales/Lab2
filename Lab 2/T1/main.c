#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_VET 2

struct pessoa {
    int codigo;
    char nome[81];
    float peso;
    int altura;
    float IMC;
    char faixa[15];
};

typedef struct pessoa Pessoa;

void preenche (Pessoa* vet, int i, int codigo, char* nome, float peso, int altura);
//cadastrar pessoa
void cadastrarCodigoPessoa(int *codigo, int valor);
void cadastrarNomePessoa(char nome[81], char *valor);
void cadastrarPesoPessoa(float *peso, float valor);
void cadastrarAlturaPessoa(int *altura, int valor);
void cadastrarIMC (float *imc, float valor);
void cadastrarFaixa(float imc, char faixa[15]);
float computarIMC(float peso, int altura);
//apresentação de dados
void imprimeDados(Pessoa *pessoas, int tamanho);
void imprimeNomeDePessoasComSobrepeso(Pessoa *pessoas, int tamanho);
void imprimeCodigoDePessoasComObesidade(Pessoa *pessoas, int tamanho);
void imprimeValorMedioDosPesosDasPessoas(Pessoa *pessoas, int tamanho);
void imprimeQuantidadeDePessoasComPesoAcimaDoValorMedio(Pessoa *pessoas, int tamanho);
void imprimeQuantidadeDePessoasComPesoNormal(Pessoa *pessoas, int tamanho);
void imprimeNomeDePessoasComPesoNormalEComPesoAbaixoDaMedia(Pessoa *pessoas, int tamanho);
void imprimeNomeDePessoasComMaiorIMC(Pessoa *pessoas, int tamanho);
void imprimeNomeDePessoasComMenorIMC(Pessoa *pessoas, int tamanho);
//Funções auxiliares
void app(Pessoa* pessoas, int tamanho);
void imprimeMenu();
void limpaTela();
void preencheVetor(Pessoa *pessoas);
float valorMedioDosPesos(Pessoa *pessoas, int tamanho);
float encontraMaiorIMC(Pessoa *pessoas, int tamanho);
float encontraMenorIMC(Pessoa *pessoas, int tamanho);

void main(){
    Pessoa pessoas[TAM_VET];
    app(pessoas, TAM_VET);
}

void app(Pessoa* pessoas, int tamanho){
    int comando;    
    do {
        comando = 0;
        imprimeMenu();
        if(scanf("%i", &comando)){
            limpaTela();
            switch (comando){
                case 1:
                    imprimeDados(pessoas, TAM_VET);
                    break;
                case 2:
                    imprimeNomeDePessoasComSobrepeso(pessoas, TAM_VET);
                    break;
                case 3:
                    imprimeCodigoDePessoasComObesidade(pessoas, TAM_VET);
                    break;
                case 4:
                    imprimeValorMedioDosPesosDasPessoas(pessoas, TAM_VET);
                    break;
                case 5:
                    imprimeQuantidadeDePessoasComPesoAcimaDoValorMedio(pessoas, TAM_VET);
                    break;
                case 6:
                    imprimeQuantidadeDePessoasComPesoNormal(pessoas, TAM_VET);
                    break;
                case 7:
                    imprimeNomeDePessoasComPesoNormalEComPesoAbaixoDaMedia(pessoas, TAM_VET);
                    break;
                case 8:
                    imprimeNomeDePessoasComMaiorIMC(pessoas, TAM_VET);
                    break;
                case 9:
                    imprimeNomeDePessoasComMenorIMC(pessoas, TAM_VET);
                    break;
                case 10:
                    preencheVetor(pessoas);
                    break;
                case 0:
                    printf("Obrigado por utilizar o nosso programa volte sempre.");
                    break;
                default:
                    printf("opcao invalida");
                    break;
            }
        }
        
    } while (comando != 0);
}

void imprimeMenu(){
    printf("\n");
    printf("Comandos\n");
    printf("0) sair.\n");
    printf("1) os dados de todas as pessoas do vetor;\n");
    printf("2) o nome das pessoas que estão com sobrepeso;\n");
    printf("3) o codigo das pessoas que estao com obesidade;\n");
    printf("4) o valor medio dos pesos;\n");
    printf("5) a quantidade de pessoas que tem peso acima do valor medio dos pesos;\n");
    printf("6) a quantidade de pessoas que não estao na faixa normal de peso;\n");
    printf("7) o nome das pessoas que tem peso normal e que pesam menos do que o valor medio dos pesos;\n");
    printf("8) o nome da(s) pessoa(s) que obteve (obtiveram) o maior IMC;\n");
    printf("9) o codigo da(s) pessoa (s) que obteve (obtiveram) o menor IMC.\n");
    printf("10) cadastrar uma pessoa no vetor\n");
    printf("\n");
    printf("\n");
    printf(" o que gostaria de fazer? :");
    
}

void limpaTela(){
    system("cls");
}

void preencheVetor(Pessoa *pessoas){
        int codigo, posicao, altura;
        float peso;
        char nome[81];
        printf("Qual o nome da pessoa: ");
        scanf("%s", &nome);
        printf("Qual a posicao no vetor em que a pessoas deve ser alocada pessoa: ");
        scanf("%i", &posicao);
        printf("Qual o codigo da pessoa: ");
        scanf("%i", &codigo);
        printf("Qual o peso da pessoa: ");
        scanf("%f", &peso);
        printf("Qual a altura da pessoa em centimetros: ");
        scanf("%i", &altura);
        preenche(pessoas, posicao, codigo, nome, peso, altura);
}

void preenche (Pessoa* vet, int i, int codigo, char* nome, float peso, int altura){
    cadastrarCodigoPessoa(&vet[i].codigo, codigo);
    cadastrarNomePessoa(vet[i].nome, nome);
    cadastrarPesoPessoa(&vet[i].peso, peso);
    cadastrarAlturaPessoa(&vet[i].altura, altura);
    cadastrarIMC(&vet[i].IMC, computarIMC(vet[i].peso, vet[i].altura));
    cadastrarFaixa(vet[i].IMC, vet[i].faixa);
}

void cadastrarCodigoPessoa(int *codigo, int valor){
    *codigo = valor;
}

void cadastrarNomePessoa(char nome[81], char *valor){
    strcpy(nome, valor);
}

void cadastrarPesoPessoa(float *peso, float valor){
    *peso = valor;
}

void cadastrarAlturaPessoa(int *altura, int valor){
    *altura = valor;
}

void cadastrarIMC (float *imc, float valor){
    *imc = valor;
}

float computarIMC(float peso, int altura){
    return (peso / (altura * altura)) * 10000;
}

void cadastrarFaixa(float imc, char faixa[15]){
    if(imc < 18.5) {
        strcpy(faixa, "Magreza");
    } else if(imc >= 18.5 && imc <= 24.9) {
        strcpy(faixa, "Normal");
    } else if(imc >= 24.9 && imc < 30) {
        strcpy(faixa, "Sobrepeso");
    } else {
        strcpy(faixa, "Obesidade");
    }
}

void imprimeDados(Pessoa* pessoas, int tamanho){
    for (size_t i = 0; i < tamanho; i++){
        printf("%-50s", &pessoas[i].nome);
        printf("%-6i", pessoas[i].codigo);
        printf("%-10.2f", pessoas[i].peso);
        printf("%-9i", pessoas[i].altura);
        printf("%-9.2f", pessoas[i].IMC);
        printf("%s", &pessoas[i].faixa);
        printf("\n");
    }
}

void imprimeNomeDePessoasComSobrepeso(Pessoa *pessoas, int tamanho){
    for (size_t i = 0; i < tamanho; i++){
        if(strcmp(pessoas[i].faixa, "Sobrepeso") == 0){
            printf("%s",pessoas[i].nome);
            printf("\n");
        }
    }
}

void imprimeCodigoDePessoasComObesidade(Pessoa *pessoas, int tamanho){
    for (size_t i = 0; i < tamanho; i++){
        if(strcmp(pessoas[i].faixa, "Obesidade") == 0){
            printf("%i",pessoas[i].codigo);
            printf("\n");
        }
    }
}

void imprimeValorMedioDosPesosDasPessoas(Pessoa *pessoas, int tamanho){
    printf("%.2f", valorMedioDosPesos(pessoas, tamanho));
}

void imprimeQuantidadeDePessoasComPesoAcimaDoValorMedio(Pessoa *pessoas, int tamanho){
    int contador = 0; 
    float pesoMedioCalculado = valorMedioDosPesos(pessoas, tamanho);
    for (size_t i = 0; i < tamanho; i++){
        if(pessoas[i].peso > pesoMedioCalculado){
            contador++;
        }
    }
    printf("%i",contador);
}

void imprimeQuantidadeDePessoasComPesoNormal(Pessoa *pessoas, int tamanho){
    int contador = 0;
    for (size_t i = 0; i < tamanho; i++){
        if(strcmp(pessoas[i].faixa, "Normal") == 0){
            contador++;
        }
    }
    printf("%i", contador);
}

void imprimeNomeDePessoasComPesoNormalEComPesoAbaixoDaMedia(Pessoa *pessoas, int tamanho){
    float pesoMedioCalculado = valorMedioDosPesos(pessoas, tamanho);
    for (size_t i = 0; i < tamanho; i++){
        if((strcmp(pessoas[i].faixa, "Normal") == 0) && (pessoas[i].peso < pesoMedioCalculado)){
            printf("%s",pessoas[i].nome);
            printf("\n");
        }
    }
}

void imprimeNomeDePessoasComMaiorIMC(Pessoa *pessoas, int tamanho){
    float maiorIMC = encontraMaiorIMC(pessoas,tamanho);
    for (size_t i = 0; i < tamanho; i++){
        if (pessoas[i].IMC >= maiorIMC){
            printf("%s",pessoas[i].nome);
            printf("\n");  
        }
    }
}

void imprimeNomeDePessoasComMenorIMC(Pessoa *pessoas, int tamanho){
    float menorIMC = encontraMenorIMC(pessoas,tamanho);
    for (size_t i = 0; i < tamanho; i++){
        if (pessoas[i].IMC <= menorIMC){
            printf("%s",pessoas[i].nome);
            printf("\n");  
        }
    }
}

float valorMedioDosPesos(Pessoa *pessoas, int tamanho){
    float somatorio = 0;
    for (size_t i = 0; i < tamanho; i++){
        somatorio = somatorio + pessoas[i].peso;
    }
    return somatorio / tamanho;
}

float encontraMaiorIMC(Pessoa *pessoas, int tamanho){
    float valorIMCAtual = 0;
    for (size_t i = 0; i < tamanho; i++){
        if(pessoas[i].IMC > valorIMCAtual){
            valorIMCAtual = pessoas[i].IMC;
        }
    }
    return valorIMCAtual;
}

float encontraMenorIMC(Pessoa *pessoas, int tamanho){
    float valorIMCAtual = encontraMaiorIMC(pessoas ,tamanho);
    for (size_t i = 0; i < tamanho; i++){
        if(pessoas[i].IMC < valorIMCAtual){
            valorIMCAtual = pessoas[i].IMC;
        }
    }
    return valorIMCAtual;
}