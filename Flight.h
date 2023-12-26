//
// Created by User on 23/12/2023.
//

#ifndef PROJETOAED5_FLIGHT_H
#define PROJETOAED5_FLIGHT_H

#include <string>
#include "Airline.h"


class Flight {
private:
    std::string source;
    std::string target;
    std::string airline;
public:
    bool operator<(const Flight& other) const {return source < other.source;}
    Flight(std::string source_, std::string target_, std::string airline1);
    std::string getSource();
    std::string getTarget();
    std::string getAirlineFromFlight();
};


#endif //PROJETOAED5_FLIGHT_H