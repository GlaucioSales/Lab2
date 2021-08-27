#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "auxiliar.h"
#include "../models/aluno.h"
#include "../models/codAlunoArv.h"
#include "../models/nomeAlunoArv.h"
#include "../models/mediaAlunoArv.h"

void sair(Alunos *alunos, RaizDaArvoreCodAluno *raizDaArvoreCodAluno, RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno, RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno);

void cadastrarUmNovoAluno(Alunos *alunos, RaizDaArvoreCodAluno *raizDaArvoreCodAluno, RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno, RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno);

int colocarAlunoNaListaDeAlunos(Alunos *alunos, Aluno *aluno);

void excluirUmAluno(Alunos *alunos, RaizDaArvoreCodAluno *raizDaArvoreCodAluno, RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno, RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno);

void listarTodosOsAlunos(Alunos *alunos);

void mostrarTodosOsCodigosAlunosNaArvoreEmOrdem(RaizDaArvoreCodAluno *raizDaArvoreCodAluno);

void mostrarTodosOsNomesAlunosNaArvoreEmOrdem(RaizDaArvoreNomeAluno *raizDaArvoreCodAluno);

void mostrarTodosAsMediasDosAlunosNaArvoreEmOrdem(RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno);