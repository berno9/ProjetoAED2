//
// Created by User on 23/12/2023.
//

#ifndef PROJETOAED5_FLIGHT_H
#define PROJETOAED5_FLIGHT_H

#include <string>
#include "Airline.h"

/// Esta classe representa um voo, com os seus atributos
/// @param source : código do aeroporto de partida
/// @param target : código do aeroporto de destino
/// @param airline : código da companhia aérea que realiza esse voo
/// @see Airline()

class Flight {
private:
    std::string source;
    std::string target;
    std::string airline;
public:
    /// Comparador de voos
    /// @param other : voo
    bool operator<(const Flight& other) const {return source < other.source;}

    /// Construtor de voos que cria um voo com um código do aeroporto de origem, um código do aeroporto de destino e o código da companhia aérea que realiza o voo
    /// @param source : código do aeroporto de partida
    /// @param target : código do aeroporto de destino
    /// @param airline : código da companhia aérea que realiza esse voo
    Flight(std::string source_, std::string target_, std::string airline1);

    /// Obter o código do aeroporto de partida
    /// @return código do aeroporto
    std::string getSource();

    /// Obter o código do aeroporto de destino
    /// @return código do aeroporto
    std::string getTarget();

    /// Obter o código da companhia aérea
    /// @return código da companhia
    std::string getAirlineFromFlight();
};


#endif //PROJETOAED5_FLIGHT_H