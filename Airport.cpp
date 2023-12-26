//
// Created by User on 23/12/2023.
//

#include "Airport.h"
Airport::Airport(){
    this->code = "";
    this->name ="";
    this->city = "";
    this->country ="";
    this->latitude =0;
    this->longitude = 0;
}
Airport::Airport(const Airport &other) {
    this->code = other.code;
    this->name = other.name;
    this->city = other.city;
    this->country = other.country;
    this->latitude = other.latitude;
    this->longitude = other.longitude;
}
Airport::Airport(std::string code,std::string name,std::string city,std::string country,double latitude,double longitude){
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this->longitude = longitude;
}
bool Airport ::operator==(const Airport &other){
    return code == other.code;
}

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
