#include <iostream>
#include "Graph.h"
#include "Airport.h"
#include "Flight.h"
#include "Menu.h"
#include <fstream>
#include <sstream>
#include <set>


// Função para encontrar o nome para um código
std::string findNameForCode(const set<Airport>& airports, std::string code) {
    for (Airport airport : airports) {
        if (airport.getCode() == code) return airport.getName();
    }
    return "";
}

void loadAirports(set<Airport>& airports) {
    ifstream aeroportos("airports.csv");
    vector<string> temp;
    string line;
    getline(aeroportos, line);  //ignorar a primeira linha

    while (getline(aeroportos, line)) {
        istringstream iss(line);
        string eachWord;

        while (getline(iss, eachWord, ',')) temp.push_back(eachWord);

        Airport airport = Airport(temp[1]);
        airport.setCode(temp[0]);
        airport.setCity(temp[2]);
        airport.setCountry(temp[3]);
        airport.setLatitude(stod(temp[4]));
        airport.setLongitude(stod(temp[5]));

        airports.insert(airport);
        temp.clear();
    }
}

void loadAirportsToVertices(Graph<string>* &g, const set<Airport>& airports) {
    for (Airport airport : airports) g->addVertex(airport.getCode() + ',' + airport.getName());
}

void loadAirlines(set<Airline>& airlines) {
    ifstream linhas("airports.csv");
    vector<string> temp;
    string line;
    getline(linhas, line);  //ignorar a primeira linha

    while (getline(linhas, line)) {
        istringstream iss(line);
        string eachWord;

        while (getline(iss, eachWord, ',')) temp.push_back(eachWord);

        Airline airline = Airline(temp[1]);
        airline.setCode(temp[0]);
        airline.setCallSign(temp[2]);
        airline.setCountry(temp[3]);

        airlines.insert(airline);
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

void loadFlightsToEdges(Graph<string>* &g, const set<Airport>& airports, vector<Flight>& flights) {
    for (Flight flight : flights) {
        for (auto vertex : g->getVertexSet()) {
            if (vertex->getInfo().substr(0, 3) == flight.getSource()) {
                //std::cout << findNameForCode(airports, flight.getSource()) << std::endl;
                std::string source = flight.getSource() + ',' + findNameForCode(airports, flight.getSource());
                std::string destination = flight.getTarget() + ',' + findNameForCode(airports, flight.getTarget());
                g->addEdge(source, destination, 0, flight.getAirlineFromFlight().getCode());
            }
        }
    }
}




int main() {
    Graph<string>* g = new Graph<string>();
    set<Airport> airports;
    set<Airline> airlines;
    vector<Flight> flights;
    loadAirports(airports);
    loadAirlines(airlines);
    loadFlights(flights);
    loadAirportsToVertices(g, airports);
    loadFlightsToEdges(g, airports, flights);
    Menu menu = Menu(g);
    menu.Base();
    return 0;
}


