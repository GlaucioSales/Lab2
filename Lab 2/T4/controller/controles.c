#include "controles.h"

void sair(Mesa ***mesas, Fila *fila, int linhas, int colunas){
    liberarMesas(mesas, linhas, colunas);
    liberarFila(fila);
    exit(0);
}

void imprimirDadosSobreMesa(Mesa ***mesas, int linhas, int colunas){
    int numeroDaMesa = solicitaInteiro("Qual o numero da mesa: ");
    Mesa *mesa = localizarMesaPeloNumero(mesas, linhas, colunas, numeroDaMesa);
    if (mesa == NULL) {
        printf("Nao conseguimos localizar esta mesa");
        return;
    }
    
    imprimeMesa(mesa);
}

void imprimirDadosSobreTodasAsMesas(Mesa ***mesas, int linhas, int colunas){
    imprimeTodasAsMesas(mesas, linhas, colunas);
}

void imprimirDadosSobreMesasVazias(Mesa ***mesas, int linhas, int colunas){
    imprimeTodasAsMesasVazias(mesas, linhas, colunas);
}

void cadastrarGrupoDePessoas(Mesa ***mesas, Fila *fila, int linhas, int colunas){
    int numeroDePessoasNoGrupo = solicitaInteiro("Quantas pessoa tem o grupo: ");
    int numeroDePessoasSemMesa = alocarGrupoNaMesa(mesas, linhas, colunas, numeroDePessoasNoGrupo);
    if (numeroDePessoasSemMesa > 0){
        Grupo *grupo = criaGrupo(numeroDePessoasSemMesa);
        inserirGrupoNaFila(fila, grupo);
    }
    
}

int alocarGrupoNaMesa(Mesa ***mesas, int linhas, int colunas, int numeroDePessoasNoGrupo){
    if (numeroDePessoasNoGrupo <= 0) return 0;
    
    Mesa *mesa = localizarMesaLivre(mesas, linhas, colunas);
    if (mesa == NULL) return numeroDePessoasNoGrupo;

    if (numeroDePessoasNoGrupo >= NUM_MAX_PESSOAS_MESA){
        colocarPessoasNaMesa(mesa, NUM_MAX_PESSOAS_MESA);
    } else {
        colocarPessoasNaMesa(mesa, numeroDePessoasNoGrupo);
    }

    alocarGrupoNaMesa(mesas, linhas, colunas, numeroDePessoasNoGrupo - NUM_MAX_PESSOAS_MESA);
}

void liberarMesa(Mesa ***mesas, Fila *fila, int linhas, int colunas){
    int numeroDaMesa = solicitaInteiro("Qual o numero da mesa: ");
    Mesa *mesa = localizarMesaPeloNumero(mesas, linhas, colunas, numeroDaMesa);
    if (mesa == NULL) {
        printf("Nao conseguimos localizar esta mesa");
        return;
    }
    liberarMesaQueEstavaOcupada(mesa);
    alocaPessoasDaFilaNasMesas(mesa, fila);
}

void alocaPessoasDaFilaNasMesas(Mesa *mesa, Fila *fila){
    if (filaVazia(fila)) return;
    
    Grupo* grupo = proximoGrupoDaFila(fila);
    int quantidadeDePessoasNesseGrupo = quantidadeDePessoasNoGrupo(grupo);

    if (quantidadeDePessoasNesseGrupo > NUM_MAX_PESSOAS_MESA){
        colocarPessoasNaMesa(mesa, NUM_MAX_PESSOAS_MESA);
        subtrairDoGrupoAsPessoaQueVaoParaAMesa(grupo, NUM_MAX_PESSOAS_MESA);
        return;
    }

    colocarPessoasNaMesa(mesa, quantidadeDePessoasNesseGrupo);
    retirarGrupoDaFila(fila);
}

void desistiuDeEsperar(Fila *fila){
    int  chaveDoGrupo = solicitaInteiro("\nInforme a chave do grupo que desistiu de esperar: ");
    if(retirarUmDeterminadoGrupoDaFila(fila, chaveDoGrupo)){
        printf("Grupo retirado com sucesso\n");
    } else {
        printf("Ocorreu um erro, tente novamente\n");
    }
}

void imprimirTodosOsGruposNaFinal(Fila *fila){
    imprimirFila(fila);
}

