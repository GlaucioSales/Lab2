#include "menu.h"

void menuPrincial(Alunos *alunos, RaizDaArvoreCodAluno *raizDaArvoreCodAluno, RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno, RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno){
    int acao;
    do{
        printf("\n\nMENU PRINCIPAL\n");

        printf("0) Sair\n");
        printf("1) Incluir aluno na lista.\n");
        printf("2) Excluir aluno na lista.\n");
        printf("3) Imprimir os dados da lista.\n");
        printf("4) Imprimir os dados dos alunos ordenadamente pelo codigo, usando a arvore binaria de busca de codigos.\n");
        printf("5) Imprimir os dados dos alunos ordenadamente pelo nome, atraves da arvore binaria de busca de nomes.\n");
        printf("6) Imprimir os dados dos alunos ordenadamente pela media final, atraves da arvore binaria de busca de medias.\n");
        acao = solicitaInteiro("O que voce gostaria de fazer: ");
        controlePrincial(acao, alunos, raizDaArvoreCodAluno, raizDaArvoreNomeAluno, raizDaArvoreMediaAluno);
    } while(acao != 0);
}

void controlePrincial(int acao, Alunos *alunos, RaizDaArvoreCodAluno *raizDaArvoreCodAluno, RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno, RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno){
    switch (acao){
    case 0:
        sair(alunos, raizDaArvoreCodAluno, raizDaArvoreNomeAluno, raizDaArvoreMediaAluno);
        break;
    case 1:
        cadastrarUmNovoAluno(alunos, raizDaArvoreCodAluno, raizDaArvoreNomeAluno, raizDaArvoreMediaAluno);
        break;
    case 2:
        excluirUmAluno(alunos, raizDaArvoreCodAluno, raizDaArvoreNomeAluno, raizDaArvoreMediaAluno);
        break;
    case 3:
        listarTodosOsAlunos(alunos);
        break;
    case 4:
        mostrarTodosOsCodigosAlunosNaArvoreEmOrdem(raizDaArvoreCodAluno);
        break;
    case 5:
        mostrarTodosOsNomesAlunosNaArvoreEmOrdem(raizDaArvoreNomeAluno);
        break;
    case 6:
        mostrarTodosAsMediasDosAlunosNaArvoreEmOrdem(raizDaArvoreMediaAluno);
        break;
    default:
        printf("\n valor incoreto por favor digite um valor valido\n\n");
        break;
    }
}