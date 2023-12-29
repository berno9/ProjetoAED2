#include <iostream>
#include "Menu.h"
#include <fstream>
#include <sstream>
#include <set>
#include <unordered_map>

void loadAirports(Graph<Airport> &g) {
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
        temp.clear();
    }
}

void loadAirlines(unordered_map<std::string ,Airline> &airlines) {
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

void loadFlightsToEdges(Graph<Airport> &g,const vector<Flight>& flights, const unordered_map<std::string, Airline> &airlines,const unordered_map<std::string ,Airport> &airports) {
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
    unordered_map<std::string ,Airport> airports;
    unordered_map<std::string ,Airline> airlines;
    vector<Flight> flights; // We can order this from the source Airport so the loadFlightsToEdges is faster
    loadAirports(g);
    loadAirlines(airlines);
    loadFlights(flights);
    loadFlightsToEdges(g,flights,airlines,airports);
    Menu menu = Menu(&g);
    return 0;
}


