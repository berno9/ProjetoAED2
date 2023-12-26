//
// Created by User on 23/12/2023.
//

#include "Airline.h"

Airline::Airline(std::string name_) : name(name_) {}
Airline::Airline(std::string code,std::string name,std::string callSign,std::string country){
    this->code = code;
    this->name = name;
    this->callSign = callSign;
    this->country = country;
}

void Airline::setCode(std::string code_) {
    code = code_;
}

void Airline::setName(std::string name_) {
    name = name_;
}

void Airline::setCallSign(std::string callSign_) {
    callSign = callSign_;
}

void Airline::setCountry(std::string country_) {
    country = country_;
}
std::string Airline::getCode() const {
    return code;
}

std::string Airline::getName() const {
    return name;
}

std::string Airline::getCallSign() const {
    return callSign;
}

std::string Airline::getCountry() const {
    return country;
}