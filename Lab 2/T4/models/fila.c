#include "fila.h"

struct grupo{
    int chaveDoGrupo;
    int quantidadeDePessoas;
};

struct fila{
    Elemento *elementoInicioDaFila;
    Elemento *elementoFinalDaFila;
    int tamanhoDaFila;
};

struct elemento{
    Grupo *grupo;
    Elemento *proxElemento;
    Elemento *elementoAnt;
};

Fila* criaFila(){
    Fila *fila = (Fila*)malloc( sizeof(Fila));
    if (fila == NULL){
        printf("Nao foi possivel iniciar a fila de espera");
        return NULL;
    }
    fila->elementoInicioDaFila = NULL;
    fila->elementoFinalDaFila = NULL;
    fila->tamanhoDaFila = 0;
    return fila;
}

Grupo* criaGrupo(int numeroDePessoasNoGrupo){
    Grupo *grupo = (Grupo*)malloc(sizeof(Grupo));
    grupo->chaveDoGrupo = solicitaInteiro("Qual a chave do grupo que vai aguardar: ");
    grupo->quantidadeDePessoas = numeroDePessoasNoGrupo;
}

void liberarFila(Fila *fila){
    if (fila == NULL) return;
    
    Elemento *elemento;
    while (fila->elementoInicioDaFila != NULL){
        elemento = fila->elementoInicioDaFila;
        fila->elementoInicioDaFila = fila->elementoInicioDaFila->proxElemento;
        free(elemento);    
    }
    free(fila);
}

int tamanhoDaFila(Fila *fila) {
    if (fila == NULL) return 0;
    
    int contador = 1;
    Elemento *atual = fila->elementoInicioDaFila;
    while (atual != NULL){
        atual = atual->proxElemento;
        contador++;
    }
    return contador;
}


bool filaVazia(Fila *fila){
    if (fila == NULL) return true;

    if (fila->elementoInicioDaFila == NULL) return true;

    return false;    
}

Grupo* proximoGrupoDaFila(Fila *fila){
    return fila->elementoInicioDaFila->grupo;

}

int quantidadeDePessoasNoGrupo(Grupo *grupo){
    return grupo->quantidadeDePessoas;
}

void subtrairDoGrupoAsPessoaQueVaoParaAMesa(Grupo *grupo, int numeroDePessoas){
    grupo->quantidadeDePessoas = grupo->quantidadeDePessoas - numeroDePessoas;
}

bool inserirGrupoNaFila(Fila *fila, Grupo *grupo) {
    if (fila == NULL) return false;
    
    Elemento *elemento = (Elemento*) malloc(sizeof(Elemento));
    if (elemento == NULL) return false;

    elemento->grupo = grupo;
    elemento->proxElemento = NULL;
    elemento->elementoAnt = fila->elementoFinalDaFila;

    if (filaVazia(fila)) {
        fila->elementoInicioDaFila = elemento;
    } else {
        fila->elementoFinalDaFila->proxElemento = elemento;
    }

    fila->elementoFinalDaFila = elemento;
    fila->tamanhoDaFila++;
    return true;
}

bool retirarGrupoDaFila(Fila *fila){
    if (fila == NULL || fila->elementoInicioDaFila == NULL) return false;
    Elemento *elemento = fila->elementoInicioDaFila;

    fila->elementoInicioDaFila = fila->elementoInicioDaFila->proxElemento;
    fila->elementoInicioDaFila->elementoAnt = NULL;
    if (fila->elementoInicioDaFila == NULL) fila->elementoFinalDaFila = NULL;
    free(elemento->grupo);
    free(elemento);
    fila->tamanhoDaFila--;

    return true;
}

bool retirarUmDeterminadoGrupoDaFila(Fila *fila, int chaveDoGrupo){
    if (fila == NULL || fila->elementoInicioDaFila == NULL) return false;
    
    Elemento *atual = fila->elementoInicioDaFila;

    while (atual != NULL){
        if (atual->grupo->chaveDoGrupo == chaveDoGrupo){
            if (atual->elementoAnt == NULL) {
                retirarGrupoDaFila(fila);
                return true;
            }
            if (atual->proxElemento == NULL){
                fila->elementoFinalDaFila = atual->elementoAnt;
                atual->elementoAnt->proxElemento = NULL;
            }
            if (atual->proxElemento != NULL && atual->proxElemento != NULL){
                atual->elementoAnt->proxElemento = atual->proxElemento;
            }

            free(atual->grupo);
            free(atual);
            return true;
        }
        atual = atual->proxElemento;
    }
}

void imprimirFila(Fila *fila){
    if (fila == NULL || fila->elementoInicioDaFila == NULL) return;
    Elemento *atual = fila->elementoInicioDaFila;
    while (atual != NULL){
        imprimirGrupo(atual->grupo);
        atual = atual->proxElemento;
    }
}

void imprimirGrupo(Grupo *grupo){
    printf("\n");
    printf("Chave do Grupo: %d \n", grupo->chaveDoGrupo);
    printf("Numero de pessoas esperando %d \n", grupo->quantidadeDePessoas);
}