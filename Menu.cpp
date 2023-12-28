//
// Created by User on 23/12/2023.
//

#include <algorithm>
#include "Menu.h"

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
        if (vertex->getInfo().getName() == source) {
            exists = true;
            for (auto flight : vertex->getAdj()) {
                std::cout << "Existe um voo que parte de " << vertex->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
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
            if (flight.getDest()->getInfo().getName() == target) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
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
            if (vertex->getInfo().getName() == source && flight.getDest()->getInfo().getName() == target) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
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
            std::cout << "Existe um voo que parte de " << vertex->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
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
            if (flight.getAirlineOfFlight().getName() == airline && vertex->getInfo().getName() == source) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
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
            if (flight.getAirlineOfFlight().getName() == airline && flight.getDest()->getInfo().getName()== target) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
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
            if (flight.getAirlineOfFlight().getName() == airline && vertex->getInfo().getName() == source && flight.getDest()->getInfo().getName() == target) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
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
            if (flight.getAirlineOfFlight().getName() == airline) {
                exists = true;
                std::cout << "Existe um voo que parte de " << vertex->getInfo().getName() << " e que aterra em " << flight.getDest()->getInfo().getName() << " pela companhia aérea " << flight.getAirlineOfFlight().getName() << " ." << std::endl;
            }
        }
    }
    if (!exists) std::cout << "Não existe nenhum voo com essas especificações." << std::endl;
    DisplayOptions();
}
/////// Fim do 1 /////////////////
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
pair<int,int> Menu::nFlightAirlineInAirport(Airport airport){
   set<Airline> airlines;
   auto a = g->findVertex(airport);
   for (auto d : a->getAdj()){
       airlines.insert(d.getAirlineOfFlight());
   }
   return {a->getAdj().size(),airlines.size()};
}
map<std::string,int> Menu::nFlightPerCity(){
    map<std::string,int> contagem;
    for (auto v : g->getVertexSet()){
        std::string city = v->getInfo().getCity();
        contagem[city]++;
    }
    return contagem;
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



int totalDegree(Airport airport, Graph<Airport>* g) {
    auto v = g->findVertex(airport);
    int total1 = v->getAdj().size();
    int total = 0;
    for (auto vertex : g->getVertexSet()) {
        for (auto edge : vertex->getAdj()) {
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
    for (auto vertex : g->getVertexSet()) highest.push_back({vertex->getInfo(), totalDegree(vertex->getInfo(), g)});

    sort(highest.begin(), highest.end(), compare);
    highest.erase(highest.begin() + k, highest.end());
    return highest;
}

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
    for (auto vertex : g->getVertexSet())vertex->setProcessing(false);
    for (auto vertex : g->getVertexSet()) {
        if (vertex->getNum() == 0){
            dfs_art(vertex,res,i);
        }
    }
    return res;
}
bool inStack(queue<Vertex<Airport> *> q,Vertex<Airport> * a){
    while (!q.empty()){
        if (a == q.front())return true;
        q.pop();
    }
    return false;
}
vector<vector<Flight>> Menu::AirportToAirport(Airport a, Airport b){
    auto v = g->findVertex(a);
    vector<vector<Flight>> res;
    queue<Vertex<Airport> *> q;
    queue<Vertex<Airport> *> q2;
    for (auto k : g->getVertexSet()){
        k->setVisited(false);
        k->setFEmpty();
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
                q2.push(w);
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
        k->setVisited(false);
        k->setFEmpty();
        if (k->getInfo().getCity() == a)q.push(k);
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
                q2.push(w);
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
bool inVector(vector<std::string> airlines, std::string s){
    for (auto a : airlines)if (a == s)return true;
    return false;
}
vector<vector<Flight>> Menu::AirportToAirportWF(Airport a, Airport b,vector<std::string> airlines){
    auto v = g->findVertex(a);
    vector<vector<Flight>> res;
    queue<Vertex<Airport> *> q;
    queue<Vertex<Airport> *> q2;
    for (auto k : g->getVertexSet()){
        k->setVisited(false);
        k->setFEmpty();
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
                q2.push(w);
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



