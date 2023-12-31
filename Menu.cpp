//
// Created by User on 23/12/2023.
//

#include <algorithm>
#include "Menu.h"
#include <cmath>


//void nDestinationsShowInterface(Airport airport, int i);

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
bool Menu::existCountry(std::string c){
    return countries.find(c) != countries.end();
}
bool Menu::existAirline(std::string airline){
    return airlinesNames.find(airline) != airlinesNames.end() || airlinesCodes.find(airline) != airlinesCodes.end();
}

void Menu::Base(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Consultar :                                                     ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      1 -> Mostrar voos                                            ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      0 -> Fechar Menu                                             ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;

    int k;
    std::cout<<"Opcao: ";
    std::cin>>k;

    switch (k){
        case 1:
            DisplayOptions();
    }
    Base();
}

//////// Início do 1 /////////////////////

void Menu::DisplayOptions(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Mostrar voos:                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     (Companhia de voos irrelevante)                               ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      1 -> Com uma certa origem                                    ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      2 -> Com um certo destino                                    ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      3 -> Com uma certa origem e um certo destino                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      4 -> Todos os voos                                           ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     (Companhia de voos relevante)                                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      5 -> Com uma certa origem                                    ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      6 -> Com um certo destino                                    ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      7 -> Com uma certa origem e um certo destino                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      8 -> Todos os voos                                           ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;

    int k;
    std::cout<<"Opcao: ";
    std::cin>>k;

    switch (k){
        case 1:
            SourceNo();
        case 2:
            DestNo();
        case 3:
            SourceDestNo();
        case 4:
            allNo();
        case 5:
            SourceYes();
        case 6:
            DestYes();
        case 7:
            SourceDestYes();
        case 8:
            allYes();
        case 0:
            Base();
    }
    DisplayOptions();
}

void Menu::SourceNo(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Introduzir :                                                    ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      Local de origem:______                                       ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;

    std::string source;
    std::cout<<"Local de origem: ";
    std::cin>>source;
    if (source == "0") DisplayOptions();
    bool exists = false;


    for (auto vertex : g->getVertexSet()) {
        if (vertex.second->getInfo().getName() == source) {
            exists = true;
            for (auto flight : vertex.second->getAdj()) {
                std::cout << "Existe um voo que parte de " << vertex.second->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
            }
        }
    }
    if (!exists) std::cout << "Não existe nenhum voo com essas especificações." << std::endl;
    DisplayOptions();
}

void Menu::DestNo(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Introduzir :                                                    ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      Local de destino:______                                      ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;

    std::string target;
    std::cout<<"Local de destino: ";
    std::cin>>target;
    if (target == "0") DisplayOptions();
    bool exists = false;

    for (auto vertex : g->getVertexSet()) {
        for (auto flight : vertex.second->getAdj()) {
            if (flight.getDest()->getInfo().getName() == target) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex.second->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
            }
        }
    }
    if (!exists) std::cout << "Não existe nenhum voo com essas especificações." << std::endl;
    DisplayOptions();
}

void Menu::SourceDestNo(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Introduzir :                                                    ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      Local de origem:______                                       ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      Local de destino:______                                      ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;

    std::string source;
    std::cout<<"Local de origem: ";
    std::cin>>source;
    if (source == "0") DisplayOptions();
    std::string target;
    std::cout<<"Local de destino: ";
    std::cin>>target;
    bool exists = false;

    for (auto vertex : g->getVertexSet()) {
        for (auto flight : vertex.second->getAdj()) {
            if (vertex.second->getInfo().getName() == source && flight.getDest()->getInfo().getName() == target) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex.second->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
            }
        }
    }
    if (!exists) std::cout << "Não existe nenhum voo com essas especificações." << std::endl;
    DisplayOptions();
}

void Menu::allNo(){
    bool exists = false;
    for (auto vertex : g->getVertexSet()) {
        for (auto flight : vertex.second->getAdj()) {
            exists = true;
            std::cout << "Existe um voo que parte de " << vertex.second->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
        }
    }
    if (!exists) std::cout << "Não existe nenhum voo com essas especificações." << std::endl;
    DisplayOptions();
}

void Menu::SourceYes(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Introduzir :                                                    ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      Companhia aérea:______                                       ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      Local de origem:______                                       ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;

    std::string airline;
    std::cout<<"Companhia aérea: ";
    std::cin>>airline;
    if (airline == "0") DisplayOptions();
    std::string source;
    std::cout<<"Local de origem: ";
    std::cin>>source;
    bool exists = false;

    for (auto vertex : g->getVertexSet()) {
        for (auto flight : vertex.second->getAdj()) {
            if (flight.getAirlineOfFlight().getName() == airline && vertex.second->getInfo().getName() == source) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex.second->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
            }
        }
    }
    if (!exists) std::cout << "Não existe nenhum voo com essas especificações." << std::endl;
    DisplayOptions();
}

void Menu::DestYes(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Introduzir :                                                    ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      Companhia aérea:______                                       ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      Local de destino:______                                       ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;

    std::string airline;
    std::cout<<"Companhia aérea: ";
    std::cin>>airline;
    if (airline == "0") DisplayOptions();
    std::string target;
    std::cout<<"Local de destino: ";
    std::cin>>target;
    bool exists = false;

    for (auto vertex : g->getVertexSet()) {
        for (auto flight : vertex.second->getAdj()) {
            if (flight.getAirlineOfFlight().getName() == airline && flight.getDest()->getInfo().getName()== target) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex.second->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
            }
        }
    }
    if (!exists) std::cout << "Não existe nenhum voo com essas especificações." << std::endl;
    DisplayOptions();
}

void Menu::SourceDestYes(){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Introduzir :                                                    ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      Companhia aérea:______                                       ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      Local de origem:______                                       ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      Local de destino:______                                      ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;

    std::string airline;
    std::cout<<"Companhia aérea: ";
    std::cin>>airline;
    if (airline == "0") DisplayOptions();
    std::string source;
    std::cout<<"Local de origem: ";
    std::cin>>source;
    std::string target;
    std::cout<<"Local de destino: ";
    std::cin>>target;
    bool exists = false;

    for (auto vertex : g->getVertexSet()) {
        for (auto flight : vertex.second->getAdj()) {
            if (flight.getAirlineOfFlight().getName() == airline && vertex.second->getInfo().getName() == source && flight.getDest()->getInfo().getName() == target) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex.second->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
            }
        }
    }
    if (!exists) std::cout << "Não existe nenhum voo com essas especificações." << std::endl;
    DisplayOptions();
}

void Menu::allYes() {
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Introduzir :                                                    ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      Companhia aérea:______                                       ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##      0 -> Voltar                                                  ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;

    std::string airline;
    std::cout<<"Companhia aérea: ";
    std::cin>>airline;
    if (airline == "0") DisplayOptions();
    bool exists = false;

    for (auto vertex : g->getVertexSet()) {
        for (auto flight : vertex.second->getAdj()) {
            if (flight.getAirlineOfFlight().getName() == airline) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex.second->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
            }
        }
    }
    if (!exists) std::cout << "Não existe nenhum voo com essas especificações." << std::endl;
    DisplayOptions();
}

/////// Fim do 1 /////////////////


//Interface inicial:
std::string Menu::addspasces(std::string str, int nr){
    std::string res;
    for(int i = 0; i<(nr-str.size()); i++){
        res.push_back(' ');
    }
    return res;
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
    std::cout << "##      6- Numero de destinos alcancaveis a partir de um aeroporto com um maximo de X escalas         ##" << std::endl;
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
            //
            break;
        case 7:
            //
            break;
        case 8:
            //
            break;
        case 9:
            //
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
    std::cout<<"##     Numero de voos da Companhia " << airline <<':'<<addspasces(airline ,39)<<"##"<<std::endl;
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

int Menu::nFlightPerAirlineOne(std::string airline){
    int contagem;
    for (auto v : g->getVertexSet()){
        for (auto f : v.second->getAdj()){
            if( airline == f.getAirlineOfFlight().getCode()) {
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
    std::string k;
    std::getline(std::cin, k);
    if (k == "0"){
        std::cout << std::endl << "A sair ..." << std::endl;
        differentCountriesInterface();
        return;
    }
    auto r = getAirportByName(k);
    if (r == nullptr) r = getAirportByCode(k);
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
    std::cout << "######################################################################################" << std::endl
              << std::endl;

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
    std::cout<<"##     Introduza o nome do aeroporto:_______                               ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout<<"Aeroporto: ";

    //precisamos do aeroporto cujo nome é inserido
    Airport airport = Airport("CDG","Charles De Gaulle","Paris","France",49.012779,2.550000);

    std::string nameAirport;
    //std::cin >> nameAirport;
    int k;
    std::cin >> k;

    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            secBase();
            break;
        case 1:
            //nDestinationsTypeInterface(airport);
        default:
            std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
            nDestinationsInterface();
    }
}

void Menu::nDestinationsTypeInterface(Airport airport){
    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
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
            nDestinationsShowInterface(airport,1);
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


void Menu::nDestinationsShowInterface(Airport airport,int num){
    std::string tipo;
    map<std::string,int> myMap;
    switch (num) {
        case 1:
            myMap = nDestinationsAirports(airport);
            tipo = "Aeroporto";
            break;
        case 2:
            myMap = nDestinationsCities(airport);
            tipo = "Cidade";
    }
}
/////////////////////////////////
//       3v                    //
/////////////////////////////////
map<std::string,int> Menu::nDestinationsAirports(Airport airport){
    map<std::string,int> contagem;
    queue<Vertex<Airport> *> q;
    queue<Vertex<Airport> *> q2;
    int c = 1;
    for (auto k : g->getVertexSet()){
        k.second->setVisited(false);
    }
    auto v = g->findVertexByCode(airport.getCode());
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
map<std::string,int> Menu::nDestinationsCities(Airport airport){
    map<std::string,int> contagem;
    queue<Vertex<Airport> *> q;
    queue<Vertex<Airport> *> q2;
    int c = 0;
    for (auto k : g->getVertexSet()){
        k.second->setVisited(false);
    }
    auto v = g->findVertexByCode(airport.getCode());
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
map<std::string,int> Menu::nDestinationsCountries(Airport airport){
    map<std::string,int> contagem;
    queue<Vertex<Airport> *> q;
    queue<Vertex<Airport> *> q2;
    int c = 0;
    for (auto k : g->getVertexSet()){
        k.second->setVisited(false);
    }
    auto v = g->findVertexByCode(airport.getCode());
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
/////////////////////////////////
//       3vi                   //
/////////////////////////////////
map<std::string,int> Menu::nReachableDestinationsAirports(Airport airport,int k){
    map<std::string,int> contagem;
    queue<Vertex<Airport>*> temp;
    queue<Vertex<Airport>*> temp2;
    for (auto v : g->getVertexSet())v.second->setVisited(false);
    temp.push(g->findVertexByCode(airport.getCode())); // Inicial vertex put in the queue
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
map<std::string,int> Menu::nReachableDestinationsCities(Airport airport,int k){
    map<std::string,int> contagem;
    queue<Vertex<Airport>*> temp;
    queue<Vertex<Airport>*> temp2;
    for (auto v : g->getVertexSet())v.second->setVisited(false);
    temp.push(g->findVertexByCode(airport.getCode())); // Inicial vertex put in the queue
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
map<std::string,int> Menu::nReachableDestinationsCountries(Airport airport,int k){
    map<std::string,int> contagem;
    queue<Vertex<Airport>*> temp;
    queue<Vertex<Airport>*> temp2;
    for (auto v : g->getVertexSet())v.second->setVisited(false);
    temp.push(g->findVertexByCode(airport.getCode())); // Inicial vertex put in the queue
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
    std::cout<<"##          3 -> Coordenadas geográficas                             ##"<<std::endl;
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
        // Voltar para menu inicial
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
    std::cout<<"##     Para :                                                        ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          1 -> Aeroporto                                           ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          2 -> Cidade                                              ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          3 -> Coordenadas geográficas                             ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"Para : ";
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
    std::cout<<"##   Quer escolher as companhias aereas? :                           ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          1 -> Sim                                                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          2 -> Nao (vai ver voos de todas as companhias)           ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"Escolha : ";
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
    std::cout<<"##   Escreve as companhias separadas por vírgulas :                  ##"<<std::endl;
    std::cout<<"##   (Tanto pode escrever o código como o nome)                      ##"<<std::endl;
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
    std::cout<<"##   Quer minimizar ao maximo o número das companhias aereas ? :     ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          1 -> Sim                                                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##          2 -> Nao                                                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"Escolha : ";
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
                    //AirportToCityInterface(airlines,minimize);
                    break;
                case 3:
                    //AirportToGeoCordinatesInterface(airlines,minimize);
                    break;
            }
            break;
        case 2:
            switch (d) {
                case 1:
                    //CityToAirportInterface(airlines,minimize);
                    break;
                case 2:
                    //CityToCityInterface(airlines,minimize);
                    break;
                case 3:
                    //CityToGeoCordinatesInterface(airlines,minimize);
                    break;
            }
            break;
        case 3:
            switch (d) {
                case 1:
                    //GeoCordinatesToAirportInterface(airlines,minimize);
                    break;
                case 2:
                    //GeoCordinatesToCityInterface(airlines,minimize);
                    break;
                case 3:
                    //GeoCordinatesToGeoCordinatesInterface(airlines,minimize);
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
    std::cout<<"##   (Tanto pode ser com código ou nome)                             ##"<<std::endl;
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
        choose( i,d,airlines, minimize);
        return;
    }
    auto r = getAirportByName(k);
    if (r == nullptr) r = getAirportByCode(k);
    if (r == nullptr) {
        std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        nFlightAirlineInAirportChoiceInterface();
        return;
    }
    std::cout<<"Escolha o segundo : ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        choose( i,d,airlines, minimize);
        return;
    }
    auto r2 = getAirportByName(k);
    if (r2 == nullptr)r2 = getAirportByCode(k);
    if (r2 == nullptr) {
        std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        nFlightAirlineInAirportChoiceInterface();
        return;
    }
    AirportToAirportInterfaceResult(i,d,airlines,minimize,r,r2);
}
void Menu::AirportToAirportInterfaceResult(int i ,int d,vector<std::string>airlines,bool minimize,Vertex<Airport>* v, Vertex<Airport>* b){
    vector<vector<Flight>> res;
    if (airlines.empty())res = AirportToAirport(v,b);
    else res = AirportToAirportWF(v,b,airlines);
    if (minimize)minimizeAirlines(res);
    int k = 0;
    for (auto f : res){
        cout << "Opcao " << k <<" : "<<endl;
        for (auto h : f){
            cout << "Partiu de "<< g->getVertexSet().find(h.getSource())->second->getInfo().getName() << " para " << g->getVertexSet().find(h.getTarget())->second->getInfo().getName() << " usando " << h.getAirlineFromFlight() << endl;
        }
        k++;
    }
    cout <<" Estes voos tem " <<res.begin()->size()<< " paragens." << endl;
    // Interface de resposta
}
void Menu::AirportToCityInterface(int i ,int d,vector<std::string>airlines,bool minimize){
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"#######################################################################"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##   Digite os Parametros :                                          ##"<<std::endl;
    std::cout<<"##   (Tanto pode ser com código ou nome o aeroporto)                 ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     1 -> Aeroporto:_______                                        ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     2 -> Cidade:_______                                           ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                   ##"<<std::endl;
    std::cout<<"##                                                                   ##"<<std::endl;
    std::cout<<"#######################################################################"<<std::endl<<std::endl;
    std::string k;
    std::cout<<"Aeroporto : ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        choose( i,d,airlines, minimize);
        return;
    }
    auto r = getAirportByName(k);
    if (r == nullptr) r = getAirportByCode(k);
    if (r == nullptr) {
        std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
        AirportToCityInterface(i,d,airlines,minimize);
        return;
    }
    std::cout<<"Cidade : ";
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, k);
    if (k == "0") {
        std::cout << std::endl << "A sair ..." << std::endl;
        choose( i,d,airlines, minimize);
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
    int k = 0;
    for (auto f : res){
        cout << "Opcao " << k <<" : "<<endl;
        for (auto h : f){
            cout << "Partiu de "<< g->getVertexSet().find(h.getSource())->second->getInfo().getName() << " para " << g->getVertexSet().find(h.getTarget())->second->getInfo().getName() << " usando " << h.getAirlineFromFlight() << endl;
        }
        k++;
    }
    cout <<" Estes voos tem " <<res.begin()->size()<< " paragens." << endl;
    // Interface de resposta
}
bool inQueue(queue<Vertex<Airport> *> q,Vertex<Airport> * a){
    while (!q.empty()){
        if (a == q.front())return true;
        q.pop();
    }
    return false;
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
                w->addFlight(Flight(v->getInfo().getCode(),w->getInfo().getCode(),e.getAirlineOfFlight().getCode()));
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
vector<vector<Flight>> Menu::CityToAirport(std::string c, Vertex<Airport>* v,vector<std::string>airlines){
    queue<Vertex<Airport> *> q1;
    queue<Vertex<Airport> *> q2;
    q2.push(v);
    for (auto v : g->getVertexSet()){
        if (v.second->getInfo().getCity() == c)q1.push(v.second);
    }
    if (airlines.empty())return ListAirportToListAirport(q1,q2);
    else return ListAirportToListAirportWF(q1,q2,airlines);
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
                w->addFlight(Flight(v->getInfo().getCode(),w->getInfo().getCode(),e.getAirlineOfFlight().getCode()));
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
            if (!w->isVisited() && !inQueue(s,w) && inVector(airlines,e.getAirlineOfFlight().getCode())){
                w->setFEmpty();
                for (auto f : v->getFlights()){w->addFlight(f);}
                w->addFlight(Flight(v->getInfo().getCode(),w->getInfo().getCode(),e.getAirlineOfFlight().getCode()));
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

