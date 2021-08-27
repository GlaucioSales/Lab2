#include "controles.h"

void sair(Agencias *agencias, Clientes *clientes, Contas *contas, Transacoes *transacoes){
    destruirListaDeAgencias(agencias);
    destruirListaDeClientes(clientes);
    destruirListaDeContas(contas);
    destruirListaDeTransacoes(transacoes);
    exit(0);
}

void cadastrarUmaNovaAgencia(Agencias *agencias){
    char nome[81], endereco[255], nomeGerente[81];
    int codAgencia = solicitaInteiro("Informe o codigo da agencia que deve ser cadastrado: ");
    solicitaString("Informe o nome da agencia que deve ser cadastrada: ", nome);
    solicitaString("Informe o endereco da agencia que deve ser cadastrada: ", endereco);
    solicitaString("Informe o nome do Gerente da agencia que deve ser cadastrada: ", nomeGerente);
    Agencia *agencia = criaAgencia(codAgencia, nome, endereco, nomeGerente);
    colocarAgenciaNaListaDeAgencias(agencias, agencia);
}

int colocarAgenciaNaListaDeAgencias(Agencias *agencias, Agencia *agencia){
    quebraLinha();
    imprimeAgencia(agencia);
    quebraLinha();
    int inserir = solicitaInteiro("Voce gostaria de inserir a agencia na lista de agencias: \ndigite 0 para NAO \ndigite 1 para SIM \n->");
    if(inserir == 1){
        if (listaDeAgenciasVazia(agencias)){
            insereNaListaDeAgenciasVazia(agencias, agencia);
            printf("Parabens voce acaba de incluir a sua primeira agencia na sua lista de agencias\n\n");

            return 1;
        }else{
            insereNoFinalDaListaDeAgencias(agencias, agencia);
            printf("Agencia incluida na lista de agencias\n\n");
            return 1;
        }        
    }
    printf("Agencias nao inseridas na lista de agencias sao excluidas \nPara adicionar posteriormente essa agencia sera necessario cadastra-la novamente\n");
    free(agencia);
    return 0;
}

void excluirUmaAgencia(Agencias *agencias, Contas *contas, Transacoes *transacoes){
    int valorDeRetorno = solicitaInteiro("Voce gostaria que listassemos as agencias contidas na lista de agencias: \ndigite 0 para NAO \ndigite 1 para SIM \n->");
    if(valorDeRetorno == 1) {
        listarTodasAsAgencias(agencias);
    }
    if (listaDeAgenciasVazia(agencias)){
        return;
    }
    valorDeRetorno = solicitaInteiro("Para excluir digite o codigo da agencia \n->");
    Agencia *agencia = buscaAgenciaPorCodigo(agencias, valorDeRetorno);
    valorDeRetorno = buscarPosicaoAgenciaPorCodigo(agencias, valorDeRetorno);
    int excluir = solicitaInteiro("Realmente deseja remover essa agencia, todas as contas e transacoes serao removidas como consequencia \ndigite 0 para NAO \ndigite 1 para SIM \n->");
    if(excluir == 1){
        removerContasDeUmaDeterminadaAgencia(contas, agencia);
        removerTransacoesDeUmaDeterminadaAgencia(transacoes, agencia);
        removeAgenciaDaListaDeAgencias(agencias, valorDeRetorno);
    }
}

void cadastrarUmNovoCliente(Clientes *clientes){
    char nome[81], cpf[255], telefone[81];
    solicitaString("\nInforme o nome do cliente: ", nome);
    solicitaString("\nInforme o cpf do cliente: ", cpf);
    solicitaString("\nInforme o telefone do cliente: ", telefone);
    Cliente *cliente = criaCliente(nome, cpf, telefone);
    colocarClienteNaListaDeClientes(clientes, cliente);
}

int colocarClienteNaListaDeClientes(Clientes *clientes, Cliente *cliente){
    quebraLinha();
    imprimeCliente(cliente);
    quebraLinha();
    int inserir = solicitaInteiro("Voce gostaria de inserir o cliente na lista de clientes: \ndigite 0 para NAO \ndigite 1 para SIM \n->");
    if(inserir == 1){
        if (listaDeClientesVazia(clientes)){
            insereNaListaDeClientesVazia(clientes, cliente);
            printf("Parabens voce acaba de incluir o seu primeiro cliente na sua lista de clientes\n\n");
            return 1;
        }else{
            insereNoFinalDaListaDeClientes(clientes, cliente);
            printf("Cliente incluido na lista de clientes\n\n");
            return 1;
        }        
    }
    printf("Clientes nao inclusos na lista de clientes sao excluidos \nPara adicionar posteriormente esse cliente sera necessario cadastra-lo novamente\n");
    free(cliente);
    return 0;
}

void excluirUmCliente(Clientes *clientes, Contas *contas, Transacoes *transacoes){
    char cpf[16];
    int valorDeRetorno = solicitaInteiro("Voce gostaria que listassemos os clientes contidos na lista de clientes: \ndigite 0 para NAO \ndigite 1 para SIM \n->");
    if(valorDeRetorno == 1) {
        listarTodosOsClientes(clientes);
    }
    if (listaDeClientesVazia(clientes)){
        return;
    }
    solicitaString("Para excluir digite o CPF do cliente (Todas as contas que esse cliente possui serao removidas)\n->", cpf);
    valorDeRetorno = buscarPosicaoClientePorCPF(clientes, cpf);
    Cliente *cliente = buscaClientePorCPF(clientes, cpf);
    int excluir = solicitaInteiro("Realmente deseja remover esse cliente, todas as contas e transacoes serao removidas como consequencia \ndigite 0 para NAO \ndigite 1 para SIM \n->");
    if(excluir == 1){
        removerTransacoesDeUmDeterminadoCliente(transacoes, cliente);
        removerContasDeUmDeterminadoCliente(contas, cliente);
        removeClienteDaListaDeClientes(clientes, valorDeRetorno);
    }
}

void cadastrarUmaNovaConta(Contas *contas, Agencias *agencias, Clientes *clientes){
    int numeroDaConta;
    char dataDeCriacaoDaConta[11];
    double saldo, limitePermitido;

    numeroDaConta = solicitaInteiro("Informe o numero da conta: ");
    solicitaString("Informe a dataDeCriacao da conta: ", dataDeCriacaoDaConta);
    saldo = solicitaDouble("Informe o saldo da conta: ");
    limitePermitido = solicitaDouble("Informe o limite permitido da conta: ");
    Agencia *agencia = recuperaAgencia(agencias);
    if (agencia == NULL){
        printf("Nao encontramos a agencia em questao");
        return;
    }
    Cliente *cliente = recuperaCliente(clientes);
    if (cliente == NULL){
        printf("Nao encontramos o cliente em questao");
        return;
    }
    Conta *conta = criaConta(numeroDaConta, dataDeCriacaoDaConta, saldo, limitePermitido, agencia, cliente);
    colocarContaNaListaDeContas(contas, conta);
}

int colocarContaNaListaDeContas(Contas *contas, Conta *conta){
    quebraLinha();
    imprimeConta(conta);
    quebraLinha();
    int inserir = solicitaInteiro("Voce gostaria de inserir a Conta na lista de contas: \ndigite 0 para NAO \ndigite 1 para SIM \n->");
    if(inserir == 1){
        if (listaDeContasVazia(contas)){
            insereNaListaDeContasVazia(contas, conta);
            printf("Parabens voce acaba de incluir a sua primeira conta na sua lista de contas\n\n");
            return 1;
        }else{
            insereNoFinalDaListaDeContas(contas, conta);
            printf("Conta incluida na lista de contas\n\n");
            return 1;
        }        
    }
    printf("Contas nao inclusas na lista de contas sao excluidas \nPara adicionar posteriormente esse conta sera necessario cadastra-lo novamente\n");
    free(conta);
    return 0;
}

void excluirUmaConta(Contas *contas, Transacoes *transacoes){
    int valorDeRetorno = solicitaInteiro("Voce gostaria que listassemos as contas contidas na lista de contas: \ndigite 0 para NAO \ndigite 1 para SIM \n->");
    if(valorDeRetorno == 1) {
        listarTodasAsContas(contas);
    }
    if (listaDeContasVazia(contas)){
        return;
    }
    valorDeRetorno = solicitaInteiro("Para excluir digite o numero da conta\n->");
    Conta *conta = obterContaPeloNumeroDaConta(contas, valorDeRetorno);
    valorDeRetorno = buscarPosicaoPorNumeroConta(contas, valorDeRetorno);
    int excluir = solicitaInteiro("Realmente deseja remover essa conta, todas as transacoes serao removidas como consequencia \ndigite 0 para NAO \ndigite 1 para SIM \n->");
    if(excluir == 1){
        removerTransacoesDeUmaDeterminadaConta(transacoes, conta);
        removeContaDaListaDeContas(contas, valorDeRetorno);
    }
}

void verificarSaldo(Transacoes *transacoes, Agencias *agencias, Contas *contas){
    iniciaUmaTransacao(transacoes, 0, agencias, contas);
}

void efetuaSaque(Transacoes *transacoes, Agencias *agencias, Contas *contas){
    iniciaUmaTransacao(transacoes, 1, agencias, contas);
}

void efetuaTransferencia(Transacoes *transacoes, Agencias *agencias, Contas *contas){
    iniciaUmaTransacao(transacoes, 2, agencias, contas);
}

void efetuaPagemento(Transacoes *transacoes, Agencias *agencias, Contas *contas){
    iniciaUmaTransacao(transacoes, 3, agencias, contas);
}

void iniciaUmaTransacao(Transacoes *transacoes, int tipoTranscao, Agencias *agencias, Contas *contas){
    if (listaDeAgenciasVazia(agencias) || listaDeContasVazia(contas)){
        printf("A sua lista de contas ou de agencias esta vazia");
        return;
    }

    int codigoTransacao = solicitaInteiro("Digite o codigo da trasacao: ");
    char dataDaTranscao[11];
    int dia = solicitaInteiro("Qual o dia em que esta conta esta sendo criada(somente o dia do mes): ");
    int mes = solicitaInteiro("Qual o mes em que esta conta esta sendo criada(somente o mes do ano): ");
    int ano = solicitaInteiro("Qual o ano em que esta conta esta sendo criada: ");
 

    int numeroDaConta = solicitaInteiro("Qual o numero da conta: ");
    Conta *contaPrincipal = obterContaPeloNumeroDaConta(contas, numeroDaConta);
    Conta *contaSecundaria = NULL;
    if (tipoTranscao == 2){ 
        int numeroDaConta = solicitaInteiro("Qual o numero da conta que voce gostaria de efetuar a transferencia: ");
        contaSecundaria = obterContaPeloNumeroDaConta(contas, numeroDaConta);
    }
    int codigoAgencia = solicitaInteiro("qual o codigo da agencia que voce esta utilizando: ");
    Agencia *agencia = buscaAgenciaPorCodigo(agencias, codigoAgencia);
    Transacao *transacao = criaTransacao(codigoTransacao, dia, mes, ano, tipoTranscao, agencia, contaPrincipal, contaSecundaria);
    colocarTransacaoNaListaDeTransacoes(transacoes, transacao);

    
}

int colocarTransacaoNaListaDeTransacoes(Transacoes *transacoes, Transacao *transacao){
    quebraLinha();
    imprimeTransacao(transacao);
    quebraLinha();
    if (listaDeTransacoesVazia(transacoes)){
        insereNaListaDeTransacoesVazia(transacoes, transacao);
        return 1;
    }else{
        insereNoFinalDaListaDeTransacoes(transacoes, transacao);
        return 1;
    };
    return 0;
}

void excluirUmaTransacao(Transacoes *transacoes){
    int valorDeRetorno = solicitaInteiro("Voce gostaria que listassemos as transacoes contidos na lista de transacoes: \ndigite 0 para NAO \ndigite 1 para SIM \n->");
    if(valorDeRetorno == 1) {
        listarTodasAsTransacoes(transacoes);
    }
    if (listaDeTransacoesVazia(transacoes)){
        return;
    }
    valorDeRetorno = solicitaInteiro("Para excluir digite o codigo da transacao \n->");
    valorDeRetorno = buscarPosicaoTransacaoPorCodigo(transacoes, valorDeRetorno);
    removeTransacaoDaListaDeTransacoes(transacoes, valorDeRetorno);
}

Agencia* recuperaAgencia(Agencias *agencias){
    int codigoAgencia;
    codigoAgencia = solicitaInteiro("\nInforme o codigo da agencia (Esta agencia deve estar listada na lista de agencias): \n");
    return buscaAgenciaPorCodigo(agencias, codigoAgencia);
}

Cliente* recuperaCliente(Clientes *clientes){
    char cpf[16]; 
    solicitaString("\nInforme o cpf do cliente(este cliente deve estar listado na lista de clientes): ", cpf);
    return buscaClientePorCPF(clientes, cpf);
}

void listarTodasAsAgencias(Agencias *agencias){
    imprimeListaDeAgencias(agencias);
}

void listarTodosOsClientes(Clientes *clientes){
    imprimeListaDeClientes(clientes);
}

void listarTodasAsContas(Contas *contas){
    imprimeListaDeContas(contas);
}

void listarTodasAsTransacoes(Transacoes *transacoes){
    imprimeListaDeTransacoes(transacoes);
}

void listarNomeClientesEAgenciasEmQuePossuemContas(Contas *contas){
    imprimeListaDeNomesDosClientesENomesDasAgenciasDeUmaConta(contas);
}

void listarAgenciasSemContasAbertas(Agencias *agencias, Contas *contas){
    if (listaDeAgenciasVazia(agencias)){
        printf("\n\n Verificamos ao Listar as agencias que a lista de agencias esta vazia\n\n");
        return;
    }
    Agencia *atual = getInicioDaListaDeAgencias(agencias);
	while(atual != NULL){
        if (agenciaPossuiConta(contas, atual) == 0){
            imprimeAgencia(atual);
        }
		atual = getProximaAgencia(atual);
	}
}

void listarTodosOsSaquesEfetuadosEmUmDeterminadoMes(Transacoes *transacoes){
    int mes = solicitaInteiro("Qual o mes que voce gostaria que listassemos todas as transacoes: ");
    imprimeListaDeTransacoesDeUmDeterminadoMes(transacoes, mes, 1);
}

void listarSaldoContasNaoNegativo(Contas *contas){
    imprimeListaDeContasComSaldoPositivo(contas);
}

void listarTodasAsContasDeUmDeterminadoCliente(Clientes *clientes, Contas *contas){
    Cliente *cliente = recuperaCliente(clientes);
    imprimeContasDoCliente(contas, cliente);
}
