//
// Created by User on 23/12/2023.
//

#ifndef PROJETOAED5_AIRPORT_H
#define PROJETOAED5_AIRPORT_H

#include <string>
#include <vector>

/// Esta classe define um aeroporto, com os seus atributos
/// @param code : código do aeroporto
/// @param name : nome
/// @param city : cidade onde está localizado
/// @param country : país onde está localizado
/// @param latitude : latitude da localização
/// @param longitude : longitude da localização

class Airport {
private:
    std::string code;
    std::string name;
    std::string city;
    std::string country;
    double latitude;
    double longitude;
public:
    /// Comparadores de aeroportos
    /// @param other : aeroporto
    bool operator<(const Airport& other) const {return code < other.code;}
    bool operator==(const Airport &other);

    /// Construtor padrão, cria um aeroporto com atributos nulos
    Airport();

    /// Altera os atributos de um aeroporto
    /// @param other : aeroporto com os novos atributos
    Airport(const Airport &other);

    /// Cria um aeroporto com um código, um nome, de uma cidade, de um país, numa localização com uma certa latitude e uma certa longitude
    /// @param code : código do aeroporto
    /// @param name : nome
    /// @param city : cidade onde está localizado
    /// @param country : país onde está localizado
    /// @param latitude : latitude da localização
    /// @param longitude : longitude da localização
    Airport(std::string code,std::string name,std::string city,std::string country,double latitude,double longitude);

    /// Altera o código de um aeroporto
    /// @param code_ : código do novo aeroporto
    void setCode(std::string code_);

    /// Altera o nome de um aeroporto
    /// @param name_ : nome do novo aeroporto
    void setName(std::string name_);

    /// Altera a cidade de um aeroporto
    /// @param city_ : cidade novo aeroporto
    void setCity(std::string city_);

    /// Altera o país de um aeroporto
    /// @param country_ : país do novo aeroporto
    void setCountry(std::string country_);

    /// Altera a latitude da localização de um aeroporto
    /// @param latitude_ : latitude do novo aeroporto
    void setLatitude(double latitude_);

    /// Altera a longitude da localização de um aeroporto
    /// @param longitude_ : longitude do novo aeroporto
    void setLongitude(double longitude_);

    /// Obter o código de um aeroporto
    /// @return código
    std::string getCode() const;

    /// Obter o nome de um aeroporto
    /// @return nome
    std::string getName() const;

    /// Obter a cidade de origem de um aeroporto
    /// @return cidade
    std::string getCity() const;

    /// Obter o país de origem de um aeroporto
    /// @return país
    std::string getCountry() const;

    /// Obter a latitude da localização de um aeroporto
    /// @return latitude
    double getLatitude() const;

    /// Obter a longitude da localização de um aeroporto
    /// @return longitude
    double getLongitude() const;

};

#endif //PROJETOAED5_AIRPORT_H