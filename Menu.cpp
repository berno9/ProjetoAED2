//
// Created by User on 23/12/2023.
//

#include "Menu.h"



Menu::Menu(Graph<Airport> *graph) {
    g = graph;
}
/*
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
        if (vertex->getInfo().substr(4) == source) {
            exists = true;
            for (auto flight : vertex->getAdj()) {
                std::cout << "Existe um voo que parte de " << vertex->getInfo().substr(4) << " e que aterra em " << flight.getDest()->getInfo().substr(4) << " pela companhia aérea " << flight.getAirlineOfFlight() << " ." << std::endl;
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
        for (auto flight : vertex->getAdj()) {
            if (flight.getDest()->getInfo().substr(4) == target) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex->getInfo().substr(4) << " e que aterra em " << flight.getDest()->getInfo().substr(4) << " pela companhia aérea " << flight.getAirlineOfFlight() << " ." << std::endl;
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
        for (auto flight : vertex->getAdj()) {
            if (vertex->getInfo().substr(4) == source && flight.getDest()->getInfo().substr(4) == target) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex->getInfo().substr(4) << " e que aterra em " << flight.getDest()->getInfo().substr(4) << " pela companhia aérea " << flight.getAirlineOfFlight() << " ." << std::endl;
            }
        }
    }
    if (!exists) std::cout << "Não existe nenhum voo com essas especificações." << std::endl;
    DisplayOptions();
}

void Menu::allNo(){
    bool exists = false;
    for (auto vertex : g->getVertexSet()) {
        for (auto flight : vertex->getAdj()) {
            exists = true;
            std::cout << "Existe um voo que parte de " << vertex->getInfo().substr(4) << " e que aterra em " << flight.getDest()->getInfo().substr(4) << " pela companhia aérea " << flight.getAirlineOfFlight() << " ." << std::endl;
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
        for (auto flight : vertex->getAdj()) {
            if (flight.getAirlineOfFlight() == airline && vertex->getInfo().substr(4) == source) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex->getInfo().substr(4) << " e que aterra em " << flight.getDest()->getInfo().substr(4) << " pela companhia aérea " << flight.getAirlineOfFlight() << " ." << std::endl;
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
        for (auto flight : vertex->getAdj()) {
            if (flight.getAirlineOfFlight() == airline && flight.getDest()->getInfo().substr(4) == target) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex->getInfo().substr(4) << " e que aterra em " << flight.getDest()->getInfo().substr(4) << " pela companhia aérea " << flight.getAirlineOfFlight() << " ." << std::endl;
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
        for (auto flight : vertex->getAdj()) {
            if (flight.getAirlineOfFlight() == airline && vertex->getInfo().substr(4) == source && flight.getDest()->getInfo().substr(4) == target) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex->getInfo().substr(4) << " e que aterra em " << flight.getDest()->getInfo().substr(4) << " pela companhia aérea " << flight.getAirlineOfFlight() << " ." << std::endl;
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
        for (auto flight : vertex->getAdj()) {
            if (flight.getAirlineOfFlight() == airline) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex->getInfo().substr(4) << " e que aterra em " << flight.getDest()->getInfo().substr(4) << " pela companhia aérea " << flight.getAirlineOfFlight() << " ." << std::endl;
            }
        }
    }
    if (!exists) std::cout << "Não existe nenhum voo com essas especificações." << std::endl;
    DisplayOptions();
}*/
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


int Menu::numberOfAirports() {
    return g->getNumVertex();
}

int Menu::numberOfFlights() {
    int c = 0;
    for (auto v : g->getVertexSet()){
        c += v->getAdj().size();
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

pair<int,int> Menu::nFlightAirlineInAirport(Airport airport){
   set<Airline> airlines;
   auto a = g->findVertex(airport);
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
map<std::string,int> Menu::nFlightPerCity(){
    map<std::string,int> contagem;
    for (auto v : g->getVertexSet()){
        std::string city = v->getInfo().getCity();
        contagem[city]++;
    }
    return contagem;
}
int Menu::nFlightPerCityOne(std::string name) {
    int contagem = 0;
    for (auto v: g->getVertexSet()) {
        if (name == v->getInfo().getCity()) {
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
        for (auto f : v->getAdj()){
            std::string airline = f.getAirlineOfFlight().getCode();
            contagem[airline]++;
        }
    }
    return contagem;
}
int Menu::nFlightPerAirlineOne(Airline airline){
    int contagem;
    for (auto v : g->getVertexSet()){
        for (auto f : v->getAdj()){
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


map<std::string,int> Menu::airportToCountries(Airport airport){
    auto a = g->findVertex(airport);
    map<std::string,int> contagem;
    for (auto d : a->getAdj()){
        contagem[d.getDest()->getInfo().getCountry()]++;
    }
    return contagem;
}

map<std::string,int> Menu::cityToCountries(std::string city){
    map<std::string,int> contagem;
    for (auto v : g->getVertexSet()){
        if (v->getInfo().getCity() == city){
            for (auto d : v->getAdj()){
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



map<std::string,int> Menu::nDestinationsAirports(Airport airport){
    map<std::string,int> contagem;
    for (auto v : g->findVertex(airport)->getAdj()){
        contagem[v.getDest()->getInfo().getCode()]++;
    }
    return contagem;
}
map<std::string,int> Menu::nDestinationsCities(Airport airport){
    map<std::string,int> contagem;
    for (auto v : g->findVertex(airport)->getAdj()){
        contagem[v.getDest()->getInfo().getCity()]++;
    }
    return contagem;
}
map<std::string,int> Menu::nDestinationsCountries(Airport airport){
    map<std::string,int> contagem;
    for (auto v : g->findVertex(airport)->getAdj()){
        contagem[v.getDest()->getInfo().getCountry()]++;
    }
    return contagem;
}
//------------------------------------------------------Fim 3v---------------------------------------

//------------------------------------------------------3vi Inicio-----------------------------------
map<std::string,int> Menu::nReachableDestinationsAirports(Airport airport,int k){
    map<std::string,int> contagem;
    queue<Vertex<Airport>*> temp;
    queue<Vertex<Airport>*> temp2;
    for (auto v : g->getVertexSet())v->setVisited(false);
    temp.push(g->findVertex(airport)); // Inicial vertex put in the queue
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
        }
    }
    return contagem;
}
map<std::string,int> Menu::nReachableDestinationsCities(Airport airport,int k){
    map<std::string,int> contagem;
    queue<Vertex<Airport>*> temp;
    queue<Vertex<Airport>*> temp2;
    for (auto v : g->getVertexSet())v->setVisited(false);
    temp.push(g->findVertex(airport)); // Inicial vertex put in the queue
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
        }
    }
    return contagem;
}
map<std::string,int> Menu::nReachableDestinationsCountries(Airport airport,int k){
    map<std::string,int> contagem;
    queue<Vertex<Airport>*> temp;
    queue<Vertex<Airport>*> temp2;
    for (auto v : g->getVertexSet())v->setVisited(false);
    temp.push(g->findVertex(airport)); // Inicial vertex put in the queue
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
        }
    }
    return contagem;
}
//------------------------------------------------------Fim 3vi---------------------------------------

//------------------------------------------------------3vii Inicio-----------------------------------