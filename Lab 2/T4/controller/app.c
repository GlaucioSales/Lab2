#include "app.h"

void app(){
    int linhas = solicitaInteiro("qual o nome de mesas horizontalmente: ");
    int colunas = solicitaInteiro("qual o nome de mesas verticalmente: ");
    Mesa ***mesas = alocaMatrizDeMesas(linhas, colunas);
    Fila *fila = criaFila();
    inicializarMesas(mesas, linhas, colunas);
    menuPrincial(mesas, fila, linhas, colunas);
}