#include <iostream>
#include "Graph.h"
#include "Airport.h"
#include "Flight.h"
#include "Menu.h"
#include <fstream>
#include <sstream>
#include <set>
#include <unordered_map>

void loadAirports(unordered_map<std::string ,Airport>& airports) {
    ifstream aeroportos("airports.csv");
    vector<string> temp;
    string line;
    getline(aeroportos, line);  //ignorar a primeira linha

    while (getline(aeroportos, line)) {
        istringstream iss(line);
        string eachWord;

        while (getline(iss, eachWord, ',')) temp.push_back(eachWord);
        Airport airport = Airport(temp[0],temp[1],temp[2],temp[3],stod(temp[4]),stod(temp[5]));
        airports.insert({temp[0],airport});
        temp.clear();
    }
}

void loadAirportsToVertices(Graph<Airport> &g, const unordered_map<std::string ,Airport>& airports) {
    for (auto airport : airports) {
        g.addVertex(airport.second);
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
    auto i = g.getVertexSet().front();
    for (Flight flight : flights) {
        if (flight.getSource() != last)i = g.findVertex(airports.find(flight.getSource())->second);
        auto d = g.findVertex(airports.find(flight.getTarget())->second);
        g.addEdge(i->getInfo(),d->getInfo(),0,airlines.find(flight.getAirlineFromFlight())->second);
        last = flight.getSource();
    }
}

int main() {
    Graph<Airport> g;
    unordered_map<std::string ,Airport> airports;
    unordered_map<std::string ,Airline> airlines;
    vector<Flight> flights; // We can order this from the source Airport so the loadFlightsToEdges is faster
    loadAirports(airports);
    loadAirlines(airlines);
    loadFlights(flights);
    loadAirportsToVertices(g, airports);
    loadFlightsToEdges(g,flights,airlines,airports);
    Menu menu = Menu(&g);
    //menu.Base();
    return 0;
}


