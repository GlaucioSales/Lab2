#include "menu.h"

void menuPrincial(Mesa ***mesas, Fila *fila, int linhas, int colunas){
    int acao;
    do{
        printf("\n\nMENU PRINCIPAL\n");

        printf("0) Sair\n");
        printf("1) Dados de uma determinada mesa\n");
        printf("2) Dados de todas as mesas\n");
        printf("3) Dados de mesas vazias\n");
        printf("4) Cadastrar Grupo\n");
        printf("5) Liberar uma mesa que estava ocupada\n");
        printf("6) Um grupo desistiu de ficar na fila\n");
        printf("7) Imprimir fila de espera\n");

        acao = solicitaInteiro("O que voce gostaria de fazer: ");
        controlePrincial(acao, mesas, fila, linhas, colunas);
    } while(acao != 0);
}

void controlePrincial(int acao, Mesa ***mesas, Fila *fila, int linhas, int colunas){
    switch (acao){
    case 0:
        sair(mesas, fila, linhas, colunas);
        break;
    case 1:
        imprimirDadosSobreMesa(mesas, linhas, colunas);
        break;
    case 2:
        imprimirDadosSobreTodasAsMesas(mesas, linhas, colunas);
        break;
    case 3:
        imprimirDadosSobreMesasVazias(mesas, linhas, colunas);
        break;
    case 4:
        cadastrarGrupoDePessoas(mesas, fila, linhas, colunas);
        break;
    case 5:
        liberarMesa(mesas, fila, linhas, colunas);
        break;
    case 6:
        desistiuDeEsperar(fila);
        break;
    case 7:
        imprimirFila(fila);
        break;
    default:
        printf("\n valor incoreto por favor digite um valor valido\n\n");
        break;
    }
}
