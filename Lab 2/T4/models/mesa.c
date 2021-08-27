#include "mesa.h"

struct mesa {
    int numeroDaMesa;
    int quantidadeDePessoasSentadas;
    int numeroDaComanda;
    bool estaLivre;
};

Mesa*** alocaMatrizDeMesas(int linhas, int colunas){
    Mesa ***mesas = (Mesa***) malloc(linhas * sizeof(Mesa**));
    for (int i = 0; i < linhas; i++){
        mesas[i] = (Mesa**) malloc(colunas * sizeof(Mesa*));
    }
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            mesas[i][j] = (Mesa*) malloc(sizeof(Mesa));
        }
    }
    return mesas;
}

void liberarMesas(Mesa ***mesas, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
             free(mesas[i][j]);  
        }
    }
    for (int i = 0; i < linhas; i++){
        free(mesas[i]);
    }
    free(mesas);
}

void inicializarMesas(Mesa ***mesas, int linhas, int colunas){
    int contador = 0;
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            contador++;
            disponibilizarMesa(mesas[i][j], contador); 
        }
    }
}

void disponibilizarMesa(Mesa *mesa, int valor){
    mesa->numeroDaMesa = valor;
    mesa->quantidadeDePessoasSentadas = 0;
    mesa->numeroDaComanda = valor;
    mesa->estaLivre = true;
}

void liberarMesaQueEstavaOcupada(Mesa *mesa){
    mesa->quantidadeDePessoasSentadas = 0;
    mesa->estaLivre = true;
}

void imprimeNumeroDaMesa(Mesa *mesa){
    printf("Numero da mesa: %d \n", mesa->numeroDaMesa);
}

void imprimeQuantidadeDePessoasSentadas(Mesa *mesa){
    printf("Quantidades de pessoas sentadas na mesa: %d \n", mesa->quantidadeDePessoasSentadas);
}

void imprimeNumeroDaComanda(Mesa *mesa){
    printf("Numero da comanda: %d \n", mesa->numeroDaComanda);
}

void imprimeSeEstaLivre(Mesa *mesa){
    printf("Mesa Livre: %d \n", mesa->estaLivre);
}

void imprimeMesa(Mesa * mesa){
    printf("\n\n\n");
    imprimeNumeroDaMesa(mesa);
    imprimeQuantidadeDePessoasSentadas(mesa);
    imprimeNumeroDaComanda(mesa);
    imprimeSeEstaLivre(mesa);
}

void imprimeTodasAsMesas(Mesa ***mesas, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("\n\n\n");
            imprimeMesa(mesas[i][j]);
        }
    }   
}

void imprimeTodasAsMesasVazias(Mesa ***mesas, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (mesaEstaLivre(mesas[i][j])){
                imprimeMesa(mesas[i][j]);
            }
        }
    }   
}

bool mesaEstaLivre(Mesa *mesa){
    return mesa->estaLivre;
}

bool colocarPessoasNaMesa(Mesa *mesa, int quantidadeDePessoas){
    if (quantidadeDePessoas <= NUM_MAX_PESSOAS_MESA){
        mesa->quantidadeDePessoasSentadas = quantidadeDePessoas;
        mesa->estaLivre = false;
        return true;
    }
    return false;
}

Mesa* localizarMesaLivre(Mesa ***mesas, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (mesaEstaLivre(mesas[i][j])){
                return mesas[i][j];
            }
        }
    }
    return NULL;
}

Mesa* localizarMesaPeloNumero(Mesa ***mesas, int linhas, int colunas, int numeroDaMesa){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (mesas[i][j]->numeroDaMesa == numeroDaMesa){
                return mesas[i][j];
            }
        }
    }
    return NULL;
}