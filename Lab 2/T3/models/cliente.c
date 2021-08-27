#include "cliente.h"

struct cliente {
    char nome[81];
    char cpf[16];
    char telefone[16];
    Cliente *proximo;
    Cliente *anterior;
};


struct clientes{
    int tamanho;
    Cliente* inicioDaLista;
    Cliente* finalDaLista;
};

Clientes* criaListaDeClientes(){
	Clientes* novaLista = (Clientes*) malloc( sizeof(Clientes));
    novaLista->tamanho = 0;
    novaLista->inicioDaLista = NULL;
    novaLista->finalDaLista = NULL; 
	return novaLista;
}

Cliente* criaCliente(char nome[81], char cpf[16], char telefone[16]) {
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
    strcpy(cliente->nome, nome);
    strcpy(cliente->cpf, cpf);
    strcpy(cliente->telefone, telefone);
    cliente->proximo = NULL;
    cliente->anterior = NULL;
    return cliente;
}

int verificaSeClienteCorreto(Cliente *clienteX, Cliente *clienteY){
    if (clienteX == clienteY){
        return 1;
    }
    return 0;
}

int insereNaListaDeClientesVazia (Clientes* clientes, Cliente *cliente){
    cliente->proximo = clientes->finalDaLista;
    cliente->anterior = clientes->inicioDaLista;
    clientes->inicioDaLista = cliente;   
    clientes->finalDaLista = cliente;   
    clientes->tamanho++;   
    return 0;   
}

int insereNoInicioDaListaDeClientes(Clientes *clientes, Cliente *cliente){
    cliente->proximo = clientes->finalDaLista;
    cliente->anterior = NULL;
    clientes->inicioDaLista->anterior = cliente;
    clientes->inicioDaLista = cliente;
    clientes->tamanho++;
    return 0;
}

int insereNoFinalDaListaDeClientes(Clientes *clientes, Cliente *cliente){
    cliente->proximo = NULL;
    cliente->anterior = clientes->finalDaLista;
    clientes->finalDaLista->proximo = cliente;   
    clientes->finalDaLista = cliente;   
    clientes->tamanho++;
    return 0;
}

int listaDeClientesVazia (Clientes *clientes){
    if (clientes == NULL) return 1;
    return clientes->tamanho == 0;
}

int tamanhoListaDeClientes(Clientes *clientes){
    if (listaDeClientesVazia(clientes)) return 0;
    int contador = 0;
    Cliente* atual = clientes->inicioDaLista;
    while (atual != NULL){
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

int removeClienteDaListaDeClientes(Clientes *clientes, int pos){   
    Cliente *elemento;
    if(listaDeClientesVazia(clientes)) return -1;

    if(pos == 1){
        elemento = clientes->inicioDaLista;
        clientes->inicioDaLista = clientes->inicioDaLista->proximo; 
        if(clientes->inicioDaLista == NULL){
            clientes->finalDaLista = NULL;
        }else{
            clientes->inicioDaLista->anterior= NULL;
        }   
    }else if(pos == clientes->tamanho){
        elemento = clientes->finalDaLista;
        clientes->finalDaLista->anterior->proximo = NULL;
        clientes->finalDaLista = clientes->finalDaLista->anterior;
    }else {
        Cliente* atual = clientes->inicioDaLista;
        for(int i = 1; i < pos; i++){
            atual = atual->proximo;
        };
        elemento = atual;
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
    }
    free(elemento->nome);
    free(elemento->cpf);
    free(elemento->nome);
    free(elemento);
    clientes->tamanho--;
    return 0;
}

int destruirListaDeClientes(Clientes *clientes){   
    while(clientes->tamanho > 0){
        removeClienteDaListaDeClientes(clientes, 1);
    }
    free(clientes);
    return 1;
}

int buscarPosicaoClientePorCPF(Clientes *clientes, char cpf[16]){
    if (listaDeClientesVazia(clientes)){
        return 0;
    }
    int contador = 0;
    Cliente *atual = clientes->inicioDaLista;
	while(atual != NULL){
        contador++;
        if (strcmp(atual->cpf, cpf) == 0){
            return contador;
        }
		atual = atual->proximo;
	}
}

Cliente* buscaClientePorCPF(Clientes *clientes, char cpf[16]){
    if (listaDeClientesVazia(clientes)){
        return NULL;
    }
    Cliente *atual = clientes->inicioDaLista;
	while(atual != NULL){
        if (strcmp(atual->cpf, cpf) == 0){
            return atual;
        }
		atual = atual->proximo;
	}
}

void imprimeNomeCliente(Cliente* cliente){
    printf("Nome do cliente: %s\n", cliente->nome);
}

void imprimeCPFCliente(Cliente* cliente){
    printf("CPF do cliente: %s\n", cliente->cpf);
}

void imprimeTelefoneCliente(Cliente* cliente){
    printf("Telefone do cliente: %s\n", cliente->telefone );
}

void imprimeCliente(Cliente* cliente){
    imprimeNomeCliente(cliente);
    imprimeCPFCliente(cliente);
    imprimeTelefoneCliente(cliente);
}

void imprimeListaDeClientes(Clientes *clientes){
	if (listaDeClientesVazia(clientes)){
        printf("\n\nVerificamos ao Listar os clientes que a lista de clientes esta vazia\n\n");
        return;
    }
    Cliente *atual;
    atual = clientes->inicioDaLista;
	while(atual != NULL){
        printf("\n\n");
		imprimeCliente(atual);
		atual = atual->proximo;
	}
}