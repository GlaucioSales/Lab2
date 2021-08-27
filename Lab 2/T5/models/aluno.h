#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

typedef struct alunos Alunos;

Alunos* criaListaDeAlunos();

Aluno* criaAluno(int codAluno,char nomeAluno[81], float media);

int getCodigoDoAluno(Aluno *aluno);

char* getNomeDoAluno(Aluno *aluno);

float getMediaDoAluno(Aluno *aluno);

int verificaIgualdadeEntreDoisAlunos(Aluno *alunoX, Aluno* alunoY);

Aluno* getInicioDaListaDeAlunos(Alunos *alunos);

Aluno* getProximoAluno(Aluno *aluno);

int insereNaListaDeAlunosVazia (Alunos* alunos, Aluno *aluno);

int insereNoInicioDaListaDeAlunos(Alunos *alunos, Aluno *aluno);

int insereNoFinalDaListaDeAlunos(Alunos *alunos, Aluno *aluno);

int listaDeAlunosVazia (Alunos *alunos);

int tamanhoListaDeAlunos(Alunos *alunos);

int removeAlunoDaListaDeAlunos(Alunos *alunos, int pos);

int destruirListaDeAlunos(Alunos *alunos);

int buscarPosicaoAlunoPorCodigo(Alunos *alunos, int codAluno);

Aluno* buscaAlunoPorCodigo(Alunos *alunos, int codAluno);

void imprimeCodigoAluno(Aluno* aluno);

void imprimeNomeAluno(Aluno* aluno);

void imprimeMediaAluno(Aluno *aluno);

void imprimeAluno(Aluno* aluno);

void imprimeListaDeAlunos(Alunos *alunos);