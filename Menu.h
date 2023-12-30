//
// Created by User on 23/12/2023.
//

#ifndef PROJETOAED5_MENU_H
#define PROJETOAED5_MENU_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include "Graph.h"

class Menu {
private:
    Graph<Airport> *g;
public:
    Menu(Graph<Airport> *graph);
    std::string addspasces(std::string, int);
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
        //3i
        void numberOfAirportsInterface(); //mostra numero total de voos e de aeroportos
                int numberOfAirports(); // obtem o número total de aeroportos
                int numberOfFlights(); // obtem o número total de voos
        //3ii
        void nFlightAirlineInAirportChoiceInterface();
            void nFlightAirlineInAirportInterface(Airport airport); // 3ii
                pair<int,int> nFlightAirlineInAirport(Airport airport); // 3ii
        //3iii

        //escolher entre companhia aérea ou cidade
        void nFlightPerCityOrAirlineChoiceInterface();

        // Cidade
            void nFlightPerCityInterface(); //escolher entre todas as cidades ou apenas uma
                //Apenas uma cidade
                void nFlightPerCityInterfaceChoise(); //escolher a cidade pretendida
                    void nFlightPerCityOneInterface(std::string); //mostrar o número de voos da cidade
                        int nFlightPerCityOne(std::string); //calcular o número de voos de uma determinada cidade
                //Todas as cidades
                void nFlightPerCityInterfaceAll(); //mostrar todos os voos por cidade
                    map<std::string,int> nFlightPerCity(); //obter todos os voos por cidade
        //Companhia Aérea
            void nFlightPerAirlineInterface(); //escolher entre todas as companhias ou apenas uma
                //Apenas uma companhia aérea
                void nFlightPerAirlineInterfaceChoise();//escolher a companhia aérea pretendida
                    void nFlightPerAirlineOneInterface(Airline); //mostrar o número de voos da companhia aérea
                        int nFlightPerAirlineOne(Airline); //calcular o número de voos de uma determinada companhia
                            map<std::string,int> airportToCountriesOne(Airport airport);
                        //Todas as cidades
                void nFlightPerAirlineInterfaceAll(); //mostrar todos os voos por cidade
                    map<std::string,int> nFlightPerAirline(); //obter todos os voos por companhia aérea

    //3iv
    void differentCountriesInterface(); //Escolher entre cidade ou aeroporto
        //Cidade
            void diffCountriesCityChoiseInterface(); //escolher a cidade pretendida
                void diffCountriesCityShowInterface(std::string city); //mostrar o número de países na cidade
                    map<std::string,int> cityToCountries(std::string city); // 3iv
        //Aeroporto
            void diffCountriesAirportChoiseInterface(); //escolher o Aeroporto pretendido
                void diffCountriesAirportShowInterface(Airport airport);
                    map<std::string,int> airportToCountries(Airport airport); // 3iv
    //3v
    void nDestinationsInterface();//escolher qual o aeroporto
        void nDestinationsTypeInterface(Airport airport); //escolher o tipo de destino sobre o qual quer a informação
           //void nDestinationsShowInterface(Airport,int);

    map<std::string,int> nDestinationsAirports(Airport airport); // 3v
    map<std::string,int> nDestinationsCities(Airport airport); // 3v
    map<std::string,int> nDestinationsCountries(Airport airport); // 3v

    map<std::string,int> nReachableDestinationsAirports(Airport airport,int k); // 3vi
    map<std::string,int> nReachableDestinationsCities(Airport airport,int k); // 3vi
    map<std::string,int> nReachableDestinationsCountries(Airport airport,int k); // 3vi

            int maxTrip(); // vii
            std::vector<pair<Airport, int>> nGreatestAirTrafficCapacity(int k); // 3viii
            set<std::string>  essentialAirports(); //3ix
            // 4 BestFlightOption
            vector<vector<Flight>> AirportToAirport(Airport a, Airport b);
            vector<vector<Flight>> CityToCity(std::string a, std::string b);
            // 5 BestFlightOption with filters
            vector<vector<Flight>> AirportToAirportWF(Airport a, Airport b,vector<std::string>airlines);
};


#endif //PROJETOAED5_MENU_H
