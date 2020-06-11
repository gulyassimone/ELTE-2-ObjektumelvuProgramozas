//Készítette:    Veszprémi Anna
//Dátum:         2018.02.20.
//Menürendszer header állomány

#pragma once

#include "priorsor.h"

class Menu
{
    public:
        Menu(){};
        void Run();
    private:
        int MenuPrint();
        void Sorba();
        void Sorbol();
        void Legnagyobb();
        void Urese();
        void KiirSor();
        void TerhelesTeszt();
        PrQueue pq;

};
