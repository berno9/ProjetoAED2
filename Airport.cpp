//
// Created by User on 23/12/2023.
//

#include "Airport.h"

Airport::Airport(std::string name_) : name(name_) {}


void Airport::setCode(std::string code_) {
    code = code_;
}

void Airport::setName(std::string name_) {
    name = name_;
}

void Airport::setCity(std::string city_) {
    city = city_;
}

void Airport::setCountry(std::string country_) {
    country = country_;
}

void Airport::setLatitude(double latitude_) {
    latitude = latitude_;
}

void Airport::setLongitude(double longitude_) {
    longitude = longitude_;
}

std::string Airport::getCode() const {
    return code;
}

std::string Airport::getName() const {
    return name;
}

std::string Airport::getCity() const {
    return city;
}

std::string Airport::getCountry() const {
    return country;
}

double Airport::getLatitude() const {
    return latitude;
}

double Airport::getLongitude() const {
    return longitude;
}