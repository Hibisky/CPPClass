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
		
		double temperatureAmbiante();
		virtual double 	getTemp(){return this->temperature;};
		double getValueVector();
		bool setTemp(double temperature);
		void recupererTemp();
        void setMesure(int value);
        int getMesure();
        
	private:
	    double temperature; //temperature d'initialisation du capteur
	    const double delta = 2; // difference acceptée entre 2 valeurs successives
	    std::vector<double> stockValue;
	    int mesure = -1;
	    double mintemp = getTemp() - delta;
	    double maxtemp = getTemp() + delta;
	
};


#endif //__DUMMY_CAPTEUR_TEMP_H__



