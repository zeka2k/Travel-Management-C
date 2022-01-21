//
// Created by ACER-PC on 08/01/2022.
//

#ifndef AGORA_E_DE_VEZ_PROJETO_H
#define AGORA_E_DE_VEZ_PROJETO_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX100 100

/**
 * @brief Lista ligada de clientes 1.A
 * NOTA: falta as funções inserir à cauda e à cabeça
 */
typedef struct data
{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct poi
{
    char *nome;
    char *infomacao;

} POI;
typedef struct pois
{
    POI *ppois;
    int poi_size;
    int current_poi;
} POIS;
typedef struct cidade
{
    char *informacao;
    char *nome;
    float x,y;
    POIS *pois;
} CIDADE;


typedef struct cidades
{
    CIDADE *pcidades;
    int ncidades;
    int size_cidades;
} CIDADES;

typedef struct viagem
{
    int id_viagem;
    DATA * date;
    CIDADES * pcidades;
} VIAGEM;
typedef struct viagens
{

    VIAGEM *pviagens;
    int size_viagem;
    int nviagens;
} VIAGENS;
typedef struct cliente
{
    VIAGENS  *viagens;//apontador pa viagem
    char *identificaco;
    int  contacto;
    char* dataNascimento;
    char *moradaFiscal;
    int NIF;
    struct cliente *pnext;//sequalahr fazer uma dupla
} CLIENTE;

typedef struct clientes
{
    CLIENTE *pfirst;
    int nclientes;
} CLIENTES;

typedef struct informacao_ag{
    int **populacao_atual;  //matriz da populacao atual
    int **populacao_seguinte;//matrix da proxima populacao
    int *individuo_mais_apto;//array com as posicoes ordenadas de aptidao maior para menor
    float *aptidao;
    struct informacao_ag *pnext,*pbefore;
}INFORMACAO_AG;
typedef struct lista_informacao_ag{
    INFORMACAO_AG *phead,*ptail;
    int size;
}LISTA_INFORMACAO_AG;
typedef struct ag
{

    int **populacao_inicial;
    float **distancias;
    LISTA_INFORMACAO_AG * plista;//lista ligada para recolher informacao de cada geracao

}AG;
typedef struct parametros_ag
{
    int p;//populacao inicial tem de ser par
    float q;//probabilidade de mutacao de gene
    int e;//numero de individos que passam por elitismo tem de ser par
    int g;//numero de geraçoes criadas
    int n;//numero de cidades de cada individuo

}PARAMETROS_AG;
int main_project();
/*-----------------------------------ESCRITA / LEITURA-------------------------*/
CLIENTES fazer_relatorio();
void save_clientes_relatorio_txt(CLIENTES cs, char filename[]);
void save_clientes_txt2(CLIENTES cs, char filename[]);
void read_clientes_txt2(CLIENTES *cs, char filename[]);
void save_bin(char filename[], CLIENTES cs);
void read_bin(char filename[], CLIENTES *cs);

/*-----------------------------------EDIÇIAO-----------------------------------*/
void edit_relatorio_cidade_viagem(CLIENTES *pcs, int NIF);
void editar_viagem_cliente(CLIENTE *pcliente, int id_viagem, VIAGEM *nova);
void editar_viagem_dynarray_viagens(VIAGEM *pcs, char *antigo, CIDADE *nova);
void editar_informacao_cidade(CIDADES *pcs, char *nome, char *informacao);
void edit_relatorio_cliente_viagem(CLIENTES *pcs);
/*-----------------------------------CONSULTA-----------------------------------*/
void consulta_viagem_cliente(CLIENTE pc);
void consultar_viagem_cidade(VIAGENS vg, char *nome);
void consultar_viagem_poi(VIAGENS vg, char *nome);

/*-----------------------------------LISTA LIGADA CLIENTES-----------------------------------*/
void insert_cliente_ordered(CLIENTES *pcs, char *identificaco, int contacto, char *dataNascimento, char *moradaFiscal, int NIF);
void remove_cliente(CLIENTES *pcs, int NIF);
CLIENTE *find_cliente(CLIENTES *clientes, int NIF);
CLIENTE *find_cliente_bin_search(CLIENTES *clientes, int NIF);
void print_clientes(CLIENTES cs);

/*-----------------------------------ARRAY DINAMICO VIAGENS-----------------------------------*/
void create_dynarray_viagens(VIAGENS *pcs, int intsize, CLIENTE *pct);
void insert_viagem_dynarray_viagens_data(VIAGENS *pcs, int id_viagem, DATA data);
VIAGEM remove_viagem_dynarray_viagens(VIAGENS *pcs, int id_viagem);
VIAGEM *find_viagem_dynarray_viagens(VIAGENS cs, int id_viagem);
void print_dynarray_viagens(VIAGENS cs);
int diferencna_data(DATA *data1, DATA *data2);

/*-----------------------------------ARRAY DINAMICO CIDADES-----------------------------------*/
void create_dynarray_cidades(CIDADES *pcs, int intsize);
void insert_cidade_dynarray_cidades_nome(CIDADES *pcs, float x, float y, char *informacao, char *nome);
CIDADE remove_cidade_dynarray_cidades(CIDADES *pcs, char *nome);
CIDADE *find_cidade_dynarray_cidades(CIDADES cs, char *nome);
void print_dynarray_cidades(CIDADES cs);
int comparar_nome(char *a, char *b);

/*-----------------------------------ARRAY DINAMICO POIS-----------------------------------*/
void insert_poi_dynarray_pois(POIS *pcs, char *nome, char *info);
void create_dynarray_poi(POIS *ppois, int intsize);
POI remove_poi_dynarray_pois(POIS *pcs, char *nome);
void print_dynarray_pois(POIS pois);
POI *find_poi_dynarray_pois(POIS cs, char *nome);
void criar_matriz_distancias(PARAMETROS_AG ag,AG *pag,CIDADES cd);
float calcular_distancia(float x ,float y,float x2,float y2);
void print_matrixNx100_float(float **mNx100, int lines, int columns);
void print_matrixNx100_int(int **mNx100, int lines, int columns);
void gerar_populacao_inicial(PARAMETROS_AG ag,AG *pag);
int* gerador_populacao(int size);
void verificar_se_populacao_ja_existe(int **populacao,int size);
float *calcular_aptidao(int **populacao,PARAMETROS_AG ag,AG *pag);
float aptidao(int individuo[],int size,AG *pag);
void insert_ag(LISTA_INFORMACAO_AG *ag,AG agg,PARAMETROS_AG param);
void individuo_mais_apto(INFORMACAO_AG *infag,PARAMETROS_AG ag);
INFORMACAO_AG * find_geracao_id(LISTA_INFORMACAO_AG ag,int id);
int  * find_geracao_aptidao_superior(LISTA_INFORMACAO_AG ag,float aptidao);
void gerar_populacao_seguinte(PARAMETROS_AG ag,INFORMACAO_AG *infag);
void inserir_elitismo(INFORMACAO_AG *infag,PARAMETROS_AG ag,int **populacao);
void inserir_pai_filhos(INFORMACAO_AG *infag,PARAMETROS_AG ag,int **populacao);
void pai_filho(int *pai1,int *pai2,PARAMETROS_AG ag);
void fazer_mutacao(int *pai,PARAMETROS_AG ag);
void print_ag(LISTA_INFORMACAO_AG ag,PARAMETROS_AG param);
void insert_parametros_ag(PARAMETROS_AG *ag, int pop, float mut, int elit, int ger, int ngenes);
#endif //AGORA_E_DE_VEZ_PROJETO_H
