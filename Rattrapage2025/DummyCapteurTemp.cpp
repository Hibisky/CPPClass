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
        std::cout << somValue << std::endl;
    }
    return somValue;
}
//----------------------------------------------------------------------

void DummyCapteurTemp::recupererTemp()
{
    double randomtemp = distrib(gen); //generer une valeur au hasard
    bool validTemp = setTemp(randomtemp); //On s'assure qu'elle soit realiste
    stockValue.push_back(validTemp);// stocker la valeur
}
//----------------------------------------------------------------------

bool DummyCapteurTemp::setTemp(double temperatureIn)
{
    
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

double DummyCapteurTemp::getValueVector(){
    
    return 1;
}
//----------------------------------------------------------------------
void DummyCapteurTemp::setMesure(int newMesure){
    mesure = newMesure;
}
//----------------------------------------------------------------------
int DummyCapteurTemp::getMesure(){
    return mesure;
}
//----------------------------------------------------------------------

