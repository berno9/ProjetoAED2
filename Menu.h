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

        void secBase();
            void numberOfAirportsInterface();
                int numberOfAirports(); // 3i
                int numberOfFlights(); // 3i
            void nFlightAirlineInAirportInterface();
                pair<int,int> nFlightAirlineInAirport(Airport airport); // 3ii

            map<std::string,int> nFlightPerCity(); // 3iii
            map<std::string,int> nFlightPerAirline(); // 3iii
            map<std::string,int> airportToCountrys(Airport airport); // 3iv

};


#endif //PROJETOAED5_MENU_H
