//
// Created by User on 23/12/2023.
//

#ifndef PROJETOAED5_MENU_H
#define PROJETOAED5_MENU_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include "Graph.h"
/// Classe que declara um menu
///
/// É criada uma interface para visualizar informações sobre uma rede de voos
/// @param g : Grafo no qual os vértices representam aeroportos e as arestas representam a companhia aérea de cada voo
/// @param nameToCodeAirport : um unordered_map que contém todos os pares de códigos e nomes de aeroportos existentes
/// @param cities : todas os nomes de cidades existentes
/// @param airlinesNames : todos os nomes das companhias aéreas existentes
/// @param airlinesCodes : todos os códigos das companhias aéreas existentes
class Menu {
private:
    Graph<Airport> *g;
    unordered_map<std::string,std::string> nameToCodeAirport;
    unordered_set<std::string> cities;
    unordered_set<std::string> airlinesNames;
    unordered_set<std::string> airlinesCodes;
public:
    /// Cria um grafo e as outras estruturas com as informações preenchidas
    /// @param graph : Grafo com as informações
    /// @param map : um unordered_map que contém todos os pares de códigos e nomes de aeroportos existentes
    /// @param city : todas os nomes de cidades existentes
    /// @param airlinesN : todos os nomes das companhias aéreas existentes
    /// @param airlinesC : todos os códigos das companhias aéreas existentes
    Menu(Graph<Airport> *graph,unordered_map<std::string,std::string> map,unordered_set<std::string> city,unordered_set<std::string> airlinesN,unordered_set<std::string> airlinesC);
    /// Obtem o vértice que corresponde ao aeroporto com o nome n
    /// @param n : nome do aerporto
    /// @return vértice correspondente do grafo
    Vertex<Airport>* getAirportByName(std::string n);
    /// Obtem o vértice que corresponde ao aeroporto com o código c
    /// @param c : código do aeroporto
    /// @return vértice correspondente do grafo
    Vertex<Airport>* getAirportByCode(std::string c);
    /// Verifica se uma companhia aérea existe
    /// @param airline : nome ou código da companhia aérea
    /// @return true se existir
    bool existAirline(std::string airline);
    /// Verifica se uma cidade existe através do unordered_set com os nomes das cidades
    /// @param c : nome da cidade
    /// @return true se existir
    bool existCity(std::string c);

    /// Interface principal onde é possível escolher várias opções
    void secBase();

    /// Interface que mostra o número total de voos e de aeroportos
    void numberOfAirportsInterface();
    /// Função que obtem o número total de aeroportos
    int numberOfAirports();
    /// Função que obtem o número total de voos
    int numberOfFlights();

    /// Interface que recebe um aeroporto
    void nFlightAirlineInAirportChoiceInterface();
    /// Interface que retorna o número de voos que partem desse aeroporto, de quantas companhias diferentes
    /// @param airport : vértice correspondente a esse aeroporto de partida
    void nFlightAirlineInAirportInterface(Vertex<Airport>* airport);
    /// Função que realiza esses cálculos
    /// @param airport : vértice correspondente a esse aeroporto de partida
    /// @return um par com o número de voos com esse aeroporto de origem e com o número de companhias diferentes
    pair<int,int> nFlightAirlineInAirport(Vertex<Airport>* airport);


    /// Interface que permite escolher visualizar todos os voos de uma companhia aérea ou de uma cidade
    void nFlightPerCityOrAirlineChoiceInterface();
    /// Caso cidade seja escolhida ///
    /// O utilizador pode escolher visualizar todos os voos de todas as cidades ou de apenas uma
    void nFlightPerCityInterface();
    /// Caso só queira visualizar apenas de uma cidade ///
    /// Escolher a cidade pretendida
    void nFlightPerCityInterfaceChoise();
    /// Mostra o número de voos dessa cidade
    /// @param city : cidade escolhida
    void nFlightPerCityOneInterface(std::string city);
    /// Função que calcula o número de voos de uma determinada cidade
    /// @param city : cidade escolhida
    /// @return número de voos
    int nFlightPerCityOne(std::string city);
    /// Caso queira visualizar de todas as cidades ///
    /// Mostra todos os voos por cidade
    void nFlightPerCityInterfaceAll();
    /// Função que calcula o número de voos por cidade
    /// @return conjunto de pares com a cidade e a respetiva contagem de voos
    /// Complexidade esperada : 0(n)
    map<std::string,int> nFlightPerCity();
    /// Caso companhia aérea seja escolhida ///
    /// O utilizador pode escolher visualizar todos os voos de todas as companhias ou de apenas uma
    void nFlightPerAirlineInterface();
    /// Caso só queira visualizar apenas de uma companhia ///
    /// Escolher a companhia pretendida
    void nFlightPerAirlineInterfaceChoise();
    /// Mostra o número de voos dessa companhia
    /// @param airline : companhia escolhida
    void nFlightPerAirlineOneInterface(std::string airline);
    /// Função que calcula o número de voos de uma determinada companhia
    /// @param airline : companhia escolhida
    /// @return número de voos
    int nFlightPerAirlineOne(std::string airline);
    /// Caso queira visualizar de todas as companhias aéreas ///
    /// Mostra todos os voos por companhia
    void nFlightPerAirlineInterfaceAll();
    /// Função que calcula o número de voos por companhia
    /// @return conjunto de pares com a companhia aérea e a respetiva contagem de voos
    map<std::string,int> nFlightPerAirline();


    /// Interface que mostra todos os países diferentes que um aeroporto ou uma cidade têm como destino (escolha do utilizador)
    void differentCountriesInterface();
    /// Caso escolha cidade ///
    /// Escolher a cidade pretendida
    void diffCountriesCityChoiseInterface();
    /// Mostrar os países que têm essa cidade como destino
    /// @param city : cidade escolhida
    void diffCountriesCityShowInterface(std::string city);
    /// Função que realiza esse cálculo
    /// @param city : cidade escolhida
    /// @return conjunto de pares com o país e a respetiva contagem de voos
    /// Complexidade esperada : 0(n^2)
    map<std::string,int> cityToCountries(std::string city);
    /// Caso escolha aeroporto ///
    /// Escolher o aeroporto pretendido
    void diffCountriesAirportChoiseInterface();
    /// Mostrar os países que têm esse aeroporto como destino
    /// @param airport : aeroporto escolhido
    void diffCountriesAirportShowInterface(Vertex<Airport>* airport);
    /// Função que realiza esse cálculo
    /// @param airport  : aeroporto escolhido
    /// @return conjunto de pares com o país e a respetiva contagem de voos
    map<std::string,int> airportToCountries(Vertex<Airport>* airport);


    /// Interface que permite visualizar o número de destinos (aeroportos, cidades, ou países) disponíveis para um determinado aeroporto
    /// Escolher o aeroporto
    void nDestinationsInterface();
    /// Escolher entre aeroporto, cidade e país como tipo de destino
    /// @param airport : vértice correspondente ao aeroporto escolhido
    void nDestinationsTypeInterface(Vertex<Airport>* airport);
    /// Com base na escolha do utilizador, escolher função a ser executada
    /// @param airport : vértice correspondente ao aeroporto escolhido
    /// @param num : opção escolhida pelo utilizador (aeroportos, cidades, ou países)
    void nDestinationsShowInterface(Vertex<Airport>* airport,int num);
    /// Caso tenha sido escolhido aeroportos
    /// @param airport : vértice correspondente ao aeroporto escolhido
    /// @return conjunto de pares com o nome de cada aeroporto disponível com o respetivo número de caminhos até lá
    /// Complexidade esperada : n * m, 0(n^2)
    map<std::string,int> nDestinationsAirports(Vertex<Airport>* airport);
    /// Caso tenha sido escolhido cidades
    /// @param airport : vértice correspondente ao aeroporto escolhido
    /// @return conjunto de pares com nome de cada cidade disponível com o respetivo número de caminhos até lá
    map<std::string,int> nDestinationsCities(Vertex<Airport>* airport);
    /// Caso tenha sido escolhido aeroportos
    /// @param airport : vértice correspondente ao aeroporto escolhido
    /// @return conjunto de pares com nome de cada país disponível com o respetivo número de caminhos até lá
    map<std::string,int> nDestinationsCountries(Vertex<Airport>* airport);


    /// Interface que permite visualizar o número de destinos alcançáveis (aeroportos, cidades, ou países) a partir de um certo aeroporto com um número máximo de paragens
    /// Escolher o aeroporto de partida
    void nReachableDestinationsInterface();
    /// Escolher o tipo de destino (aeroporto, cidade, ou país)
    /// @param airport : aeroporto escolhido
    void nReachableDestinationsTypeInterface(Vertex<Airport>* airport);
    /// Selecionar número máximo de escalas
    /// @param airport : aeroporto escolhido
    /// @param dest : tipo de destino escolhido
    void nReachableDestinationsStopsInterface(Vertex<Airport>* airport, int dest);
    /// Com base na escolha do utilizar, selecionar função a ser executada
    /// @param airport : aeroporto escolhido
    /// @param escalas : número máximo de escalas
    /// @param dest : tipo de destino escolhido
    /// @param tipo : aeroporto, cidade ou país
    void nReachableDestinationsShowAirports (Vertex<Airport>* airport, int escalas, int dest,std::string tipo);
    /// Caso tenha sido escolhido aeroportos
    /// @param airport : aeroporto escolhido
    /// @param k : número máximo de escalas
    /// @return conjunto de pares com o destino disponível e o número de caminhos até lá
    /// Complexidade esperada : n * m, 0(n^2)
    map<std::string,int> nReachableDestinationsAirports(Vertex<Airport>* airport,int k);
    /// Caso tenha sido escolhido cidades
    /// @param airport : aeroporto escolhido
    /// @param k : número máximo de escalas
    /// @return conjunto de pares com o destino disponível e o número de caminhos até lá
    map<std::string,int> nReachableDestinationsCities(Vertex<Airport>* airport,int k);
    /// Caso tenha sido escolhido países
    /// @param airport : aeroporto escolhido
    /// @param k : número máximo de escalas
    /// @return conjunto de pares com o destino disponível e o número de caminhos até lá
    map<std::string,int> nReachableDestinationsCountries(Vertex<Airport>* airport,int k);


    /// Interface que permite visualizar pares de aeroportos que têm entre eles a maior distância
    /// Mostra resultados
    void maxTripInterface();
    /// Função que faz esse cálculo
    /// @return um vetor com os pares de aeroportos com a maior distância, seguidos desse valor
    /// Complexidade esperada : n * m * o * p, O(n^4)
    pair<vector<pair<std::string,std::string>>,int>maxTrip();


    /// Interface que permite visualizar os n aeroportos com o maior número de voos
    /// Introduzir esse número
    void gratestKInterface();
    /// Mostra o resultado
    /// @param k : número de aeroportos para realizar o cálculo
    void gratestKShowInterface(int k);
    /// Função que realizar esse cálculo
    /// @param k : número de aeroportos
    /// @return um vetor de pares com o Aeroporto e o seu número de voos
    std::vector<pair<Airport, int>> nGreatestAirTrafficCapacity(int k);


    /// Interface que permite visualizar os aeroportos essenciais ao funcionamento da rede de voos
    /// Mostra o resultado
    void essentialAirportsInterface();
    /// Função que realiza esse cálculo
    /// @return conjunto de aeroportos que, se removidos, provocam que outros se tornem impossíveis de alcançar
    /// Complexidade esperada : n * m, O(n^2)
    set<std::string> essentialAirports();


    /// Visualizar a melhor opção de voos entre dois locais
    /// Interface que permite escolher a origem (com aeroporto, cidade ou coordenadas geográficas)
    void flightOptionsInterfaceStart();
    /// Interface que permite escolher o destino (com aeroporto, cidade ou coordenadas geográficas)
    /// @param i : opção escolhida para a origem
    void flightOptionsInterfaceTarget(int i);
    /// O utilizador pode decidir se tem companhias aéreas preferenciais ou não
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    void preferenceAirlineInterface(int i ,int d);
    /// Especificar nomes ou códigos das companhias preferenciais (caso tenha)
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    void preferenceAirlineChosingInterface(int i ,int d);
    /// O utilizador pode escolher o caminho com o menor número de companhias aéreas
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    void minimizeAirlinesInterface(int i ,int d,vector<std::string>airlines);
    /// Escolhe entre todas as combinações de dois possíveis (aeroporto, cidade e coordenadas geográficas)
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    void choose(int i ,int d,vector<std::string>airlines,bool minimize);


    /// Foram escolhidos um aeroporto origem e um aeroporto destino ///
    /// Escolher origem e destino
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    void AirportToAirportInterface(int i ,int d,vector<std::string>airlines,bool minimize);
    /// Mostrar resultado
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    /// @param v : vértice de origem
    /// @param d : vértice de destino
    void AirportToAirportInterfaceResult(int i ,int d,vector<std::string>airlines,bool minimize,Vertex<Airport>* v, Vertex<Airport>* b);
    /// Função para realizar esse cálculo sem companhias aéreas preferenciais
    /// @param v : vértice de origem
    /// @param d : vértice de destino
    /// @return lista do conjunto de voos possíveis
    /// Complexidade esperada : n * m * o, O(n^3)
    vector<vector<Flight>> AirportToAirport(Vertex<Airport>* v, Vertex<Airport>* b);
    /// Função para realizar esse cálculo com companhias aéreas preferenciais
    /// @param v : vértice de origem
    /// @param d : vértice de destino
    /// @return lista do conjunto de voos possíveis
    vector<vector<Flight>> AirportToAirportWF(Vertex<Airport>* a, Vertex<Airport>* b,vector<std::string>airlines);

    /// Foram escolhidos um aeroporto origem e uma cidade destino ///
    /// Escolher origem e destino
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    void AirportToCityInterface(int i ,int d,vector<std::string>airlines,bool minimize);
    /// Mostrar resultado
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    /// @param v : vértice de origem
    /// @param c : cidade de destino
    void AirportToCityInterfaceResult(int i ,int d,vector<std::string>airlines,bool minimize,Vertex<Airport>* v, std::string c);
    /// Função para realizar esse cálculo com companhias aéreas preferenciais
    /// @param v : vértice de origem
    /// @param c : cidade de destino
    /// @return lista do conjunto de voos possíveis
    vector<vector<Flight>> AirportToCity(Vertex<Airport>* v, std::string c,vector<std::string>airlines);

    /// Foram escolhidos um aeroporto origem e coordenadas geográficas de destino ///
    /// Escolher origem e destino
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    void AirportToGeoCordinatesInterface(int i, int d, vector<std::string>airlines,bool minimize);
    /// Mostrar resultado
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    /// @param v : vértice de origem
    /// @param lat1 : latitude da localização de destino
    /// @param long1 : longitude da localização de destino
    void AirportToGeoCordinatesInterfaceResult(int i, int d, vector<std::string>airlines,bool minimize,Vertex<Airport>* v,double lat1,double long1);
    /// @param v : vértice de origem
    /// @param lat1 : latitude da localização de destino
    /// @param long1 : longitude da localização de destino
    /// @param airlines : companhias aéreas preferenciais
    /// @return lista do conjunto de voos possíveis
    vector<vector<Flight>> AirportToGeoCordinates(Vertex<Airport>* v,double lat1,double long1,vector<std::string>airlines);

    /// Foram escolhidos uma cidade de origem e um aeroporto de destino
    /// Escolher origem e destino
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    void CityToAirportInterface(int i , int d ,vector<std::string>airlines,bool minimize);
    /// Mostrar resultado
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    /// @param c : cidade de origem
    /// @param v : vértice do aeroporto de destino
    void CityToAirportInterfaceResult(int i, int d,vector<std::string>airlines,bool minimize,std::string c, Vertex<Airport>* v);
    /// @param airlines : companhias aéreas preferenciais
    /// @param c : cidade de origem
    /// @param v : vértice do aeroporto de destino
    /// @return lista do conjunto de voos possíveis
    vector<vector<Flight>> CityToAirport(std::string c, Vertex<Airport>* v,vector<std::string>airlines);

    /// Foram escolhidas uma cidade de origem e uma cidade de destino
    /// Escolher origem e destino
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    void CityToCityInterface(int i, int d, vector<std::string>airlines,bool minimize);
    /// Mostrar resultado
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    /// @param c1 : cidade de origem
    /// @param c2 : cidade de destino
    void CityToCityInterfaceResult(int i, int d, vector<std::string>airlines,bool minimize,std::string c1, std::string c2);
    /// @param airlines : companhias aéreas preferenciais
    /// @param c1 : cidade de origem
    /// @param c2 : cidade de destino
    /// @return lista do conjunto de voos possíveis
    vector<vector<Flight>> CityToCity(std::string a, std::string b,vector<std::string>airlines);

    /// Foram escolhidas uma cidade de origem e coordenadas geográficas de destino
    /// Escolher origem e destino
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    void CityToGeoCordinatesInterface(int i, int d, vector<std::string>airlines,bool minimize);
    /// Mostrar resultado
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    /// @param c : cidade de origem
    /// @param lat1 : latitude da localização de destino
    /// @param long1 : longitude da localização de destino
    void CityToGeoCordinatesInterfaceResult(int i, int d, vector<std::string>airlines,bool minimize,std::string c, double lat1,double long1);
    /// @param c : cidade de origem
    /// @param lat1 : latitude da localização de destino
    /// @param long1 : longitude da localização de destino
    /// @param airlines : companhias aéreas preferenciais
    /// @return lista do conjunto de voos possíveis
    vector<vector<Flight>> CityToGeoCordinates(std::string c, double lat1,double long1,vector<std::string>airlines);

    /// Foram escolhidas coordenadas geográficas de origem e aeroporto de destino
    /// Escolher origem e destino
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    void GeoCordinatesToAirportInterface(int i,int d,vector<std::string>airlines,bool minimize);
    /// Mostrar resultado
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    /// @param lat1 : latitude da localização de origem
    /// @param long1 : longitude da localização de origem
    /// @param v : vértice do aeroporto de destino
    void GeoCordinatesToAirportInterfaceResult(int i,int d,vector<std::string>airlines,bool minimize,double lat1,double long1,Vertex<Airport>* v);
    /// @param lat1 : latitude da localização de origem
    /// @param long1 : longitude da localização de origem
    /// @param v : vértice do aeroporto de destino
    /// @param airlines : companhias aéreas preferenciais
    /// @return lista do conjunto de voos possíveis
    vector<vector<Flight>> GeoCordinatesToAirport(double lat1,double long1,Vertex<Airport>* v,vector<std::string>airlines);

    /// Foram escolhidas coordenadas geográficas de origem e uma cidade de destino
    /// Escolher origem e destino
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    void GeoCordinatesToCityInterface(int i,int d,vector<std::string>airlines,bool minimize);
    /// Mostrar resultado
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    /// @param lat1 : latitude da localização de origem
    /// @param long1 : longitude da localização de origem
    /// @param c : cidade de destino
    void GeoCordinatesToCityInterfaceResult(int i,int d,vector<std::string>airlines,bool minimize,double lat1,double long1,std::string c);
    /// @param lat1 : latitude da localização de origem
    /// @param long1 : longitude da localização de origem
    /// @param c : cidade de destino
    /// @param airlines : companhias aéreas preferenciais
    /// @return lista do conjunto de voos possíveis
    vector<vector<Flight>> GeoCordinatesToCity(double lat1,double long1,std::string c,vector<std::string>airlines);

    /// Foram escolhidas coordenadas geográficas de origem e coordenadas geográficas de destino
    /// Escolher origem e destino
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    void GeoCordinatesToGeoCordinatesInterface(int i,int d,vector<std::string>airlines,bool minimize);
    /// Mostrar resultado
    /// @param i : opção escolhida para a origem
    /// @param d : opção escolhida para o destino
    /// @param airlines : companhias aéreas preferenciais
    /// @param minimize : true caso o utilizador tenha escolhido minimizar o caminho
    /// @param lat1 : latitude da localização de origem
    /// @param lat2 : latitude da localização de destino
    /// @param long1 : longitude da localização de origem
    /// @param long2 : latitude da localização de destino
    void GeoCordinatesToGeoCordinatesInterfaceResult(int i,int d,vector<std::string>airlines,bool minimize,double lat1,double lat2,double long1,double long2);
    /// @param lat1 : latitude da localização de origem
    /// @param lat2 : latitude da localização de destino
    /// @param long1 : longitude da localização de origem
    /// @param long2 : latitude da localização de destino
    /// @param airlines : companhias aéreas preferenciais
    /// @return lista do conjunto de voos possíveis
    vector<vector<Flight>> GeoCordinatesToGeoCordinates(double lat1,double lat2,double long1,double long2,vector<std::string>airlines);

    /// Função geral usada para descobrir os melhores voos de uma lista de aeroportos para outra lista dos mesmos
    /// @param s : fila de aeroportos de partida
    /// @param t : fila de aeroportos de chegada
    /// @return lista do conjunto de voos possíveis
    /// Complexidade esperada : n * m * o, O(n^3)
    vector<vector<Flight>> ListAirportToListAirport(queue<Vertex<Airport>*> s, queue<Vertex<Airport>*> t); // General function used in almost every case
    /// Função geral usada para descobrir os melhores voos de uma lista de aeroportos para outra lista dos mesmos tendo em conta um filtro de companhias
    /// @param s : fila de aeroportos de partida
    /// @param t : fila de aeroportos de chegada
    /// @param airlines : lista das únicas companhias pelas quais pode haver viagem
    /// @return lista do conjunto de voos possíveis tendo em conta as companhias
    vector<vector<Flight>> ListAirportToListAirportWF(queue<Vertex<Airport>*> s, queue<Vertex<Airport>*> t,vector<std::string>airlines); // With airline filter
    /// Filtra os voos de modo a reduzir ao máximo o número de companhias diferentes usadas nas viagens
    /// @param flights : lista do conjunto de voos possíveis
    void minimizeAirlines(vector<vector<Flight>> &flights); // To minimize the diferent airlines in the answer
};


#endif //PROJETOAED5_MENU_H
