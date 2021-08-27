#include "../models/aluno.h"

typedef struct raizDaArvoreCodAluno RaizDaArvoreCodAluno;

typedef struct noArvoreCodAluno NoArvoreCodAluno;

RaizDaArvoreCodAluno* criaCodAlunoArvore();

NoArvoreCodAluno* getRaizDaArvoreDeCodAlunos(RaizDaArvoreCodAluno *raizDaArvoreCodAluno);

int estaVaziaArvoreCodAluno(RaizDaArvoreCodAluno* raizDaArvoreCodAluno);

int inserirNoNaArvoreCodAluno(RaizDaArvoreCodAluno *raizDaArvoreCodAluno, Aluno *aluno);

int insereAlunoNaArvoreCodAlunoVazia (RaizDaArvoreCodAluno *raiz, Aluno *aluno);

int insereAlunoNaArvoreCodAlunoNaoVazia(NoArvoreCodAluno *noArvoreCodAluno, Aluno *aluno);

NoArvoreCodAluno* alocaNoDaArvoreCodAluno(Aluno *aluno, NoArvoreCodAluno *esquerda, NoArvoreCodAluno *direita);

void arvoreCodAlunoInsere(NoArvoreCodAluno* pai, NoArvoreCodAluno* filho, int dir);

int arvoreCodAlunoRemoveNo(RaizDaArvoreCodAluno* raizDaArvoreCodAluno, Aluno *aluno);

int arvoreCodAlunoRemoveNo(RaizDaArvoreCodAluno* raizDaArvoreCodAluno, Aluno *aluno);

int arvoreCodAlunoRemoveNoRecursivamente(NoArvoreCodAluno *noArvoreCodAluno, Aluno *aluno);

void retiraONoDaArvoreCodAluno(NoArvoreCodAluno * filho);

NoArvoreCodAluno*encontraMaiorArvoreCodAluno (NoArvoreCodAluno *noArvoreCodAluno);

NoArvoreCodAluno *encontraMenorArvoreCodAluno (NoArvoreCodAluno * noArvoreCodAluno);

void liberaArvoreCodAluno(RaizDaArvoreCodAluno* raizDaArvoreCodAluno);

void liberaNoDaArvoreCodAluno(NoArvoreCodAluno* noArvoreCodAluno);

void imprimeArvoreCodAluno(NoArvoreCodAluno* noArvoreCodAluno);