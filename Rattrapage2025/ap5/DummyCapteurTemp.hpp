/**
 *	@file	CapteurTemp.hpp
 * 	@brief 	Header file for temperature sensor interface
 * 	@author		
 * 	@date	
 * 
 */

#ifndef __DUMMY_CAPTEUR_TEMP_H__
#define	__DUMMY_CAPTEUR_TEMP_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <vector>

#include "CapteurTemp.hpp"

/**
 * 	DummyCapteurTemp Class (Interface)
 * 
 * 
 */
class DummyCapteurTemp: public CapteurTemp{
	
	public:
		DummyCapteurTemp() = default;
		virtual ~DummyCapteurTemp() = default;

		/**
		*	\brief constructeur qui prend tous les paremtres pour 
					etre setter pas l'utilisateur
		* 	\param Tmin: la valeur min
			\param Tmax: la valeur max 
			\param temperature: la valeur de temperature à l'initiale
			\param delta: la difference qu'on accepete netre 2 val consecutive
		*/	
		DummyCapteurTemp(double Tmin, double Tmax, double temp, double delta);

		/**
		*	\brief permet de determiber la temperature d'ambiance 
					realiser la moyenne sur 5 dernieres valeurs 
		* 	@return 
		*/	
		double temperatureAmbiante();

		/**
		*	\brief generer une valeur de temperature au hasard
					on verifie qu'elle soit réaliste en la comparant 
					avec la derniere valeur de temperature mesurée
			        elle est ensuite stocker dans un vecteur 
		*/	
		void recupererTemp();

		
		/**
		*	\brief cette methode sert à stocker les elements dans notre vecteur
		* 	\param valueAstocker: la valeur de temperature a placer dans le vecteur 
		*/	
		void stockerValue(double valueAstocker);

		////----------------------------- ACCESSORS -----------------------------------////

		std::vector<double> getValueVector(){return stockValue;};

		virtual double 	getTemp(){return this->temperature;};
		bool setTemp(double temperature);

        void setMesure(int value);
        int getMesure(){return this->mesure;};

		double getDelta(){return this->delta;};
		//Pas de set car delta est en read only
        
	private:
	    double temperature; //temperature d'initialisation du capteur
	    const double delta = 2.0; // difference acceptée entre 2 valeurs successives
	    std::vector<double> stockValue;
	    int mesure = -1;
	    double tMin = getTemp() - delta;
	    double tMax = getTemp() + delta;
	
};


#endif //__DUMMY_CAPTEUR_TEMP_H__



