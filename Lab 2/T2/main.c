#include <stdio.h>
#include <stdlib.h>

//Funções de alocações
char** alocaMatriz(int numeroDeLinhas, int numeroDeColunas);
void liberaMatriz(char** matriz, int numeroDeColunas);
void populaMatriz(char** matriz, int numeroDeLinhas, int numeroDeColunas);
void imprimeMatriz(char** matriz, int numeroDeLinhas, int numeroDeColunas);
// Funções auxiliares
void app();
char geraLetraAleatoria();
int getNumeroDeLinhas();
int getNumeroDeColunas();
int solicitaNumero(char string[81]);
char *palavraBuscada(char textoBusca[81]);
int busca(char** matriz, int numeroDeLinhas, int numeroDeColunas, char* palavra);
void menuDeBusca(char** matriz, int numeroDeLinhas, int numeroDeColunas);
// Funções de verificação
int verificaVizinhos(char** matriz, int posicaoLinha, int posicaoColuna, int numeroDeLinhas, int numeroDeColunas, char* palavra);
int verificaIgualdadeDaPalavra(char** matriz, char* palavra, int posicaoLinha, int posicaoColuna, int posicaoAtualLinha, int posicaoAtualColuna, int numeroDeLinhas, int numeroDeColunas);
int verificaHorizontalDireta(char** matriz, char* palavra,int posicaoLinha, int posicaoColuna,  int numeroDeColunas);
int verificaHorizontalReversa(char** matriz, char* palavra,int posicaoLinha, int posicaoColuna);
int verificaVerticalDireta(char** matriz, char* palavra,int posicaoLinha, int posicaoColuna, int numeroDeLinhas);
int verificaVerticalReversa(char** matriz, char* palavra,int posicaoLinha, int posicaoColuna);
int verificaDiagonalDireta(char** matriz, char* palavra,int posicaoLinha, int posicaoColuna, int numeroDeLinhas, int numeroDeColunas);
int verificaDiagonalReversa(char** matriz, char* palavra,int posicaoLinha, int posicaoColuna);
int verificaDiagonalSegundariaDireta(char** matriz, char* palavra,int posicaoLinha, int posicaoColuna, int numeroDeLinhas,int numeroDeColunas);
int verificaDiagonalSegundariaReversa(char** matriz, char* palavra,int posicaoLinha, int posicaoColuna);

void main(){
    app();
}

void app(){
    int linhas = getNumeroDeLinhas();
    int colunas = getNumeroDeColunas();
    char** matriz = alocaMatriz(linhas, colunas);
    populaMatriz(matriz, linhas, colunas);
    imprimeMatriz(matriz, linhas, colunas);
    menuDeBusca(matriz, linhas, colunas);
    liberaMatriz(matriz, colunas);
}

char** alocaMatriz(int numeroDeLinhas, int numeroDeColunas){
    char** matriz = (char**)malloc(sizeof(char*) * numeroDeLinhas);
    if(matriz == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    for(int i = 0; i < numeroDeLinhas; i++){
        matriz[i] = (char*)malloc(sizeof(char) * numeroDeColunas);
        if(matriz[i] == NULL){
            printf("Memoria insuficiente.\n");
            exit(1);
        }
    }
    return matriz;
}

void liberaMatriz(char** matriz, int numeroDeColunas){
    for(int i = 0; i < numeroDeColunas; i++){
        free(matriz[i]);
    }
    free(matriz);
}

void populaMatriz(char** matriz, int numeroDeLinhas, int numeroDeColunas){
    for(int i = 0; i < numeroDeLinhas; i++){
        for(int j = 0; j < numeroDeColunas; j++){
            matriz[i][j] = geraLetraAleatoria();
        }
    }
}

char geraLetraAleatoria(){
    return 97 + (char)(rand()%26);
}

void imprimeMatriz(char** matriz, int numeroDeLinhas, int numeroDeColunas){
    printf("\n");
    printf("  Digite 0 para sair");
    printf("\n\n");
    for(int i = 0; i < numeroDeLinhas; i++){
        for(int j = 0; j < numeroDeColunas; j++){
        printf(" %2c ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int solicitaNumero(char string[81]){
    int valorDigitado;
    printf("%s: ", string);
    scanf("%d", &valorDigitado);
    return valorDigitado;
}

int getNumeroDeLinhas (){
    return solicitaNumero("digite o numero de linhas que a matriz deve conter");
}

int getNumeroDeColunas (){    
    return solicitaNumero("digite o numero de colunas que a matriz deve conter");
}

char *palavraBuscada(char textoBusca[81]){
    char* palavra = (char*)calloc(81,sizeof(char));
    printf("%s", textoBusca);
    scanf("%s", palavra);
    return palavra;
}

int busca(char** matriz, int numeroDeLinhas, int numeroDeColunas, char* palavra){
    char primeiraLetra = palavra[0];
    for (int i = 0; i < numeroDeLinhas; i++){
        for (int j = 0; j < numeroDeColunas; j++){
            if (primeiraLetra == matriz[i][j]){
                if(verificaVizinhos(matriz, i, j, numeroDeLinhas, numeroDeColunas, palavra)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

void menuDeBusca(char** matriz, int numeroDeLinhas, int numeroDeColunas){
    int continuarProcurando = 1;
    do{
        char* palavra = palavraBuscada("\n\nBusque uma palavra: ");
        int achouAPalavra = busca(matriz, numeroDeLinhas, numeroDeColunas, palavra);
        continuarProcurando = palavra[0] == '0' ? 0 : 1;

        if (!achouAPalavra && continuarProcurando != 0){
            printf("Essa palavra nao se encontra em nossa matriz de letras");
        }
        
    }while(continuarProcurando);
}

int verificaVizinhos(
    char** matriz, 
    int posicaoLinha, 
    int posicaoColuna, 
    int numeroDeLinhas, 
    int numeroDeColunas,
    char* palavra
){
    int posicaoFinalLinhas = numeroDeLinhas - 1;
    int posicaoFinalColunas = numeroDeColunas - 1;
    char segundaLetra = palavra[1];

    if(segundaLetra == '\0'){
        printf("So tem uma letra");
        return 1;
    }
    
    int posicaoAtualLinha = posicaoLinha > 0 ? posicaoLinha - 1 : 0;
    int posicaoMaximaLinha = posicaoLinha == posicaoFinalLinhas ? posicaoLinha : posicaoLinha + 1; 
    for (posicaoAtualLinha; posicaoAtualLinha <= posicaoMaximaLinha; posicaoAtualLinha++){
        int posicaoAtualColuna = posicaoColuna > 0 ? posicaoColuna - 1 : 0;
        int posicaoMaximaColunas = posicaoColuna == posicaoFinalColunas ? posicaoFinalColunas : posicaoColuna + 1; 
        for (posicaoAtualColuna; posicaoAtualColuna <= posicaoMaximaColunas; posicaoAtualColuna++){
            if (posicaoAtualLinha != posicaoLinha || posicaoAtualColuna != posicaoColuna){
                if (segundaLetra == matriz[posicaoAtualLinha][posicaoAtualColuna]){
                   int achou = verificaIgualdadeDaPalavra(matriz, palavra, posicaoLinha, posicaoColuna, posicaoAtualLinha, posicaoAtualColuna, numeroDeLinhas, numeroDeColunas);
                   if(achou){
                       return achou;
                   }
                }
            }
        }
    }
    return 0;
}

int verificaIgualdadeDaPalavra(
    char** matriz, 
    char* palavra, 
    int posicaoLinha, 
    int posicaoColuna, 
    int posicaoAtualLinha, 
    int posicaoAtualColuna, 
    int numeroDeLinhas, 
    int numeroDeColunas
){
    if (posicaoLinha == posicaoAtualLinha && posicaoColuna < posicaoAtualColuna){
        if (verificaHorizontalDireta(matriz, palavra, posicaoLinha, posicaoColuna, numeroDeColunas)){
            return 1;
        }
    }
    if (posicaoLinha == posicaoAtualLinha && posicaoColuna > posicaoAtualColuna){
       if (verificaHorizontalReversa(matriz, palavra, posicaoLinha, posicaoColuna)){
            return 1;
        }
    } 
    if (posicaoColuna == posicaoAtualColuna && posicaoLinha < posicaoAtualLinha){
        if (verificaVerticalDireta(matriz, palavra, posicaoLinha, posicaoColuna, numeroDeLinhas)){
            return 1;
        }
    } 
    if (posicaoColuna == posicaoAtualColuna && posicaoLinha > posicaoAtualLinha){
        if (verificaVerticalReversa(matriz, palavra, posicaoLinha, posicaoColuna)){
            return 1;
        }
    } 
    if (posicaoLinha < posicaoAtualLinha && posicaoColuna < posicaoAtualColuna){
        if (verificaDiagonalDireta(matriz, palavra, posicaoLinha, posicaoColuna, numeroDeLinhas, numeroDeColunas)){
            return 1;
        }
    } 
    if (posicaoLinha > posicaoAtualLinha && posicaoColuna > posicaoAtualColuna){
        if (verificaDiagonalReversa(matriz, palavra, posicaoLinha, posicaoColuna)){
            return 1;
        }
    } 
    if (posicaoLinha < posicaoAtualLinha && posicaoColuna > posicaoAtualColuna){
        if (verificaDiagonalSegundariaDireta(matriz, palavra, posicaoLinha, posicaoColuna, numeroDeLinhas, numeroDeColunas)){
            return 1;
        }
    } 
    if (posicaoLinha > posicaoAtualLinha && posicaoColuna < posicaoAtualColuna){
        if (verificaDiagonalSegundariaReversa(matriz, palavra, posicaoLinha, posicaoColuna)){
            return 1;
        }
    } 
    

    return 0;
}

int verificaHorizontalDireta(
    char** matriz, 
    char* palavra,
    int posicaoLinha,
    int posicaoColuna, 
    int numeroDeColunas
){
    int i = 0, j = posicaoColuna;
    for (i, j; palavra[i] != '\0' ; i++, j++){
        if (j >= numeroDeColunas || palavra[i] != matriz[posicaoLinha][j]){
            return 0;
        }
    }
    printf("Palavra %s ocorre na horizontal direta, iniciando na posicao [%i,%i] e terminando na posicao [%i,%i]", palavra, posicaoLinha, posicaoColuna, posicaoLinha, j - 1);
    return 1;
}

int verificaHorizontalReversa(char** matriz, char* palavra,int posicaoLinha, int posicaoColuna){
    int i = 0, j = posicaoColuna;
    for (i, j; palavra[i] != '\0'; i++, j--){
        if (j < 0 || palavra[i] != matriz[posicaoLinha][j]){
            return 0;
        }
    }
    printf("Palavra %s ocorre na horizontal reversa, iniciando na posicao [%i,%i] e terminando na posicao [%i,%i]", palavra, posicaoLinha, posicaoColuna, posicaoLinha, j + 1);
    return 1;
}

int verificaVerticalDireta(
    char** matriz, 
    char* palavra,
    int posicaoLinha, 
    int posicaoColuna, 
    int numeroDeLinhas
){
    int i = 0, j = posicaoLinha;
    for (i, j; palavra[i] != '\0' ; i++, j++){
        if (j >= numeroDeLinhas || palavra[i] != matriz[j][posicaoColuna]){
            return 0;
        }
    }
    printf("Palavra %s ocorre na vertical direta, iniciando na posicao [%i,%i] e terminando na posicao [%i,%i]", palavra, posicaoLinha, posicaoColuna, j - 1, posicaoLinha);
    return 1;
}

int verificaVerticalReversa(char** matriz, char* palavra,int posicaoLinha, int posicaoColuna){
    int i = 0, j = posicaoLinha;
    for (i, j; palavra[i] != '\0'; i++, j--){
        if (j < 0 || palavra[i] != matriz[j][posicaoColuna]){
            return 0;
        }
    }
    printf("Palavra %s ocorre na vertical reversa, iniciando na posicao [%i,%i] e terminando na posicao [%i,%i]", palavra, posicaoLinha, posicaoColuna, j + 1, posicaoColuna);
    return 1;
}

int verificaDiagonalDireta(
    char** matriz, 
    char* palavra,
    int posicaoLinha, 
    int posicaoColuna, 
    int numeroDeLinhas, 
    int numeroDeColunas
){
    int i = 0, j = posicaoLinha, k = posicaoColuna;
    for (i, j; palavra[i] != '\0' ; i++, j++, k++){
        if (j >= numeroDeLinhas || k >= numeroDeColunas || palavra[i] != matriz[j][k]){
            return 0;
        }
    }
    printf("Palavra %s ocorre na diagonal direta, iniciando na posicao [%i,%i] e terminando na posicao [%i,%i]", palavra, posicaoLinha, posicaoColuna, j - 1, k - 1);
    return 1;
}

int verificaDiagonalReversa(char** matriz, char* palavra,int posicaoLinha, int posicaoColuna){
    int i = 0, j = posicaoLinha, k = posicaoColuna;
    for (i, j; palavra[i] != '\0' ;i++, j--, k--){
        if (j < 0 || k < 0 || palavra[i] != matriz[j][k]){
            return 0;
        }
    }
    printf("Palavra %s ocorre na diagonal reversa, iniciando na posicao [%i,%i] e terminando na posicao [%i,%i]", palavra, posicaoLinha, posicaoColuna, j + 1, k + 1);
    return 1;
}

int verificaDiagonalSegundariaDireta(
    char** matriz, 
    char* palavra,
    int posicaoLinha, 
    int posicaoColuna, 
    int numeroDeLinhas,
    int numeroDeColunas
){
    int i = 0, j = posicaoLinha, k = posicaoColuna;
    for (i, j; palavra[i] != '\0' ;i++, j++, k--){
        if (j > numeroDeLinhas || k > numeroDeColunas || palavra[i] != matriz[j][k]){
            return 0;
        }
    }
    printf("Palavra %s ocorre na diagonal segundaria direta, iniciando na posicao [%i,%i] e terminando na posicao [%i,%i]", palavra, posicaoLinha, posicaoColuna, j - 1, k + 1);
    return 1;
}

int verificaDiagonalSegundariaReversa(char** matriz, char* palavra,int posicaoLinha, int posicaoColuna){
    int i = 0, j = posicaoLinha, k = posicaoColuna;
    for (i, j; palavra[i] != '\0' ;i++, j--, k++){
        if (j < 0 || k < 0 || palavra[i] != matriz[j][k]){
            return 0;
        }
    }
    printf("Palavra %s ocorre na diagonal segundaria reversa, iniciando na posicao [%i,%i] e terminando na posicao [%i,%i]", palavra, posicaoLinha, posicaoColuna, j + 1, k - 1);
    return 1;
}