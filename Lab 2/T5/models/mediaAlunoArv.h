#include "../models/aluno.h"

typedef struct raizDaArvoreMediaAluno RaizDaArvoreMediaAluno;

typedef struct noArvoreMediaAluno NoArvoreMediaAluno;

RaizDaArvoreMediaAluno* criaMediaAlunoArvore();

NoArvoreMediaAluno* getRaizDaArvoreDeMediaAlunos(RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno);

int estaVaziaArvoreMediaAluno(RaizDaArvoreMediaAluno* raizDaArvoreMediaAluno);

int inserirNoNaArvoreMediaAluno(RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno, Aluno *aluno);

int insereAlunoNaArvoreMediaAlunoVazia (RaizDaArvoreMediaAluno *raiz, Aluno *aluno);

int insereAlunoNaArvoreMediaAlunoNaoVazia(NoArvoreMediaAluno *noArvoreMediaAluno, Aluno *aluno);

NoArvoreMediaAluno* alocaNoDaArvoreMediaAluno(Aluno *aluno, NoArvoreMediaAluno *esquerda, NoArvoreMediaAluno *direita);

void arvoreMediaAlunoInsere(NoArvoreMediaAluno* pai, NoArvoreMediaAluno* filho, int dir);

int arvoreMediaAlunoRemoveNo(RaizDaArvoreMediaAluno* raizDaArvoreMediaAluno, Aluno *aluno);

int arvoreMediaAlunoRemoveNo(RaizDaArvoreMediaAluno* raizDaArvoreMediaAluno, Aluno *aluno);

int arvoreMediaAlunoRemoveNoRecursivamente(NoArvoreMediaAluno *noArvoreMediaAluno, Aluno *aluno);

void retiraONoDaArvoreMediaAluno(NoArvoreMediaAluno * filho);

NoArvoreMediaAluno*encontraMaiorArvoreMediaAluno (NoArvoreMediaAluno *noArvoreMediaAluno);

NoArvoreMediaAluno *encontraMenorArvoreMediaAluno (NoArvoreMediaAluno * noArvoreMediaAluno);

void liberaArvoreMediaAluno(RaizDaArvoreMediaAluno* raizDaArvoreMediaAluno);

void liberaNoDaArvoreMediaAluno(NoArvoreMediaAluno* noArvoreMediaAluno);

void imprimeArvoreMediaAluno(NoArvoreMediaAluno* noArvoreMediaAluno);