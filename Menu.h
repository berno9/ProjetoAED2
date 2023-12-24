//
// Created by User on 23/12/2023.
//

#ifndef PROJETOAED5_MENU_H
#define PROJETOAED5_MENU_H

#include <iostream>
#include <string>
#include <set>
#include "Graph.h"
#include "Airport.h"
#include "Airline.h"
#include "Flight.h"

class Menu {
private:
    Graph<std::string>* g;
public:
    Menu(Graph<std::string>* g_);
    void Base();
        void DisplayOptions();
            void SourceNo();
            void DestNo();
            void SourceDestNo();
            void allNo();
            void SourceYes();
            void DestYes();
            void SourceDestYes();
            void allYes();
};


#endif //PROJETOAED5_MENU_H
