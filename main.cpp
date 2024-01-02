#include <iostream>
#include "Menu.h"
#include <fstream>
#include <sstream>
#include <set>
#include <unordered_map>

void loadAirports(Graph<Airport> &g,unordered_map<std::string,std::string> &nameToCodeAirport,unordered_set<std::string> &cities,unordered_set<std::string> &countries) {
    ifstream aeroportos("airports.csv");
    vector<string> temp;
    string line;
    getline(aeroportos, line);  //ignorar a primeira linha

    while (getline(aeroportos, line)) {
        istringstream iss(line);
        string eachWord;

        while (getline(iss, eachWord, ',')) temp.push_back(eachWord);
        Airport airport = Airport(temp[0],temp[1],temp[2],temp[3],stod(temp[4]),stod(temp[5]));
        g.addVertex(temp[0],airport);
        nameToCodeAirport.insert({temp[1],temp[0]});
        cities.insert(temp[2]);
        countries.insert(temp[3]);
        temp.clear();
    }
}

void loadAirlines(unordered_map<std::string ,Airline> &airlines,unordered_set<std::string> &airlinesNames,unordered_set<std::string> &airlinesCodes) {
    ifstream linhas("airlines.csv");
    vector<string> temp;
    string line;
    getline(linhas, line);  //ignorar a primeira linha

    while (getline(linhas, line)) {
        istringstream iss(line);
        string eachWord;

        while (getline(iss, eachWord, ',')) temp.push_back(eachWord);
        Airline airline = Airline(temp[0],temp[1],temp[2],temp[3]);
        airlines.insert({temp[0],airline});
        airlinesNames.insert(temp[1]);
        airlinesCodes.insert(temp[0]);
        temp.clear();
    }
}

void loadFlights(vector<Flight>& flights) {
    ifstream voos("flights.csv");
    vector<string> temp;
    string line;
    getline(voos, line);  //ignorar a primeira linha

    while (getline(voos, line)) {
        istringstream iss(line);
        string eachWord;

        while (getline(iss, eachWord, ',')) temp.push_back(eachWord);
        Flight flight = Flight(temp[0], temp[1], temp[2]);
        flights.push_back(flight);
        temp.clear();
    }
}

void loadFlightsToEdges(Graph<Airport> &g,const vector<Flight>& flights, const unordered_map<std::string, Airline> &airlines) {
    std::string last;
    auto i = new Vertex<Airport>();
    for (Flight flight : flights) {
        if (flight.getSource() != last)i = g.findVertexByCode(flight.getSource());
        auto d = g.findVertexByCode(flight.getTarget());
        g.addEdge(i->getInfo().getCode(),d->getInfo().getCode(),airlines.find(flight.getAirlineFromFlight())->second);
        last = flight.getSource();
    }
}

int main() {
    Graph<Airport> g;
    unordered_map<std::string ,Airline> airlines;
    unordered_map<std::string,std::string> nameToCodeAirport;
    unordered_set<std::string> cities;
    unordered_set<std::string> countries;
    unordered_set<std::string> airlinesNames;
    unordered_set<std::string> airlinesCodes;
    vector<Flight> flights;
    loadAirports(g,nameToCodeAirport,cities,countries);
    loadAirlines(airlines,airlinesNames,airlinesCodes);
    loadFlights(flights);
    loadFlightsToEdges(g,flights,airlines);
    Menu menu = Menu(&g,nameToCodeAirport,cities,countries,airlinesNames,airlinesCodes);
    menu.secBase();
    return 0;
}