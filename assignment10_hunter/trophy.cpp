#include "trophy.h"

Trophy::Trophy(std::string spieces,std::string spot,std::string date,int weight, std::string specialAttribute)
{
    this->spieces=spieces;
    this->spot=spot;
    this->date=date;
    this->weight=weight;
    this->specialAttribute.gender=specialAttribute;
}

Trophy::Trophy(std::string spieces,std::string spot,std::string date,int weight, int specialAttribute)
{
    this->spieces=spieces;
    this->spot=spot;
    this->date=date;
    this->weight=weight;
    this->specialAttribute.hornWeight=specialAttribute;
}
Trophy::Trophy(std::string spieces,std::string spot,std::string date,int weight, IvoryLength specialAttribute)
{
    this->spieces=spieces;
    this->spot=spot;
    this->date=date;
    this->weight=weight;
    this->specialAttribute.ivoryLength=specialAttribute;
}
