//
// Created by ACER-PC on 08/01/2022.
//

#include "projeto.h"
/**
 * melhor individo minimiza as distancias;
 * calcular a aptidao para toda a populacao;
 * 2 A, 1 B => A A B (mais provavel sair A);
 * se tiver uma grande aptidao passa para a proxima selecao (helitismo);
 * comecar a estruturar o projeto (criar estruturas .h);
 * evitar funcoes grandes (usar pequenas funcoes dentro de funcoes);
 * nao ha menus;
 * ir vendo algoritmo;
 * criar um funcao para ver aptidao, uma para a distancia;
 *
 * user:
 *  -trip_history (id utilizador, cidades, data inicio/fim);
 *  -data_nascimento;
 *  -data_registo;
 *  -nif;
 *  -morada;
 *
 * cidade:
 *  -lat;
 *  -long;
 *  -POI (points of interest)
 *
 *
 * [A][B][C][D][E] -> conjunto de cidades (individuo) cada cidade é um gene
 * populaçao -> conjunto de individos [ [A][B][C][D][E] [A][C][B][D][E] [B][C][D][E][A] ] -> 1 populacao, 3 individuos, com 5 cidades cada um
 * o individuo visita as cidades em ciclo;
 *
 * Algoritmo Genético:
 * 1º gerar a populacao (sabendo set de cidades a visitar), gerar P individos (populacao), com N cidades (genes);
 * 2º sumatorio das distancias entre as cidades do individuo, quanto menor a distancia melhor a aptidao;
 * 3º selecionar pares de individuos para cruzar, e quais sao selecionados por elitismo para passar diretamento á proxima geracao sem cruzamento (rollete wheel (cruzam segundo a formula) e elitismo ( nao cruzam passar direto))
 * 4º cruzar e mutaçoes (proxima geraçao tera um combinaçao dos genes do pais sem estes serem repetidos) (pegar nos genes dos pais gerar um filho aleatorio e verificar se é diferente de ambos os pais);
 *      pai 1 -> [A][B][C][D][E]; pai 2 -> [A][D][B][C][E];
 *      filho 1 -> [C][D][B][A][F]; filho 2 -> [][][][][];
 * 5º mutaçoes : filho 1 -> [C][D][B][A][F]; apos mutaçao -> [A][D][B][C][F];
 * 6º repete apartir do requesito 2;
 *
 * requesito 1:
 *      [CLIENT]->[ ]->[ ]->[ ]->[ ] (lista ligada de clientes)
 *         ↓
 *      {[TRIP]} -> {[CITY][][][][]} (array dinamico de cidades)
 *      {  []  }        ↓
 *      {  []  }    {[POI]}   (array estatico ou array dinamico para points od interest)
 *      {  []  }    { [] }
 *      {  []  }    { [] }
 * (array dinamico para viagens)
 **/
int main_project()
{

     CLIENTES pcs={NULL,0};
     char path[]="C:\\Users\\ACER-PC\\Documents\\agora_e_de_vez\\clientes.txt";
     char filename[]="C:\\Users\\ACER-PC\\Documents\\agora_e_de_vez\\clientes.bin";
     char relatorio[]="C:\\Users\\ACER-PC\\Documents\\agora_e_de_vez\\clientes_relatorio.txt";
     //pcs=fazer_relatorio();
    /*-----------------------------------EDIÇIAO-----------------------------------*/
    // edit_relatorio_cliente_viagem(&pcs);
    //  edit_relatorio_cidade_viagem(&pcs, 333333333);
    //  editar_informacao_cidade(find_viagem_dynarray_viagens(*find_cliente(&pcs, 333333333)->viagens, 3)->pcidades, "Porto", "asdasdasd");
    //  save_clientes_relatorio_txt(pcs, relatorio);

    /*-----------------------------------ESCRITA / LEITURA-------------------------*/
    // save_clientes_txt2(pcs, path);
     read_clientes_txt2(&pcs, path);
     print_clientes(pcs);
    // save_clientes_bin(pcs,filename);
    // read_clientes_bin(&pcs, filename);

    /*---------------------------------Requesito/2--------------------------------*/
    /*PARAMETROS_AG param={0,0.0,0,0,0};
    insert_parametros_ag(&param,10,0.0001,2,30,5);
    CIDADES cd={NULL,0,0};
    insert_cidade_dynarray_cidades_nome(&cd,0.0,1.0," ","Antas");
    insert_cidade_dynarray_cidades_nome(&cd,0.0,2.0," ","Benfica");
    insert_cidade_dynarray_cidades_nome(&cd,0.0,3.0," ","Coimbra");
    insert_cidade_dynarray_cidades_nome(&cd,0.0,4.0," ","Faro");
    insert_cidade_dynarray_cidades_nome(&cd,0.0,5.0," ","Guimaraes");
    AG ag={NULL,NULL,NULL};
    criar_matriz_distancias(param,&ag,cd);
    gerar_populacao_inicial(param,&ag);
    LISTA_INFORMACAO_AG linfag={NULL,NULL,0};

    for (int i = 0; i <param.g ; i++) {
       insert_ag(&linfag,ag,param);
    }
    int *a=find_geracao_id(linfag,param.g-1)->individuo_mais_apto;

    for (int j = 0; j <param.n ; j++) {
        printf("%d|",find_geracao_id(linfag,param.g-1)->populacao_atual[a[0]][j]);
    }
    return 0;*/
}

/*-----------------------------------ESCRITA / LEITURA-------------------------*/
/*--->Requesito 1.G<---*/
/**
 * Função para criar um relatorio de todos os clientes.
 */
CLIENTES fazer_relatorio()
{
    /*---------------------------------CLIENTE 1------------------------------------------*/
    CLIENTES pcs = {NULL, 0};
    char filename[] = "C:\\Users\\ACER-PC\\Documents\\agora_e_de_vez\\clientes_relatorio.txt";
    insert_cliente_ordered(&pcs, "Jose Silva", 911111111, "21-03-1999", "Rua 1", 111111111);
    CLIENTE *pct = pcs.pfirst;
    create_dynarray_viagens(pct->viagens, 10, pcs.pfirst);

    /* VIAGEM 1 */
    DATA d1 = {11, 1, 2000};
    insert_viagem_dynarray_viagens_data(pct->viagens, 1, d1);
    VIAGEM *pvg = pct->viagens->pviagens;
    create_dynarray_cidades(pvg->pcidades, 10);
    /** CIDADE 1 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 41.1579, 8.6291, "Portugal", "Porto");
    CIDADE *pcd = pvg->pcidades->pcidades;
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Estadio do Dragao", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Via Catarina", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Ponte D.Luiz", "info");
    /** CIDADE 2 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 38.7223, 9.1393, "Portugal", "Lisboa");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Lisboa");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Estadio da Luz", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Torre de Belem", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Oceanario de Lisboa", "info");
    /** CIDADE 3 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 41.5454, 8.4265, "Portugal", "Braga");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Braga");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Estadio d", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Santuario de Nossa Senhora do Sameiro", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Elevador do Bom Jesus do Monte", "info");

    /* VIAGEM 2 */
    DATA d2 = {21, 3, 1999};
    insert_viagem_dynarray_viagens_data(pct->viagens, 2, d2);
    pvg = find_viagem_dynarray_viagens(*pct->viagens, 2);
    create_dynarray_cidades(pvg->pcidades, 10);
    /** CIDADE 1 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 51.5072, 0.1276, "Inglaterra", "Londres");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Londres");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "The British Museum", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Tower of London", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Natural History Museum", "info");
    /** CIDADE 2 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 41.9028, 12.4964, "Italia", "Roma");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Roma");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Colosseum", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Pantheon", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Trevi Fountain", "info");
    /** CIDADE 3 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 36.3932, 25.4615, "Grecia", "Santorini");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Santorini");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Red Beach", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Kamari Beach", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Perivolos", "info");

    /* VIAGEM 3 */
    DATA d3 = {21, 1, 1999};
    insert_viagem_dynarray_viagens_data(pct->viagens, 3, d3);
    pvg = find_viagem_dynarray_viagens(*pct->viagens, 3);
    create_dynarray_cidades(pvg->pcidades, 10);
    /** CIDADE 1 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 43.7384, 7.4246, "Monaco", "Monaco");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Monaco");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Monte Carlo Casino", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Exotic Garden of Monaco", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Saint Nicholas Cathedral", "info");
    /** CIDADE 2 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 40.4168, 3.7038, "Espanha", "Madrid");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Madrid");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Estadio Santiago Bernabeu", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Plaza Mayor", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Gran Via", "info");
    /** CIDADE 3 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 34.0522, 118.2437, "America do Norte", "Los Angels");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Los Angels");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Disneyland Park", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Los Angels Museum of Art", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Santa Monica Pier", "info");

    /*---------------------------------CLIENTE 2------------------------------------------*/
    insert_cliente_ordered(&pcs, "Rodrigo Branco", 922222222, "23-08-1999", "Rua 2", 222222222);
    pct = find_cliente(&pcs, 222222222);
    create_dynarray_viagens(pct->viagens, 10, pct);
    /** VIAGEM 1 **/
    DATA d4 = {21, 3, 1999};
    insert_viagem_dynarray_viagens_data(pct->viagens, 1, d4);
    pvg = find_viagem_dynarray_viagens(*pct->viagens, 1);
    create_dynarray_cidades(pvg->pcidades, 10);
    /** CIDADE 1 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 40.6405, 8.6538, "Portugal", "Aveiro");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Aveiro");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Praia da Barra", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Aveiro Museum", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Praia da Costa Nova", "info");
    /** CIDADE 2 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 40.7128, 74.0060, "America do Norte", "New York");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "New York");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Central Park", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Museum of Modern Art", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Statue of Liberty Nacional Monument", "info");
    /** CIDADE 3 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 35.6804, 139.7690, "Japao", "Tokyo");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Tokyo");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Senso-ji", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Meiji Jingu", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Shinjuku Gyoen Nacional Garden", "info");

    /** VIAGEM 2 **/
    DATA d5 = {21, 10, 2010};
    insert_viagem_dynarray_viagens_data(pct->viagens, 2, d5);
    pvg = find_viagem_dynarray_viagens(*pct->viagens, 2);
    create_dynarray_cidades(pvg->pcidades, 10);
    /** CIDADE 1 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 40.7128, 74.0060, "America do Norte", "New York");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "New York");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Central Park", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Museum of Modern Art", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Statue of Liberty Nacional Monument", "info");
    /** CIDADE 2 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 34.0522, 118.2437, "America do Norte", "Los Angels");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Los Angels");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Disneyland Park", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Los Angels Museum of Art", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Santa Monica Pier", "info");
    /** CIDADE 3 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 40.4168, 3.7038, "Espanha", "Madrid");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Madrid");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Estadio Santiago Bernabeu", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Plaza Mayor", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Gran Via", "info");

    /** VIAGEM 3 **/
    DATA d6 = {21, 12, 1970};
    insert_viagem_dynarray_viagens_data(pct->viagens, 3, d6);
    pvg = find_viagem_dynarray_viagens(*pct->viagens, 3);
    create_dynarray_cidades(pvg->pcidades, 10);
    /** CIDADE 1 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 35.6804, 139.7690, "Japao", "Tokyo");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Tokyo");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Senso-ji", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Meiji Jingu", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Shinjuku Gyoen Nacional Garden", "info");
    /** CIDADE 2 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 36.3932, 25.4615, "Grecia", "Santorini");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Santorini");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Red Beach", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Kamari Beach", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Perivolos", "info");
    /** CIDADE 3 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 43.7384, 7.4246, "Monaco", "Monaco");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Monaco");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Monte Carlo Casino", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Exotic Garden of Monaco", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Saint Nicholas Cathedral", "info");

    /*---------------------------------CLIENTE 3------------------------------------------*/
    insert_cliente_ordered(&pcs, "Ana Costa", 933333333, "08-10-2001", "Rua 3", 333333333);
    pct = find_cliente(&pcs, 333333333);
    create_dynarray_viagens(pct->viagens, 10, pct);
    /** VIAGEM 1 **/
    DATA d7 = {21, 3, 2021};
    insert_viagem_dynarray_viagens_data(pct->viagens, 1, d7);
    pvg = find_viagem_dynarray_viagens(*pct->viagens, 1);
    create_dynarray_cidades(pvg->pcidades, 10);
    /** CIDADE 1 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Aveiro");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Aveiro");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Estadio do Dragao", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Via Catarina", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Ponte D.Luiz", "info");
    /** CIDADE 2 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Porto");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Porto");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Estadio do Dragao", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Via Catarina", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Ponte D.Luiz", "info");
    /** CIDADE 3 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Benfica");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Benfica");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Estadio do Dragao", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Via Catarina", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Ponte D.Luiz", "info");

    /** VIAGEM 2 **/
    DATA d8 = {21, 10, 2015};
    insert_viagem_dynarray_viagens_data(pct->viagens, 2, d8);
    pvg = find_viagem_dynarray_viagens(*pct->viagens, 2);
    create_dynarray_cidades(pvg->pcidades, 10);
    /** CIDADE 1 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Aveiro");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Aveiro");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Estadio do Dragao", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Via Catarina", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Ponte D.Luiz", "info");
    /** CIDADE 2 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Porto");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Porto");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Estadio do Dragao", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Via Catarina", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Ponte D.Luiz", "info");
    /** CIDADE 3 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Benfica");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Benfica");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Estadio do Dragao", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Via Catarina", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Ponte D.Luiz", "info");

    /** VIAGEM 3 **/
    DATA d9 = {21, 12, 2013};
    insert_viagem_dynarray_viagens_data(pct->viagens, 3, d9);
    pvg = find_viagem_dynarray_viagens(*pct->viagens, 3);
    create_dynarray_cidades(pvg->pcidades, 10);
    /** CIDADE 1 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Aveiro");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Aveiro");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Estadio do Dragao", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Via Catarina", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Ponte D.Luiz", "info");
    /** CIDADE 2 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Porto");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Porto");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Estadio do Dragao", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Via Catarina", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Ponte D.Luiz", "info");
    /** CIDADE 3 **/
    insert_cidade_dynarray_cidades_nome(pvg->pcidades, 0.0, 0.0, "info", "Benfica");
    pcd = find_cidade_dynarray_cidades(*pvg->pcidades, "Benfica");
    create_dynarray_poi(pcd->pois, 10);
    /*** POI 1 ***/
    insert_poi_dynarray_pois(pcd->pois, "Estadio do Dragao", "info");
    /*** POI 2 ***/
    insert_poi_dynarray_pois(pcd->pois, "Via Catarina", "info");
    /*** POI 3 ***/
    insert_poi_dynarray_pois(pcd->pois, "Ponte D.Luiz", "info");

    save_clientes_relatorio_txt(pcs, filename);
    return pcs;
}
/**
 * Guarda toda a informação de todos os clientes num relatorio .txt.
 * @param cs - apontador para a lista ligada (CLIENTES).
 * @param filename - path do ficheiro .txt.
 */
void save_clientes_relatorio_txt(CLIENTES cs, char filename[])
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("ERRO %s\n", filename);
        return;
    }
    fprintf(fp, "Clientes: %d\n\n", cs.nclientes);
    CLIENTE *pr = cs.pfirst;
    for (int i = 0; i < cs.nclientes; i++)
    {
        fprintf(fp, "\n|------------------------------------CLIENTE[%d]------------------------------------|\n", i + 1);
        fprintf(fp, "NIF -> %d\nIDENTIFICACAO -> %s\nCONTACTO -> %d\nDATA NASCIMENTO -> %s\nMORADA FISCAL -> %s\n", pr->NIF, pr->identificaco, pr->contacto, pr->dataNascimento, pr->moradaFiscal);
        fprintf(fp, "\nHistorico de Viagens:\n");
        VIAGEM *vg = pr->viagens->pviagens;
        for (int j = 0; j < pr->viagens->nviagens; j++)
        {
            fprintf(fp, "\nviagem[%d]-> ", vg->id_viagem);
            fprintf(fp, "%d/%d/%d\n", vg->date->dia, vg->date->mes, vg->date->ano);
            CIDADE *cd = vg->pcidades->pcidades;
            for (int k = 0; k < vg->pcidades->ncidades; k++)
            {
                fprintf(fp, "\t->cidade[%d] || ", k + 1);
                fprintf(fp, "%s, %s, Cordenadas: %0.04fºN, %0.04fºW\n", cd->nome, cd->informacao, cd->x, cd->y);
                POI *poi = cd->pois->ppois;
                for (int l = 0; l < cd->pois->current_poi; l++)
                {
                    fprintf(fp, "\t\t||poi[%d] -> ", l + 1);
                    fprintf(fp, "%s, %s\n", poi->nome, poi->infomacao);
                    poi++;
                }
                fprintf(fp, "\n");
                cd++;
            }
            vg++;
        }
        pr = pr->pnext;
    }
    fclose(fp);
}
/*--->Requesito 1.F<---*/
/**
 * Guarda toda a informação num ficheiro .txt.
 * @param cs - apontador para a lista ligada (CLIENTES).
 * @param filename - path do ficheiro .txt.
 */
void save_clientes_txt2(CLIENTES cs, char filename[])
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("ERRO %s\n", filename);
        return;
    }
    CLIENTE *pr = cs.pfirst;
    fprintf(fp, "%d\n", cs.nclientes);
    for (int i = 0; i < cs.nclientes; i++)
    {
        fprintf(fp, "%d,%s,%d,%s,%s,\n", pr->NIF, pr->identificaco, pr->contacto, pr->dataNascimento, pr->moradaFiscal);
        VIAGEM *pviagem = pr->viagens->pviagens;
        fprintf(fp, "%d\n", pr->viagens->nviagens);
        for (int j = 0; j < pr->viagens->nviagens; j++)
        {
            fprintf(fp, "%d,%d,%d,%d\n", pviagem->id_viagem, pviagem->date->dia, pviagem->date->mes, pviagem->date->ano);
            CIDADE *pcidade = pviagem->pcidades->pcidades;
            fprintf(fp, "%d\n", pviagem->pcidades->ncidades);
            for (int k = 0; k < pviagem->pcidades->ncidades; k++)
            {
                fprintf(fp, "%s,%s,%0.1f,%0.1f\n", pcidade->nome, pcidade->informacao, pcidade->x, pcidade->y);
                POI *poi = pcidade->pois->ppois;
                fprintf(fp, "%d\n", pcidade->pois->current_poi);
                for (int l = 0; l < pcidade->pois->current_poi; l++)
                {
                    fprintf(fp, "%s,%s,\n", poi->nome, poi->infomacao);
                    poi++;
                }
                pcidade++;
            }
            pviagem++;
        }
        pr = pr->pnext;
    }
    fclose(fp);
}
/**
 * Le toda a informação num ficheiro .txt.
 * @param cs - apontador para a lista ligada (CLIENTES).
 * @param filename - path do ficheiro .txt.
 */
void read_clientes_txt2(CLIENTES *cs, char filename[])
{

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("ERRO %s\n", filename);
        return;
    }
    int size = 0;
    int size2 = 0;
    int size3 = 0;
    int size4 = 0;
    fscanf(fp, "%d", &size);
    char identificaco[100] = "";
    int contacto;
    char dataNascimento[100] = "";
    char moradaFiscal[100] = "";
    int NIF;
    int id_viagem;
    DATA date;
    char informacao[100];
    char nome[100];
    float x, y;
    for (int i = 0; i < size; i++)
    {
        fscanf(fp, "%d%*[,]%[^,]%*[,]%d%*[,]%[^,]%*[,]%[^,]%*[,]", &NIF, identificaco, &contacto, dataNascimento, moradaFiscal);
        insert_cliente_ordered(cs, identificaco, contacto, dataNascimento, moradaFiscal, NIF);
        CLIENTE *pcliente = cs->pfirst;
        fscanf(fp, "%d", &size2);

        for (int j = 1; j < cs->nclientes; j++)
        {
            pcliente = pcliente->pnext;
        }
        create_dynarray_viagens(pcliente->viagens, size2, pcliente);
        VIAGEM *pviagem = pcliente->viagens->pviagens;
        for (int k = 0; k < pcliente->viagens->size_viagem; k++)
        {
            fscanf(fp, "%d%*[,]%d%*[,]%d%*[,]%d", &id_viagem, &date.dia, &date.mes, &date.ano);
            insert_viagem_dynarray_viagens_data(pcliente->viagens, id_viagem, date);
            fscanf(fp, "%d", &size3);
            create_dynarray_cidades(pviagem->pcidades, size3);
            CIDADE *pcidade = pviagem->pcidades->pcidades;
            for (int j = 0; j < pviagem->pcidades->size_cidades; j++)
            {
                fscanf(fp, "%*[\n]%[^,]%*[,]%[^,]%*[,]%f%*[,]%f", nome, informacao, &x, &y);
                insert_cidade_dynarray_cidades_nome(pviagem->pcidades, x, y, informacao, nome);
                fscanf(fp, "%d", &size4);
                create_dynarray_poi(pcidade->pois, size4);
                POI *ppoi = pcidade->pois->ppois;
                for (int l = 0; l < pcidade->pois->poi_size; l++)
                {
                    fscanf(fp, "%*[\n]%[^,]%*[,]%[^,]%*[,]", nome, informacao);
                    insert_poi_dynarray_pois(pcidade->pois, nome, informacao);
                    ppoi++;
                }
                pcidade++;
            }
            pviagem++;
        }
    }
    fclose(fp);
}
/**
 * Guarda toda a informação num ficheiro .bin.
 * @param cs - apontador para a lista ligada (CLIENTES).
 * @param filename - path do ficheiro .bin.
 */
void save_bin(char filename[], CLIENTES cs)
{
    FILE *fp = NULL;
    fp = fopen(filename, "wb");

    if (fp == NULL)
    {
        printf("ERRO A ABRIR FICHEIRO %s PARA LEITURA!\n", filename);
        return;
    }
    CLIENTE *pr = cs.pfirst;
    fwrite(&cs.nclientes, sizeof(int), 1, fp);
    int size;
    for (int i = 0; i < cs.nclientes; i++)
    {

        fwrite(&pr->NIF, sizeof(int), 1, fp);
        size = strlen(pr->identificaco) + 1;
        fwrite(&size, sizeof(int), 1, fp);
        fwrite(pr->identificaco, sizeof(char), size, fp);
        fwrite(&pr->contacto, sizeof(int), 1, fp);
        size = strlen(pr->dataNascimento) + 1;
        fwrite(&size, sizeof(int), 1, fp);
        fwrite(pr->dataNascimento, sizeof(char), size, fp);
        size = strlen(pr->moradaFiscal) + 1;
        fwrite(&size, sizeof(int), 1, fp);
        fwrite(pr->moradaFiscal, sizeof(char), size, fp);
        VIAGEM *pviagem = pr->viagens->pviagens;
        fwrite(&pr->viagens->nviagens, sizeof(int), 1, fp);
        for (int j = 0; j < pr->viagens->nviagens; j++)
        {
            fwrite(&pviagem->id_viagem, sizeof(int), 1, fp);
            fwrite(&pviagem->date->dia, sizeof(int), 1, fp);
            fwrite(&pviagem->date->mes, sizeof(int), 1, fp);
            fwrite(&pviagem->date->ano, sizeof(int), 1, fp);
            CIDADE *pcidade = pviagem->pcidades->pcidades;
            fwrite(&pviagem->pcidades->ncidades, sizeof(int), 1, fp);
            for (int k = 0; k < pviagem->pcidades->ncidades; k++)
            {
                size = strlen(pcidade->nome) + 1;
                fwrite(&size, sizeof(int), 1, fp);
                fwrite(pcidade->nome, sizeof(char), size, fp);
                size = strlen(pcidade->informacao) + 1;
                fwrite(&size, sizeof(int), 1, fp);
                fwrite(pcidade->informacao, sizeof(char), size, fp);
                fwrite(&pcidade->x, sizeof(float), 1, fp);
                fwrite(&pcidade->y, sizeof(float), 1, fp);
                POI *poi = pcidade->pois->ppois;
                fwrite(&pcidade->pois->current_poi, sizeof(int), 1, fp);
                for (int l = 0; l < pcidade->pois->current_poi; l++)
                {

                    size = strlen(poi->nome) + 1;
                    fwrite(&size, sizeof(int), 1, fp);
                    fwrite(poi->nome, sizeof(char), size, fp);
                    size = strlen(poi->infomacao) + 1;
                    fwrite(&size, sizeof(int), 1, fp);
                    fwrite(poi->infomacao, sizeof(char), size, fp);
                    poi++;
                }
                pcidade++;
            }
            pviagem++;
        }
        pr = pr->pnext;
    }
    fclose(fp);
}
/**
 * Le do ficheiro .bin.
 * @param pcs - apontador para a lista ligada (CLIENTES).
 * @param filename - path do ficheiro .bin.
 */
void read_bin(char filename[], CLIENTES *cs)
{
    FILE *fp = NULL;
    fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        printf("ERRO A ABRIR FICHEIRO %s PARA LEITURA!\n", filename);
        return;
    }

    int size = 0;
    int size2 = 0;
    int size3 = 0;
    int size4 = 0;
    int sizechar = 0;
    char identificaco[100] = "";
    int contacto;
    char dataNascimento[100] = "";
    char moradaFiscal[100] = "";
    int NIF;
    int id_viagem;
    DATA date;
    char informacao[100];
    char nome[100];
    float x, y;
    fread(&size, sizeof(int), 1, fp);
    for (int i = 0; i < size; i++)
    {
        fread(&NIF, sizeof(int), 1, fp);
        fread(&sizechar, sizeof(int), 1, fp);
        fread(identificaco, sizeof(char), sizechar, fp);
        fread(&contacto, sizeof(int), 1, fp);
        fread(&sizechar, sizeof(int), 1, fp);
        fread(dataNascimento, sizeof(char), sizechar, fp);
        fread(&sizechar, sizeof(int), 1, fp);
        fread(moradaFiscal, sizeof(char), sizechar, fp);
        insert_cliente_ordered(cs, identificaco, contacto, dataNascimento, moradaFiscal, NIF);
        CLIENTE *pcliente = cs->pfirst;
        fread(&size2, sizeof(int), 1, fp);
        for (int j = 1; j < cs->nclientes; j++)
        {
            pcliente = pcliente->pnext;
        }
        create_dynarray_viagens(pcliente->viagens, size2, pcliente);
        VIAGEM *pviagem = pcliente->viagens->pviagens;
        for (int k = 0; k < pcliente->viagens->size_viagem; k++)
        {
            fread(&id_viagem, sizeof(int), 1, fp);
            fread(&date.dia, sizeof(int), 1, fp);
            fread(&date.mes, sizeof(int), 1, fp);
            fread(&date.ano, sizeof(int), 1, fp);
            insert_viagem_dynarray_viagens_data(pcliente->viagens, id_viagem, date);
            fread(&size3, sizeof(int), 1, fp);
            create_dynarray_cidades(pviagem->pcidades, size3);
            CIDADE *pcidade = pviagem->pcidades->pcidades;
            for (int j = 0; j < pviagem->pcidades->size_cidades; j++)
            {
                fread(&sizechar, sizeof(int), 1, fp);
                fread(nome, sizeof(char), sizechar, fp);
                fread(&sizechar, sizeof(int), 1, fp);
                fread(informacao, sizeof(char), sizechar, fp);
                fread(&x, sizeof(float), 1, fp);
                fread(&y, sizeof(float), 1, fp);
                insert_cidade_dynarray_cidades_nome(pviagem->pcidades, x, y, informacao, nome);
                fread(&size4, sizeof(int), 1, fp);
                create_dynarray_poi(pcidade->pois, size4);
                POI *ppoi = pcidade->pois->ppois;
                for (int l = 0; l < pcidade->pois->poi_size; l++)
                {
                    fread(&sizechar, sizeof(int), 1, fp);
                    fread(nome, sizeof(char), sizechar, fp);
                    fread(&sizechar, sizeof(int), 1, fp);
                    fread(informacao, sizeof(char), sizechar, fp);
                    insert_poi_dynarray_pois(pcidade->pois, nome, informacao);
                    ppoi++;
                }
                pcidade++;
            }
            pviagem++;
        }
    }
    fclose(fp);
}

/*-----------------------------------EDIÇIAO-----------------------------------*/
/**
 * Edita uma certa viagem de um dado cliente.
 * @param pcs - apontador para a lista ligada (CLIENTES).
 */
void edit_relatorio_cliente_viagem(CLIENTES *pcs)
{
    DATA d10 = {01, 01, 3000};
    VIAGEM viagem = {5, &d10, NULL};
    viagem.pcidades = (CIDADES *)malloc(sizeof(CIDADES));
    create_dynarray_cidades(viagem.pcidades, 10);
    insert_cidade_dynarray_cidades_nome(viagem.pcidades, 5.5, 5.5, "Alta", "Porquinho");
    create_dynarray_poi(find_cidade_dynarray_cidades(*viagem.pcidades, "Porquinho")->pois, 10);
    insert_poi_dynarray_pois(find_cidade_dynarray_cidades(*viagem.pcidades, "Porquinho")->pois, "gggg", "ffff");
    insert_cidade_dynarray_cidades_nome(viagem.pcidades, 5.5, 5.5, "Baixa", "Benfica");
    create_dynarray_poi(find_cidade_dynarray_cidades(*viagem.pcidades, "Benfica")->pois, 10);
    insert_poi_dynarray_pois(find_cidade_dynarray_cidades(*viagem.pcidades, "Benfica")->pois, "Leitao", "eeee");
    editar_viagem_cliente(find_cliente(pcs, 333333333), 1, &viagem);
}
/**
 * Edita uma certa cidade de uma dada viagem.
 * @param pcs - apontador para a lista ligada (CLIENTES).
 * @param NIF - NIF do cliente que fez a viagem.
 */
void edit_relatorio_cidade_viagem(CLIENTES *pcs, int NIF)
{
    CIDADE pcidade = {"Ola", "Antas", 10.0, 10.0, NULL};
    pcidade.pois = (POIS *)malloc(sizeof(POIS));
    create_dynarray_poi(pcidade.pois, 10);
    insert_poi_dynarray_pois(pcidade.pois, "Rabanadas", "aaaaa");
    insert_poi_dynarray_pois(pcidade.pois, "Leitao", "bbbbb");
    editar_viagem_dynarray_viagens(find_viagem_dynarray_viagens(*find_cliente(pcs, NIF)->viagens, 2), "Porto", &pcidade);
}
/**
 * Edita uma dada viagem no array dinamico de viagens.
 * @param pcs - apontador para uma viagem.
 * @param antigo - nome da cidade a ser editada.
 * @param nova - apontador para a nova cidade.
 */
void editar_viagem_dynarray_viagens(VIAGEM *pcs, char *antigo, CIDADE *nova)
{
    CIDADE *pc = find_cidade_dynarray_cidades(*pcs->pcidades, antigo);
    if (pc == NULL)
    {
        printf("Nao existe cidade com o nome %s\n", antigo);
        return;
    }
    remove_cidade_dynarray_cidades(pcs->pcidades, antigo);
    insert_cidade_dynarray_cidades_nome(pcs->pcidades, nova->x, nova->y, nova->informacao, nova->nome);
    pc = find_cidade_dynarray_cidades(*pcs->pcidades, nova->nome);
    create_dynarray_poi(pc->pois, 10);
    pc->pois = nova->pois;
}
/**
 * Edita a informação de uma dada cidade.
 * @param pcs - apontador para a lista ligada (CIDADES).
 * @param nome - nome da cidade a ser editada.
 * @param informacao - nova informaçao.
 */
void editar_informacao_cidade(CIDADES *pcs, char *nome, char *informacao)
{
    CIDADE *pc = find_cidade_dynarray_cidades(*pcs, nome);
    if (pc == NULL)
        return;

    pc->informacao = (char *)malloc(sizeof(char) * strlen(informacao) + 1);
    strcpy(pc->informacao, informacao);
}
/**
 * Edita uma dada viagem de um certo cliente.
 * @param pcliente - apontador para um cliente.
 * @param nome - nome da cidade a ser editada.
 * @param informacao - nova informaçao.
 */
void editar_viagem_cliente(CLIENTE *pcliente, int id_viagem, VIAGEM *nova)
{
    VIAGEM *pviagem = find_viagem_dynarray_viagens(*pcliente->viagens, id_viagem);
    if (pviagem == NULL)
        return;
    remove_viagem_dynarray_viagens(pcliente->viagens, id_viagem);
    insert_viagem_dynarray_viagens_data(pcliente->viagens, nova->id_viagem, *nova->date);
    find_viagem_dynarray_viagens(*pcliente->viagens, nova->id_viagem)->pcidades = nova->pcidades;
}

/*-----------------------------------LISTA LIGADA CLIENTES-----------------------------------*/
/*--->Requesito 1.A (IMPLEMENTADO)<---*/
/**
 * insere ordenadamente pelo NIF um cliente na lista ligada de clientes
 * @param pcs - apontador para a lista ligada (CLIENTES).
 * @param identificacao - identificacao do cliente
 * @param contacto - contacto de cliente
 * @param dataNascimento - data de nascimento cliente
 * @param moradaFiscal - morada fiscal do cliente
 * @param NIF - NIF do cliente
 */
void insert_cliente_ordered(CLIENTES *pcs, char *identificaco, int contacto, char *dataNascimento, char *moradaFiscal, int NIF)
{
    CLIENTE *temp = (CLIENTE *)malloc(sizeof(CLIENTE));
    CLIENTE *temp2;
    temp->viagens = (VIAGENS *)malloc(sizeof(VIAGENS));
    temp->viagens->pviagens = NULL;
    temp->viagens->nviagens = 0;
    temp->viagens->size_viagem = 0;
    temp->contacto = contacto;
    temp->dataNascimento = (char *)malloc(sizeof(char) * strlen(dataNascimento) + 1);
    strcpy(temp->dataNascimento, dataNascimento);
    temp->NIF = NIF;
    temp->identificaco = (char *)malloc(sizeof(char) * strlen(identificaco) + 1);
    strcpy(temp->identificaco, identificaco);
    temp->moradaFiscal = (char *)malloc(sizeof(char) * strlen(moradaFiscal) + 1);
    strcpy(temp->moradaFiscal, moradaFiscal);
    pcs->nclientes++;
    temp->pnext = NULL;

    if (pcs->pfirst == NULL)
    {
        pcs->pfirst = temp;
        return;
    }
    else
    {

        if (pcs->pfirst->NIF > NIF)
        {
            temp2 = pcs->pfirst;
            pcs->pfirst = temp;
            pcs->pfirst->pnext = temp2;
            return;
        }
        CLIENTE *current = pcs->pfirst;
        while (current->pnext != NULL && current->NIF < NIF)
        {
            temp2 = current;
            current = current->pnext;
        }
        if (current->NIF > NIF)
        {

            temp2->pnext = temp;
            temp->pnext = current;

            return;
        }
        if (current->pnext == NULL)
        {
            current->pnext = temp;
            current->pnext->pnext = NULL;
            return;
        }
    }
}
/**
 * Imprime toda a informação da lista ligada de clientes.
 * @param cs - apontador para a lista ligada (CLIENTES).
 */
void print_clientes(CLIENTES cs)
{
    CLIENTE *pc = cs.pfirst;
    for (int i = 0; i < cs.nclientes; i++)
    {
        if (pc->identificaco != NULL)
        {
            printf("CLIENTE[%d] || NIF -> %d; IDENTIFICACAO -> %s; CONTACTO -> %d, DATA NASCIMENTO -> %s, MORADA FISCAL -> %s\n", i + 1, pc->NIF, pc->identificaco, pc->contacto, pc->dataNascimento, pc->moradaFiscal);
            print_dynarray_viagens(*pc->viagens);
            pc = pc->pnext;
        }
        else
            return;
    }
}
/**
 * Remove um dado cliente.
 * @param pcs - apontador para a lista ligada (CLIENTES).
 * @param NIF - NIF do cliente.
 */
void remove_cliente(CLIENTES *pcs, int NIF)
{
    CLIENTE *pcl = find_cliente(pcs, NIF);
    CLIENTE *temp;
    if (pcl != NULL)
    {
        if (pcl == pcs->pfirst)
        {
            printf("CLIENTE -> %s;|| NIF -> %d; Foi removido com sucesso\n", pcl->identificaco, pcl->NIF);
            pcs->pfirst = pcl->pnext;
            pcs->nclientes--;
            return;
        }
        if (pcl->pnext->pnext == NULL)
        {
            printf("CLIENTE -> %s;|| NIF -> %d; Foi removido com sucesso\n", pcl->pnext->identificaco, pcl->pnext->NIF);
            pcl->pnext = NULL;
            pcs->nclientes--;
            return;
        }
        printf("CLIENTE -> %s;|| NIF -> %d; Foi removido com sucesso\n", pcl->pnext->identificaco, pcl->pnext->NIF);
        pcl->pnext = pcl->pnext->pnext;
        pcs->nclientes--;

        return;
    }
    printf("Nao existe esse cliente com o %d\n", NIF);
}
/**
 * Encontra um dado cliente.
 * @param clientes - apontador para a lista ligada (CLIENTES).
 * @param NIF - NIF do cliente.
 */
CLIENTE *find_cliente(CLIENTES *clientes, int NIF)
{
    CLIENTE *current = clientes->pfirst;
    if (current->NIF == NIF)
        return current;
    current = current->pnext;
    while (current != NULL)
    {
        if (current->NIF == NIF)
            return current;
        if (current->NIF > NIF)
            break;
        current = current->pnext;
    }
    return NULL;
}
/**
 * Encontra um dado cliente usando binary search.
 * @param clientes - apontador para a lista ligada (CLIENTES).
 * @param NIF - NIF do cliente.
 */
CLIENTE *find_cliente_bin_search(CLIENTES *clientes, int NIF)
{
    int first, last, middle;

    first = 0;
    last = clientes->nclientes;
    middle = (first + last) / 2;

    while (first <= last)
    {
        CLIENTE *pmiddle = clientes->pfirst;

        for (int i = 0; i < middle - 1; i++)
        {
            pmiddle = pmiddle->pnext;
        }

        if (pmiddle->NIF < NIF)
            first = middle + 1;
        else if (pmiddle->NIF == NIF)
        {
            return pmiddle;
        }
        else
            last = middle - 1;
        middle = (first + last) / 2;
    }
    if (first > last)
    {
        printf("Not found! %d is not present in the list.\n", NIF);
        return NULL;
    }
    return 0;
}

/*-----------------------------------ARRAY DINAMICO VIAGENS-----------------------------------*/
/*--->Requesito 1.B (IMPLEMENTADO)<---*/
/**
 * Criar um array dinâmico de viagens com um dado tamanho inicial.
 * @param pcs - apontador para o array (VIAGENS).
 * @param initsize - tamanho inicial do array dinâmico de viagens.
 */
void create_dynarray_viagens(VIAGENS *pcs, int intsize, CLIENTE *pct)
{
    pcs->pviagens = (VIAGEM *)calloc(intsize, sizeof(VIAGEM));
    pcs->size_viagem = intsize;
    pcs->nviagens = 0;
    pct->viagens = pcs;
}
/**
 * Insere ordenadamente pela data uma viagem no array dinâmico de todas as viagens.
 * @param pcs - apontador para o array (VIAGENS).
 * @param id_viagem - id da viagem a inserir.
 * @param data - data da viagem.
 */
void insert_viagem_dynarray_viagens_data(VIAGENS *pcs, int id_viagem, DATA data)
{
    int newSize = pcs->size_viagem + 10;
    int oldSize = pcs->size_viagem;

    VIAGEM *vg = NULL, *temp = NULL, temp2 = {0, NULL, NULL}, temp3 = {0, NULL, NULL}, v0 = {0, NULL, NULL};
    DATA *pd = (DATA *)malloc(sizeof(DATA));
    if (pcs->size_viagem == pcs->nviagens)
    {
        pcs->pviagens = (VIAGEM *)realloc(pcs->pviagens, newSize * sizeof(VIAGEM));
        pcs->size_viagem = newSize;
        vg = pcs->pviagens;

        for (int i = oldSize; i < newSize; i++)
        {
            *(vg + i) = v0;
        }
    }

    *pd = data;
    temp = pcs->pviagens;
    while (diferencna_data(temp->date, &data) != 0)
    {
        temp++;
    }
    temp2 = *temp;

    vg = temp;
    vg->date = pd;
    vg->id_viagem = id_viagem;
    vg->pcidades = (CIDADES *)malloc(sizeof(CIDADES));
    vg->pcidades->pcidades = NULL;
    vg->pcidades->size_cidades = 0;
    vg->pcidades->ncidades = 0;
    pcs->nviagens++;
    temp++;
    while (temp != pcs->pviagens + pcs->size_viagem)
    {
        temp3 = *temp;
        *temp = temp2;
        temp++;
        temp2 = temp3;
        if (temp->id_viagem == 0)
        {
            *temp = temp2;
            break;
        }
    }
}
/**
 * Ve qual a data mais recente.
 * @param d1 - apontador para a primeira data.
 * @param d2 - apontador para a segunda data.
 */
int diferencna_data(DATA *d1, DATA *d2)
{
    if (d1 == NULL)
    {
        return 0;
    }
    if (d1->ano > d2->ano)
        return 0;

    else if (d1->ano < d2->ano)
        return 1;

    if (d1->ano == d2->ano)
    {
        if (d1->mes > d2->mes)
            return 0;
        else if (d1->mes < d2->mes)
            return 1;
        else if (d1->dia > d2->dia)
            return 0;
        else if (d1->dia < d2->dia)
            return 1;

        return 1;
    }
    return 1;
}
/**
 * Imprime toda a informação do array dinamico de viagens.
 * @param cs - apontador para o array dinamico (VIAGENS).
 */
void print_dynarray_viagens(VIAGENS cs)
{
    VIAGEM *pvg = cs.pviagens;
    if (pvg == NULL)
        return;
    for (int i = 0; i < cs.nviagens; i++)
    {
        printf("viagem-[%d] ", i + 1);
        printf("%d/%d/%d id_viagem-%d\n", pvg->date->dia, pvg->date->mes, pvg->date->ano, pvg->id_viagem);
        print_dynarray_cidades(*pvg->pcidades);
        pvg++;
    }
}
/**
 * Remove uma dada viagem.
 * @param pcs - apontador para o array dinamico (VIAGENS).
 * @param id_viagem - id da viagem a remover.
 */
VIAGEM remove_viagem_dynarray_viagens(VIAGENS *pcs, int id_viagem)
{
    VIAGEM vg = {0, 0, NULL};
    VIAGEM *pvg = find_viagem_dynarray_viagens(*pcs, id_viagem);

    if (pvg != NULL)
    {
        vg = *pvg;
        while (pvg < (pcs->pviagens + pcs->size_viagem - 1))
        {
            *pvg = *(pvg + 1);
            pvg++;
        }
        if (pvg == pcs->pviagens + pcs->size_viagem - 1)
        {
            pvg->id_viagem = 0;
            pvg->date = NULL;
        }
        pcs->nviagens--;
    }

    return vg;
}
/**
 * Encontra uma dada viagem.
 * @param cs - apontador para o array dinamico(VIAGENS).
 * @param id_viagem - id da viagem a ser encontrada.
 */
VIAGEM *find_viagem_dynarray_viagens(VIAGENS cs, int id_viagem)
{
    VIAGEM *pst = cs.pviagens;
    if (pst == NULL)
    {
        return NULL;
    }
    for (int i = 0; (i < cs.nviagens); i++)
    {
        if (pst->id_viagem == id_viagem)
            return pst;
        pst++;
    }
    return NULL;
}

/*-----------------------------------ARRAY DINAMICO CIDADES-----------------------------------*/
/*--->Requesito 1.C (IMPLEMENTADO)<---*/
/**
 * Criar um array dinâmico de cidades com um dado tamanho inicial.
 * @param pcs - apontador para o array dinamico (CIDADES).
 * @param initsize - tamanho inicial do array dinâmico de cidades.
 */
void create_dynarray_cidades(CIDADES *pcs, int intsize)
{

    pcs->pcidades = (CIDADE *)calloc(intsize, sizeof(CIDADE));
    pcs->size_cidades = intsize;
    pcs->ncidades = 0;
}
/**
 * Insere uma viagem no array dinâmico de todas as cidades.
 * @param pcs - apontador para o array dinamico (CIDADES).
 * @param x - coordenada x da cidade.
 * @param y - coordenada y da cidade.
 * @param informacao - infomarção da cidades.
 * @param nome - nome da cidade.
 */
void insert_cidade_dynarray_cidades_nome(CIDADES *pcs, float x, float y, char *informacao, char *nome)
{
    int newSize = pcs->size_cidades + 10;
    int oldSize = pcs->size_cidades;

    CIDADE *vg = NULL, *temp = NULL, temp2 = {NULL, NULL, 0.0, 0.0, NULL}, temp3 = {NULL, NULL, 0.0, 0.0, NULL}, v0 = {NULL, NULL, 0.0, 0.0, NULL};
    if (pcs->size_cidades == pcs->ncidades)
    {
        pcs->pcidades = (CIDADE *)realloc(pcs->pcidades, newSize * sizeof(CIDADE));
        pcs->size_cidades = newSize;
        vg = pcs->pcidades;

        for (int i = oldSize; i < newSize; i++)
        {
            *(vg + i) = v0;
        }
    }

    temp = pcs->pcidades;

    while (comparar_nome(temp->nome, nome) != 0)
    {
        temp++;
    }
    temp2 = *temp;

    vg = temp;
    vg->nome = (char *)malloc(sizeof(char) * strlen(nome) + 1);
    strcpy(vg->nome, nome);
    vg->informacao = (char *)malloc(sizeof(char) * strlen(informacao) + 1);
    strcpy(vg->informacao, informacao);
    vg->y = y;
    vg->x = x;
    vg->pois = (POIS *)malloc(sizeof(POIS));
    vg->pois->poi_size = 0;
    vg->pois->ppois = NULL;
    vg->pois->current_poi = 0;
    pcs->ncidades++;
    temp++;
    while (temp != pcs->pcidades + pcs->size_cidades)
    {
        temp3 = *temp;
        *temp = temp2;
        temp++;
        temp2 = temp3;
        if (temp->nome == NULL)
        {
            *temp = temp2;
            break;
        }
    }
}
/**
 * Compara dois nomes.
 * @param a - nome a.
 * @param b - nome b.
 */
int comparar_nome(char *a, char *b)
{
    if (a == NULL)
        return 0;
    if (strcmp(a, b) > 0)
        return 0;
    return 1;
}
/**
 * Imprime toda a informação do array dinamico de cidades.
 * @param cs - apontador para o array dinamico (CIDADES).
 */
void print_dynarray_cidades(CIDADES cs)
{
    CIDADE *pc = cs.pcidades;
    if (pc == NULL)
        return;
    for (int i = 0; i < cs.ncidades; i++)
    {
        printf("cidade[%d] nome-%s informacao-%s x-%0.1f y-%0.1f\n", i + 1, pc->nome, pc->informacao, pc->x, pc->y);
        print_dynarray_pois(*pc->pois);
        pc++;
    }
}
/**
 * Encontra uma dada cidade.
 * @param cs - apontador para o array dinamico(CIDADES).
 * @param nome - nome da cidade a ser encontrada.
 */
CIDADE *find_cidade_dynarray_cidades(CIDADES cs, char *nome)
{
    CIDADE *pcd = cs.pcidades;
    if (pcd == NULL)
        return NULL;
    for (int i = 0; i < cs.ncidades; ++i)
    {
        if (strcmp(pcd->nome, nome) == 0)
            return pcd;
        else if (strcmp(pcd->nome, nome) > 0)
            return NULL;
        pcd++;
    }
    return NULL;
}
/**
 * Remove uma dada cidade.
 * @param pcs - apontador para o array dinamico (CIDADES).
 * @param nome - nome da cidade a remover.
 */
CIDADE remove_cidade_dynarray_cidades(CIDADES *pcs, char *nome)
{
    CIDADE vg = {NULL, NULL, 0.0, 0.0, NULL};
    CIDADE *pc = find_cidade_dynarray_cidades(*pcs, nome);
    if (pc == NULL)
    {
        printf("Nao existe cidade com o nome %s\n", nome);
        return vg;
    }
    vg = *pc;
    while (pc < (pcs->pcidades + pcs->size_cidades - 1))
    {
        *pc = *(pc + 1);
        pc++;
    }
    if (pc == pcs->pcidades + pcs->size_cidades - 1)
    {
        pc->nome = NULL;
        pc->y = 0.0;
        pc->x = 0.0;
        pc->pois = NULL;
    }
    pcs->ncidades--;
    return vg;
}

/*-----------------------------------ARRAY DINAMICO POIS-----------------------------------*/
/*--->Requesito 1.D (IMPLEMENTADO)<---*/
/**
 * Criar um array dinâmico de pois com um dado tamanho inicial.
 * @param pcs - apontador para o array dinamico (POIS).
 * @param initsize - tamanho inicial do array dinâmico de pois.
 */
void create_dynarray_poi(POIS *ppois, int intsize)
{

    ppois->ppois = (POI *)calloc(intsize, sizeof(POI));
    ppois->poi_size = intsize;
    ppois->current_poi = 0;
}
/**
 * Insere um poi no array dinâmico de todos os pois.
 * @param pcs - apontador para o array dinamico (POIS).
 * @param nome - nome do poi.
 * @param info - informação do poi.
 */
void insert_poi_dynarray_pois(POIS *pcs, char *nome, char *info)
{
    int newSize = pcs->poi_size + 10;
    int oldSize = pcs->poi_size;

    POI *poi = NULL, p0 = {NULL, NULL};

    if (pcs->poi_size == pcs->current_poi)
    {
        pcs->ppois = (POI *)realloc(pcs->ppois, newSize * sizeof(POI));
        pcs->poi_size = newSize;
        poi = pcs->ppois;

        for (int i = oldSize; i < newSize; i++)
        {
            *(poi + i) = p0;
        }
    }
    poi = pcs->ppois + pcs->current_poi;

    poi->nome = (char *)malloc(sizeof(char) * strlen(nome) + 1);
    strcpy(poi->nome, nome);
    poi->infomacao = (char *)malloc(sizeof(char) * strlen(info) + 1);
    strcpy(poi->infomacao, info);

    pcs->current_poi++;
}
/**
 * Imprime toda a informação do array dinamico de pois.
 * @param pois - apontador para o array dinamico (POIS).
 */
void print_dynarray_pois(POIS pois)
{

    POI *poi = pois.ppois;
    if (poi == NULL)
        return;

    for (int i = 0; i < pois.current_poi; i++)
    {
        printf("poi[%d] nome-%s | informacao-%s\n", i + 1, poi->nome, poi->infomacao);
        poi++;
    }
}
/**
 * Remove um dado poi.
 * @param pcs - apontador para o array dinamico (POIS).
 * @param nome - nome do poi a remover.
 */
POI remove_poi_dynarray_pois(POIS *pcs, char *nome)
{
    POI vg = {NULL, NULL};
    POI *pc = find_poi_dynarray_pois(*pcs, nome);
    if (pc == NULL)
    {
        printf("Nao existe poi com o nome %s\n", nome);
        return vg;
    }
    vg = *pc;
    while (pc < (pcs->ppois + pcs->poi_size - 1))
    {
        *pc = *(pc + 1);
        pc++;
    }
    if (pc == pcs->ppois + pcs->poi_size - 1)
    {
        pc->nome = NULL;
        pc->infomacao = NULL;
    }
    pcs->current_poi--;
    return vg;
}
/**
 * Encontra um dado poi.
 * @param cs - apontador para o array dinamico(POIS).
 * @param nome - nome do poi a ser encontrado.
 */
POI *find_poi_dynarray_pois(POIS cs, char *nome)
{
    POI *ppoi = cs.ppois;
    if (ppoi == NULL)
        return NULL;
    for (int i = 0; i < cs.current_poi; ++i)
    {
        if (strcmp(ppoi->nome, nome) == 0)
            return ppoi;
        ppoi++;
    }
    return NULL;
}

/*-----------------------------------CONSULTA-----------------------------------*/
/*--->Requesito 1.E (IMPLEMENTADO)<---*/
/**
 * Consulta as viagens de um cliente.
 * @param pc - apontador para um cliente.
 */
void consulta_viagem_cliente(CLIENTE pc)
{
    printf("%s\n", pc.identificaco);
    print_dynarray_viagens(*pc.viagens);
}
/**
 * Consulta se uma viagem passa numa dada cidade.
 * @param vg - apontador para o array dinamico de viagens.
 * @param nome - nome da cidade.
 */
void consultar_viagem_cidade(VIAGENS vg, char *nome)
{
    CIDADE *pcidade = NULL;
    VIAGEM *pviagem = vg.pviagens;
    for (int i = 0; i < vg.nviagens; i++)
    {
        pcidade = find_cidade_dynarray_cidades(*pviagem->pcidades, nome);
        if (pcidade != NULL)
        {
            printf("viagem com id-%d\n", pviagem->id_viagem);
            printf("cidade-%s x-%0.1f y-%0.1f descricao- %s \n", pcidade->nome, pcidade->x, pcidade->y, pcidade->informacao);
            print_dynarray_pois(*pcidade->pois);
        }
        pviagem++;
    }
}
/**
 * Consulta se uma viagem passa numa dado poi.
 * @param vg - apontador para o array dinamico de viagens.
 * @param nome - nome do poi.
 */
void consultar_viagem_poi(VIAGENS vg, char *nome)
{
    CIDADE *pcidade;
    VIAGEM *pviagem = vg.pviagens;
    for (int i = 0; i < vg.nviagens; i++)
    {
        pcidade = pviagem->pcidades->pcidades;
        for (int j = 0; j < pviagem->pcidades->ncidades; j++)
        {
            POI *ppoi = find_poi_dynarray_pois(*pcidade->pois, nome);
            if (ppoi != NULL)
            {
                printf("viagem com id-%d\n", pviagem->id_viagem);
                printf("cidade-%s\n", pcidade->nome);
                printf("Poi-%s\n", ppoi->nome);
            }

            pcidade++;
        }
        pviagem++;
    }
}

/*-----------------------------------REQUESITO 2-----------------------------------*/
/**
 * insere os parametros na estrutura PARAMETROS
 * @param ag - apontador para a estrutura PARAMETROS_AG.
 * @param pop - populacao inicial.
 * @param mut - probabilidade de mutacao de gene.
 * @param elit - numero de individos que passam por elitismo.
 * @param ger - numero de geraçoes criadas.
 * @param ngenes - numero de cidades de cada individuo.
 */
void insert_parametros_ag(PARAMETROS_AG *ag, int pop, float mut, int elit, int ger, int ngenes)
{
    float min = 0.00, max = 100.0;

    if (pop % 2 == 0)
        ag->p = pop;
    else
    {
        printf("Insira uma populacao com numero par\n");

    }

    if (min <= mut || mut >= max)
        ag->q = mut;
    else
    {
        printf("Insira uma probabilidade de mutacao entre 0 e 100 porcento\n");

    }

    if (elit % 2 == 0)
        ag->e = elit;
    else
    {
        printf("Insira um numero par de individos selecionados para elitismo\n");

    }

    ag->g = ger;
    ag->n = ngenes;

}
/**
 * Calcula a distancia entre cidades.
 * @param x1 - coordenada x da cidade 1.
 * @param y1 - coordenada y da cidade 1.
 * @param x2 - coordenada x da cidade 2.
 * @param y2 - coordenada y da cidade 2.
 */
float calcular_distancia(float x1, float y1, float x2, float y2)
{
    float res;
    return res = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
/**
 * Cria a matriz das distancias.
 * @param ag - estrutura PARAMETROS_AG.
 * @param pag - apontador para a estrutura AG.
 * @param cd - estrutura CIDADES.
 */
void criar_matriz_distancias(PARAMETROS_AG ag, AG *pag, CIDADES cd)
{ // https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
    int size = ag.n, len;
    float *ptr;

    len = sizeof(float *) * size + sizeof(float) * size * size;
    float **arr = (float **)malloc(len);
    CIDADE *pcidade = cd.pcidades;
    ptr = (float *)(arr + size);
    for (int i = 0; i < size; i++)
        arr[i] = (ptr + size * i);

    for (int i = 0; i < size; i++)
    {
        CIDADE *pcidade2 = cd.pcidades;
        for (int j = 0; j < size; j++)
        {
            if (i != j && i < j)
            {
                *(*(arr + i) + j) = calcular_distancia(pcidade->x, pcidade->y, pcidade2->x, pcidade2->y);
            }
            else
                *(*(arr + i) + j) = 0;
            pcidade2++;
        }
        pcidade++;
    }
    pag->distancias = arr;
}
/**
 * Imprime uma matrix de floats.
 * @param mNx100 - nome da matriz.
 * @param lines - numero de linhas.
 * @param columns - numero de colunas.
 */
void print_matrixNx100_float(float **mNx100, int lines, int columns)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%0.1f |", mNx100[i][j]);
        }
        printf("\n");
    }
}
/**
 * Imprime uma matrix de inteiros.
 * @param mNx100 - nome da matriz.
 * @param lines - numero de linhas.
 * @param columns - numero de colunas.
 */
void print_matrixNx100_int(int **mNx100, int lines, int columns)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d |", mNx100[i][j]);
        }
        printf("\n");
    }
}
/**
 * Gera um individo.
 * @param size - tamanho do individo.
 */
int *gerador_populacao(int size)
{
    int array[size];
    int *ppopulacao = (int *)malloc(sizeof(int) * size);
    int a = size;
    for (int i = 0; i < size; i++)
    {
        array[i] = i;
    }
    for (int j = 0; j < size; j++)
    {
        int b = rand() % a;
        ppopulacao[j] = array[b];
        if (b != size)
        {
            array[b] = array[a - 1];
        }
        a--;
    }
    return ppopulacao;
}
/**
 * Verifica se um individo ja existe numa dada populacao.
 * @param populacao - populacao a procurar o individo.
 * @param size - tamanha da populacao.
 */
void verificar_se_populacao_ja_existe(int **populacao, int size)
{
}
/**
 * Gera uma populacao inicial.
 * @param ag - estrutura PARAMETROS_AG.
 * @param pag - apontador para a estrutura AG.
 */
void gerar_populacao_inicial(PARAMETROS_AG ag, AG *pag)
{
    int c = ag.n, r = ag.p, len;
    int *ptr;
    len = sizeof(int *) * r + sizeof(int) * c * r;
    int **arr = (int **)malloc(len);
    ptr = (int *)(arr + r);
    for (int i = 0; i < r; i++)
        arr[i] = (ptr + c * i);
    for (int j = 0; j < ag.p; j++)
    {
        arr[j] = gerador_populacao(ag.n);
    }
    pag->populacao_inicial = arr;
    // print_matrixNx100_int(pag->populacao_inicial,r,c);
}
/**
 * Gera uma populacao seguinte.
 * @param ag - estrutura PARAMETROS_AG.
 * @param infag - apontador para a estrutura INFORMACAO_AG.
 */
void gerar_populacao_seguinte(PARAMETROS_AG ag, INFORMACAO_AG *infag)
{
    int c = ag.n, r = ag.p, len;
    int *ptr;
    len = sizeof(int *) * r + sizeof(int) * c * r;
    int **arr = (int **)malloc(len);
    ptr = (int *)(arr + r);
    for (int i = 0; i < r; i++)
        arr[i] = (ptr + c * i);
    inserir_elitismo(infag, ag, arr);
}
/**
 * Retorna o array das aptidoes.
 * @param populacao - matriz da populacao.
 * @param ag - estrutura ag.
 * @param pag - apontador para a estrutura AG.
 */
float *calcular_aptidao(int **populacao, PARAMETROS_AG ag, AG *pag)
{
    float *apt = (float *)malloc(sizeof(float) * ag.p);
    for (int i = 0; i < ag.p; i++)
    {
        apt[i] = aptidao(populacao[i], ag.n, pag);
    }
    return apt;
}
/**
 * Calcula a aptidao de um individuo.
 * @param individuo - individuo a calcular aptidao.
 * @param size - tamanho do individuo.
 * @param pag - apontador para a estrutura AG.
 */
float aptidao(int individuo[], int size, AG *pag)
{
    float distancia_total = 0;
    int a, b;
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            a = individuo[i];
            b = individuo[i + 1];
            if (a > b)
            { // como so tem a metade superiro da matriz das distancias feita o a tem de ser sempre menor que o b
                int temp = a;
                a = b;
                b = temp;
            }
            distancia_total += pag->distancias[a][b];
        }
        else
        {
            a = individuo[i];
            b = individuo[0];
            if (a > b)
            {
                int temp = a;
                a = b;
                b = temp;
            }
            distancia_total += pag->distancias[a][b];
        }
    }
    return 1 / distancia_total;
}
/**
 * Insere na lista uma geracao.
 * @param ag - apontador para a estrutura LISTA_INFORMACAO_AG.
 * @param agg - estrutura AG.
 * @param param - estrutura PARAMETROS_AG.
 */
void insert_ag(LISTA_INFORMACAO_AG *ag, AG agg, PARAMETROS_AG param)
{
    INFORMACAO_AG *temp = (INFORMACAO_AG *)malloc(sizeof(INFORMACAO_AG));
    temp->pnext = NULL;
    temp->pbefore = NULL;

    if (ag->phead == NULL)
    {
        ag->phead = temp;
        ag->ptail = temp;
        ag->phead->populacao_atual = agg.populacao_inicial;
        ag->phead->aptidao = calcular_aptidao(ag->phead->populacao_atual, param, &agg);
        individuo_mais_apto(ag->phead, param);
        ag->phead->populacao_seguinte = ag->phead->populacao_atual;
        ag->size++;
    }
    else if (ag->phead == ag->ptail)
    {
        ag->ptail = temp;
        ag->phead->pnext = ag->ptail;
        ag->ptail->pbefore = ag->phead;
        ag->ptail->populacao_atual = ag->phead->populacao_seguinte;
        ag->ptail->aptidao = calcular_aptidao(ag->ptail->populacao_atual, param, &agg);
        individuo_mais_apto(ag->ptail, param);
        ag->ptail->populacao_seguinte = ag->ptail->populacao_atual;
        ag->size++;
    }
    else
    {
        ag->ptail->pnext = temp;
        ag->ptail->pnext->pbefore = ag->ptail;
        ag->ptail = temp;
        ag->ptail->populacao_atual = ag->ptail->pbefore->populacao_seguinte;
        ag->ptail->aptidao = calcular_aptidao(ag->ptail->populacao_atual, param, &agg);
        individuo_mais_apto(ag->ptail, param);
        ag->ptail->populacao_seguinte = ag->ptail->populacao_atual;
        ag->size++;
    }
}
/**
 * Guarda na estrutura INFORMACAO_AG no array individuo mais apto os individuos ordenados pela aptidao.
 * @param infag - apontador para a estrutura INFORMACAO_AG.
 * @param ag - estrutura PARAMETROS_AG.
 */
void individuo_mais_apto(INFORMACAO_AG *infag, PARAMETROS_AG ag)
{
    int *indv = (int *)malloc(sizeof(int) * ag.p);
    float array[ag.p];
    for (int k = 0; k < ag.p; k++)
    {
        array[k] = infag->aptidao[k];
    }
    int size = ag.p;
    for (int i = 0; i < size; i++)
    {
        int max = 0;
        for (int j = 1; j < size; j++)
        {
            if (array[max] < array[j])
            {
                max = j;
            }
        }
        array[max] = 0;
        indv[i] = max;
    }
    infag->individuo_mais_apto = indv;
}
/**
 * Encontra uma geracao com um dado ID.
 * @param ag - estrutura LISTA_INFORMACAO_AG a encontrar a geracao.
 * @param id - id da geracao a encontrar.
 */
INFORMACAO_AG *find_geracao_id(LISTA_INFORMACAO_AG ag, int id)
{ // id=0 e a cabeca
    INFORMACAO_AG *pag = ag.phead;
    if (id > ag.size)
        return NULL;
    for (int i = 0; i < id; i++)
    {
        pag = pag->pnext;
    }
    return pag;
}
/**
 * Retorna um array com os ids das geracoes com aptidao superior a aptidao dada.
 * @param ag - estrutura LISTA_INFORMACAO_AG a encontrar a geracao.
 * @param aptidao - aptidao dada.
 */
int *find_geracao_aptidao_superior(LISTA_INFORMACAO_AG ag, float aptidao)
{ // retorna um array com as iteracoes que tÃªm aptidao superior a aptidao retorna null senao houber nenhum
    int array[ag.size];
    int size = 0;
    INFORMACAO_AG *pag = ag.phead;
    for (int i = 0; i < ag.size; i++)
    {
        if (pag->aptidao[0] >= aptidao)
        {
            array[size] = i;
            size++;
        }
    }
    if (size == 0)
        return NULL;
    int *arr = (int *)malloc(sizeof(int) * size);
    for (int j = 0; j < size; j++)
    {
        arr[j] = array[j];
    }
    return arr;
}
/**
 * Inseres por elitismo.
 * @param infag - apontador para a estrutura INFORMACAO_AG.
 * @param ag - estrutura AG.
 * @param populacao - matriz da populacao seguinte.
 */
void inserir_elitismo(INFORMACAO_AG *infag, PARAMETROS_AG ag, int **populacao)
{

    for (int i = 0; i < ag.e; i++)
    {
        populacao[i] = infag->populacao_atual[infag->individuo_mais_apto[i]];
    }
}
/**
 * Obtem um par de pais e gera um par de filhos.
 * @param pai1 - apontador para o array pai1.
 * @param pai2 - apontador para o array pai2.
 * @param ag - estrutura PARAMETROS_AG
 */
void pai_filho(int *pai1, int *pai2, PARAMETROS_AG ag)
{
    int *filho1 = (int *)malloc(sizeof(int) * ag.n);
    int *filho2 = (int *)malloc(sizeof(int) * ag.n);
    int b = rand() % ag.n - 1;
    for (int l = 0; l < ag.n; ++l)
    {
        filho1[l] = -1;
        filho2[l] = -1;
    }
    for (int i = b; i < b + 2; i++)
    {
        filho1[i] = pai1[i];
    }

    for (int j = 0; j < ag.n; j++)
    {

        if (pai2[j] != filho1[b] && pai2[j] != filho1[b + 1] && filho1[j] == -1)
        {
            filho1[j] = pai2[j];
        }
    }

    for (int k = 0; k < ag.n; ++k)
    {
        pai1[k] = filho1[k];
        pai2[k] = filho2[k];
    }
}
/**
 * Insere na populacao seguintes os filhos.
 * @param infag - apontador para a estrutura INFORMACAO_AG.
 * @param ag - estrutura ag.
 * @param populacao - apontador para a matriz populacao.
 */
void inserir_pai_filhos(INFORMACAO_AG *infag, PARAMETROS_AG ag, int **populacao)
{
    int pai1[ag.n], pai2[ag.n];
    for (int i = ag.e; i < ag.p; i = i + 2)
    {
        for (int j = 0; j < ag.n; j++)
        {
            pai1[j] = infag->populacao_atual[i][j];
            pai2[j] = infag->populacao_atual[i + 1][j];
        }
        pai_filho(pai1, pai2, ag);
        infag->populacao_atual[i] = pai1;
        infag->populacao_atual[i + 1] = pai2;
    }
}
/**
 * Faz mutacao.
 * @param pai - apontador para o pai.
 * @param ag - estrutura PARAMETROS_AG.
 */
void fazer_mutacao(int *pai, PARAMETROS_AG ag)
{
    float r = (float)rand() / (float)RAND_MAX;
    if (r < ag.q)
    {
        int temp = pai[0];
        pai[0] = pai[ag.n - 1];
        pai[ag.n - 1] = temp;
    }
}
/**
 * Imprime a lista ligada das geracoes.
 * @param ag - estrutura LISTA_INFORMACAO_AG.
 * @param param - estrutura PARAMETROS_AG.
 */
void print_ag(LISTA_INFORMACAO_AG ag, PARAMETROS_AG param)
{
    INFORMACAO_AG *infag = ag.phead;
    int c = param.n, r = param.p;
    for (int i = 0; i < ag.size; i++)
    {
        print_matrixNx100_int(infag->populacao_atual, r, c);
        printf("\n");
        print_matrixNx100_int(infag->populacao_seguinte, r, c);
        printf("\n");
        infag = infag->pnext;
    }
}