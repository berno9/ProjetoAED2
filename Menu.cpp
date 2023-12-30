//
// Created by User on 23/12/2023.
//

#include <algorithm>
#include "Menu.h"
#include <cmath>



Menu::Menu(Graph<Airport> *graph) {
    g = graph;
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

    int k;
    std::cout<<"Voltar?: ";
    std::cin>>k;
    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            secBase();
            break;
        default:
            std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
            numberOfAirportsInterface();
    }
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


    //if name == '0', k = 0
    //if airport name exists k = 1


    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            secBase();
            break;
        case 1:
            nFlightAirlineInAirportInterface(airport);
            break;
        default:
            //nFlightAirlineInAirport(k);
            std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
            nFlightAirlineInAirportChoiceInterface();
    }
}

void Menu::nFlightAirlineInAirportInterface(Airport airport){
    std::cout<<std::endl<<std::endl;
    std::cout<<"############################################################################################"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##     Voos de partida do aeroporto "<<airport.getName()<<" e numero de companhias aereas:"<<addspasces(airport.getName(),23)<<"##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##     Numero de voos: "<< nFlightAirlineInAirport(airport).first<<addspasces(to_string(nFlightAirlineInAirport(airport).first),67)<<"##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##     Numero de companhias: "<< nFlightAirlineInAirport(airport).second<<addspasces(to_string(nFlightAirlineInAirport(airport).second),61)<<"##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                                        ##"<<std::endl;
    std::cout<<"##                                                                                        ##"<<std::endl;
    std::cout<<"############################################################################################"<<std::endl<<std::endl;

    std::cout<<"Voltar? ";
    int k;
    std::cin>>k;

    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            nFlightAirlineInAirportChoiceInterface();
            break;
        default:
            std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
            nFlightAirlineInAirportInterface(airport);
            break;
    }
}


/////////////////////////////////
//       3ii                   //
/////////////////////////////////

pair<int,int> Menu::nFlightAirlineInAirport(Airport airport){
   set<Airline> airlines;
   auto a = g->findVertexByCode(airport.getCode());
   for (auto d : a->getAdj()){
       airlines.insert(d.getAirlineOfFlight());
   }
   return {a->getAdj().size(),airlines.size()};
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
    int k;
    std::cin>>k;

    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            secBase();
            break;
        case 1:
            nFlightPerCityInterface();
            break;
        case 2:
            nFlightPerAirlineInterface();
            break;
        default:
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

    std::cout << "Opcao: ";
    int k;
    std::cin>>k;

    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            nFlightPerCityOrAirlineChoiceInterface();
            break;
        case 1:
            nFlightPerCityInterfaceChoise();
            break;
        case 2:
            nFlightPerCityInterfaceAll();
            break;
        default:
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
    std::string city = "Porto";
    //std::cin >> cidade;
    int k;
    std::cin >> k;


    //if name == '0', k = 0
    //if cidade name exists k = 1


    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            nFlightPerCityInterface();
            break;
        case 1:
            nFlightPerCityOneInterface(city);
            break;
        default:
            std::cout << "O nome da cidade que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
            nFlightPerCityInterfaceChoise();
    }

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
    int k;
    std::cin >> k;

    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            nFlightPerCityInterfaceChoise();
            break;
        default:
            nFlightPerCityOneInterface(city);
            std::cout << "O nome da cidade que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
            break;
    }

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
    int k;
    std::cin>>k;

    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            nFlightPerCityInterface();
            break;
        default:
            std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
            nFlightPerCityInterfaceAll();
    }

}


//

/////////////////////////////////
//       3iii                  //
/////////////////////////////////

map<std::string,int> Menu::nFlightPerCity(){
    map<std::string,int> contagem;
    for (auto v : g->getVertexSet()){
        std::string city = v.second->getInfo().getCity();
        contagem[city]++;
    }
    return contagem;
}
int Menu::nFlightPerCityOne(std::string name) {
    int contagem = 0;
    for (auto v: g->getVertexSet()) {
        if (name == v.second->getInfo().getCity()) {
            contagem++;
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
    int k;
    std::cin>>k;

    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            nFlightPerCityOrAirlineChoiceInterface();
            break;
        case 1:
            nFlightPerAirlineInterfaceChoise();
            break;
        case 2:
            nFlightPerAirlineInterfaceAll();
            break;
        default:
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
    std::cout<<"##     Introduza o nome da Companhia Aerea:_______                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout << "Companhia Aerea: ";
    //std::cin >> compahia;
    Airline companhia = Airline("IBE","Iberia Airlines","IBERIA","Spain");
    int k;
    std::cin >> k;


    //if name == '0', k = 0
    //if cidade name exists k = 1


    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            nFlightPerAirlineInterface();
            break;
        case 1:
            nFlightPerAirlineOneInterface(companhia);
            break;
        default:
            //nFlightAirlineInAirport(k);
            std::cout << "O nome da cidade que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
            nFlightPerAirlineInterfaceChoise();
    }
}
void Menu::nFlightPerAirlineOneInterface(Airline airline) {
    std::cout<<std::endl<<std::endl;
    std::cout<<"#############################################################################"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     Numero de voos da Companhia " << airline.getName() <<':'<<addspasces(airline.getName(),39)<<"##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     --- "<<nFlightPerAirlineOne(airline)<<addspasces(to_string(nFlightPerAirlineOne(airline)),62)<<"##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"##     0 -> Voltar                                                         ##"<<std::endl;
    std::cout<<"##                                                                         ##"<<std::endl;
    std::cout<<"#############################################################################"<<std::endl<<std::endl;

    std::cout<<"Voltar?";
    int k;
    std::cin >> k;

    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            nFlightPerAirlineInterfaceChoise();
            break;
        default:
            nFlightPerAirlineOneInterface(airline);
            std::cout << "O nome da cidade que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
            break;
    }

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


    std::cout << "Voltar?";
    int k;
    std::cin>>k;

    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            nFlightPerAirlineInterface();
            break;
        default:
            std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
            nFlightPerAirlineInterfaceAll();
    }

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
    std::cout << "#############################################################################" << std::endl
              << std::endl;

    std::cout << "Opcao: ";
    int k;
    std::cin >> k;

    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            secBase();
            break;
        case 1:
            diffCountriesCityChoiseInterface();
            break;
        case 2:
            diffCountriesAirportChoiseInterface();
            break;
        default:
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
    std::string city = "Porto";
    //std::cin >> cidade;
    int k;
    std::cin >> k;


    //if name == '0', k = 0
    //if cidade name exists k = 1


    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            differentCountriesInterface();
            break;
        case 1:
            diffCountriesCityShowInterface(city);
            break;
        default:
            diffCountriesCityChoiseInterface();
            std::cout << "O nome da cidade que inseriu nao esta correto. Por favor volte a tentar." << std::endl;

    }
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
    int k;
    std::cin >> k;
    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            diffCountriesCityChoiseInterface();
            break;
        default:
            std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
            diffCountriesCityShowInterface(city);
    }
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

        //precisamos do aeroporto cujo nome é inserido
        Airport airport = Airport("CDG","Charles De Gaulle","Paris","France",49.012779,2.550000);

        std::string nameAirport;
        //std::cin >> nameAirport;
        int k;
        std::cin >> k;


        //if name == '0', k = 0
        //if airport name exists k = 1


        switch (k) {
            case 0:
                std::cout << std::endl << "A sair ..." << std::endl;
                differentCountriesInterface();
                break;
            case 1:
                diffCountriesAirportShowInterface(airport);
                break;
            default:
                std::cout << "O nome do aeroporto que inseriu nao esta correto. Por favor volte a tentar." << std::endl;
                diffCountriesAirportChoiseInterface();
        }
}


void Menu::diffCountriesAirportShowInterface(Airport airport) {
    map<std::string, int> myMap;
    myMap = airportToCountries(airport);
    std::cout << std::endl << std::endl;
    std::cout << "######################################################################################" << std::endl;
    std::cout << "##                                                                                  ##" << std::endl;
    std::cout << "##     Numero de paises cobertos por " << airport.getName() << ":" << addspasces(airport.getName(), 45) << "##" << std::endl;
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
    int k;
    std::cin >> k;
    switch (k) {
        case 0:
            std::cout << std::endl << "A sair ..." << std::endl;
            diffCountriesAirportChoiseInterface();
            break;
        default:
            std::cout << "Opcao invalida. Por favor, escolha uma opcao valida." << std::endl;
            diffCountriesAirportShowInterface(airport);
    }
}


/////////////////////////////////
//       3iv                   //
/////////////////////////////////
map<std::string,int> Menu::airportToCountries(Airport airport){
    auto a = g->findVertexByCode(airport.getCode());

    map<std::string,int> contagem;
    for (auto d : a->getAdj()){
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

void nDestinationsTypeInterface(Airport airport){
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


}

//void Menu::nDestinationsShowInterface(Airport airport,int num){
//    std::string tipo;
//    map<std::string,int> myMap;
//    switch (num) {
//        case 1:
//            myMap = nDestinationsAirports(airport);
//            tipo = "Aeroporto";
//            break;
//        case 2:
//            myMap = nDestinationsCities(airport);
//            tipo = "Cidade";
//    }
//}
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
int helpTrip(Vertex<Airport>* v,Graph<Airport> *g){
    queue<Vertex<Airport>*> temp;
    queue<Vertex<Airport>*> temp2;
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
        temp.pop();
        if (temp.empty()){ // This means we have changed level
            c++;
            temp = temp2;
            while (!temp2.empty())temp2.pop();
        }
    }
    return c-1;
}
int Menu::maxTrip(){
    int maxV = 0;
    for (auto par : g->getVertexSet()){
        auto v = par.second;
        maxV = max(maxV,helpTrip(v,g));
    }
    return maxV;
}
/////////////////////////////////
//       3viii                 //
/////////////////////////////////
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








