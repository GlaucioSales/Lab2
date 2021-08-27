#include "mediaAlunoArv.h"


struct raizDaArvoreMediaAluno {
    NoArvoreMediaAluno *raiz;
};

struct noArvoreMediaAluno {
    Aluno *aluno;
    NoArvoreMediaAluno *esquerda;
    NoArvoreMediaAluno *direita;
    NoArvoreMediaAluno *pai;
};

RaizDaArvoreMediaAluno* criaMediaAlunoArvore(){
    RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno = (RaizDaArvoreMediaAluno*)malloc(sizeof(RaizDaArvoreMediaAluno));
    if(raizDaArvoreMediaAluno == NULL){
        printf("Memoria insuficiente\n");
    }
    raizDaArvoreMediaAluno->raiz = NULL;
    return raizDaArvoreMediaAluno;
}

NoArvoreMediaAluno* getRaizDaArvoreDeMediaAlunos(RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno){
    return raizDaArvoreMediaAluno->raiz;
}

int estaVaziaArvoreMediaAluno(RaizDaArvoreMediaAluno* raizDaArvoreMediaAluno){
    if (raizDaArvoreMediaAluno->raiz == NULL) return 1;
    return 0;
}

int inserirNoNaArvoreMediaAluno(RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno, Aluno *aluno){
    if (estaVaziaArvoreMediaAluno(raizDaArvoreMediaAluno)){
        return insereAlunoNaArvoreMediaAlunoVazia(raizDaArvoreMediaAluno, aluno);
    }
    return insereAlunoNaArvoreMediaAlunoNaoVazia(raizDaArvoreMediaAluno->raiz, aluno);
}

int insereAlunoNaArvoreMediaAlunoVazia (RaizDaArvoreMediaAluno *raizDaArvoreMediaAluno, Aluno *aluno){
    NoArvoreMediaAluno *noArvoreMediaAluno = alocaNoDaArvoreMediaAluno(aluno, NULL, NULL);
    if (noArvoreMediaAluno == NULL) return 0;
    raizDaArvoreMediaAluno->raiz = noArvoreMediaAluno;
    return 1;
}

int insereAlunoNaArvoreMediaAlunoNaoVazia(NoArvoreMediaAluno *noArvoreMediaAluno, Aluno *aluno){
    if (getMediaDoAluno(aluno) > getMediaDoAluno(noArvoreMediaAluno->aluno)){
        if (noArvoreMediaAluno->direita == NULL){
            NoArvoreMediaAluno *filho = alocaNoDaArvoreMediaAluno(aluno, NULL, NULL);
            arvoreMediaAlunoInsere(noArvoreMediaAluno, filho, 1);
        }else{
            insereAlunoNaArvoreMediaAlunoNaoVazia(noArvoreMediaAluno->direita, aluno);
        }
        return 1;
    } else if (getMediaDoAluno(aluno) < getMediaDoAluno(noArvoreMediaAluno->aluno)){
        if (noArvoreMediaAluno->esquerda == NULL){
            NoArvoreMediaAluno *filho = alocaNoDaArvoreMediaAluno(aluno, NULL, NULL);
            arvoreMediaAlunoInsere(noArvoreMediaAluno, filho, 0);
        }else{
            insereAlunoNaArvoreMediaAlunoNaoVazia(noArvoreMediaAluno->esquerda, aluno);
        }
        return 1;
    } else {
        printf("Valor duplicado");
        return 0;
    }
    return 0;
}

NoArvoreMediaAluno* alocaNoDaArvoreMediaAluno(Aluno *aluno, NoArvoreMediaAluno *esquerda, NoArvoreMediaAluno *direita){
    NoArvoreMediaAluno* no = (NoArvoreMediaAluno*)malloc(sizeof(NoArvoreMediaAluno));
    no->aluno = aluno;
    no->esquerda = esquerda;
    no->direita = direita;
    return no;
}

void arvoreMediaAlunoInsere(NoArvoreMediaAluno* pai, NoArvoreMediaAluno* filho, int dir){
   if (dir){
      pai->direita = filho;
   }else{
      pai->esquerda = filho;
   }
   filho->pai = pai;
}

int arvoreMediaAlunoRemoveNo(RaizDaArvoreMediaAluno* raizDaArvoreMediaAluno, Aluno *aluno){
    if (raizDaArvoreMediaAluno->raiz == NULL) return 0;

    return arvoreMediaAlunoRemoveNoRecursivamente(raizDaArvoreMediaAluno->raiz, aluno);
}
    
int arvoreMediaAlunoRemoveNoRecursivamente(NoArvoreMediaAluno *noArvoreMediaAluno, Aluno *aluno){
    if (noArvoreMediaAluno == NULL) return 0;

    if (verificaIgualdadeEntreDoisAlunos(noArvoreMediaAluno->aluno, aluno)){
        retiraONoDaArvoreMediaAluno(noArvoreMediaAluno);
        return 1;
    }

    if (getMediaDoAluno(aluno) < getMediaDoAluno(noArvoreMediaAluno->aluno)){
        return arvoreMediaAlunoRemoveNoRecursivamente(noArvoreMediaAluno->esquerda, aluno);
    } else {
        return arvoreMediaAlunoRemoveNoRecursivamente(noArvoreMediaAluno->direita, aluno);
    }
}

void retiraONoDaArvoreMediaAluno(NoArvoreMediaAluno * filho){
    if (filho->esquerda == NULL && filho->direita == NULL){
        if (filho->pai->esquerda == filho){
            filho->pai->esquerda = NULL;
        } else{
            filho->pai->direita = NULL;
        }
        free(filho);
        return;
    }
    if (filho->esquerda != NULL){
        NoArvoreMediaAluno *maior = encontraMaiorArvoreMediaAluno(filho->esquerda);
        filho->aluno = maior->aluno;
        retiraONoDaArvoreMediaAluno(maior);
        return;
    } else {
        NoArvoreMediaAluno *menor = encontraMenorArvoreMediaAluno(filho->direita);
        filho->aluno = menor->aluno;
        retiraONoDaArvoreMediaAluno(menor);
        return;
    }
}

NoArvoreMediaAluno*encontraMaiorArvoreMediaAluno (NoArvoreMediaAluno *noArvoreMediaAluno){
    if (noArvoreMediaAluno->direita == NULL) return noArvoreMediaAluno;
    return encontraMaiorArvoreMediaAluno(noArvoreMediaAluno->direita);
}

NoArvoreMediaAluno *encontraMenorArvoreMediaAluno (NoArvoreMediaAluno * noArvoreMediaAluno){
    if (noArvoreMediaAluno->esquerda == NULL) return noArvoreMediaAluno;
    return encontraMenorArvoreMediaAluno(noArvoreMediaAluno->esquerda);
}


void liberaArvoreMediaAluno(RaizDaArvoreMediaAluno* raizDaArvoreMediaAluno){
    if (raizDaArvoreMediaAluno->raiz == NULL) return;
    liberaNoDaArvoreMediaAluno(raizDaArvoreMediaAluno->raiz);
    free(raizDaArvoreMediaAluno);
}

void liberaNoDaArvoreMediaAluno(NoArvoreMediaAluno* noArvoreMediaAluno){
    if (noArvoreMediaAluno == NULL) return;
    liberaNoDaArvoreMediaAluno(noArvoreMediaAluno->esquerda);
    liberaNoDaArvoreMediaAluno(noArvoreMediaAluno->direita);
    free(noArvoreMediaAluno);
}

void imprimeArvoreMediaAluno(NoArvoreMediaAluno* noArvoreMediaAluno){
    if (noArvoreMediaAluno == NULL) return;
    imprimeArvoreMediaAluno(noArvoreMediaAluno->esquerda);
    imprimeAluno(noArvoreMediaAluno->aluno);
    imprimeArvoreMediaAluno(noArvoreMediaAluno->direita);
}