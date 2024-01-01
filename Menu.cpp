//
// Created by User on 23/12/2023.
//

#include <algorithm>
#include "Menu.h"
#include <cmath>


void nDestinationsShowInterface(Airport airport, int i);
//Interface inicial:
std::string Menu::addspasces(std::string str, int nr){
    std::string res;
    for(int i = 0; i<(nr-str.size()); i++){
        res.push_back(' ');
    }
    return res;
}

Menu::Menu(Graph<Airport> *graph,unordered_map<std::string,std::string> map,set<std::string> city,set<std::string> country){
    g = graph;
    nameToCodeAirport = map;
    cities = city;
    countries = country;
}
Vertex<Airport>* Menu::getAirportByName(std::string n){
    auto it = nameToCodeAirport.find(n);
    if (it != nameToCodeAirport.end()){
        return g->getVertexSet().find(it->second)->second;
    }
    return nullptr;
}
Vertex<Airport>* Menu::getAirportByCode(std::string c){
    auto set = g->getVertexSet();
    auto it = set.find(c);
    if (it != set.end()){
        return it->second;
    }
    return nullptr;
}
bool Menu::existCity(std::string c){
    return cities.find(c) != cities.end();
}
bool Menu::existCountry(std::string c){
    return countries.find(c) != countries.end();
}
bool helpExistAirline(Vertex<Airport>* s,Graph<Airport> &g,std::string c){
    queue<Vertex<Airport> *> q;
    q.push(s);
    s->setVisited(true);
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto & e : v->getAdj()) {
            if (e.getAirlineOfFlight().getCode() == c || e.getAirlineOfFlight().getName() == c)return true;
            auto w = e.getDest();
            if ( ! w->isVisited() ) {
                q.push(w);
                w->setVisited(true);
            }
        }
    }
    return false;
}
bool Menu::existAirline(std::string airline){
    for (auto v : g->getVertexSet())v.second->setVisited(false);
    for (auto v : g->getVertexSet()){
        if (!v.second->isVisited() && helpExistAirline(v.second,*g,airline))return true;
    }
    return false;
}


void Menu::secBase(){

    std::cout << std::endl;
    std::cout << "########################################################################################################" << std::endl;
    std::cout << "##                                                                                                    ##" << std::endl;
    std::cout << "##   Consultar:                                                                                       ##" << std::endl;
    std::cout << "##                                                                                                    ##" << std::endl;
    std::cout << "##      1- Numero de aeroportos e voos disponiveis                                                    ##" << std::endl;
    std::cout << "##                                                                                                    ##" << std::endl;
    std::cout << "##      2- Numero de voos de partida de um aeroporto e numero de companhias aereas                    ##" << std::endl;
    std::cout << "##                                                                                                    ##" << std::endl;
    std::cout << "##      3- Numero de voos por cidade/companhia aerea                                                  ##" << std::endl;
    std::cout << "##                                                                                                    ##" << std::endl;
    std::cout << "##      4- Numero de paises destino diferentes de um aeroporto/cidade                                 ##" << std::endl;
    std::cout << "##                                                                                                    ##" << std::endl;
    std::cout << "##      5- Numero de destinos disponiveis com partida num aeroporto                                   ##" << std::endl;
    std::cout << "##                                                                                                    ##" << std::endl;
    std::cout << "##      6- Numero de destinos alcancaveis com partida num aeroporto com um maximo de X escalas        ##" << std::endl;
    std::cout << "##                                                                                                    ##" << std::endl;
    std::cout << "##      7- Viagem com maior numero de escalas                                                         ##" << std::endl;
    std::cout << "##                                                                                                    ##" << std::endl;
    std::cout << "##      8- Os k principais aeroportos com maior capacidade de trafego aereo                           ##" << std::endl;
    std::cout << "##                                                                                                    ##" << std::endl;
    std::cout << "##      9- Identificar os aeroportos essenciais para a capacidade de circulacao da rede               ##" << std::endl;
    std::cout << "##                                                                                                    ##" << std::endl;
    std::cout << "##                                                                                                    ##" << std::endl;
    std::cout << "##      0 -> Sair                                                                                     ##" << std::endl;
    std::cout << "##                                                                                                    ##" << std::endl;
    std::cout << "########################################################################################################" << std::endl << std::endl;

    int k;
    std::cout<<"Opcao: ";
    std::cin>>k;
    switch (k) {
        case 0:
            std::cout << "A sair ..." << std::endl;
            break;
        case 1:
            numberOfAirportsInterface();
            break;
        case 2:
            nFlightAirlineInAirportChoiceInterface();
            break;
        case 3:
            nFlightPerCityOrAirlineChoiceInterface();
            break;
        case 4:
            differentCountriesInterface();
            break;
        case 5:
            nDestinationsInterface();
            break;
        case 6:
            nReachableDestinationsInterface();
            break;
        case 7:
            maxTripInterface();
            break;
        case 8:
            gratestKInterface();
            break;
        case 9:
            essentialAirportsInterface();
            break;
        default:
            std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
            secBase();
            break;
    }
}

//----------------------------------------------------------3i inicio----------------------------
void Menu::numberOfAirportsInterface() {
    std::cout<<std::endl<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##    Numero de aeroportos: " <<numberOfAirports()<<addspasces(std::to_string(numberOfAirports()),41)<<"##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##    Numero de voos: " <<numberOfFlights()<<addspasces(to_string(numberOfAirports()),46)<<"##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##    0 -> Voltar                                                    ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;

    std::string k;
    std::cout<<"Voltar?: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        secBase();
    }
    std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
    numberOfAirportsInterface();
}

/////////////////////////////////
//       3i                    //
/////////////////////////////////

int Menu::numberOfAirports() {
    return g->getNumVertex();
}

int Menu::numberOfFlights() {
    int c = 0;
    for (auto v : g->getVertexSet()){
        c += v.second->getAdj().size();
    }
    return c;
}

//------------------------------------------------------Fim 3i---------------------------------------

//------------------------------------------------------3ii Inicio-----------------------------------

void Menu::nFlightAirlineInAirportChoiceInterface(){

    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Voos de partida de um aeroporto e numero de companhias aereas:      ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     1 -> Introduza o aeroporto:_______                                  ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout<<"Aeroporto: ";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);

    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        secBase();
        return;
    }
    auto r = getAirportByName(k);
    if (r == nullptr) r = getAirportByCode(k);
    if (r == nullptr){
            std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        nFlightAirlineInAirportChoiceInterface();
    }else nFlightAirlineInAirportInterface(r);

}

void Menu::nFlightAirlineInAirportInterface(Vertex<Airport>* airport){
    std::cout<<std::endl<<std::endl;
    std::cout<<"############################################################################################"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##     Voos de partida do aeroporto "<<airport->getInfo().getName()<<" e numero de companhias aereas:"<<addspasces(airport->getInfo().getName(),23)<<"##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##     Numero de voos: "<< nFlightAirlineInAirport(airport).first<<addspasces(to_string(nFlightAirlineInAirport(airport).first),67)<<"##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##     Numero de companhias: "<< nFlightAirlineInAirport(airport).second<<addspasces(to_string(nFlightAirlineInAirport(airport).second),61)<<"##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                                        ##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"############################################################################################"<<std::endl<<std::endl;

    std::cout<<"Voltar? ";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        nFlightAirlineInAirportChoiceInterface();
        return;
    }
    std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
    nFlightAirlineInAirportInterface(airport);
}


/////////////////////////////////
//       3ii                   //
/////////////////////////////////

pair<int,int> Menu::nFlightAirlineInAirport(Vertex<Airport>* airport){
    set<Airline> airlines;
    for (auto d : airport->getAdj()){
        airlines.insert(d.getAirlineOfFlight());
    }
    return {airport->getAdj().size(),airlines.size()};
}

//------------------------------------------------------Fim 3ii---------------------------------------

//------------------------------------------------------3iii Inicio-----------------------------------

void Menu::nFlightPerCityOrAirlineChoiceInterface(){

    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Numero de voos por:                                                 ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     1 -> Cidade                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     2 -> Companhia aerea                                                ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout<<"Opcao: ";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        secBase();
        return;
    }else if(k == "1") nFlightPerCityInterface();
    else if (k == "2") nFlightPerAirlineInterface();
    else {
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        nFlightPerCityOrAirlineChoiceInterface();
    }
}
void Menu::nFlightPerCityInterface() {
    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Numero de voos por Cidade:                                          ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     1 -> Escolher cidade:                                               ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     2 -> Em todas:                                                      ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout<<"Opcao: ";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        nFlightPerCityOrAirlineChoiceInterface();
        return;
    }else if(k == "1") nFlightPerCityInterfaceChoise();
    else if (k == "2") nFlightPerCityInterfaceAll();
    else {
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        nFlightPerCityInterface();
    }
}
void Menu::nFlightPerCityInterfaceChoise(){
    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Numero de voos por Cidade:                                          ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Introduza o nome da Cidade:_______                                  ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout << "Cidade: ";
    std::string city;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, city);
    if(city =="0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        nFlightPerCityInterface();
    }else if (!existCity(city)){
        std::cout << std::endl << "Essa cidade nao consta na nossa base de dados." << std::endl;
        nFlightPerCityInterfaceChoise();
    }else nFlightPerCityOneInterface(city);

}
void Menu::nFlightPerCityOneInterface(std::string city) {
    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Numero de voos da Cidade " << city <<':'<<addspasces(city,42)<<"##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     --- "<<nFlightPerCityOne(city)<<addspasces(to_string(nFlightPerCityOne(city)),64)<<"##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout<<"Voltar?";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if(k =="0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        nFlightPerCityInterfaceChoise();
        return;
    }
    nFlightPerCityOneInterface(city);
    std::cout << "O nome da cidade que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
}
void Menu::nFlightPerCityInterfaceAll() {
    map<std::string,int> myMap;
    myMap = nFlightPerCity();
    std::cout<<std::endl<<std::endl;
    std::cout<< "######################################################################################" << std::endl;
    std::cout<< "##                                                                                  ##"<<std::endl;
    std::cout<< "##     Numero de voos por Cidade:                                                   ##"<<std::endl;
    std::cout<< "##                                                                                  ##"<<std::endl;
    for (auto it = myMap.cbegin(); it != myMap.cend(); ++it) {
        std::cout <<"##    " << it->first << " -> " << it->second << addspasces(it->first+ to_string(it->second),74) <<"##"<<std::endl;
    }
    std::cout<< "##                                                                                  ##"<<std::endl;
    std::cout<< "##    0 -> Voltar                                                                   ##"<<std::endl;
    std::cout<< "##                                                                                  ##"<<std::endl;
    std::cout<< "######################################################################################" << std::endl<< std::endl;


    std::cout << "Voltar?";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if(k =="0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        nFlightPerCityInterface();
        return;
    }
    std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
    nFlightPerCityInterfaceAll();
}


//

/////////////////////////////////
//       3iii                  //
/////////////////////////////////

map<std::string,int> Menu::nFlightPerCity(){
    map<std::string,int> contagem;
    for (auto v : g->getVertexSet()){
        std::string city = v.second->getInfo().getCity();
        contagem[city] += v.second->getAdj().size();
    }
    return contagem;
}
int Menu::nFlightPerCityOne(std::string name) {
    int contagem = 0;
    for (auto v: g->getVertexSet()) {
        if (name == v.second->getInfo().getCity()) {
            contagem += v.second->getAdj().size();
        }
    }
    return contagem;
}

void Menu::nFlightPerAirlineInterface(){
    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Numero de voos por Companhia Aerea:                                 ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     1 -> Escolher companhia:                                            ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     2 -> Em todas:                                                      ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout << "Opcao: ";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        nFlightPerCityOrAirlineChoiceInterface();
        return;
    }else if (k == "1")nFlightPerAirlineInterfaceChoise();
    else if (k == "2")nFlightPerAirlineInterfaceAll();
    else {
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        nFlightPerAirlineInterface();
    }
}

void Menu::nFlightPerAirlineInterfaceChoise(){
    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Numero de voos por Companhia Aerea:                                 ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Introduza a Companhia Aerea:_______                                 ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout << "Companhia Aerea: ";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        nFlightPerAirlineInterface();
        return;
    }else if (!existAirline(k)){
        std::cout << "A companhia aerea que inseriu nao existe. Por favor volte a tentar." << std::endl;
        nFlightPerAirlineInterfaceChoise();
    }else nFlightPerAirlineOneInterface(k);
}
void Menu::nFlightPerAirlineOneInterface(Airline airline) {
    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Numero de voos da Companhia " << airline.getName() <<':'<<addspasces(airline.getName(),3)<<"##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     --- "<<nFlightPerAirlineOne(airline)<<addspasces(to_string(nFlightPerAirlineOne(airline)),62)<<"##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout<<"Voltar?";
    std::string k;
    std::cin >> k;
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        nFlightPerAirlineInterfaceChoise();
        return;
    }
    std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
    nFlightPerAirlineOneInterface(airline);

}

void Menu::nFlightPerAirlineInterfaceAll() {
    map<std::string,int> myMap;
    myMap = nFlightPerAirline();
    std::cout<< "######################################################################################" << std::endl;
    std::cout<< "##                                                                                  ##"<<std::endl;
    std::cout<< "##     Numero de voos por Companhia Aerea:                                          ##"<<std::endl;
    std::cout<< "##                                                                                  ##"<<std::endl;
    for (auto it = myMap.cbegin(); it != myMap.cend(); ++it) {
        std::cout <<"##    " << it->first << " -> " << it->second << addspasces(it->first+ to_string(it->second),74) <<"##"<<std::endl;
    }
    std::cout<< "##                                                                                  ##"<<std::endl;
    std::cout<< "##    0 -> Voltar                                                                   ##"<<std::endl;
    std::cout<< "##                                                                                  ##"<<std::endl;
    std::cout<< "######################################################################################" << std::endl<< std::endl;

    std::cout<<"Voltar?";
    std::string k;
    std::cin >> k;
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        nFlightPerAirlineInterface();
        return;
    }
    std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
    nFlightPerAirlineInterfaceAll();

}



map<std::string,int> Menu::nFlightPerAirline(){
    map<std::string,int> contagem;
    for (auto v : g->getVertexSet()){
        for (auto f : v.second->getAdj()){
            std::string airline = f.getAirlineOfFlight().getCode();
            contagem[airline]++;
        }
    }
    return contagem;
}

int Menu::nFlightPerAirlineOne(Airline airline){
    int contagem;
    for (auto v : g->getVertexSet()){
        for (auto f : v.second->getAdj()){
            if( airline.getCode() == f.getAirlineOfFlight().getCode()) {
                contagem++;
            }
        }
    }
    return contagem;
}

//------------------------------------------------------Fim 3iii---------------------------------------

//------------------------------------------------------3iv Inicio-----------------------------------

void Menu:: differentCountriesInterface() {
    std::cout << std::endl << std::endl;
    std::cout << "#############################################################################" << std::endl;
    std::cout << "##                                                                         ##" << std::endl;
    std::cout << "##     Numero de paises destino diferentes de:                             ##" << std::endl;
    std::cout << "##                                                                         ##" << std::endl;
    std::cout << "##     1 -> Cidade                                                         ##" << std::endl;
    std::cout << "##                                                                         ##" << std::endl;
    std::cout << "##     2 -> Aeroporto                                                      ##" << std::endl;
    std::cout << "##                                                                         ##" << std::endl;
    std::cout << "##     0 -> Voltar                                                         ##" << std::endl;
    std::cout << "##                                                                         ##" << std::endl;
    std::cout << "#############################################################################" << std::endl<< std::endl;

    std::cout << "Opcao: ";
    std::string k;
    std::cin >> k;
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        secBase();
        return;
    }else if (k == "1")diffCountriesCityChoiseInterface();
    else if (k == "2")diffCountriesAirportChoiseInterface();
    else {
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        differentCountriesInterface();
    }
}

//Cidade
void Menu:: diffCountriesCityChoiseInterface() {
    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Numero de Paises por Cidade:                                        ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Introduza o nome da Cidade:_______                                  ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout << "Cidade: ";
    std::string city;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, city);

    if(city == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        differentCountriesInterface();
    }
    else if (!existCity(city)){
        std::cout << "Essa cidade nao consta na nossa base de dados" << std::endl;
        diffCountriesCityChoiseInterface();
    }else diffCountriesCityShowInterface(city);
}

void Menu::diffCountriesCityShowInterface(std::string city) {
    map<std::string, int> myMap;
    myMap = cityToCountries(city);
    std::cout << std::endl << std::endl;
    std::cout << "######################################################################################" << std::endl;
    std::cout << "##                                                                                  ##" << std::endl;
    std::cout << "##     Numero de paises cobertos por " << city << ":" << addspasces(city, 45) << "##" << std::endl;
    std::cout << "##                                                                                  ##" << std::endl;
    std::cout << "##     ----- " << myMap.size() << addspasces(to_string(myMap.size()), 71) << "##" << std::endl;
    std::cout << "##                                                                                  ##" << std::endl;
    std::cout << "##    Paises -> Numero de Voos:                                                     ##" << std::endl;
    std::cout << "##                                                                                  ##" << std::endl;
    for (auto it = myMap.cbegin(); it != myMap.cend(); ++it) {
        std::cout << "##    " << it->first << " -> " << it->second << addspasces(it->first + to_string(it->second), 74)
                  << "##" << std::endl;
    }
    std::cout << "##                                                                                  ##" << std::endl;
    std::cout << "##    0 -> Voltar                                                                   ##" << std::endl;
    std::cout << "##                                                                                  ##" << std::endl;
    std::cout << "######################################################################################" << std::endl
              << std::endl;

    std::cout << "Voltar? ";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        diffCountriesCityChoiseInterface();
        return;
    }
    std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
    diffCountriesCityShowInterface(city);
}

//Aeroporto

void Menu:: diffCountriesAirportChoiseInterface() {
    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Numero de Paises por Aeroporto:                                     ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Introduza o nome do Aeroporto:_______                               ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout<<"Aeroporto: ";
    std::string airport;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, airport);
    if (airport == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        differentCountriesInterface();
        return;
    }
    auto r = getAirportByName(airport);
    if (r == nullptr) r = getAirportByCode(airport);
    if (r == nullptr){
        std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        diffCountriesAirportChoiseInterface();
    }else diffCountriesAirportShowInterface(r);
}


void Menu::diffCountriesAirportShowInterface(Vertex<Airport>* airport) {
    map<std::string, int> myMap;
    myMap = airportToCountries(airport);
    std::cout << std::endl << std::endl;
    std::cout << "######################################################################################" << std::endl;
    std::cout << "##                                                                                  ##" << std::endl;
    std::cout << "##     Numero de paises cobertos por " << airport->getInfo().getName() << ":" << addspasces(airport->getInfo().getName(), 45) << "##" << std::endl;
    std::cout << "##                                                                                  ##" << std::endl;
    std::cout << "##     ----- " << myMap.size() << addspasces(to_string(myMap.size()), 71) << "##" << std::endl;
    std::cout << "##                                                                                  ##" << std::endl;
    std::cout << "##    Paises -> Numero de Voos:                                                     ##" << std::endl;
    std::cout << "##                                                                                  ##" << std::endl;
    for (auto it = myMap.cbegin(); it != myMap.cend(); ++it) {
        std::cout << "##    " << it->first << " -> " << it->second << addspasces(it->first + to_string(it->second), 74)
                  << "##" << std::endl;
    }
    std::cout << "##                                                                                  ##" << std::endl;
    std::cout << "##    0 -> Voltar                                                                   ##" << std::endl;
    std::cout << "##                                                                                  ##" << std::endl;
    std::cout << "######################################################################################" << std::endl<< std::endl;

    std::cout << "Voltar? ";
    std::string k;
    std::cin >> k;
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        diffCountriesAirportChoiseInterface();
        return;
    }
    std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
    diffCountriesAirportShowInterface(airport);
}

/////////////////////////////////
//       3iv                   //
/////////////////////////////////
map<std::string,int> Menu::airportToCountries(Vertex<Airport>* airport){
    map<std::string,int> contagem;
    for (auto d : airport->getAdj()){
        contagem[d.getDest()->getInfo().getCountry()]++;
    }
    return contagem;
}
map<std::string,int> Menu::cityToCountries(std::string city){
    map<std::string,int> contagem;
    for (auto v : g->getVertexSet()){
        if (v.second->getInfo().getCity() == city){
            for (auto d : v.second->getAdj()){
                contagem[d.getDest()->getInfo().getCountry()]++;
            }
        }
    }
    return  contagem;
}
//------------------------------------------------------Fim 3iv---------------------------------------

//------------------------------------------------------3v Inicio-------------------------------------

void Menu::nDestinationsInterface(){

    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Numero de destinos disponiveis com partida:                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Introduza o aeroporto:_______                                       ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout<<"Aeroporto: ";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        secBase();
        return;
    }
    auto r = getAirportByName(k);
    if (r == nullptr) r = getAirportByCode(k);
    if (r == nullptr){
        std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        diffCountriesAirportChoiseInterface();
    }else nDestinationsTypeInterface(r);

}

void Menu::nDestinationsTypeInterface(Vertex<Airport>* airport){
    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Partida: Aeroporto "<<airport->getInfo().getName()<<addspasces(airport->getInfo().getName(),49)<<"##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Qual o tipo de destino?                                             ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     1 -> Aeroporto                                                      ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     2 -> Cidade                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     3 -> Pais                                                           ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout<<"Opcao: ";
    int k;
    std::cin>>k;

    switch(k){
        case 0:
            nDestinationsInterface();
            break;
        case 1:
            nDestinationsShowInterface(airport,1);
            break;
        case 2:
            nDestinationsShowInterface(airport,2);
            break;
        case 3:
            nDestinationsShowInterface(airport,3);
            break;
    }
}


void Menu::nDestinationsShowInterface(Vertex<Airport>* airport,int num){
    std::string tipo;
    map<std::string,int> myMap;
    switch (num) {
        case 1:
            myMap = nDestinationsAirports(airport);
            tipo = "Aeroportos";
            break;
        case 2:
            myMap = nDestinationsCities(airport);
            tipo = "Cidades";
        case 3:
            myMap =nDestinationsCountries(airport);
            tipo = "Paises";
    }

    std::cout << std::endl << std::endl;
    std::cout << "############################################################################################" << std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    std::cout << "##    Numero de "<<tipo<<" disponiveis compartida no Aeroporto "<<airport->getInfo().getName()<<addspasces(tipo+airport->getInfo().getName(),37)<<"##"<< std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    std::cout << "##     ----- " << myMap.size() << addspasces(to_string(myMap.size()), 77) << "##" << std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    std::cout << "##    "<<tipo<<" -> Numero de Voos:"<<addspasces(tipo,65)<<"##"<< std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    for (auto it = myMap.cbegin(); it != myMap.cend(); ++it) {
        std::cout << "##    " << it->first << " -> " << it->second << addspasces(it->first + to_string(it->second), 80)
                  << "##" << std::endl;
    }
    std::cout << "##                                                                                        ##" << std::endl;
    std::cout << "##    0 -> Voltar                                                                         ##" << std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    std::cout << "############################################################################################" << std::endl<< std::endl;

    std::string k;
    std::cout<<"Voltar?: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        nDestinationsTypeInterface(airport);
    }
    std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
    nDestinationsShowInterface(airport,num);

}
/////////////////////////////////
//       3v                    //
/////////////////////////////////
map<std::string,int> Menu::nDestinationsAirports(Vertex<Airport>* airport){
    map<std::string,int> contagem;
    queue<Vertex<Airport> *> q;
    queue<Vertex<Airport> *> q2;
    int c = 1;
    for (auto k : g->getVertexSet()){
        k.second->setVisited(false);
    }
    auto v = g->findVertexByCode(airport->getInfo().getCode());
    v->setVisited(true);
    q.push(v);
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto & e : v->getAdj()) {
            auto w = e.getDest();
            if (!w->isVisited()){
                contagem.insert({w->getInfo().getCode(),c});
                q2.push(w);
                w->setVisited(true);
            }
        }
        if (q.empty()){
            c++;
            q = q2;
            while (!q2.empty())q2.pop();
        }
    }
    return contagem;
}
map<std::string,int> Menu::nDestinationsCities(Vertex<Airport>* airport){
    map<std::string,int> contagem;
    queue<Vertex<Airport> *> q;
    queue<Vertex<Airport> *> q2;
    int c = 0;
    for (auto k : g->getVertexSet()){
        k.second->setVisited(false);
    }
    auto v = g->findVertexByCode(airport->getInfo().getCode());
    v->setVisited(true);
    q.push(v);
    while (!q.empty()) {
        auto v = q.front();
        if (contagem.find(v->getInfo().getCity()) == contagem.end())contagem[v->getInfo().getCity()] = c;
        q.pop();
        for (auto & e : v->getAdj()) {
            auto w = e.getDest();
            if (!w->isVisited()){
                q2.push(w);
                w->setVisited(true);
            }
        }
        if (q.empty()){
            c++;
            q = q2;
            while (!q2.empty())q2.pop();
        }
    }
    return contagem;
}
map<std::string,int> Menu::nDestinationsCountries(Vertex<Airport>* airport){
    map<std::string,int> contagem;
    queue<Vertex<Airport> *> q;
    queue<Vertex<Airport> *> q2;
    int c = 0;
    for (auto k : g->getVertexSet()){
        k.second->setVisited(false);
    }
    auto v = g->findVertexByCode(airport->getInfo().getCode());
    v->setVisited(true);
    q.push(v);
    while (!q.empty()) {
        auto v = q.front();
        if (contagem.find(v->getInfo().getCountry()) == contagem.end())contagem[v->getInfo().getCountry()] = c;
        q.pop();
        for (auto & e : v->getAdj()) {
            auto w = e.getDest();
            if (!w->isVisited()){
                q2.push(w);
                w->setVisited(true);
            }
        }
        if (q.empty()){
            c++;
            q = q2;
            while (!q2.empty())q2.pop();
        }
    }
    return contagem;
}
//------------------------------------------------------Fim 3v---------------------------------------

//------------------------------------------------------3vi Inicio-----------------------------------


void Menu::nReachableDestinationsInterface(){
    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Numero de destinos alcancaveis com partida num Aeroporto            ##"<<std::endl;
    std::cout<<"##           com um maximo de X escalas:                                   ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Introduzir o Aeroporto:_______                                      ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar:                                                        ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout<<"Aeroporto: ";
    std::string airport;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin,airport);
    if (airport == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        secBase();
        return;
    }
    auto r = getAirportByName(airport);
    if (r == nullptr) r = getAirportByCode(airport);
    if (r == nullptr){
        std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        nReachableDestinationsInterface();
    }else nReachableDestinationsTypeInterface(r);
}
void Menu::nReachableDestinationsTypeInterface(Vertex<Airport>* airport){
    std::cout<<std::endl<<std::endl;
    std::cout<<"#######################################################################################"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"##     Numero de destinos alcancaveis com partida no Aeroporto "<<airport->getInfo().getName()<<addspasces(airport->getInfo().getName(),22)<<"##"<<std::endl;
    std::cout<<"##           com um maximo de X escalas:                                             ##"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"##     Qual o tipo de destino?                                                       ##"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"##     1 -> Aeroporto                                                                ##"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"##     2 -> Cidade                                                                   ##"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"##     3 -> Pais                                                                     ##"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                                   ##"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################################"<<std::endl<<std::endl;

    std::cout<<"Opcao: ";
    int k;
    std::cin>>k;

    switch(k){
        case 0:
            nReachableDestinationsInterface();
            break;
        case 1:
            nReachableDestinationsStopsInterface(airport,1);
            break;
        case 2:
            nReachableDestinationsStopsInterface(airport,2);
            break;
        case 3:
            nReachableDestinationsStopsInterface(airport,3);
            break;
        default:
            std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
            nReachableDestinationsTypeInterface(airport);
    }
}

void Menu::nReachableDestinationsStopsInterface(Vertex<Airport>* airport, int dest){
    std::string tipo;
    switch (dest) {
        case 1:
            tipo = "Aeroportos";
            break;
        case 2:
            tipo = "Cidades";
            break;
        case 3:
            tipo = "Paises";
            break;
    }
    std::cout<<std::endl<<std::endl;
    std::cout<<"############################################################################################"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##     Numero de "<<tipo<<" alcancaveis com partida no Aeroporto "<<airport->getInfo().getName()<<addspasces(airport->getInfo().getName()+tipo,35)<<"##"<<std::endl;
    std::cout<<"##           com um maximo de X Escalas:                                                  ##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##     Introduzir o Numero de Escalas:_______                                             ##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##     0 -> Voltar:                                                                       ##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"############################################################################################"<<std::endl<<std::endl;

    std::cout<<"Numero de Escalas: ";
    int escalas;
    std::cin.clear();
    std::cin.sync();
    std::cin>>escalas;

    switch (escalas) {
        case 0:
            std::cout<<"A sair...";
            nReachableDestinationsTypeInterface(airport);
            break;
        default:
            nReachableDestinationsShowAirports(airport,escalas,dest,tipo);
    }
}
void Menu::nReachableDestinationsShowAirports(Vertex<Airport>* airport, int escalas, int dest, std::string tipo){
    map<std::string,int> myMap;
    switch (dest) {
        case 1:
            myMap= nReachableDestinationsAirports(airport,escalas);
            break;
        case 2:
            myMap = nReachableDestinationsCities(airport,escalas);
            break;
        case 3:
            myMap = nReachableDestinationsCountries(airport,escalas);
            break;
    }

    std::cout<<std::endl<<std::endl;
    std::cout<<"############################################################################################"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##     Numero de "<<tipo<<" alcancaveis com partida no Aeroporto "<<airport->getInfo().getName()<<addspasces(airport->getInfo().getName()+tipo,35)<<"##"<<std::endl;
    std::cout<<"##           com um maximo de "<<escalas<<" Escalas:"<<addspasces(to_string(escalas),51)<<"##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout <<"##     ----- " << myMap.size() << addspasces(to_string(myMap.size()), 77) << "##" << std::endl;std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout <<"##    "<<tipo<<" -> Numero de Voos:"<<addspasces(tipo,65)<<"##"<< std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    for (auto it = myMap.cbegin(); it != myMap.cend(); ++it) {
        std::cout << "##    " << it->first << " -> " << it->second << addspasces(it->first + to_string(it->second), 80)
                  << "##" << std::endl;
    }
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##     0 -> Voltar:                                                                       ##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"############################################################################################"<<std::endl<<std::endl;

    std::string k;
    std::cout<<"Voltar?: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        nReachableDestinationsStopsInterface(airport,dest);
    }
    std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
    nReachableDestinationsShowAirports(airport,escalas,dest,tipo);

}
/////////////////////////////////
//       3vi                   //
/////////////////////////////////
map<std::string,int> Menu::nReachableDestinationsAirports(Vertex<Airport>* airport,int k){
    map<std::string,int> contagem;
    queue<Vertex<Airport>*> temp;
    queue<Vertex<Airport>*> temp2;
    for (auto v : g->getVertexSet())v.second->setVisited(false);
    temp.push(g->findVertexByCode(airport->getInfo().getCode())); // Inicial vertex put in the queue
    while (!temp.empty() && k > 0){
        for (auto v : temp.front()->getAdj()){
            if (!v.getDest()->isVisited()){
                temp2.push(v.getDest());
                contagem[v.getDest()->getInfo().getCode()]++;
                v.getDest()->setVisited(true);
            }
        }
        temp.pop();
        if (temp.empty()){ // This means we have changed level
            k--;
            temp = temp2;
            while (!temp2.empty())temp2.pop();
        }
    }
    return contagem;
}
map<std::string,int> Menu::nReachableDestinationsCities(Vertex<Airport>* airport,int k){
    map<std::string,int> contagem;
    queue<Vertex<Airport>*> temp;
    queue<Vertex<Airport>*> temp2;
    for (auto v : g->getVertexSet())v.second->setVisited(false);
    temp.push(g->findVertexByCode(airport->getInfo().getCode())); // Inicial vertex put in the queue
    while (!temp.empty() && k > 0){
        for (auto v : temp.front()->getAdj()){
            if (!v.getDest()->isVisited()){
                temp2.push(v.getDest());
                contagem[v.getDest()->getInfo().getCity()]++;
                v.getDest()->setVisited(true);
            }
        }
        temp.pop();
        if (temp.empty()){ // This means we have changed level
            k--;
            temp = temp2;
            while (!temp2.empty())temp2.pop();
        }
    }
    return contagem;
}
map<std::string,int> Menu::nReachableDestinationsCountries(Vertex<Airport>* airport,int k){
    map<std::string,int> contagem;
    queue<Vertex<Airport>*> temp;
    queue<Vertex<Airport>*> temp2;
    for (auto v : g->getVertexSet())v.second->setVisited(false);
    temp.push(g->findVertexByCode(airport->getInfo().getCode())); // Inicial vertex put in the queue
    while (!temp.empty() && k > 0){
        for (auto v : temp.front()->getAdj()){
            if (!v.getDest()->isVisited()){
                temp2.push(v.getDest());
                contagem[v.getDest()->getInfo().getCity()]++;
                v.getDest()->setVisited(true);
            }
        }
        temp.pop();
        if (temp.empty()){ // This means we have changed level
            k--;
            temp = temp2;
            while (!temp2.empty())temp2.pop();
        }
    }
    return contagem;
}
//------------------------------------------------------Fim 3vi---------------------------------------

//------------------------------------------------------3vii Inicio-----------------------------------
/////////////////////////////////
//       3vii                  //
/////////////////////////////////

void Menu::maxTripInterface() {
    std::cout<<std::endl<<std::endl;
    std::cout<<"#######################################################################################"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"##     Viagem com maior numero de escalas:                                           ##"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"##     //dar print                                                                   ##"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar?                                                                  ##"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################################"<<std::endl<<std::endl;

    std::string k;
    std::cout<<"Voltar?: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        secBase();
    }
    std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
    maxTripInterface();
}





map<std::string,int> helpTrip(Vertex<Airport>* v,Graph<Airport> *g){
    queue<Vertex<Airport>*> temp;
    queue<Vertex<Airport>*> temp2;
    map<std::string,int> res;
    int c = 0;
    for (auto v : g->getVertexSet())v.second->setVisited(false);
    temp.push(v); // Inicial vertex put in the queue
    while (!temp.empty()){
        for (auto v : temp.front()->getAdj()){
            if (!v.getDest()->isVisited()){
                temp2.push(v.getDest());
                v.getDest()->setVisited(true);
            }
        }
        res.insert({temp.front()->getInfo().getName(),c});
        temp.pop();
        if (temp.empty()){ // This means we have changed level
            c++;
            temp = temp2;
            if(!temp.empty())res.clear();
            while (!temp2.empty())temp2.pop();
        }
    }
    return res;
}
pair<vector<pair<std::string,std::string>>,int> Menu::maxTrip(){
    pair<vector<pair<std::string,std::string>>,int> res;
    for (auto par : g->getVertexSet()){
        auto v = par.second;
        auto r = helpTrip(v,g);
        int k = r.begin()->second;
        if (r.begin()->second == res.second){
            cout << r.size()<< ","<<k << endl;
            for (auto k : r)res.first.push_back({v->getInfo().getName(),k.first});
        }else if (r.begin()->second > res.second){
            cout << r.size()<< ","<<k << endl;
            res.first.clear();
            res.second = r.begin()->second;
            for (auto k : r)res.first.push_back({v->getInfo().getName(),k.first});
        }
    }
    return res;
}
/////////////////////////////////
//       3viii                 //
/////////////////////////////////

void Menu::gratestKInterface() {

    std::cout << std::endl << std::endl;
    std::cout << "#######################################################################################" << std::endl;
    std::cout << "##                                                                                   ##" << std::endl;
    std::cout << "##     Os k principais aeroportos com maior capacidade de trafego aereo:             ##" << std::endl;
    std::cout << "##                                                                                   ##" << std::endl;
    std::cout << "##                                                                                   ##" << std::endl;
    std::cout << "##     Introduza o numero k:                                                         ##" << std::endl;
    std::cout << "##                                                                                   ##" << std::endl;
    std::cout << "##                                                                                   ##" << std::endl;
    std::cout << "##     0 -> Voltar                                                                   ##" << std::endl;
    std::cout << "##                                                                                   ##" << std::endl;
    std::cout << "#######################################################################################" << std::endl<< std::endl;

    std::cout<<"Opcao: ";
    int k;
    std::cin.clear();
    std::cin.sync();
    std::cin>> k;
    if (k == 0){
        std::cout << std::endl << "A sair ..." << std::endl;
        secBase();
    }
    else{
    gratestKShowInterface(k);
    }
}


void Menu::gratestKShowInterface(int k){
    std::cout<<"olá";

    //std::vector<pair<Airport, int>> gratest = nGreatestAirTrafficCapacity(k);
    std::cout << std::endl << std::endl;
    std::cout << "############################################################################################" << std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    std::cout << "##     Os "<<k<<" principais aeroportos com maior capacidade de trafego aereo:"<<addspasces(to_string(k),19)<<"##" << std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    for (auto k : nGreatestAirTrafficCapacity(k)) {
        std::cout << "##    " << k.first.getName() << " -> " << k.second << addspasces(k.first.getName() + to_string(k.second), 80)
                  << "##" << std::endl;
    }
    std::cout << "##     0 -> Voltar                                                                        ##" << std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    std::cout << "############################################################################################" << std::endl<< std::endl;
}

int totalDegree(Airport airport, Graph<Airport>* g) {
    auto v = g->findVertexByCode(airport.getCode());
    int total1 = v->getAdj().size();
    int total = 0;
    for (auto vertex : g->getVertexSet()) {
        for (auto edge : vertex.second->getAdj()) {
            if (edge.getDest()->getInfo().getCode() == airport.getCode()) total++;
        }
    }
    return total + total1;
}

bool compare(pair<Airport, int> a1, pair<Airport, int> a2) {
    return a1.second > a2.second;
}

std::vector<pair<Airport, int>> Menu::nGreatestAirTrafficCapacity(int k) {
    std::unordered_set<int> numbers;
    std::vector<pair<Airport, int>> highest;
    for (auto vertex : g->getVertexSet()) highest.push_back({vertex.second->getInfo(), totalDegree(vertex.second->getInfo(), g)});

    sort(highest.begin(), highest.end(), compare);
    highest.erase(highest.begin() + k, highest.end());
    return highest;
}
void Menu::essentialAirportsInterface(){
    set<std::string> airports = essentialAirports();
    std::cout << std::endl << std::endl;
    std::cout << "#######################################################################################" << std::endl;
    std::cout << "##                                                                                   ##" << std::endl;
    std::cout << "##    Aeroportos essenciais para a capacidade de circulacao da rede:                 ##" << std::endl;
    std::cout << "##                                                                                   ##" << std::endl;
    for (auto k : airports) {
        std::cout << "##    " << k << addspasces(k, 79)
                  << "##" << std::endl;
    }

    std::cout << "##                                                                                   ##" << std::endl;
    std::cout << "##     0 -> Voltar                                                                   ##" << std::endl;
    std::cout << "##                                                                                   ##" << std::endl;
    std::cout << "#######################################################################################" << std::endl<< std::endl;

    std::cout<<"Voltar? ";
    int k;
    std::cin.clear();
    std::cin.sync();
    std::cin>> k;
    if (k == 0){
        std::cout << std::endl << "A sair ..." << std::endl;
        secBase();
    }
    else{
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        essentialAirportsInterface();
    }
}





/////////////////////////////////
//       3ix                   //
/////////////////////////////////
void dfs_art(Vertex<Airport>* v,  set<std::string> &res,int &index) {
    v->setNum(index);
    v->setLow(index);
    index++;
    v->setProcessing(true);
    for (auto w : v->getAdj()){
        auto neighbor = w.getDest();
        if (neighbor->getNum() == 0){
            dfs_art(neighbor,res,index);
            v->setLow(min(v->getLow(),neighbor->getLow()));
            if (neighbor->getLow() >= v->getNum())res.insert(v->getInfo().getCode());
        }else if (neighbor->isProcessing()){
            v->setLow(min(v->getLow(),neighbor->getNum()));
        }
    }
    v->setProcessing(false);
}

set<std::string> Menu::essentialAirports() {
    set<std::string> res;
    int i = 0; // Contagem
    for (auto vertex : g->getVertexSet())vertex.second->setProcessing(false);
    for (auto vertex : g->getVertexSet()) {
        if (vertex.second->getNum() == 0){
            dfs_art(vertex.second,res,i);
        }
    }
    return res;
}
/////////////////////////////////
//       4                     //
/////////////////////////////////
bool inStack(queue<Vertex<Airport> *> q,Vertex<Airport> * a){
    while (!q.empty()){
        if (a == q.front())return true;
        q.pop();
    }
    return false;
}
vector<vector<Flight>> Menu::AirportToAirport(Airport a, Airport b){
    auto v = g->findVertexByCode(a.getCode());
    vector<vector<Flight>> res;
    queue<Vertex<Airport> *> q;
    queue<Vertex<Airport> *> q2;
    for (auto k : g->getVertexSet()){
        k.second->setVisited(false);
        k.second->setFEmpty();
    }
    q.push(v);
    v->setVisited(true);
    bool isFound = false;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto & e : v->getAdj()) {
            auto w = e.getDest();
            if (!w->isVisited() && !inStack(q,w)){
                w->setFEmpty();
                for (auto f : v->getFlights()){w->addFlight(f);}
                w->addFlight(Flight(v->getInfo().getCode(),w->getInfo().getCode(),e.getAirlineOfFlight().getCode()));
                if (w->getInfo().getCode() == b.getCode()){
                    isFound = true;
                    res.push_back(w->getFlights());
                }
                if (!inStack(q2,w))q2.push(w);
            }
        }
        v->setVisited(true);
        if (q.empty()){
            if(isFound)break;
            q = q2;
            while (!q2.empty())q2.pop();
        }
    }
    return res;
}

vector<vector<Flight>> Menu::CityToCity(std::string a, std::string b){
    vector<vector<Flight>> res;
    queue<Vertex<Airport> *> q;
    queue<Vertex<Airport> *> q2;
    for (auto k : g->getVertexSet()){
        k.second->setVisited(false);
        k.second->setFEmpty();
        if (k.second->getInfo().getCity() == a)q.push(k.second);
    }
    bool isFound = false;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto & e : v->getAdj()) {
            auto w = e.getDest();
            if (!w->isVisited() && !inStack(q,w)){
                w->setFEmpty();
                for (auto f : v->getFlights()){w->addFlight(f);}
                w->addFlight(Flight(v->getInfo().getCode(),w->getInfo().getCode(),e.getAirlineOfFlight().getCode()));
                if (w->getInfo().getCity() == b){
                    isFound = true;
                    res.push_back(w->getFlights());
                }
                if (!inStack(q2,w))q2.push(w);
            }
        }
        v->setVisited(true);
        if (q.empty()){
            if(isFound)break;
            q = q2;
            while (!q2.empty())q2.pop();
        }
    }
    return res;
}
/////////////////////////////////
//       5                     //
/////////////////////////////////
bool inVector(vector<std::string> airlines, std::string s){
    for (auto a : airlines)if (a == s)return true;
    return false;
}
vector<vector<Flight>> Menu::AirportToAirportWF(Airport a, Airport b,vector<std::string> airlines){
    auto v = g->findVertexByCode(a.getCode());
    vector<vector<Flight>> res;
    queue<Vertex<Airport> *> q;
    queue<Vertex<Airport> *> q2;
    for (auto k : g->getVertexSet()){
        k.second->setVisited(false);
        k.second->setFEmpty();
    }
    q.push(v);
    v->setVisited(true);
    bool isFound = false;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto & e : v->getAdj()) {
            auto w = e.getDest();
            if (!w->isVisited() && !inStack(q,w) && !inVector(airlines,e.getAirlineOfFlight().getCode())){
                w->setFEmpty();
                for (auto f : v->getFlights()){w->addFlight(f);}
                w->addFlight(Flight(v->getInfo().getCode(),w->getInfo().getCode(),e.getAirlineOfFlight().getCode()));
                if (w->getInfo().getCode() == b.getCode()){
                    isFound = true;
                    res.push_back(w->getFlights());
                }
                if (!inStack(q2,w))q2.push(w);
            }
        }
        v->setVisited(true);
        if (q.empty()){
            if(isFound)break;
            q = q2;
            while (!q2.empty())q2.pop();
        }
    }
    return res;
}
double haversineDistance(double lat1,double lat2,double long1,double long2){
    double PI = 4.0*atan(1.0);
    double dlat1=lat1*(PI/180);
    double dlong1=long1*(PI/180);
    double dlat2=lat2*(PI/180);
    double dlong2=long2*(PI/180);
    double dLong=dlong1-dlong2;
    double dLat=dlat1-dlat2;
    double aHarv= pow(sin(dLat/2.0),2.0)+cos(dlat1)*cos(dlat2)*pow(sin(dLong/2),2);
    double cHarv=2*atan2(sqrt(aHarv),sqrt(1.0-aHarv));
    double earth=3963.19;
    return earth*cHarv;
}