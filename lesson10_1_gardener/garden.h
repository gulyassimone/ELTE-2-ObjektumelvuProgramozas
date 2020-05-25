#pragma once
#include "parcel.h"
#include <vector>

class Garden
{
    protected:
        std::vector<Parcel*> _parcels;
    public:
        Garden(int n);

        std::vector<int> canHarvest(int date);

        void plant(int id, Plant* plant, int date){
            _parcels[id]->plant(plant, date);
        }

        ~Garden();
};
