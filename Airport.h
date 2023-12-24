//
// Created by User on 23/12/2023.
//

#ifndef PROJETOAED5_AIRPORT_H
#define PROJETOAED5_AIRPORT_H

#include <string>
#include <vector>

class Airport {
private:
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    double latitude;
    double longitude;
public:
    bool operator<(const Airport& other) const {return code < other.code;}
    Airport(std::string name_);
    void setCode(std::string code_);
    void setName(std::string name_);
    void setCity(std::string city_);
    void setCountry(std::string country_);
    void setLatitude(double latitude_);
    void setLongitude(double longitude_);
    std::string getCode() const;
    std::string getName() const;
    std::string getCity() const;
    std::string getCountry() const;
    double getLatitude() const;
    double getLongitude() const;

};


#endif //PROJETOAED5_AIRPORT_H
