#include "agencia.h"

struct agencia {
    int codAgencia;
    char nome[81];
    char endereco[255];
    char nomeGerente[81];
    Agencia *proxima;
    Agencia *anterior;
};

struct agencias{
    int tamanho;
    Agencia* inicioDaLista;
    Agencia* finalDaLista;
};

Agencias* criaListaDeAgencias(){
	Agencias* novaLista = (Agencias*) malloc( sizeof(Agencias));
    novaLista->tamanho = 0;
    novaLista->inicioDaLista = NULL;
    novaLista->finalDaLista = NULL; 
	return novaLista;
}

Agencia* criaAgencia(int codAgencia,char nome[81], char endereco[255], char nomeGerente[81]) {
    Agencia* agencia = (Agencia*) malloc(sizeof(Agencia));
    agencia->codAgencia = codAgencia;
    strcpy(agencia->nome, nome);
    strcpy(agencia->endereco, endereco);
    strcpy(agencia->nomeGerente, nomeGerente);
    agencia->proxima = NULL;
    agencia->anterior = NULL;
    return agencia;
}

int getCodigoDaAgencia(Agencia *agencia){
    return agencia->codAgencia;
}

Agencia* getInicioDaListaDeAgencias(Agencias *agencias){
    return agencias->inicioDaLista;
}

Agencia* getProximaAgencia(Agencia *agencia){
    return agencia->proxima;
}

int insereNaListaDeAgenciasVazia (Agencias* agencias, Agencia *agencia){
    agencia->proxima = agencias->finalDaLista;
    agencia->anterior = agencias->inicioDaLista;
    agencias->inicioDaLista = agencia;   
    agencias->finalDaLista = agencia;   
    agencias->tamanho++;   
    return 0;   
}

int insereNoInicioDaListaDeAgencias(Agencias *agencias, Agencia *agencia){
    agencia->proxima = agencias->finalDaLista;
    agencia->anterior = NULL;
    agencias->inicioDaLista->anterior = agencia;
    agencias->inicioDaLista = agencia;
    agencias->tamanho++;
    return 0;
}

int insereNoFinalDaListaDeAgencias(Agencias *agencias, Agencia *agencia){
    agencia->proxima = NULL;
    agencia->anterior = agencias->finalDaLista;
    agencias->finalDaLista->proxima = agencia;   
    agencias->finalDaLista = agencia;   
    agencias->tamanho++;
    return 0;
}

int listaDeAgenciasVazia (Agencias *agencias){
    if (agencias == NULL) return 0;
    if (agencias->tamanho == 0) return 1;
    return 0;
}

int tamanhoListaDeAgencias(Agencias *agencias){
    if (listaDeAgenciasVazia(agencias) == 1) return 0;
    int contador = 0;
    Agencia* atual = agencias->inicioDaLista;
    while (atual != NULL){
        contador++;
        atual = atual->proxima;
    }
    return contador;
}

int removeAgenciaDaListaDeAgencias(Agencias *agencias, int pos){   
    Agencia *elemento;   
    if(listaDeAgenciasVazia(agencias)) return -1;

    if(pos == 1){  
        elemento = agencias->inicioDaLista;   
        agencias->inicioDaLista = agencias->inicioDaLista->proxima;   
        if(agencias->inicioDaLista == NULL){
            agencias->finalDaLista = NULL;   
        }else{
            agencias->inicioDaLista->anterior= NULL;   
        }   
    }else if(pos == agencias->tamanho){ 
        elemento = agencias->finalDaLista;
        agencias->finalDaLista->anterior->proxima = NULL;
        agencias->finalDaLista = agencias->finalDaLista->anterior;
    }else {
        Agencia* atual = agencias->inicioDaLista;   
        for(int i = 1; i < pos; i++){
            atual = atual->proxima;
        };
        elemento = atual;   
        atual->anterior->proxima = atual->proxima;   
        atual->proxima->anterior = atual->anterior;   
    }   
    free(elemento->nome);   
    free(elemento->endereco);   
    free(elemento->nomeGerente);   
    free(elemento);   
    agencias->tamanho--;   
    return 0;   
}  

int destruirListaDeAgencias(Agencias *agencias){   
    while(agencias->tamanho > 0){
        removeAgenciaDaListaDeAgencias(agencias, 1);
    }
    free(agencias);
    return 1;
}

int buscarPosicaoAgenciaPorCodigo(Agencias *agencias, int codAgencia){
	if (listaDeAgenciasVazia(agencias)){
        return 0;
    }
    int contador = 0;
    Agencia *atual = agencias->inicioDaLista;
	while(atual != NULL){
        contador++;
        if (atual->codAgencia == codAgencia){
            return contador;
        }
		atual = atual->proxima;
	}
}

Agencia* buscaAgenciaPorCodigo(Agencias *agencias, int codAgencia){
    if (listaDeAgenciasVazia(agencias)){
        return NULL;
    }
    Agencia *atual = agencias->inicioDaLista;
	while(atual != NULL){
        if (atual->codAgencia == codAgencia){
            return atual;
        }
		atual = atual->proxima;
	}
}

void imprimeCodigoAgencia(Agencia* agencia){
    printf("Codigo da agencia: %d\n", agencia->codAgencia);
}

void imprimeNomeAgencia(Agencia* agencia){
    printf("Nome da agencia: %s\n", agencia->nome);
}

void imprimeEnderecoAgencia(Agencia* agencia){
    printf("Endereco da agencia: %s\n", agencia->endereco);
}

void imprimeNomeGerenteAgencia(Agencia* agencia){
    printf("Nome do gerente: %s\n", agencia->nomeGerente);
}

void imprimeOTamanhoDaListaDeAgencias(Agencias* agencias){
    printf("O tamanho da lista de agenicas e: %s\n", agencias->tamanho);
}

void imprimeAgencia(Agencia* agencia){
    imprimeCodigoAgencia(agencia);
    imprimeNomeAgencia(agencia);
    imprimeEnderecoAgencia(agencia);
    imprimeNomeGerenteAgencia(agencia);
}

void imprimeListaDeAgencias(Agencias *agencias) {
	if (listaDeAgenciasVazia(agencias)){
        printf("\n\nVerificamos ao Listar as agencias que a lista de agencias esta vazia\n\n");
        return;
    }
    Agencia *atual;
    atual = agencias->inicioDaLista;
	while(atual != NULL){
        printf("\n\n");
		imprimeAgencia(atual);
		atual = atual->proxima;
	}
}
