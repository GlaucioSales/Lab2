#include "../models/aluno.h"

typedef struct raizDaArvoreNomeAluno RaizDaArvoreNomeAluno;

typedef struct noArvoreNomeAluno NoArvoreNomeAluno;

RaizDaArvoreNomeAluno* criaNomeAlunoArvore();

NoArvoreNomeAluno* getRaizDaArvoreDeNomeAlunos(RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno);

int estaVaziaArvoreNomeAluno(RaizDaArvoreNomeAluno* raizDaArvoreNomeAluno);

int inserirNoNaArvoreNomeAluno(RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno, Aluno *aluno);

int insereAlunoNaArvoreNomeAlunoVazia (RaizDaArvoreNomeAluno *raiz, Aluno *aluno);

int insereAlunoNaArvoreNomeAlunoNaoVazia(NoArvoreNomeAluno *noArvoreNomeAluno, Aluno *aluno);

NoArvoreNomeAluno* alocaNoDaArvoreNomeAluno(Aluno *aluno, NoArvoreNomeAluno *esquerda, NoArvoreNomeAluno *direita);

void arvoreNomeAlunoInsere(NoArvoreNomeAluno* pai, NoArvoreNomeAluno* filho, int dir);

int arvoreNomeAlunoRemoveNo(RaizDaArvoreNomeAluno* raizDaArvoreNomeAluno, Aluno *aluno);

int arvoreNomeAlunoRemoveNo(RaizDaArvoreNomeAluno* raizDaArvoreNomeAluno, Aluno *aluno);

int arvoreNomeAlunoRemoveNoRecursivamente(NoArvoreNomeAluno *noArvoreNomeAluno, Aluno *aluno);

void retiraONoDaArvoreNomeAluno(NoArvoreNomeAluno * filho);

NoArvoreNomeAluno*encontraMaiorArvoreNomeAluno (NoArvoreNomeAluno *noArvoreNomeAluno);

NoArvoreNomeAluno *encontraMenorArvoreNomeAluno (NoArvoreNomeAluno * noArvoreNomeAluno);

void liberaArvoreNomeAluno(RaizDaArvoreNomeAluno* raizDaArvoreNomeAluno);

void liberaNoDaArvoreNomeAluno(NoArvoreNomeAluno* noArvoreNomeAluno);

void imprimeArvoreNomeAluno(NoArvoreNomeAluno* noArvoreNomeAluno);