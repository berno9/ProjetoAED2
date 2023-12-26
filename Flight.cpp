//
// Created by User on 23/12/2023.
//

#include "Flight.h"

Flight::Flight(std::string source_, std::string target_, std::string airline1) : source(source_), target(target_), airline(airline1){}

std::string Flight::getSource() {
    return source;
}

std::string Flight::getTarget() {
    return target;
}

std::string Flight::getAirlineFromFlight() {
    return airline;
}