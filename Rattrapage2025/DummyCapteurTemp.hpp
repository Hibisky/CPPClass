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
		DummyCapteurTemp(double Tmin, double Tmax, double temp, double delta);
		double temperatureAmbiante();
		void recupererTemp();
		void stockerValue(double valueAstocker);
		double getValueVector();

		virtual double 	getTemp(){return this->temperature;};
		bool setTemp(double temperature);

        void setMesure(int value);
        int getMesure();

		double getDelta();
		//Pas de set car delta est en read only
        
	private:
	    double temperature; //temperature d'initialisation du capteur
	    const double delta = 2; // difference acceptée entre 2 valeurs successives
	    std::vector<double> stockValue;
	    int mesure = -1;
	    double tMin = getTemp() - delta;
	    double tMax = getTemp() + delta;
	
};


#endif //__DUMMY_CAPTEUR_TEMP_H__



