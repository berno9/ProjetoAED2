//
// Created by User on 23/12/2023.
//

#ifndef PROJETOAED5_AIRLINE_H
#define PROJETOAED5_AIRLINE_H

#include <string>


class Airline {
private:
    std::string code;
    std::string name;
    std::string callSign;
    std::string country;
public:
    bool operator<(const Airline& other) const {return code < other.code;}
    Airline(std::string name_);
    Airline(std::string code,std::string name,std::string callSign,std::string country);
    void setCode(std::string code_);
    void setName(std::string name_);
    void setCallSign(std::string callSign_);
    void setCountry(std::string country_);
    std::string getCode() const;
    std::string getName() const;
    std::string getCallSign() const;
    std::string getCountry() const;
};


#endif //PROJETOAED5_AIRLINE_H
