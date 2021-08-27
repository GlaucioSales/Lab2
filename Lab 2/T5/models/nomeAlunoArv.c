#include "nomeAlunoArv.h"


struct raizDaArvoreNomeAluno {
    NoArvoreNomeAluno *raiz;
};

struct noArvoreNomeAluno {
    Aluno *aluno;
    NoArvoreNomeAluno *esquerda;
    NoArvoreNomeAluno *direita;
    NoArvoreNomeAluno *pai;
};

RaizDaArvoreNomeAluno* criaNomeAlunoArvore(){
    RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno = (RaizDaArvoreNomeAluno*)malloc(sizeof(RaizDaArvoreNomeAluno));
    if(raizDaArvoreNomeAluno == NULL){
        printf("Memoria insuficiente\n");
    }
    raizDaArvoreNomeAluno->raiz = NULL;
    return raizDaArvoreNomeAluno;
}

NoArvoreNomeAluno* getRaizDaArvoreDeNomeAlunos(RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno){
    return raizDaArvoreNomeAluno->raiz;
}

int estaVaziaArvoreNomeAluno(RaizDaArvoreNomeAluno* raizDaArvoreNomeAluno){
    if (raizDaArvoreNomeAluno->raiz == NULL) return 1;
    return 0;
}

int inserirNoNaArvoreNomeAluno(RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno, Aluno *aluno){
    if (estaVaziaArvoreNomeAluno(raizDaArvoreNomeAluno)){
        return insereAlunoNaArvoreNomeAlunoVazia(raizDaArvoreNomeAluno, aluno);
    }
    return insereAlunoNaArvoreNomeAlunoNaoVazia(raizDaArvoreNomeAluno->raiz, aluno);
}

int insereAlunoNaArvoreNomeAlunoVazia (RaizDaArvoreNomeAluno *raizDaArvoreNomeAluno, Aluno *aluno){
    NoArvoreNomeAluno *noArvoreNomeAluno = alocaNoDaArvoreNomeAluno(aluno, NULL, NULL);
    if (noArvoreNomeAluno == NULL) return 0;
    raizDaArvoreNomeAluno->raiz = noArvoreNomeAluno;
    return 1;
}

int insereAlunoNaArvoreNomeAlunoNaoVazia(NoArvoreNomeAluno *noArvoreNomeAluno, Aluno *aluno){
    if (strcmp(getNomeDoAluno(aluno), getNomeDoAluno(noArvoreNomeAluno->aluno)) > 0){
        if (noArvoreNomeAluno->direita == NULL){
            NoArvoreNomeAluno *filho = alocaNoDaArvoreNomeAluno(aluno, NULL, NULL);
            arvoreNomeAlunoInsere(noArvoreNomeAluno, filho, 1);
        }else{
            insereAlunoNaArvoreNomeAlunoNaoVazia(noArvoreNomeAluno->direita, aluno);
        }
        return 1;
    } else if (strcmp(getNomeDoAluno(aluno), getNomeDoAluno(noArvoreNomeAluno->aluno)) < 0){
        if (noArvoreNomeAluno->esquerda == NULL){
            NoArvoreNomeAluno *filho = alocaNoDaArvoreNomeAluno(aluno, NULL, NULL);
            arvoreNomeAlunoInsere(noArvoreNomeAluno, filho, 0);
        }else{
            insereAlunoNaArvoreNomeAlunoNaoVazia(noArvoreNomeAluno->esquerda, aluno);
        }
        return 1;
    } else {
        printf("Valor duplicado");
        return 0;
    }
    return 0;
}

NoArvoreNomeAluno* alocaNoDaArvoreNomeAluno(Aluno *aluno, NoArvoreNomeAluno *esquerda, NoArvoreNomeAluno *direita){
    NoArvoreNomeAluno* no = (NoArvoreNomeAluno*)malloc(sizeof(NoArvoreNomeAluno));
    no->aluno = aluno;
    no->esquerda = esquerda;
    no->direita = direita;
    return no;
}

void arvoreNomeAlunoInsere(NoArvoreNomeAluno* pai, NoArvoreNomeAluno* filho, int dir){
   if (dir){
      pai->direita = filho;
   }else{
      pai->esquerda = filho;
   }
   filho->pai = pai;
}

int arvoreNomeAlunoRemoveNo(RaizDaArvoreNomeAluno* raizDaArvoreNomeAluno, Aluno *aluno){
    if (raizDaArvoreNomeAluno->raiz == NULL) return 0;

    return arvoreNomeAlunoRemoveNoRecursivamente(raizDaArvoreNomeAluno->raiz, aluno);
}
    
int arvoreNomeAlunoRemoveNoRecursivamente(NoArvoreNomeAluno *noArvoreNomeAluno, Aluno *aluno){
    if (noArvoreNomeAluno == NULL) return 0;

    if (verificaIgualdadeEntreDoisAlunos(noArvoreNomeAluno->aluno, aluno)){
        retiraONoDaArvoreNomeAluno(noArvoreNomeAluno);
        return 1;
    }

    if (getNomeDoAluno(aluno) < getNomeDoAluno(noArvoreNomeAluno->aluno)){
        return arvoreNomeAlunoRemoveNoRecursivamente(noArvoreNomeAluno->esquerda, aluno);
    } else {
        return arvoreNomeAlunoRemoveNoRecursivamente(noArvoreNomeAluno->direita, aluno);
    }
}

void retiraONoDaArvoreNomeAluno(NoArvoreNomeAluno * filho){
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
        NoArvoreNomeAluno *maior = encontraMaiorArvoreNomeAluno(filho->esquerda);
        filho->aluno = maior->aluno;
        retiraONoDaArvoreNomeAluno(maior);
        return;
    } else {
        NoArvoreNomeAluno *menor = encontraMenorArvoreNomeAluno(filho->direita);
        filho->aluno = menor->aluno;
        retiraONoDaArvoreNomeAluno(menor);
        return;
    }
}

NoArvoreNomeAluno*encontraMaiorArvoreNomeAluno (NoArvoreNomeAluno *noArvoreNomeAluno){
    if (noArvoreNomeAluno->direita == NULL) return noArvoreNomeAluno;
    return encontraMaiorArvoreNomeAluno(noArvoreNomeAluno->direita);
}

NoArvoreNomeAluno *encontraMenorArvoreNomeAluno (NoArvoreNomeAluno * noArvoreNomeAluno){
    if (noArvoreNomeAluno->esquerda == NULL) return noArvoreNomeAluno;
    return encontraMenorArvoreNomeAluno(noArvoreNomeAluno->esquerda);
}


void liberaArvoreNomeAluno(RaizDaArvoreNomeAluno* raizDaArvoreNomeAluno){
    if (raizDaArvoreNomeAluno->raiz == NULL) return;
    liberaNoDaArvoreNomeAluno(raizDaArvoreNomeAluno->raiz);
    free(raizDaArvoreNomeAluno);
}

void liberaNoDaArvoreNomeAluno(NoArvoreNomeAluno* noArvoreNomeAluno){
    if (noArvoreNomeAluno == NULL) return;
    liberaNoDaArvoreNomeAluno(noArvoreNomeAluno->esquerda);
    liberaNoDaArvoreNomeAluno(noArvoreNomeAluno->direita);
    free(noArvoreNomeAluno);
}

void imprimeArvoreNomeAluno(NoArvoreNomeAluno* noArvoreNomeAluno){
    if (noArvoreNomeAluno == NULL) return;
    imprimeArvoreNomeAluno(noArvoreNomeAluno->esquerda);
    imprimeAluno(noArvoreNomeAluno->aluno);
    imprimeArvoreNomeAluno(noArvoreNomeAluno->direita);
}