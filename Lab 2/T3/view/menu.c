#include "menu.h"

void menuPrincial(Agencias *agencias, Clientes *clientes, Contas *contas, Transacoes *transacoes){
    int acao;
    do{
        printf("\n\nMENU PRINCIPAL\n");

        printf("0) Sair\n");
        printf("1) Cadastrar uma nova agencia\n");
        printf("2) Excluir uma agencia\n");
        printf("3) Cadastrar um novo cliente\n");
        printf("4) Excluir um cliente\n");
        printf("5) Cadastrar uma nova conta\n");
        printf("6) Excluir uma conta\n");
        printf("7) Menu de transacoes\n");
        printf("8) Menu de relatorios\n");
        acao = solicitaInteiro("O que voce gostaria de fazer: ");
        controlePrincial(acao, agencias, clientes, contas, transacoes);
    } while(acao != 0);
}

void controlePrincial(int acao, Agencias *agencias, Clientes *clientes, Contas *contas, Transacoes *transacoes){
    switch (acao){
    case 0:
        sair(agencias, clientes, contas, transacoes);
        break;
    case 1:
        cadastrarUmaNovaAgencia(agencias);
        break;
    case 2:
        excluirUmaAgencia(agencias, contas, transacoes);
        break;
    case 3:
        cadastrarUmNovoCliente(clientes);
        break;
    case 4:
        excluirUmCliente(clientes, contas, transacoes);
        break;
    case 5:
        cadastrarUmaNovaConta(contas, agencias, clientes);
        break;
    case 6:
        excluirUmaConta(contas, transacoes);
        break;
    case 7:
        menuDeTransacao(transacoes, agencias, contas);
        break;
    case 8:
        menuDeRelatorios(agencias, clientes, contas, transacoes);
        break;
    default:
        printf("\n valor incoreto por favor digite um valor valido\n\n");
        break;
    }
}

void menuDeRelatorios(Agencias *agencias, Clientes *clientes, Contas *contas, Transacoes *transacoes){
    int acao;
    do{
        printf("\n\nMENU DE RELATORIOS\n");

        printf("0) Voltar para o menu principal\n");
        printf("1) Listar todas as agencias\n");
        printf("2) Listar todos os clientes\n");
        printf("3) Listar todas as contas\n");
        printf("4) Listar todas as transacoes\n");
        printf("5) Listar o nome dos clientes e o nome da agencia em que estes possuem conta\n");
        printf("6) Listar as agencias que ainda nao possuem nenhuma conta aberta\n");
        printf("7) Listar todos os saques efetuados em certo mes informado pelo usuario\n");
        printf("8) Listar o saldo das contas que nao estao no negativo\n");
        printf("9) Listar todas as contas de certo cliente informado pelo usuario\n");
        acao = solicitaInteiro("O que voce gostaria de fazer: ");
        controleRelatorios(acao, agencias, clientes, contas, transacoes);
    } while(acao != 0);
}

void controleRelatorios(int acao, Agencias *agencias, Clientes *clientes, Contas *contas, Transacoes *transacoes){
    switch (acao){
    case 1:
        listarTodasAsAgencias(agencias);
        break;
    case 2:
        listarTodosOsClientes(clientes);
        break;
    case 3:
        listarTodasAsContas(contas);
        break;
    case 4:
        listarTodasAsTransacoes(transacoes);
        break;
    case 5:
        listarNomeClientesEAgenciasEmQuePossuemContas(contas);
        break;
    case 6:
        listarAgenciasSemContasAbertas(agencias, contas);
        break;
    case 7:
        listarTodosOsSaquesEfetuadosEmUmDeterminadoMes(transacoes);
        break;
    case 8:
        listarSaldoContasNaoNegativo(contas);
        break;
    case 9:
        listarTodasAsContasDeUmDeterminadoCliente(clientes, contas);
        break;    
    default:
        break;
    }
}

void menuDeTransacao(Transacoes *transacoes, Agencias *agencias, Contas *contas){
    int acao;
    do{
        printf("\n\nMENU DE TRANSACOES\n");

        printf("0) Sair\n");
        printf("1) Verificar saldo\n");
        printf("2) Efetuar saque\n");
        printf("3) Efetuar transferencia\n");
        printf("4) Efetuar pagamento\n");
        printf("5) Excluir uma transacao\n");
        acao = solicitaInteiro("O que voce gostaria de fazer: ");
        controleTranscao(acao, transacoes, agencias, contas);
    } while(acao != 0);
}

void controleTranscao(int acao, Transacoes *transacoes, Agencias *agencias, Contas *contas){
    switch (acao){
    case 1:
        verificarSaldo(transacoes, agencias, contas);
        break;
    case 2:
        efetuaSaque(transacoes, agencias, contas);
        break;
    case 3:
        efetuaTransferencia(transacoes, agencias, contas);
        break;
    case 4:
        efetuaPagemento(transacoes, agencias, contas);
        break;
    case 5:
        excluirUmaTransacao(transacoes);
        break;      
    default:
        break;
    }
}