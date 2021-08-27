#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente Cliente;

typedef struct clientes Clientes;

Clientes* criaListaDeClientes();

Cliente* criaCliente(char nome[81], char cpf[16], char telefone[16]);

int verificaSeClienteCorreto(Cliente *clienteX, Cliente *clienteY);

int insereNaListaDeClientesVazia (Clientes* clientes, Cliente *cliente);

int insereNoInicioDaListaDeClientes(Clientes *clientes, Cliente *cliente);

int insereNoFinalDaListaDeClientes(Clientes *clientes, Cliente *cliente);

int listaDeClientesVazia (Clientes *clientes);

int tamanhoListaDeClientes(Clientes *clientes);

int removeClienteDaListaDeClientes(Clientes *clientes, int pos);

int destruirListaDeClientes(Clientes *clientes);

int buscarPosicaoClientePorCPF(Clientes *clientes, char cpf[16]);

Cliente* buscaClientePorCPF(Clientes *clientes, char cpf[16]);

void imprimeNomeCliente(Cliente* cliente);

void imprimeCPFCliente(Cliente* cliente);

void imprimeTelefoneCliente(Cliente* cliente);

void imprimeCliente(Cliente* cliente);

void imprimeListaDeClientes(Clientes *clientes);