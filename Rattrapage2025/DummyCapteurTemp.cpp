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

double DummyCapteurTemp::temperatureAmbiante() {
    if (stockValue.empty()) return 0.0; // sécurité : éviter une division par zéro

    double somValue = std::accumulate(stockValue.begin(), stockValue.end(), 0.0);
    return somValue / static_cast<double>(stockValue.size());
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
    //On veut max une moyenne sur 5 valeurs de temp
    if (stockValue.size() >= 5) 
    {
        // Supprimer l'élément le plus ancien (le premier)
        stockValue.erase(stockValue.begin());
    }
    stockValue.push_back(valueAstocker);//on ajoute  la valeur a la fin du vecteur
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

// std::vector<double> DummyCapteurTemp::getValueVector() {
//     if (!stockValue.empty()) {
//         return stockValue; // la dernière valeur ajoutée
//     }
//     return EXIT_FAILURE; //vecteur vide donc pas de valeurs
// }

//----------------------------------------------------------------------

void DummyCapteurTemp::setMesure(int newMesure){
    mesure = newMesure;
}

//----------------------------------------------------------------------