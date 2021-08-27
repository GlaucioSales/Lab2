#include "conta.h"

struct conta {
    int numeroDaConta;
    char dataDeCriacaoDaConta[11];
    double saldo;
    double limitePermitido;
    Agencia *agencia;
    Cliente *cliente;
    Conta *proxima;
    Conta *anterior;
};

struct contas{
    int tamanho;
    Conta* inicioDaLista;
    Conta* finalDaLista;
};

Contas* criaListaDeContas(){
	Contas* novaLista = (Contas*) malloc( sizeof(Contas));
    novaLista->tamanho = 0;
    novaLista->inicioDaLista = NULL;
    novaLista->finalDaLista = NULL; 
	return novaLista;
}

Conta* criaConta(int numeroDaConta, char dataDeCriacaoDaConta[11], double saldo, double limitePermitido, Agencia * agencia, Cliente * cliente) {
    Conta* conta = (Conta*) malloc(sizeof(Conta));
    conta->numeroDaConta = numeroDaConta;
    strcpy(conta->dataDeCriacaoDaConta, dataDeCriacaoDaConta);
    conta->saldo = saldo;
    conta->limitePermitido = limitePermitido;
    conta->agencia = agencia;
    conta->cliente = cliente;
    conta->proxima = NULL;
    conta->anterior = NULL;
    return conta;
}

Cliente* getCliente(Conta *conta){
    return conta->cliente;
}

int getNumeroDaConta(Conta *conta){
    return conta->numeroDaConta;
}

int agenciaPossuiConta(Contas *contas, Agencia *agencia){
    if (listaDeContasVazia(contas)){
        return 0;
    }
    
    Conta *atual;
    atual = contas->inicioDaLista;
	while(atual != NULL){
        if (getCodigoDaAgencia(atual->agencia) == getCodigoDaAgencia(agencia)){
            return 1;
        }
        atual = atual->proxima;
	}
    return 0;
}

int verificaSeExisteEmUmaContaComUmaDeterminadaAgencia(Contas *contas, Agencia *agencia){
    if (listaDeContasVazia(contas)){
        return 0;
    }
    Conta *atual;
    atual = contas->inicioDaLista;
	while(atual != NULL){
        if (getCodigoDaAgencia(atual->agencia) == getCodigoDaAgencia(agencia)){
            return 1;   
        }
        atual = atual->proxima;
	}
}

int insereNaListaDeContasVazia (Contas *contas, Conta *conta){
    conta->proxima = contas->finalDaLista;
    conta->anterior = contas->inicioDaLista;
    contas->inicioDaLista = conta;   
    contas->finalDaLista = conta;   
    contas->tamanho++;   
    return 0;   
}

int insereNoInicioDaListaDeContas(Contas *contas, Conta *conta){
    conta->proxima = contas->finalDaLista;
    conta->anterior = NULL;
    contas->inicioDaLista->anterior = conta;
    contas->inicioDaLista = conta;
    contas->tamanho++;
    return 0;
}

int insereNoFinalDaListaDeContas(Contas *contas, Conta *conta){
    conta->proxima = NULL;
    conta->anterior = contas->finalDaLista;
    contas->finalDaLista->proxima = conta;   
    contas->finalDaLista = conta;   
    contas->tamanho++;
    return 0;
}

int listaDeContasVazia (Contas *contas){
    if (contas == NULL) return 1;
    return contas->tamanho == 0;
}

int tamanhoListaDeContas(Contas *contas){
    if (listaDeContasVazia(contas)) return 0;
    int contador = 0;
    Conta* atual = contas->inicioDaLista;
    while (atual != NULL){
        contador++;
        atual = atual->proxima;
    }
    return contador;
}

int removeContaDaListaDeContas(Contas *contas, int pos){   
    Conta *elemento;   
    if(listaDeContasVazia(contas)) return -1;
    if(pos == 1){  
        elemento = contas->inicioDaLista;   
        contas->inicioDaLista = contas->inicioDaLista->proxima;   
        if(contas->inicioDaLista == NULL){
            contas->finalDaLista = NULL;   
        }else{
            contas->inicioDaLista->anterior= NULL;   
        }   
    }else if(pos == contas->tamanho){ 
        elemento = contas->finalDaLista;
        contas->finalDaLista->anterior->proxima = NULL;
        contas->finalDaLista = contas->finalDaLista->anterior;
    }else {
        Conta* atual = contas->inicioDaLista;   
        for(int i = 1; i < pos; i++){
            atual = atual->proxima;
        };
        elemento = atual;   
        atual->anterior->proxima = atual->proxima;   
        atual->proxima->anterior = atual->anterior;   
    }   
    free(elemento->dataDeCriacaoDaConta); 
    free(elemento);
    contas->tamanho--;   
    return 0;   
}  

int destruirListaDeContas(Contas *contas){   
  while(contas->tamanho > 0){
      removeContaDaListaDeContas(contas, 1);
  }
  free(contas);
  return 1;
}

int buscarPosicaoPorNumeroConta(Contas *contas, int numeroDaConta){
	if (listaDeContasVazia(contas)){
        return 0;
    }
    int contador = 0;
    Conta *atual = contas->inicioDaLista;
	while(atual != NULL){
        contador++;
        if (atual->numeroDaConta == numeroDaConta){
            return contador;
        }
		atual = atual->proxima;
	}
}

void removerContasDeUmaDeterminadaAgencia(Contas *contas, Agencia *agencia){
	if (listaDeContasVazia(contas)){
        return ;
    }
    int contador = 0;
    Conta *atual = contas->inicioDaLista;
	while(atual != NULL){
        contador++;
        if (getCodigoDaAgencia(atual->agencia) == getCodigoDaAgencia(agencia)){
            removeContaDaListaDeContas(contas, contador);
        }
		atual = atual->proxima;
	}
}

void removerContasDeUmDeterminadoCliente(Contas *contas, Cliente *cliente){
	if (listaDeContasVazia(contas)){
        return ;
    }
    int contador = 0;
    Conta *atual = contas->inicioDaLista;
	while(atual != NULL){
        contador++;
        if (verificaSeClienteCorreto(atual->cliente, cliente) == 1){
            removeContaDaListaDeContas(contas, contador);
        }
		atual = atual->proxima;
	}
}

Conta* obterContaPeloNumeroDaConta(Contas *contas, int numeroDaConta){
    if (listaDeContasVazia(contas)){
        return 0;
    }
    Conta *atual = contas->inicioDaLista;
	while(atual != NULL){
        if (atual->numeroDaConta == numeroDaConta){
            return atual;
        }
		atual = atual->proxima;
	}
}

void debitarValorDaConta(Conta *conta, int valor){
    conta->saldo = conta->saldo - valor; 
}

void transferirValorEntreContas(Conta *contaPrincipal, Conta *contaSecundaria, double valor){
    contaPrincipal->saldo = contaPrincipal->saldo - valor;
    contaSecundaria->saldo = contaSecundaria->saldo + valor;
}

void imprimeNumeroDaConta(Conta* conta){
    printf("Numero da conta: %d\n", conta->numeroDaConta);
}

void imprimeDataDeCriacaoDaConta(Conta* conta){
    printf("Data de criacao da canta: %s\n", conta->dataDeCriacaoDaConta);
}

void imprimeSaldoConta(Conta* conta){
    printf("Saldo disponivel em conta: %lf\n", conta->saldo);
}

void imprimeLimitePermitidoDaConta(Conta* conta){
    printf("Limite permitido em conta: %lf\n", conta->limitePermitido);
}

void imprimeConta(Conta* conta){
    imprimeNumeroDaConta(conta);
    imprimeDataDeCriacaoDaConta(conta);
    imprimeSaldoConta(conta);
    imprimeLimitePermitidoDaConta(conta);
    imprimeNomeAgencia(conta->agencia);
    imprimeNomeCliente(conta->cliente);
}

void imprimeListaDeContas(Contas *contas) {
	if (listaDeContasVazia(contas)){
        printf("\n\nVerificamos ao Listar as contas que a lista de contas esta vazia\n\n");
        return;
    }
    Conta *atual;
    atual = contas->inicioDaLista;
	while(atual != NULL){
        printf("\n\n");
		imprimeConta(atual);
		atual = atual->proxima;
	}
}

void imprimeListaDeNomesDosClientesENomesDasAgenciasDeUmaConta(Contas *contas){
    if (listaDeContasVazia(contas)){
        printf("\n\nVerificamos ao Listar as contas que a lista de contas esta vazia\n\n");
        return;
    }
    Conta *atual;
    atual = contas->inicioDaLista;
	while(atual != NULL){
        imprimeNomeCliente(atual->cliente);
        imprimeNomeAgencia(atual->agencia);
        imprimeNumeroDaConta(atual);
        atual = atual->proxima;
	}

}

void imprimeListaDeContasComSaldoPositivo(Contas *contas){
    if (listaDeContasVazia(contas)){
        printf("\n\nVerificamos ao Listar as contas que a lista de contas esta vazia\n\n");
        return;
    }
    Conta *atual;
    atual = contas->inicioDaLista;
	while(atual != NULL){
        if (atual->saldo > 0){   
            imprimeNomeCliente(atual->cliente);
            imprimeNomeAgencia(atual->agencia);
            imprimeNumeroDaConta(atual);
            imprimeSaldoConta(atual);
        }
        
        atual = atual->proxima;
	}

}

void imprimeContasDoCliente(Contas *contas, Cliente *cliente){
    if (listaDeContasVazia(contas)){
        printf("\n\nVerificamos ao Listar as contas que a lista de contas esta vazia\n\n");
        return;
    }
    Conta *atual;
    atual = contas->inicioDaLista;
	while(atual != NULL){
        if (verificaSeClienteCorreto(atual->cliente, cliente) == 1){   
            imprimeNomeCliente(atual->cliente);
            imprimeConta(atual);
        }
        atual = atual->proxima;
	}

}
