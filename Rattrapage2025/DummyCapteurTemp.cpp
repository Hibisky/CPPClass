/**
 *	@file		DummyCapteurTemp.cpp
 * 	@brief 		DummyCapteurTemp definition file
 * 	@author		
 * 	@date		
 * 
 */
#include "DummyCapteurTemp.hpp"

#include <iostream>
#include <memory>
#include <thread>
#include <random>
#include <algorithm>
#include <format>

// Random generators
std::random_device rd;  
std::mt19937 gen(rd()); 
std::uniform_int_distribution<int> distrib(0, 20);

double DummyCapteurTemp::temperatureAmbiante(){
    double somValue = 0; 
    for (int i=0; i < stockValue.max_size(); ++i)
    {
        double randomTemp = stockValue.front()+ i;
        somValue += randomTemp;
        std::accumulate(stockerValue.front, stockerValue.end);
    }
    return somValue;
}

//----------------------------------------------------------------------

void DummyCapteurTemp::recupererTemp()
{
    double randomtemp = distrib(gen); //generer une valeur au hasard
    double validTemp = setTemp(randomtemp); //On s'assure qu'elle soit realiste
    stockerValue(validTemp);
}
//----------------------------------------------------------------------

void DummyCapteurTemp::stockerValue(double valueAstocker)
{
    if (stockValue.size() <= 5)
    {
        std::cout << " stockValue.size() " << stockValue.size() << std::endl;
        stockValue.push_back(valueAstocker);// stocker la valeur dans le vecteur 
    }
    else {
        //supprimer l'element le plus ancien (place 1)
        //avancer tous les elements d'une case
    }
}


//----------------------------------------------------------------------

bool DummyCapteurTemp::setTemp(double temperatureIn)
{
    //TODO : utiliser once pour faire un tour de boucle plus propre 
    if (getMesure() > 0)
    {
        if ((temperatureIn >= temperature - delta) && (temperatureIn <= temperature + delta))
        {
            temperature = temperatureIn;
            //std::cout << " new valeur de temperature ok" << std::endl;
        }
        else 
        {
            //std::cout << " la temperature prelevée n'est pas réaliste" << std::endl;
            return false;
        }
    }
    setMesure(getMesure()+1); //on incremente le nobre de prise de temperature
    return true;
}

//----------------------------------------------------------------------

double DummyCapteurTemp::getValueVector(){return 1;}

//----------------------------------------------------------------------

void DummyCapteurTemp::setMesure(int newMesure){
    mesure = newMesure;
}
//----------------------------------------------------------------------
int DummyCapteurTemp::getMesure(){
    return mesure;
}
//----------------------------------------------------------------------

double DummyCapteurTemp::getDelta(){return delta;}