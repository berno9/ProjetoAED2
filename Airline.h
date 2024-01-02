//
// Created by User on 23/12/2023.
//

#ifndef PROJETOAED5_AIRLINE_H
#define PROJETOAED5_AIRLINE_H

#include <string>

/// Esta classe define uma companhia aérea, com os seus atributos
/// @param code : código da companhia aérea
/// @param name : nome
/// @param callSign : alcunha
/// @param country : país de origem

class Airline {
private:
    std::string code;
    std::string name;
    std::string callSign;
    std::string country;
public:

    /// Comparador de companhias aéreas
    /// @param other : companhia aérea
    bool operator<(const Airline& other) const {return code < other.code;}

    /// Construtor que cria uma companhia aérea com apenas um nome
    /// @param name_ : nome da companhia
    Airline(std::string name_);

    /// Cria uma companhia aérea com um código, um nome, uma alcunha, e um país de origem
    /// @param code : código da companhia aérea
    /// @param name : nome
    /// @param callSign : alcunha
    /// @param country : país de origem
    Airline(std::string code,std::string name,std::string callSign,std::string country);

    /// Altera o código de uma companhia aérea
    /// @param code_ : código da nova companhia
    void setCode(std::string code_);

    /// Altera o nome de uma companhia aérea
    /// @param name_ : nome da nova companhia
    void setName(std::string name_);

    /// Altera a alcunha de uma companhia aérea
    /// @param callSign_ : alcunha da nova companhia
    void setCallSign(std::string callSign_);

    /// Altera o país de origem de uma companhia aérea
    /// @param country_: país da nova companhia
    void setCountry(std::string country_);

    /// Obter o código de uma companhia aérea
    /// @return código
    std::string getCode() const;

    /// Obter o nome de uma companhia aérea
    /// @return nome
    std::string getName() const;

    /// Obter a alcunha de uma companhia aérea
    /// @return alcunha
    std::string getCallSign() const;

    /// Obter o país de origem de uma companhia aérea
    /// @return pais
    std::string getCountry() const;
};


#endif //PROJETOAED5_AIRLINE_H