#include "controles.h"

void sair(Alunos *alunos, RaizDaArvoreCodAluno *raizDaArvoreCodAluno, RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno, RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno){
    liberaArvoreCodAluno(raizDaArvoreCodAluno);
    liberaArvoreNomeAluno(raizDaArvoreNomeAluno);
    liberaArvoreMediaAluno(raizDaArvoreMediaAluno);
    destruirListaDeAlunos(alunos);
    exit(0);
}

void cadastrarUmNovoAluno(Alunos *alunos, RaizDaArvoreCodAluno *raizDaArvoreCodAluno, RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno, RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno){
    int codAluno;
    char nomeAluno[81];
    float media;

    codAluno = solicitaInteiro("Informe o codigo do aluno que deve ser cadastrado: ");
    solicitaString("Informe o nome do aluno que deve ser cadastrado: ", nomeAluno);
    media =  solicitaFloat("Informe a media do aluno que deve ser cadastrado: ");
    Aluno *aluno = criaAluno(codAluno, nomeAluno, media);
    if(colocarAlunoNaListaDeAlunos(alunos, aluno)){
        inserirNoNaArvoreCodAluno(raizDaArvoreCodAluno, aluno);
        inserirNoNaArvoreNomeAluno(raizDaArvoreNomeAluno, aluno);
        inserirNoNaArvoreMediaAluno(raizDaArvoreMediaAluno, aluno);
    }
}

int colocarAlunoNaListaDeAlunos(Alunos *alunos, Aluno *aluno){
    quebraLinha();
    imprimeAluno(aluno);
    quebraLinha();
    int inserir = solicitaInteiro("Voce gostaria de inserir o aluno na lista de alunos: \ndigite 0 para NAO \ndigite 1 para SIM \n->");
    if(inserir == 1){
        if (listaDeAlunosVazia(alunos)){
            insereNaListaDeAlunosVazia(alunos, aluno);
            printf("Aluno inserido com sucesso\n\n");

            return 1;
        }else{
            insereNoFinalDaListaDeAlunos(alunos, aluno);
            printf("Aluno inserido com sucesso\n\n");
            return 1;
        }        
    }
    printf("Alunos nao inseridas na lista de alunos sao excluidas \nPara adicionar posteriormente essa agencia sera necessario cadastra-la novamente\n");
    free(aluno);
    return 0;
}


void excluirUmAluno(Alunos *alunos, RaizDaArvoreCodAluno *raizDaArvoreCodAluno, RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno, RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno){
    int valorDeRetorno = solicitaInteiro("Voce gostaria que listassemos os alunos contidos na lista de alunos: \ndigite 0 para NAO \ndigite 1 para SIM \n->");
    if(valorDeRetorno == 1) {
        listarTodosOsAlunos(alunos);
    }
    if (listaDeAlunosVazia(alunos)){
        return;
    }
    valorDeRetorno = solicitaInteiro("\n\nPara excluir digite o codigo do aluno \n->");
    Aluno *aluno = buscaAlunoPorCodigo(alunos, valorDeRetorno);
    valorDeRetorno = buscarPosicaoAlunoPorCodigo(alunos, valorDeRetorno);
    int excluir = solicitaInteiro("Realmente deseja remover esse aluno da lista de alunos \ndigite 0 para NAO \ndigite 1 para SIM \n->");
    if(excluir == 1){
        arvoreCodAlunoRemoveNo(raizDaArvoreCodAluno, aluno);
        arvoreNomeAlunoRemoveNo(raizDaArvoreNomeAluno, aluno);
        arvoreMediaAlunoRemoveNo(raizDaArvoreMediaAluno, aluno);
        removeAlunoDaListaDeAlunos(alunos, valorDeRetorno);
    }
}

void listarTodosOsAlunos(Alunos *alunos){
    imprimeListaDeAlunos(alunos);
}

void mostrarTodosOsCodigosAlunosNaArvoreEmOrdem(RaizDaArvoreCodAluno *raizDaArvoreCodAluno){
    imprimeArvoreCodAluno(getRaizDaArvoreDeCodAlunos(raizDaArvoreCodAluno));
}

void mostrarTodosOsNomesAlunosNaArvoreEmOrdem(RaizDaArvoreNomeAluno *raizDaArvoreCodAluno){
    imprimeArvoreNomeAluno(getRaizDaArvoreDeNomeAlunos(raizDaArvoreCodAluno));
}

void mostrarTodosAsMediasDosAlunosNaArvoreEmOrdem(RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno){
    imprimeArvoreMediaAluno(getRaizDaArvoreDeMediaAlunos(raizDaArvoreMediaAluno));
}