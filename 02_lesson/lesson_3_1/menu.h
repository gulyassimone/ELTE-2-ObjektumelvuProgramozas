//K�sz�tette:    Veszpr�mi Anna
//D�tum:         2018.02.20.
//Men�rendszer header �llom�ny

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
