//
// Created by User on 23/12/2023.
//

#ifndef PROJETOAED5_MENU_H
#define PROJETOAED5_MENU_H

#include <iostream>
#include <string>
#include <set>
#include <map>
#include "Graph.h"
#include "Airport.h"
#include "Airline.h"
#include "Flight.h"

class Menu {
private:
    Graph<Airport> *g;
public:
    Menu(Graph<Airport> *graph);
    void Base();
        void DisplayOptions();
            void SourceNo();
            void DestNo();
            void SourceDestNo();
            void allNo();
            void SourceYes();
            void DestYes();
            void SourceDestYes();
            void allYes();
            int numberOfAirports(); // 3i
            int numberOfFlights(); // 3i
            pair<int,int> nFlightAirlineInAirport(Airport airport); // 3ii
            map<std::string,int> nFlightPerCity(); // 3iii
            map<std::string,int> nFlightPerAirline(); // 3iii
            map<std::string,int> airportToCountries(Airport airport); // 3iv
            map<std::string,int> cityToCountries(std::string city); // 3iv
            map<std::string,int> nDestinationsAirports(Airport airport); // 3v
            map<std::string,int> nDestinationsCities(Airport airport); // 3v
            map<std::string,int> nDestinationsCountries(Airport airport); // 3v
            map<std::string,int> nReachableDestinationsAirports(Airport airport,int k); // 3vi
            map<std::string,int> nReachableDestinationsCities(Airport airport,int k); // 3vi
            map<std::string,int> nReachableDestinationsCountries(Airport airport,int k); // 3vi
            std::vector<pair<Airport, int>> nGreatestAirTrafficCapacity(int k); // 3viii
            std::unordered_set<std::string> essentialAirports(); //3ix
};


#endif //PROJETOAED5_MENU_H
