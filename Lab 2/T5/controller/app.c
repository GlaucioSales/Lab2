#include "app.h"

void app(){
    Alunos *alunos = criaListaDeAlunos();
    RaizDaArvoreCodAluno *raizDaArvoreCodAluno = criaCodAlunoArvore();
    RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno = criaNomeAlunoArvore();
    RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno = criaMediaAlunoArvore();
    menuPrincial(alunos, raizDaArvoreCodAluno, raizDaArvoreNomeAluno, raizDaArvoreMediaAluno);
}

