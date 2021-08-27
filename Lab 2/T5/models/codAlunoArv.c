#include "codAlunoArv.h"


struct raizDaArvoreCodAluno {
    NoArvoreCodAluno *raiz;
};

struct noArvoreCodAluno {
    Aluno *aluno;
    NoArvoreCodAluno *esquerda;
    NoArvoreCodAluno *direita;
    NoArvoreCodAluno *pai;
};

RaizDaArvoreCodAluno* criaCodAlunoArvore(){
    RaizDaArvoreCodAluno *raizDaArvoreCodAluno = (RaizDaArvoreCodAluno*)malloc(sizeof(RaizDaArvoreCodAluno));
    if(raizDaArvoreCodAluno == NULL){
        printf("Memoria insuficiente\n");
    }
    raizDaArvoreCodAluno->raiz = NULL;
    return raizDaArvoreCodAluno;
}

NoArvoreCodAluno* getRaizDaArvoreDeCodAlunos(RaizDaArvoreCodAluno *raizDaArvoreCodAluno){
    return raizDaArvoreCodAluno->raiz;
}

int estaVaziaArvoreCodAluno(RaizDaArvoreCodAluno* raizDaArvoreCodAluno){
    if (raizDaArvoreCodAluno->raiz == NULL) return 1;
    return 0;
}

int inserirNoNaArvoreCodAluno(RaizDaArvoreCodAluno *raizDaArvoreCodAluno, Aluno *aluno){
    if (estaVaziaArvoreCodAluno(raizDaArvoreCodAluno)){
        return insereAlunoNaArvoreCodAlunoVazia(raizDaArvoreCodAluno, aluno);
    }
    return insereAlunoNaArvoreCodAlunoNaoVazia(raizDaArvoreCodAluno->raiz, aluno);
}

int insereAlunoNaArvoreCodAlunoVazia (RaizDaArvoreCodAluno *raizDaArvoreCodAluno, Aluno *aluno){
    NoArvoreCodAluno *noArvoreCodAluno = alocaNoDaArvoreCodAluno(aluno, NULL, NULL);
    if (noArvoreCodAluno == NULL) return 0;
    raizDaArvoreCodAluno->raiz = noArvoreCodAluno;
    return 1;
}

int insereAlunoNaArvoreCodAlunoNaoVazia(NoArvoreCodAluno *noArvoreCodAluno, Aluno *aluno){
    if (getCodigoDoAluno(aluno) > getCodigoDoAluno(noArvoreCodAluno->aluno)){
        if (noArvoreCodAluno->direita == NULL){
            NoArvoreCodAluno *filho = alocaNoDaArvoreCodAluno(aluno, NULL, NULL);
            arvoreCodAlunoInsere(noArvoreCodAluno, filho, 1);
        }else{
            insereAlunoNaArvoreCodAlunoNaoVazia(noArvoreCodAluno->direita, aluno);
        }
        return 1;
    } else if (getCodigoDoAluno(aluno) < getCodigoDoAluno(noArvoreCodAluno->aluno)){
        if (noArvoreCodAluno->esquerda == NULL){
            NoArvoreCodAluno *filho = alocaNoDaArvoreCodAluno(aluno, NULL, NULL);
            arvoreCodAlunoInsere(noArvoreCodAluno, filho, 0);
        }else{
            insereAlunoNaArvoreCodAlunoNaoVazia(noArvoreCodAluno->esquerda, aluno);
        }
        return 1;
    } else {
        printf("Valor duplicado");
        return 0;
    }
    return 0;
}

NoArvoreCodAluno* alocaNoDaArvoreCodAluno(Aluno *aluno, NoArvoreCodAluno *esquerda, NoArvoreCodAluno *direita){
    NoArvoreCodAluno* no = (NoArvoreCodAluno*)malloc(sizeof(NoArvoreCodAluno));
    no->aluno = aluno;
    no->esquerda = esquerda;
    no->direita = direita;
    return no;
}

void arvoreCodAlunoInsere(NoArvoreCodAluno* pai, NoArvoreCodAluno* filho, int dir){
   if (dir){
      pai->direita = filho;
   }else{
      pai->esquerda = filho;
   }
   filho->pai = pai;
}

int arvoreCodAlunoRemoveNo(RaizDaArvoreCodAluno* raizDaArvoreCodAluno, Aluno *aluno){
    if (raizDaArvoreCodAluno->raiz == NULL) return 0;

    return arvoreCodAlunoRemoveNoRecursivamente(raizDaArvoreCodAluno->raiz, aluno);
}
    
int arvoreCodAlunoRemoveNoRecursivamente(NoArvoreCodAluno *noArvoreCodAluno, Aluno *aluno){
    if (noArvoreCodAluno == NULL) return 0;

    if (verificaIgualdadeEntreDoisAlunos(noArvoreCodAluno->aluno, aluno)){
        retiraONoDaArvoreCodAluno(noArvoreCodAluno);
        return 1;
    }

    if (getCodigoDoAluno(aluno) < getCodigoDoAluno(noArvoreCodAluno->aluno)){
        return arvoreCodAlunoRemoveNoRecursivamente(noArvoreCodAluno->esquerda, aluno);
    } else {
        return arvoreCodAlunoRemoveNoRecursivamente(noArvoreCodAluno->direita, aluno);
    }
}

void retiraONoDaArvoreCodAluno(NoArvoreCodAluno * filho){
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
        NoArvoreCodAluno *maior = encontraMaiorArvoreCodAluno(filho->esquerda);
        filho->aluno = maior->aluno;
        retiraONoDaArvoreCodAluno(maior);
        return;
    } else {
        NoArvoreCodAluno *menor = encontraMenorArvoreCodAluno(filho->direita);
        filho->aluno = menor->aluno;
        retiraONoDaArvoreCodAluno(menor);
        return;
    }
}

NoArvoreCodAluno*encontraMaiorArvoreCodAluno (NoArvoreCodAluno *noArvoreCodAluno){
    if (noArvoreCodAluno->direita == NULL) return noArvoreCodAluno;
    return encontraMaiorArvoreCodAluno(noArvoreCodAluno->direita);
}

NoArvoreCodAluno *encontraMenorArvoreCodAluno (NoArvoreCodAluno * noArvoreCodAluno){
    if (noArvoreCodAluno->esquerda == NULL) return noArvoreCodAluno;
    return encontraMenorArvoreCodAluno(noArvoreCodAluno->esquerda);
}


void liberaArvoreCodAluno(RaizDaArvoreCodAluno* raizDaArvoreCodAluno){
    if (raizDaArvoreCodAluno->raiz == NULL) return;
    liberaNoDaArvoreCodAluno(raizDaArvoreCodAluno->raiz);
    free(raizDaArvoreCodAluno);
}

void liberaNoDaArvoreCodAluno(NoArvoreCodAluno* noArvoreCodAluno){
    if (noArvoreCodAluno == NULL) return;
    liberaNoDaArvoreCodAluno(noArvoreCodAluno->esquerda);
    liberaNoDaArvoreCodAluno(noArvoreCodAluno->direita);
    free(noArvoreCodAluno);
}

void imprimeArvoreCodAluno(NoArvoreCodAluno* noArvoreCodAluno){
    if (noArvoreCodAluno == NULL) return;
    imprimeArvoreCodAluno(noArvoreCodAluno->esquerda);
    imprimeAluno(noArvoreCodAluno->aluno);
    imprimeArvoreCodAluno(noArvoreCodAluno->direita);
}