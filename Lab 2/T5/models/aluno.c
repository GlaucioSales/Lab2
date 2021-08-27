#include "aluno.h"

struct aluno {
    int codAluno;
    char nomeAluno[81];
    float media;
    Aluno *proximo;
    Aluno *anterior;
};

struct alunos{
    int tamanho;
    Aluno* inicioDaLista;
    Aluno* finalDaLista;
};

Alunos* criaListaDeAlunos(){
	Alunos* novaLista = (Alunos*) malloc( sizeof(Alunos));
    novaLista->tamanho = 0;
    novaLista->inicioDaLista = NULL;
    novaLista->finalDaLista = NULL; 
	return novaLista;
}

Aluno* criaAluno(int codAluno,char nomeAluno[81], float media) {
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
    aluno->codAluno = codAluno;
    strcpy(aluno->nomeAluno, nomeAluno);
    aluno->media = media;
    aluno->proximo = NULL;
    aluno->anterior = NULL;
    return aluno;
}

int getCodigoDoAluno(Aluno *aluno){
    return aluno->codAluno;
}

char* getNomeDoAluno(Aluno *aluno){
    return aluno->nomeAluno;
}

float getMediaDoAluno(Aluno *aluno){
    return aluno->media;
}

int verificaIgualdadeEntreDoisAlunos(Aluno *alunoX, Aluno* alunoY){
    return alunoX->codAluno == alunoY->codAluno;
}

Aluno* getInicioDaListaDeAlunos(Alunos *alunos){
    return alunos->inicioDaLista;
}

Aluno* getProximoAluno(Aluno *aluno){
    return aluno->proximo;
}

int insereNaListaDeAlunosVazia (Alunos* alunos, Aluno *aluno){
    aluno->proximo = alunos->finalDaLista;
    aluno->anterior = alunos->inicioDaLista;
    alunos->inicioDaLista = aluno;   
    alunos->finalDaLista = aluno;   
    alunos->tamanho++;   
    return 0;   
}

int insereNoInicioDaListaDeAlunos(Alunos *alunos, Aluno *aluno){
    aluno->proximo = alunos->finalDaLista;
    aluno->anterior = NULL;
    alunos->inicioDaLista->anterior = aluno;
    alunos->inicioDaLista = aluno;
    alunos->tamanho++;
    return 0;
}

int insereNoFinalDaListaDeAlunos(Alunos *alunos, Aluno *aluno){
    aluno->proximo = NULL;
    aluno->anterior = alunos->finalDaLista;
    alunos->finalDaLista->proximo = aluno;   
    alunos->finalDaLista = aluno;   
    alunos->tamanho++;
    return 0;
}

int listaDeAlunosVazia (Alunos *alunos){
    if (alunos == NULL) return 0;
    if (alunos->tamanho == 0) return 1;
    return 0;
}

int tamanhoListaDeAlunos(Alunos *alunos){
    if (listaDeAlunosVazia(alunos) == 1) return 0;
    int contador = 0;
    Aluno* atual = alunos->inicioDaLista;
    while (atual != NULL){
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

int removeAlunoDaListaDeAlunos(Alunos *alunos, int pos){   
    if(listaDeAlunosVazia(alunos)) return -1;
    Aluno *elemento;   
   
    if(pos == 1){  
        elemento = alunos->inicioDaLista;   
        alunos->inicioDaLista = alunos->inicioDaLista->proximo;   
        if(alunos->inicioDaLista == NULL){
            alunos->finalDaLista = NULL;   
        }else{
            alunos->inicioDaLista->anterior= NULL;   
        }   
    }else if(pos == alunos->tamanho){ 
        elemento = alunos->finalDaLista;
        alunos->finalDaLista->anterior->proximo = NULL;
        alunos->finalDaLista = alunos->finalDaLista->anterior;
    }else {
        Aluno* atual = alunos->inicioDaLista;   
        for(int i = 1; i < pos; i++){
            atual = atual->proximo;
        };
        elemento = atual;   
        atual->anterior->proximo = atual->proximo;   
        atual->proximo->anterior = atual->anterior;   
    }   
    free(elemento->nomeAluno); 
    free(elemento);   
    alunos->tamanho--;   
    return 0;   
}  

int destruirListaDeAlunos(Alunos *alunos){   
    while(alunos->tamanho > 0){
        removeAlunoDaListaDeAlunos(alunos, 1);
    }
    free(alunos);
    return 1;
}

int buscarPosicaoAlunoPorCodigo(Alunos *alunos, int codAluno){
	if (listaDeAlunosVazia(alunos)) return 0;
    
    int contador = 0;
    Aluno *atual = alunos->inicioDaLista;
	while(atual != NULL){
        contador++;
        if (atual->codAluno == codAluno){
            return contador;
        }
		atual = atual->proximo;
	}
}

Aluno* buscaAlunoPorCodigo(Alunos *alunos, int codAluno){
    if (listaDeAlunosVazia(alunos)){
        return NULL;
    }
    Aluno *atual = alunos->inicioDaLista;
	while(atual != NULL){
        if (atual->codAluno == codAluno){
            return atual;
        }
		atual = atual->proximo;
	}
}

void imprimeCodigoAluno(Aluno* aluno){
    printf("Codigo do aluno: %d\n", aluno->codAluno);
}

void imprimeNomeAluno(Aluno* aluno){
    printf("Nome do aluno: %s\n", aluno->nomeAluno);
}

void imprimeMediaAluno(Aluno *aluno){
    printf("Media do aluno: %f\n", aluno->media);
}

void imprimeAluno(Aluno* aluno){
    imprimeCodigoAluno(aluno);
    imprimeNomeAluno(aluno);
    imprimeMediaAluno(aluno);
}

void imprimeListaDeAlunos(Alunos *alunos) {
	if (listaDeAlunosVazia(alunos)){
        printf("\n\nVerificamos ao Listar os Alunos que a lista de alunos esta vazia\n\n");
        return;
    }
    Aluno *atual;
    atual = alunos->inicioDaLista;
	while(atual != NULL){
        printf("\n\n");
		imprimeAluno(atual);
		atual = atual->proximo;
	}
}
