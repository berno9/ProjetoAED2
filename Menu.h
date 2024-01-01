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
    unordered_map<std::string,std::string> nameToCodeAirport;
    set<std::string> cities;
    set<std::string> countries;
public:
    Menu(Graph<Airport> *graph,unordered_map<std::string,std::string> map,set<std::string> city,set<std::string> country);
    Vertex<Airport>* getAirportByName(std::string n);
    Vertex<Airport>* getAirportByCode(std::string c);
    bool existAirline(std::string airline);
    bool existCity(std::string c);
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
            void nFlightAirlineInAirportInterface(Vertex<Airport>*); // 3ii
                pair<int,int> nFlightAirlineInAirport(Vertex<Airport>*); // 3ii
    //3iii
        //escolher entre companhia aérea ou cidade
        void nFlightPerCityOrAirlineChoiceInterface();
            // Cidade
            void nFlightPerCityInterface(); //escolher entre todas as cidades ou apenas uma
                //Apenas uma cidade
                void nFlightPerCityInterfaceChoise(); //escolher a cidade pretendida
                    void nFlightPerCityOneInterface(std::string city); //mostrar o número de voos da cidade
                        int nFlightPerCityOne(std::string city); //calcular o número de voos de uma determinada cidade
                //Todas as cidades
                 void nFlightPerCityInterfaceAll(); //mostrar todos os voos por cidade
                    map<std::string,int> nFlightPerCity(); //obter todos os voos por cidade
            //Companhia Aérea
            void nFlightPerAirlineInterface(); //escolher entre todas as companhias ou apenas uma
            //Apenas uma companhia aérea
            void nFlightPerAirlineInterfaceChoise();//escolher a companhia aérea pretendida
                void nFlightPerAirlineOneInterface(std::string airline); //mostrar o número de voos da companhia aérea
                    int nFlightPerAirlineOne(std::string airline); //calcular o número de voos de uma determinada companhia
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
            void diffCountriesAirportShowInterface(Vertex<Airport>* airport);
                map<std::string,int> airportToCountries(Vertex<Airport>* airport); // 3iv
    //3v
    void nDestinationsInterface();//escolher qual o aeroporto
        void nDestinationsTypeInterface(Vertex<Airport>* airport); //escolher o tipo de destino sobre o qual quer a informação
            void nDestinationsShowInterface(Vertex<Airport>* airport,int num);
                map<std::string,int> nDestinationsAirports(Vertex<Airport>* airport); // 3v
                map<std::string,int> nDestinationsCities(Vertex<Airport>* airport); // 3v
                map<std::string,int> nDestinationsCountries(Vertex<Airport>* airport); // 3v

    //3vi
    void nReachableDestinationsInterface();// escolher o aeroporto de partida
        void nReachableDestinationsTypeInterface(Vertex<Airport>* airport); //escolher o tipo de destino
            void nReachableDestinationsStopsInterface(Vertex<Airport>* airport, int dest); //escolher o numero de escalas
                void nReachableDestinationsShowAirports (Vertex<Airport>* airport, int escalas, int dest,std::string tipo); //mostrar
    map<std::string,int> nReachableDestinationsAirports(Vertex<Airport>* airport,int k); // 3vi
    map<std::string,int> nReachableDestinationsCities(Vertex<Airport>* airport,int k); // 3vi
    map<std::string,int> nReachableDestinationsCountries(Vertex<Airport>* airport,int k); // 3vi

    //vii
    void maxTripInterface();
        pair<vector<pair<std::string,std::string>>,int>maxTrip(); // vii

    //viii
        void gratestKInterface();
            void gratestKShowInterface(int k);
                std::vector<pair<Airport, int>> nGreatestAirTrafficCapacity(int k); // 3viii
    //ix
    void essentialAirportsInterface();
        set<std::string>  essentialAirports(); //3ix
    // 4 BestFlightOption
    void flightOptionsInterfaceStart();
    void flightOptionsInterfaceTarget(int i);
    void preferenceAirlineInterface(int i ,int d);
    void preferenceAirlineChosingInterface(int i ,int d);
    void minimizeAirlinesInterface(int i ,int d,vector<std::string>airlines);
    void choose(int i ,int d,vector<std::string>airlines,bool minimize);

    void AirportToAirportInterface(int i ,int d,vector<std::string>airlines,bool minimize);
    void AirportToAirportInterfaceResult(int i ,int d,vector<std::string>airlines,bool minimize,Vertex<Airport>* v, Vertex<Airport>* b);
    vector<vector<Flight>> AirportToAirport(Vertex<Airport>* v, Vertex<Airport>* b);
    vector<vector<Flight>> AirportToAirportWF(Vertex<Airport>* a, Vertex<Airport>* b,vector<std::string>airlines); // with airline filter

    void AirportToCityInterface(int i ,int d,vector<std::string>airlines,bool minimize);
    void AirportToCityInterfaceResult(int i ,int d,vector<std::string>airlines,bool minimize,Vertex<Airport>* v, std::string c);
    vector<vector<Flight>> AirportToCity(Vertex<Airport>* v, std::string c,vector<std::string>airlines);

    void AirportToGeoCordinatesInterface(int i, int d, vector<std::string>airlines,bool minimize);
    void AirportToGeoCordinatesInterfaceResult(int i, int d, vector<std::string>airlines,bool minimize,Vertex<Airport>* v,double lat1,double long1);
    vector<vector<Flight>> AirportToGeoCordinates(Vertex<Airport>* v,double lat1,double long1,vector<std::string>airlines);

    void CityToAirportInterface(int i , int d ,vector<std::string>airlines,bool minimize);
    void CityToAirportInterfaceResult(int i, int d,vector<std::string>airlines,bool minimize,std::string c, Vertex<Airport>* v);
    vector<vector<Flight>> CityToAirport(std::string c, Vertex<Airport>* v,vector<std::string>airlines);

    void CityToCityInterface(int i, int d, vector<std::string>airlines,bool minimize);
    void CityToCityInterfaceResult(int i, int d, vector<std::string>airlines,bool minimize,std::string c1, std::string c2);
    vector<vector<Flight>> CityToCity(std::string a, std::string b,vector<std::string>airlines);

    void CityToGeoCordinatesInterface(int i, int d, vector<std::string>airlines,bool minimize);
    void CityToGeoCordinatesInterfaceResult(int i, int d, vector<std::string>airlines,bool minimize,std::string c, double lat1,double long1);
    vector<vector<Flight>> CityToGeoCordinates(std::string c, double lat1,double long1,vector<std::string>airlines);

    void GeoCordinatesToAirportInterface(int i,int d,vector<std::string>airlines,bool minimize);
    void GeoCordinatesToAirportInterfaceResult(int i,int d,vector<std::string>airlines,bool minimize,double lat1,double long1,Vertex<Airport>* v);
    vector<vector<Flight>> GeoCordinatesToAirport(double lat1,double long1,Vertex<Airport>* v,vector<std::string>airlines);

    void GeoCordinatesToCityInterface(int i,int d,vector<std::string>airlines,bool minimize);
    void GeoCordinatesToCityInterfaceResult(int i,int d,vector<std::string>airlines,bool minimize,double lat1,double long1,std::string c);
    vector<vector<Flight>> GeoCordinatesToCity(double lat1,double long1,std::string c,vector<std::string>airlines);

    void GeoCordinatesToGeoCordinatesInterface(int i,int d,vector<std::string>airlines,bool minimize);
    void GeoCordinatesToGeoCordinatesInterfaceResult(int i,int d,vector<std::string>airlines,bool minimize,double lat1,double lat2,double long1,double long2);
    vector<vector<Flight>> GeoCordinatesToGeoCordinates(double lat1,double lat2,double long1,double long2,vector<std::string>airlines);

    void interfaceResult();

    vector<vector<Flight>> ListAirportToListAirport(queue<Vertex<Airport>*> s, queue<Vertex<Airport>*> t); // General function used in almost every case
    vector<vector<Flight>> ListAirportToListAirportWF(queue<Vertex<Airport>*> s, queue<Vertex<Airport>*> t,vector<std::string>airlines); // With airline filter
    void minimizeAirlines(vector<vector<Flight>> &flights); // To minimize the diferent airlines in the answer

};


#endif //PROJETOAED5_MENU_H