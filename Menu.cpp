//
// Created by User on 23/12/2023.
//

#include <algorithm>
#include "Menu.h"
#include <cmath>

//Interface inicial:
std::string addspasces(std::string str, int nr){
    std::string res;
    for(int i = 0; i<(nr-str.size()); i++){
        res.push_back(' ');
    }
    return res;
}

Menu::Menu(Graph<Airport> *graph,unordered_map<std::string,std::string> map,unordered_set<std::string> city,
           unordered_set<std::string> country,unordered_set<std::string> airlinesN,unordered_set<std::string> airlinesC){
    g = graph;
    nameToCodeAirport = map;
    cities = city;
    countries = country;
    airlinesNames = airlinesN;
    airlinesCodes = airlinesC;
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
bool Menu::existAirline(std::string airline){
    return airlinesNames.find(airline) != airlinesNames.end() || airlinesCodes.find(airline) != airlinesCodes.end();
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
    std::cout << "##      10- Melhor opcao de voo                                                                       ##" << std::endl;
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
            exit(0);
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
        case 10:
            flightOptionsInterfaceStart();
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
void Menu::nFlightPerAirlineOneInterface(std::string airline) {
    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Numero de voos da Companhia " << airline <<':'<<addspasces(airline,39)<<"##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     --- "<<nFlightPerAirlineOne(airline)<<addspasces(to_string(nFlightPerAirlineOne(airline)),64)<<"##"<<std::endl;
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
    std::cout<<std::endl<< std::endl;
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
            std::string airline = f.getAirlineOfFlight().getName();
            contagem[airline]++;
        }
    }
    return contagem;
}

int Menu::nFlightPerAirlineOne(std::string airline){
    int contagem = 0;
    for (auto v : g->getVertexSet()){
        for (auto f : v.second->getAdj()){
            if( airline == f.getAirlineOfFlight().getCode() || airline == f.getAirlineOfFlight().getName()) {
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
    std::cout << "##     Numero de paises cobertos por " << city << ":" << addspasces(city, 46) << "##" << std::endl;
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
    std::cout << "##     Numero de paises cobertos por " << airport->getInfo().getName() << ":" << addspasces(airport->getInfo().getName(), 46) << "##" << std::endl;
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
            break;
        case 3:
            myMap =nDestinationsCountries(airport);
            tipo = "Paises";
            break;
    }

    std::cout << std::endl << std::endl;
    std::cout << "############################################################################################" << std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    std::cout << "##    Numero de "<<tipo<<" disponiveis com partida no Aeroporto "<<airport->getInfo().getName()<<addspasces(tipo+airport->getInfo().getName(),36)<<"##"<< std::endl;
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
    pair<vector<pair<std::string,std::string>>,int> vec =maxTrip();
    std::cout<<std::endl<<std::endl;
    std::cout<<"#######################################################################################"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"##     Viagem com maior numero de escalas:                                           ##"<<std::endl;
    std::cout<<"##                                                                                   ##"<<std::endl;
    for(auto a : vec.first){
        std::cout<<"##     "<< a.first<< " -> "<<a.second<<addspasces(a.first + a.second,74)<<"##"<<std::endl;
    }
    std::cout<<"##                                                                                   ##"<<std::endl;
    std::cout<<"##     Numero de paragens maximo:                                                    ##"<<std::endl;
    std::cout<<"##     ----- " << vec.second << addspasces(to_string(vec.second), 72) << "##" << std::endl;
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
        if (r.begin()->second == res.second){
            for (auto k : r)res.first.push_back({v->getInfo().getName(),k.first});
        }else if (r.begin()->second > res.second){
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
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        secBase();
    }
    else{
    gratestKShowInterface(stoi(k));
    }
}


void Menu::gratestKShowInterface(int k){
    //std::cout<<"olá";

    std::vector<pair<Airport, int>> gratest = nGreatestAirTrafficCapacity(k);
    std::cout << std::endl << std::endl;
    std::cout << "############################################################################################" << std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    std::cout << "##     Os "<<k<<" principais aeroportos com maior capacidade de trafego aereo:"<<addspasces(to_string(k),19)<<"##" << std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    for (auto k : gratest) {
        std::cout << "##    " << k.first.getName() << " -> " << k.second << addspasces(k.first.getName() + to_string(k.second), 80)
                  << "##" << std::endl;
    }
    std::cout << "##                                                                                        ##" << std::endl;
    std::cout << "##     0 -> Voltar                                                                        ##" << std::endl;
    std::cout << "##                                                                                        ##" << std::endl;
    std::cout << "############################################################################################" << std::endl<< std::endl;

    std::cout<<"Volta? ";
    std::string a;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin,a);
    if (a == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        gratestKInterface();
    }
    else{
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        gratestKShowInterface(k);
    }
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
    for (auto v : g->getVertexSet())v.second->setIndegree(0);
    for (auto v : g->getVertexSet()){
        for (auto d : v.second->getAdj()){
            auto a = d.getDest();
            a->setIndegree(a->getIndegree() + 1);
        }
    }
    for (auto vertex : g->getVertexSet()) highest.push_back({vertex.second->getInfo(), vertex.second->getIndegree()+vertex.second->getAdj().size()});
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
        std::cout << "##    " << g->getVertexSet().find(k)->second->getInfo().getName() << addspasces(g->getVertexSet().find(k)->second->getInfo().getName(), 79)
                  << "##" << std::endl;
    }
    std::cout << "##                                                                                   ##" << std::endl;
    std::cout << "##     ----- " << airports.size() << addspasces(to_string(airports.size()), 72) << "##" << std::endl;
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
    Graph<Airport>k;
    for (auto v : g->getVertexSet()){
        k.addVertex(v.first,v.second->getInfo());
    }
    k.setVertexSet(g->getVertexSet());
    int c = 0;
    for (auto v : g->getVertexSet()){
        c += v.second->getAdj().size();
    }
    cout << c <<endl;
    c = 0;
    for (auto v : k.getVertexSet()){
        c += v.second->getAdj().size();
    }
    cout << c <<endl;
    for (auto v : k.getVertexSet()){
        for (auto d : v.second->getAdj()){
            k.addEdge(d.getDest()->getInfo().getCode(),v.second->getInfo().getCode(),d.getAirlineOfFlight());
        }
    }
    c = 0;
    for (auto v : g->getVertexSet()){
        c += v.second->getAdj().size();
    }
    cout << c <<endl;
    c = 0;
    for (auto v : k.getVertexSet()){
        c += v.second->getAdj().size();
    }
    cout << c <<endl;
    int i = 0; // Contagem
    for (auto vertex : k.getVertexSet()){
        vertex.second->setNum(0);
        vertex.second->setProcessing(false);
    }
    for (auto vertex : k.getVertexSet()) {
        if (vertex.second->getNum() == 0){
            dfs_art(vertex.second,res,i);
        }
    }
    return res;
}
/////////////////////////////////
//       4                     //
/////////////////////////////////
void showInterface(vector<vector<Flight>> res, Graph<Airport>* g){

    std::cout<<std::endl;
    std::cout <<  "##############################################################################" << std::endl;
    std::cout <<  "##                                                                          ##" << std::endl;
    int k = 0;
    for (auto f : res){
        std::cout <<"##    "<< "Opcao " << k <<" : "<<addspasces(to_string(k),61)<<"##"<<std::endl;
        std::cout <<  "##                                                                          ##" << std::endl;
        for (auto h : f){
            std::cout <<"##  _ "<< g->getVertexSet().find(h.getSource())->second->getInfo().getName() << " -> " << g->getVertexSet().find(h.getTarget())->second->getInfo().getName() << ".: " << h.getAirlineFromFlight()<<addspasces(g->getVertexSet().find(h.getSource())->second->getInfo().getName()+g->getVertexSet().find(h.getTarget())->second->getInfo().getName()+h.getAirlineFromFlight(),63) << "##"<<std::endl;
        }
        k++;
    }
    std::cout <<  "##                                                                          ##" << std::endl;
    std::cout <<  "##    Estes voos tem " <<res.begin()->size()<<" paragens."<<addspasces(to_string(res.begin()->size()),45)<<"##"<<std::endl;
    std::cout <<  "##                                                                          ##" << std::endl;
    std::cout <<  "##    0 -> Voltar                                                           ##" << std::endl;
    std::cout <<  "##                                                                          ##" << std::endl;
    std::cout <<  "##############################################################################" << std::endl;
}
bool inQueue(queue<Vertex<Airport> *> q,Vertex<Airport> * a){
    while (!q.empty()){
        if (a == q.front())return true;
        q.pop();
    }
    return false;
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
void Menu::flightOptionsInterfaceStart(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Mostrar voos:                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     De :                                                          ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          1 -> Aeroporto                                           ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          2 -> Cidade                                              ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          3 -> Coordenadas geograficas                             ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"De : ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        secBase();
        return;
    }else if ( stoi(k) > 0 && stoi(k) <= 3)flightOptionsInterfaceTarget(stoi(k));
    else{
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        flightOptionsInterfaceStart();
    }
}
void Menu::flightOptionsInterfaceTarget(int i){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Mostrar voos:                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Para:                                                         ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          1 -> Aeroporto                                           ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          2 -> Cidade                                              ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          3 -> Coordenadas geograficas                             ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"Para: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        flightOptionsInterfaceStart();
        return;
    }else if ( stoi(k) > 0 && stoi(k) <= 3) preferenceAirlineInterface(i,stoi(k));
    else{
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        flightOptionsInterfaceStart();
    }
}
void Menu::preferenceAirlineInterface(int i ,int d){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Quer escolher as companhias aereas?                             ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          1 -> Sim                                                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          2 -> Nao (voos de todas as companhias)                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"Opcao: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        flightOptionsInterfaceTarget(i);
        return;
    }else if (k == "1")preferenceAirlineChosingInterface(i,d);
    else if (k == "2")minimizeAirlinesInterface(i,d,{});
    else{
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        preferenceAirlineInterface(i,d);
    }
}
void Menu::preferenceAirlineChosingInterface(int i ,int d){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Escreve as companhias separadas por virgulas :                  ##"<<std::endl;
    std::cout<<"##   (Codigo ou o nome)                                              ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     1 -> Introduza as companhias:_______                          ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"Companhias : ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    vector<std::string> airlines;
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        preferenceAirlineInterface(i,d);
        return;
    }
    istringstream iss(k);
    string eachAirline;
    while (getline(iss, eachAirline, ',')) airlines.push_back(eachAirline);
    for (auto a : airlines)if (!existAirline(a)){
            std::cout << "Por favor escreva companhias que constem na nossa base de dados." << std::endl;
            preferenceAirlineChosingInterface(i,d);
            return;
        }
    minimizeAirlinesInterface(i,d,airlines);
}

void Menu::minimizeAirlinesInterface(int i ,int d,vector<std::string>airlines){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Quer minimizar o numero de companhias aereas necessarias?       ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          1 -> Sim                                                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          2 -> Nao                                                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"Opcao: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        preferenceAirlineInterface(i, d);
        return;
    }else if (k == "1")choose(i,d,airlines,true);
    else if (k == "2")choose(i,d,airlines,false);
    else{
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        minimizeAirlinesInterface(i,d,airlines);
    }
}
void Menu::choose(int i ,int d,vector<std::string>airlines,bool minimize){
    switch (i) {
        case 1:
            switch (d) {
                case 1:
                    AirportToAirportInterface(i,d,airlines,minimize);
                    break;
                case 2:
                    AirportToCityInterface(i,d,airlines,minimize);
                    break;
                case 3:
                    AirportToGeoCordinatesInterface(i,d,airlines,minimize);
                    break;
            }
            break;
        case 2:
            switch (d) {
                case 1:
                    CityToAirportInterface(i,d,airlines,minimize);
                    break;
                case 2:
                    CityToCityInterface(i,d,airlines,minimize);
                    break;
                case 3:
                    CityToGeoCordinatesInterface(i,d,airlines,minimize);
                    break;
            }
            break;
        case 3:
            switch (d) {
                case 1:
                    GeoCordinatesToAirportInterface(i,d,airlines,minimize);
                    break;
                case 2:
                    GeoCordinatesToCityInterface(i,d,airlines,minimize);
                    break;
                case 3:
                    GeoCordinatesToGeoCordinatesInterface(i,d,airlines,minimize);
                    break;
            }
            break;
    }
}
void Menu::AirportToAirportInterface(int i ,int d,vector<std::string>airlines,bool minimize){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Digite os Aeroportos :                                          ##"<<std::endl;
    std::cout<<"##   (Codigo ou o nome)                                              ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     1 -> Primeiro aeroporto:_______                               ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     2 -> Segundo aeroporto:_______                                ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"Escolha o primeiro : ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    auto r = getAirportByName(k);
    if (r == nullptr) r = getAirportByCode(k);
    if (r == nullptr) {
        std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        AirportToAirportInterface(i,d,airlines,minimize);
        return;
    }
    std::cout<<"Escolha o segundo : ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    auto r2 = getAirportByName(k);
    if (r2 == nullptr)r2 = getAirportByCode(k);
    if (r2 == nullptr) {
        std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        AirportToAirportInterface(i,d,airlines,minimize);
        return;
    }
    AirportToAirportInterfaceResult(i,d,airlines,minimize,r,r2);
}
void Menu::AirportToAirportInterfaceResult(int i ,int d,vector<std::string>airlines,bool minimize,Vertex<Airport>* v, Vertex<Airport>* b){
    vector<vector<Flight>> res;
    if (airlines.empty())res = AirportToAirport(v,b);
    else res = AirportToAirportWF(v,b,airlines);
    if (minimize)minimizeAirlines(res);
    showInterface(res,g);
    std::cout << "Voltar?";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::cin>> k;
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        AirportToAirportInterface(i,d,airlines,minimize);}
    else{
            std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
            AirportToAirportInterfaceResult(i,d,airlines,minimize,v,b);
    }
    // Interface de resposta
}
vector<vector<Flight>> Menu::AirportToAirport(Vertex<Airport>* v, Vertex<Airport>* b){
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
            if (!w->isVisited() && !inQueue(q,w)){
                w->setFEmpty();
                for (auto f : v->getFlights()){w->addFlight(f);}
                w->addFlight(Flight(v->getInfo().getCode(),w->getInfo().getCode(),e.getAirlineOfFlight().getName()));
                if (w == b){
                    isFound = true;
                    res.push_back(w->getFlights());
                }
                if (!inQueue(q2,w))q2.push(w);
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
void Menu::AirportToCityInterface(int i ,int d,vector<std::string>airlines,bool minimize){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Digite os Parametros :                                          ##"<<std::endl;
    std::cout<<"##   (Codigo ou o nome do Aeroporto)                                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Aeroporto:_______                                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Cidade:_______                                     ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"Aeroporto: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    auto r = getAirportByName(k);
    if (r == nullptr) r = getAirportByCode(k);
    if (r == nullptr) {
        std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        AirportToCityInterface(i,d,airlines,minimize);
        return;
    }
    std::cout<<"Cidade: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (!existCity(k)){
        std::cout << "O nome da cidade que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        AirportToCityInterface(i,d,airlines,minimize);
        return;
    }
    AirportToCityInterfaceResult(i,d,airlines,minimize,r,k);
}
void Menu::AirportToCityInterfaceResult(int i ,int d,vector<std::string>airlines,bool minimize,Vertex<Airport>* v, std::string c){
    auto res = AirportToCity(v,c,airlines);
    if (minimize)minimizeAirlines(res);
    showInterface(res,g);
    std::cout << "Voltar?";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::cin>> k;
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        AirportToCityInterface(i,d,airlines,minimize);
    }
    else{
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        AirportToCityInterfaceResult(i,d,airlines,minimize,v,c);
    }
}
vector<vector<Flight>> Menu::AirportToCity(Vertex<Airport>* v, std::string c,vector<std::string>airlines){
    queue<Vertex<Airport> *> q1;
    queue<Vertex<Airport> *> q2;
    for (auto v : g->getVertexSet()){
        if (v.second->getInfo().getCity() == c)q2.push(v.second);
    }
    q1.push(v);
    if (airlines.empty())return ListAirportToListAirport(q1,q2);
    else return ListAirportToListAirportWF(q1,q2,airlines);
}
void Menu::AirportToGeoCordinatesInterface(int i, int d, vector<std::string> airlines, bool minimize){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Digite os Parametros :                                          ##"<<std::endl;
    std::cout<<"##   (Codigo ou o nome do Aeroporto)                                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Aeroporto:_______                                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Latitude destino:_______(-90 a 90)                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Longitude destino:_______(-180 a 180)              ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"Aeroporto: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    auto r = getAirportByName(k);
    if (r == nullptr) r = getAirportByCode(k);
    if (r == nullptr) {
        std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        AirportToGeoCordinatesInterface(i,d,airlines,minimize);
        return;
    }
    std::cout<<"Latitude: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (stod(k) < -90 || stod(k) > 90){
        std::cout << "A latitude deve compreender os valores colocados na tela." << std::endl;
        AirportToGeoCordinatesInterface(i,d,airlines,minimize);
        return;
    }
    std::cout<<"Longitude: ";
    std::cin.clear();
    std::cin.sync();
    std::string k1;
    std::getline(std::cin, k1);
    if (k1 == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (stod(k1) < -180 || stod(k1) > 180){
        std::cout << "A latitude deve compreender os valores colocados na tela." << std::endl;
        AirportToGeoCordinatesInterface(i,d,airlines,minimize);
        return;
    }
    AirportToGeoCordinatesInterfaceResult(i,d,airlines,minimize,r,stod(k), stod(k1));
}
void Menu::AirportToGeoCordinatesInterfaceResult(int i, int d, vector<std::string>airlines,bool minimize,Vertex<Airport>* v,double lat1,double long1){
    auto res = AirportToGeoCordinates(v,lat1,long1,airlines);
    if (minimize)minimizeAirlines(res);
    showInterface(res,g);
    std::cout << "Voltar?";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::cin>> k;
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        AirportToGeoCordinatesInterface(i,d,airlines,minimize);
    }
    else{
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        AirportToGeoCordinatesInterfaceResult(i,d,airlines,minimize,v,lat1,long1);
    }
}
vector<vector<Flight>> Menu::AirportToGeoCordinates(Vertex<Airport>* v,double lat1,double long1,vector<std::string>airlines){
    queue<Vertex<Airport> *> q1;
    queue<Vertex<Airport> *> q2;
    double minDistance = INT16_MAX;
    q1.push(v);
    for (auto v : g->getVertexSet()){
        double d = haversineDistance(lat1,v.second->getInfo().getLatitude(),long1,v.second->getInfo().getLongitude());
        if (d == minDistance)q2.push(v.second);
        else if (d < minDistance){
            minDistance = d;
            while (!q2.empty())q2.pop();
            q2.push(v.second);
        }
    }
    if (airlines.empty())return ListAirportToListAirport(q1,q2);
    else return ListAirportToListAirportWF(q1,q2,airlines);
}
void Menu::CityToCityInterface(int i, int d, vector<std::string>airlines,bool minimize){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Digite os Parametros :                                          ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Cidade 1:_______                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Cidade 2:_______                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"Cidade 1 : ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (!existCity(k)){
        std::cout << "O nome da cidade que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        AirportToCityInterface(i,d,airlines,minimize);
        return;
    }
    std::cout<<"Cidade 2 : ";
    std::cin.clear();
    std::cin.sync();
    std::string k1;
    std::getline(std::cin, k1);
    if (k1 == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (!existCity(k1)){
        std::cout << "O nome da cidade que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        AirportToCityInterface(i,d,airlines,minimize);
        return;
    }
    CityToCityInterfaceResult(i,d,airlines,minimize,k,k1);
}
void Menu::CityToCityInterfaceResult(int i, int d, vector<std::string> airlines, bool minimize, std::string c1,std::string c2) {
    auto res = CityToCity(c1,c2,airlines);
    if (minimize)minimizeAirlines(res);
    showInterface(res,g);
    std::cout << "Voltar?";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::cin>> k;
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        CityToCityInterface(i,d,airlines,minimize);
    }
    else{
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        CityToCityInterfaceResult(i,d,airlines,minimize,c1,c2);
    }

}
vector<vector<Flight>> Menu::CityToCity(std::string a, std::string b,vector<std::string>airlines){
    queue<Vertex<Airport> *> q1;
    queue<Vertex<Airport> *> q2;
    for (auto v : g->getVertexSet()){
        if (v.second->getInfo().getCity() == a)q1.push(v.second);
        if (v.second->getInfo().getCity() == b)q2.push(v.second);
    }
    if (airlines.empty())return ListAirportToListAirport(q1,q2);
    else return ListAirportToListAirportWF(q1,q2,airlines);
}
void Menu::CityToAirportInterface(int i , int d ,vector<std::string>airlines,bool minimize){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Digite os Parametros :                                          ##"<<std::endl;
    std::cout<<"##   (Escrever codigo ou nome do Aeroporto)                          ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Cidade:_______                                     ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Aeroporto:_______                                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"Cidade: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (!existCity(k)){
        std::cout << "O nome da cidade que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        CityToAirportInterface(i,d,airlines,minimize);
        return;
    }
    std::cout<<"Aeroporto: ";
    std::cin.clear();
    std::cin.sync();
    std::string k2;
    std::getline(std::cin, k2);
    if (k2 == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    auto r = getAirportByName(k2);
    if (r == nullptr) r = getAirportByCode(k2);
    if (r == nullptr) {
        std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        CityToAirportInterface(i,d,airlines,minimize);
        return;
    }
    CityToAirportInterfaceResult(i,d,airlines,minimize,k,r);
}
void Menu::CityToAirportInterfaceResult(int i, int d,vector<std::string>airlines,bool minimize,std::string c, Vertex<Airport>* v){
    auto res = CityToAirport(c,v,airlines);
    if (minimize)minimizeAirlines(res);
    showInterface(res,g);
    std::cout << "Voltar?";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::cin>> k;
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        CityToAirportInterface(i,d,airlines,minimize);

    }
    else{
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        CityToAirportInterfaceResult(i,d,airlines,minimize,c,v);
    }
}
vector<vector<Flight>> Menu::CityToAirport(std::string c, Vertex<Airport>* v,vector<std::string>airlines){
    queue<Vertex<Airport> *> q1;
    queue<Vertex<Airport> *> q2;
    q2.push(v);
    for (auto v : g->getVertexSet()){
        if (v.second->getInfo().getCity() == c){
            q1.push(v.second);
        }
    }
    if (airlines.empty())return ListAirportToListAirport(q1,q2);
    else return ListAirportToListAirportWF(q1,q2,airlines);
}
void Menu::CityToGeoCordinatesInterface(int i, int d, vector<std::string>airlines,bool minimize){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Digite os Parametros :                                          ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Cidade:_______                                     ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Latitude destino:_______(-90 a 90)                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Longitude destino:_______(-180 a 180)              ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"Cidade: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (!existCity(k)){
        std::cout << "O nome da cidade que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        CityToGeoCordinatesInterface(i,d,airlines,minimize);
        return;
    }
    std::cout<<"Latitude: ";
    std::cin.clear();
    std::cin.sync();
    std::string k2;
    std::getline(std::cin, k2);
    if (k2 == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (stod(k2) < -90 || stod(k2) > 90){
        std::cout << "A latitude deve compreender os valores colocados na tela." << std::endl;
        CityToGeoCordinatesInterface(i,d,airlines,minimize);
        return;
    }
    std::cout<<"Longitude: ";
    std::cin.clear();
    std::cin.sync();
    std::string k1;
    std::getline(std::cin, k1);
    if (k1 == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (stod(k1) < -180 || stod(k1) > 180){
        std::cout << "A latitude deve compreender os valores colocados na tela." << std::endl;
        CityToGeoCordinatesInterface(i,d,airlines,minimize);
        return;
    }
    CityToGeoCordinatesInterfaceResult(i,d,airlines,minimize,k,stod(k2), stod(k1));
}
void Menu::CityToGeoCordinatesInterfaceResult(int i, int d, vector<std::string>airlines,bool minimize,std::string c, double lat1,double long1){
    auto res = CityToGeoCordinates(c,lat1,long1,airlines);
    if (minimize)minimizeAirlines(res);
    showInterface(res,g);
    std::cout << "Voltar?";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::cin>> k;
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        CityToGeoCordinatesInterface(i,d,airlines,minimize);
    }
    else{
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        CityToGeoCordinatesInterfaceResult(i,d,airlines,minimize,c,lat1,long1);
    }


}
vector<vector<Flight>> Menu::CityToGeoCordinates(std::string c,double lat1,double long1,vector<std::string>airlines){
    queue<Vertex<Airport> *> q1;
    queue<Vertex<Airport> *> q2;
    double minDistance = INT16_MAX;
    for (auto v : g->getVertexSet()){
        if (v.second->getInfo().getCity() == c)q1.push(v.second);
        double d = haversineDistance(lat1,v.second->getInfo().getLatitude(),long1,v.second->getInfo().getLongitude());
        if (d == minDistance)q1.push(v.second);
        else if (d < minDistance){
            minDistance = d;
            while (!q2.empty())q2.pop();
            q2.push(v.second);
        }
    }
    if (airlines.empty())return ListAirportToListAirport(q1,q2);
    else return ListAirportToListAirportWF(q1,q2,airlines);
}
void Menu::GeoCordinatesToAirportInterface(int i,int d,vector<std::string>airlines,bool minimize){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Digite os Parametros :                                          ##"<<std::endl;
    std::cout<<"##   (Codigo ou nome do aeroporto)                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Latitude inicio:_______(-90 a 90)                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Longitude inicio:_______(-180 a 180)               ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Aeroporto:_______                                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::cout<<"Latitude: ";
    std::cin.clear();
    std::cin.sync();
    std::string k2;
    std::getline(std::cin, k2);
    if (k2 == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (stod(k2) < -90 || stod(k2) > 90){
        std::cout << "A latitude deve compreender os valores colocados na tela." << std::endl;
        GeoCordinatesToAirportInterface(i,d,airlines,minimize);
        return;
    }
    std::cout<<"Longitude: ";
    std::cin.clear();
    std::cin.sync();
    std::string k1;
    std::getline(std::cin, k1);
    if (k1 == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (stod(k1) < -180 || stod(k1) > 180){
        std::cout << "A latitude deve compreender os valores colocados na tela." << std::endl;
        GeoCordinatesToAirportInterface(i,d,airlines,minimize);
        return;
    }
    std::string k;
    std::cout<<"Aeroporto: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    auto r = getAirportByName(k);
    if (r == nullptr) r = getAirportByCode(k);
    if (r == nullptr) {
        std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        AirportToGeoCordinatesInterface(i,d,airlines,minimize);
        return;
    }
    GeoCordinatesToAirportInterfaceResult(i,d,airlines,minimize, stod(k2), stod(k1),r);
}
void Menu::GeoCordinatesToAirportInterfaceResult(int i,int d,vector<std::string>airlines,bool minimize,double lat1,double long1,Vertex<Airport>* v){
    auto res = GeoCordinatesToAirport(lat1,long1,v,airlines);
    if (minimize)minimizeAirlines(res);
    showInterface(res,g);
    std::cout << "Voltar?";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::cin>> k;
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        GeoCordinatesToAirportInterface(i,d,airlines,minimize);
    }
    else{
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        GeoCordinatesToAirportInterfaceResult(i,d,airlines,minimize,lat1,long1,v);
    }

}
vector<vector<Flight>> Menu::GeoCordinatesToAirport(double lat1,double long1,Vertex<Airport>* v,vector<std::string>airlines){
    queue<Vertex<Airport> *> q1;
    queue<Vertex<Airport> *> q2;
    double minDistance = INT16_MAX;
    q2.push(v);
    for (auto v : g->getVertexSet()){
        double d = haversineDistance(lat1,v.second->getInfo().getLatitude(),long1,v.second->getInfo().getLongitude());
        if (d == minDistance)q1.push(v.second);
        else if (d < minDistance){
            minDistance = d;
            while (!q1.empty())q1.pop();
            q1.push(v.second);
        }
    }
    if (airlines.empty())return ListAirportToListAirport(q1,q2);
    else return ListAirportToListAirportWF(q1,q2,airlines);
}
void Menu::GeoCordinatesToCityInterface(int i,int d,vector<std::string>airlines,bool minimize){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Digite os Parametros :                                          ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Latitude inicio:_______(-90 a 90)                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Longitude inicio:_______(-180 a 180)               ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Cidade:_______                                     ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::cout<<"Latitude: ";
    std::cin.clear();
    std::cin.sync();
    std::string k2;
    std::getline(std::cin, k2);
    if (k2 == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (stod(k2) < -90 || stod(k2) > 90){
        std::cout << "A latitude deve compreender os valores colocados na tela." << std::endl;
        CityToGeoCordinatesInterface(i,d,airlines,minimize);
        return;
    }
    std::cout<<"Longitude: ";
    std::cin.clear();
    std::cin.sync();
    std::string k1;
    std::getline(std::cin, k1);
    if (k1 == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (stod(k1) < -180 || stod(k1) > 180){
        std::cout << "A latitude deve compreender os valores colocados na tela." << std::endl;
        CityToGeoCordinatesInterface(i,d,airlines,minimize);
        return;
    }
    std::string k;
    std::cout<<"Cidade: ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (!existCity(k)){
        std::cout << "O nome da cidade que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        CityToGeoCordinatesInterface(i,d,airlines,minimize);
        return;
    }
    GeoCordinatesToCityInterfaceResult(i,d,airlines,minimize,stod(k2), stod(k1),k);
}
void Menu::GeoCordinatesToCityInterfaceResult(int i,int d,vector<std::string>airlines,bool minimize,double lat1,double long1,std::string c){
    auto res = GeoCordinatesToCity(lat1,long1,c,airlines);
    if (minimize)minimizeAirlines(res);
    showInterface(res,g);
    std::cout << "Voltar?";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::cin>> k;
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        GeoCordinatesToCityInterface(i,d,airlines,minimize);
    }
    else{
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        GeoCordinatesToCityInterfaceResult(i,d,airlines,minimize,lat1,long1,c);
    }

}
vector<vector<Flight>> Menu::GeoCordinatesToCity(double lat1,double long1,std::string c,vector<std::string>airlines){
    queue<Vertex<Airport> *> q1;
    queue<Vertex<Airport> *> q2;
    double minDistance = INT16_MAX;
    for (auto v : g->getVertexSet()){
        if (v.second->getInfo().getCity() == c)q2.push(v.second);
        double d = haversineDistance(lat1,v.second->getInfo().getLatitude(),long1,v.second->getInfo().getLongitude());
        if (d == minDistance)q1.push(v.second);
        else if (d < minDistance){
            minDistance = d;
            while (!q1.empty())q1.pop();
            q1.push(v.second);
        }
    }
    if (airlines.empty())return ListAirportToListAirport(q1,q2);
    else return ListAirportToListAirportWF(q1,q2,airlines);
}
void Menu::GeoCordinatesToGeoCordinatesInterface(int i,int d,vector<std::string>airlines,bool minimize){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Digite os Parametros :                                          ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Latitude inicio:_______(-90 a 90)                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Longitude inicio:_______(-180 a 180)               ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Latitude destino:_______(-90 a 90)                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     Introduzir Longitude destino:_______(-180 a 180)              ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::cout<<"Latitude: ";
    std::cin.clear();
    std::cin.sync();
    std::string k1;
    std::getline(std::cin, k1);
    if (k1 == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (stod(k1) < -90 || stod(k1) > 90){
        std::cout << "A latitude deve compreender os valores colocados na tela." << std::endl;
        CityToGeoCordinatesInterface(i,d,airlines,minimize);
        return;
    }
    std::cout<<"Longitude: ";
    std::cin.clear();
    std::cin.sync();
    std::string k2;
    std::getline(std::cin, k2);
    if (k2 == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (stod(k2) < -180 || stod(k2) > 180){
        std::cout << "A latitude deve compreender os valores colocados na tela." << std::endl;
        CityToGeoCordinatesInterface(i,d,airlines,minimize);
        return;
    }
    std::cout<<"Latitude: ";
    std::cin.clear();
    std::cin.sync();
    std::string k3;
    std::getline(std::cin, k3);
    if (k3 == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (stod(k3) < -90 || stod(k3) > 90){
        std::cout << "A latitude deve compreender os valores colocados na tela." << std::endl;
        CityToGeoCordinatesInterface(i,d,airlines,minimize);
        return;
    }
    std::cout<<"Longitude: ";
    std::cin.clear();
    std::cin.sync();
    std::string k4;
    std::getline(std::cin, k4);
    if (k4 == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        minimizeAirlinesInterface( i,d,airlines);
        return;
    }
    if (stod(k4) < -180 || stod(k4) > 180){
        std::cout << "A latitude deve compreender os valores colocados na tela." << std::endl;
        CityToGeoCordinatesInterface(i,d,airlines,minimize);
        return;
    }
    GeoCordinatesToGeoCordinatesInterfaceResult(i,d,airlines,minimize, stod(k1), stod(k2), stod(k3), stod(k4));
}
void Menu::GeoCordinatesToGeoCordinatesInterfaceResult(int i,int d,vector<std::string>airlines,bool minimize,double lat1,double lat2,double long1,double long2){
    auto res = GeoCordinatesToGeoCordinates(lat1,lat2,long1,long2,airlines);
    if (minimize)minimizeAirlines(res);
    showInterface(res,g);
    std::cout << "Voltar?";
    std::string k;
    std::cin.clear();
    std::cin.sync();
    std::cin>> k;
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        GeoCordinatesToGeoCordinatesInterface(i,d,airlines,minimize);
    }
    else{
        std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
        GeoCordinatesToGeoCordinatesInterfaceResult(i,d,airlines,minimize,lat1,lat2,long1,long2);
    }

}
vector<vector<Flight>> Menu::GeoCordinatesToGeoCordinates(double lat1,double lat2,double long1,double long2,vector<std::string>airlines){
    queue<Vertex<Airport>*> Sourceairports;
    queue<Vertex<Airport>*> Targetairports;
    double minDistance = INT16_MAX;
    double minDistance2 = INT16_MAX;
    for (auto v : g->getVertexSet()){
        double d = haversineDistance(lat1,v.second->getInfo().getLatitude(),long1,v.second->getInfo().getLongitude());
        double d2 = haversineDistance(lat2,v.second->getInfo().getLatitude(),long2,v.second->getInfo().getLongitude());
        if (d == minDistance)Sourceairports.push(v.second);
        else if (d < minDistance){
            minDistance = d;
            while (!Sourceairports.empty())Sourceairports.pop();
            Sourceairports.push(v.second);
        }
        if (d2 == minDistance2)Targetairports.push(v.second);
        else if (d2 < minDistance2){
            minDistance2 = d2;
            while (!Targetairports.empty())Targetairports.pop();
            Targetairports.push(v.second);
        }
    }
    if (airlines.empty())return ListAirportToListAirport(Sourceairports,Targetairports);
    else return ListAirportToListAirportWF(Sourceairports,Targetairports,airlines);
}
vector<vector<Flight>> Menu::ListAirportToListAirport(queue<Vertex<Airport>*> s, queue<Vertex<Airport>*> t){
    vector<vector<Flight>> res;
    queue<Vertex<Airport> *> q2;
    for (auto k : g->getVertexSet()){
        k.second->setVisited(false);
        k.second->setFEmpty();
    }
    bool isFound = false;
    while (!s.empty()) {
        auto v = s.front();
        s.pop();
        for (auto & e : v->getAdj()) {
            auto w = e.getDest();
            if (!w->isVisited() && !inQueue(s,w)){
                w->setFEmpty();
                for (auto f : v->getFlights()){w->addFlight(f);}
                w->addFlight(Flight(v->getInfo().getCode(),w->getInfo().getCode(),e.getAirlineOfFlight().getName()));
                if (inQueue(t,w)){
                    isFound = true;
                    res.push_back(w->getFlights());
                }
                if (!inQueue(q2,w))q2.push(w);
            }
        }
        v->setVisited(true);
        if (s.empty()){
            if(isFound)break;
            s = q2;
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
vector<vector<Flight>> Menu::AirportToAirportWF(Vertex<Airport>* v, Vertex<Airport>* b,vector<std::string> airlines){
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
            if (!w->isVisited() && !inQueue(q,w) && (inVector(airlines,e.getAirlineOfFlight().getCode())||inVector(airlines,e.getAirlineOfFlight().getName()))){
                w->setFEmpty();
                for (auto f : v->getFlights()){w->addFlight(f);}
                w->addFlight(Flight(v->getInfo().getCode(),w->getInfo().getCode(),e.getAirlineOfFlight().getName()));
                if (w == b){
                    isFound = true;
                    res.push_back(w->getFlights());
                }
                if (!inQueue(q2,w))q2.push(w);
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
vector<vector<Flight>> Menu::ListAirportToListAirportWF(queue<Vertex<Airport>*> s, queue<Vertex<Airport>*> t,vector<std::string>airlines){
    vector<vector<Flight>> res;
    queue<Vertex<Airport> *> q2;
    for (auto k : g->getVertexSet()){
        k.second->setVisited(false);
        k.second->setFEmpty();
    }
    bool isFound = false;
    while (!s.empty()) {
        auto v = s.front();
        s.pop();
        for (auto & e : v->getAdj()) {
            auto w = e.getDest();
            if (!w->isVisited() && !inQueue(s,w) && (inVector(airlines,e.getAirlineOfFlight().getCode())||inVector(airlines,e.getAirlineOfFlight().getName()))){
                w->setFEmpty();
                for (auto f : v->getFlights()){w->addFlight(f);}
                w->addFlight(Flight(v->getInfo().getCode(),w->getInfo().getCode(),e.getAirlineOfFlight().getName()));
                if (inQueue(t,w)){
                    isFound = true;
                    res.push_back(w->getFlights());
                }
                if (!inQueue(q2,w))q2.push(w);
            }
        }
        v->setVisited(true);
        if (s.empty()){
            if(isFound)break;
            s = q2;
            while (!q2.empty())q2.pop();
        }
    }
    return res;
}
void Menu::minimizeAirlines(vector<vector<Flight>> &flights){
    int minV = INT16_MAX;
    for (auto f : flights){
        set<std::string> airlines;
        for (auto a : f) airlines.insert(a.getAirlineFromFlight());
        minV = min(int(airlines.size()),minV);
    }
    auto it = flights.begin();
    while (it != flights.end()) {
        set<std::string> airlines;
        for (auto a : *it) airlines.insert(a.getAirlineFromFlight());
        if (minV < int(airlines.size())){
            it = flights.erase(it);
        } else {
            ++it;
        }
    }


}