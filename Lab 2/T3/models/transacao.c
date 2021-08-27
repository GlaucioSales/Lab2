#include "transacao.h"
struct transacao{
    int codigoTransacao;
    int dia;
    int mes;
    int ano;
    int tipoTranscao;
    Conta *contaPrincipal;
    Conta *contaSecundaria;
    Agencia *agencia;
    Transacao *proxima;
    Transacao *anterior;
};

struct transacoes{
    int tamanho;
    Transacao* inicioDaLista;
    Transacao* finalDaLista;
};

Transacoes* criaListaDeTransacoes(){
	Transacoes* novaLista = (Transacoes*) malloc( sizeof(Transacoes));
    novaLista->tamanho = 0;
    novaLista->inicioDaLista = NULL;
    novaLista->finalDaLista = NULL; 
	return novaLista;
}

Transacao* criaTransacao(int codigoTransacao, int dia, int mes, int ano, int tipoTranscao, Agencia *agencia, Conta *contaPrincipal, Conta *contaSecundaria) {
    Transacao* transacao = (Transacao*) malloc(sizeof(Transacao));
    transacao->codigoTransacao = codigoTransacao;
    transacao->dia = dia;
    transacao->mes = mes;
    transacao->ano = ano;
    transacaoSolicitada(tipoTranscao, contaPrincipal, contaSecundaria);
    transacao->tipoTranscao = tipoTranscao;
    transacao->contaPrincipal = contaPrincipal;
    transacao->contaSecundaria = contaSecundaria;
    transacao->agencia = agencia;
    transacao->proxima = NULL;
    transacao->anterior = NULL;
    return transacao;
}

void transacaoSolicitada(int tiposTransacao, Conta *contaPrincipal, Conta *contaSecundaria){
    switch (tiposTransacao){
        case 0:
            transacaoDeSaldo(contaPrincipal);
            break;
        case 1:
            transacaoDeSaque(contaPrincipal);
            break;
        case 2:
            transacaoDeTransferencia(contaPrincipal, contaSecundaria);
            break;
        case 3:
            transacaoDePagamento(contaPrincipal);
            break;
        default:
            break;
    }
}

void transacaoDeSaldo(Conta *contaPrincipal){
    printf("Seu saldo disponivel em conta e de\n");
    imprimeSaldoConta(contaPrincipal);
}

void transacaoDeSaque(Conta *contaPrincipal){
    double valorDoSaque = solicitaDouble("Qual o valor do saque a ser efetuado: ");
    debitarValorDaConta(contaPrincipal, valorDoSaque);
    quebraLinha();
    imprimeConta(contaPrincipal);
    quebraLinha();
}

void transacaoDeTransferencia(Conta *contaPrincipal, Conta *contaSecundaria){
    double valorTransferencia = solicitaDouble("Qual o valor da transferencia a ser efetuada: ");
    transferirValorEntreContas(contaPrincipal, contaSecundaria, valorTransferencia);
    quebraLinha();
    imprimeConta(contaPrincipal);
    quebraLinha();
    imprimeConta(contaSecundaria);
    quebraLinha();
}

void transacaoDePagamento(Conta *contaPrincipal){
    double valorDoSaque = solicitaDouble("Qual o valor do pagamento a ser efetuado: ");
    debitarValorDaConta(contaPrincipal, valorDoSaque);
    quebraLinha();
    imprimeConta(contaPrincipal);
    quebraLinha();
}

void removerTransacoesDeUmaDeterminadaAgencia(Transacoes *transacoes, Agencia *agencia){
    if (listaDeTransacoesVazia(transacoes)){
        return ;
    }
    int contador = 1;
    Transacao *atual = transacoes->inicioDaLista;
	while(atual != NULL){
        contador++;
        if (getCodigoDaAgencia(atual->agencia) == getCodigoDaAgencia(agencia)){
            removeTransacaoDaListaDeTransacoes(transacoes, contador);
        }
		atual = atual->proxima;
	}
}

void removerTransacoesDeUmDeterminadoCliente(Transacoes *transacoes, Cliente *cliente){
    if (listaDeTransacoesVazia(transacoes)){
        return ;
    }
    int contador = 1;
    Transacao *atual = transacoes->inicioDaLista;
	while(atual != NULL){
        contador++;
        if (verificaSeClienteCorreto( getCliente(atual->contaPrincipal), cliente) == 1){
            removeTransacaoDaListaDeTransacoes(transacoes, contador);
        }
		atual = atual->proxima;
	}
}

void removerTransacoesDeUmaDeterminadaConta(Transacoes *transacoes, Conta *conta){
    if (listaDeTransacoesVazia(transacoes)){
        return ;
    }
    int contador = 1;
    Transacao *atual = transacoes->inicioDaLista;
	while(atual != NULL){
        contador++;
        if (getNumeroDaConta(atual->contaPrincipal) == getNumeroDaConta(conta)){
            removeTransacaoDaListaDeTransacoes(transacoes, contador);
        }
		atual = atual->proxima;
	}

}

int insereNaListaDeTransacoesVazia (Transacoes* transacoes, Transacao *transacao){
    transacao->proxima = transacoes->finalDaLista;
    transacao->anterior = transacoes->inicioDaLista;
    transacoes->inicioDaLista = transacao;   
    transacoes->finalDaLista = transacao;   
    transacoes->tamanho++;   
    return 0;   
}

int insereNoInicioDaListaDeTransacoes(Transacoes *transacoes, Transacao *transacao){
    transacao->proxima = transacoes->finalDaLista;
    transacao->anterior = NULL;
    transacoes->inicioDaLista->anterior = transacao;
    transacoes->inicioDaLista = transacao;
    transacoes->tamanho++;
    return 0;
}

int insereNoFinalDaListaDeTransacoes(Transacoes *transacoes, Transacao *transacao){
    transacao->proxima = NULL;
    transacao->anterior = transacoes->finalDaLista;
    transacoes->finalDaLista->proxima = transacao;   
    transacoes->finalDaLista = transacao;   
    transacoes->tamanho++;
    return 0;
}

int listaDeTransacoesVazia (Transacoes *transacoes){
    if (transacoes == NULL) return 1;
    return transacoes->tamanho == 0;
}

int tamanhoListaDeTransacoes(Transacoes *transacoes){
    if (listaDeTransacoesVazia(transacoes)) return 0;
    int contador = 0;
    Transacao* atual = transacoes->inicioDaLista;
    while (atual != NULL){
        contador++;
        atual = atual->proxima;
    }
    return contador;
}

int removeTransacaoDaListaDeTransacoes(Transacoes *transacoes, int pos){   
    Transacao *elemento;   
    if(listaDeTransacoesVazia(transacoes)) return -1;

    if(pos == 1){  
        elemento = transacoes->inicioDaLista;   
        transacoes->inicioDaLista = transacoes->inicioDaLista->proxima;   
        if(transacoes->inicioDaLista == NULL){
            transacoes->finalDaLista = NULL;   
        }else{
            transacoes->inicioDaLista->anterior= NULL;   
        }   
    }else if(pos == transacoes->tamanho){ 
        elemento = transacoes->finalDaLista;
        transacoes->finalDaLista->anterior->proxima = NULL;
        transacoes->finalDaLista = transacoes->finalDaLista->anterior;
    }else {
        Transacao* atual = transacoes->inicioDaLista;   
        for(int i = 1; i < pos; i++){
            atual = atual->proxima;
        };
        elemento = atual;   
        atual->anterior->proxima = atual->proxima;   
        atual->proxima->anterior = atual->anterior;   
    }   
    free(elemento->contaPrincipal);   
    free(elemento->contaSecundaria);   
    free(elemento->agencia);   
    free(elemento);   
    transacoes->tamanho--;   
    return 0;   
}  

int destruirListaDeTransacoes(Transacoes *transacoes){   
    while(transacoes->tamanho > 0){
        removeTransacaoDaListaDeTransacoes(transacoes, 1);
    }
    free(transacoes);
    return 1;
}

int buscarPosicaoTransacaoPorCodigo(Transacoes *transacoes, int codigoTransacao){
    if (listaDeTransacoesVazia(transacoes)){
        return 0;
    }
    int contador = 0;
    Transacao *atual = transacoes->inicioDaLista;
	while(atual != NULL){
        contador++;
        if (atual->codigoTransacao == codigoTransacao){
            return contador;
        }
		atual = atual->proxima;
	}

}

void imprimeCodigoTransacao(Transacao *transacao){
    printf("Codigo da transacao: %d\n", transacao->codigoTransacao);
}

void imprimeDataDaTransacao(Transacao *transacao){
    printf("Data da transacao: %d/%d/%d\n", transacao->dia, transacao->mes, transacao->ano);
}

void imprimeTipoDeTransacao(Transacao *transacao){
    switch(transacao->tipoTranscao){
        case 0:
            printf("Tipo de transacao: SALDO\n");
            break;
        case 1:
            printf("Tipo de transacao: SAQUE\n");
            break;
        case 2:
            printf("Tipo de transacao: TRANSFERENCIA para a conta:\n");
            imprimeNumeroDaConta(transacao->contaSecundaria);
            break;
        case 3:
            printf("Tipo de transacao: PAGAMENTO\n");
            break;
    }
}

void imprimeTransacao(Transacao *transacao){
    imprimeCodigoTransacao(transacao);
    imprimeNumeroDaConta(transacao->contaPrincipal);
    imprimeDataDaTransacao(transacao);
    imprimeTipoDeTransacao(transacao);
}

void imprimeListaDeTransacoes(Transacoes *transacoes){
	if (listaDeTransacoesVazia(transacoes)){
        printf("\n\nVerificamos ao Listar as transacoes que a lista de transacoes esta vazia\n\n");
        return;
    }
    Transacao *atual;
    atual = transacoes->inicioDaLista;
	while(atual != NULL){
        printf("\n\n");
		imprimeTransacao(atual);
		atual = atual->proxima;
	}
}

void imprimeListaDeTransacoesDeUmDeterminadoMes(Transacoes *transacoes, int mes, int tipoTranscao){
    if (listaDeTransacoesVazia(transacoes)){
        printf("\n\nVerificamos ao Listar as transacoes que a lista de transacoes esta vazia\n\n");
        return;
    }
    Transacao *atual;
    atual = transacoes->inicioDaLista;
	while(atual != NULL){
        if (atual->mes == mes && atual->tipoTranscao == tipoTranscao){
            printf("\n\n");
		    imprimeTransacao(atual);
        }
		atual = atual->proxima;
        
	}
}