/**
 *	@file		appThermostat_main.cpp
 * 	@brief 		main for the Thermostat App 
 * 	@author		
 * 	@date		
 * 
 */
#include <iostream>
#include <memory>
#include <thread>
#include <random>
#include <algorithm>
#include <format>
#include <chrono>
//#include <stop_source>
//#include <stop_token>

#include "appThermostat.hpp"
#include "Chaudiere.hpp"
#include "DummyCapteurTemp.hpp"



void capteurTempp(std::stop_token st)
{
    DummyCapteurTemp cpt = DummyCapteurTemp();
    std::cout << "Capteur de temperature Dummy en marche " << std::endl;
    cpt.recupererTemp(); 
    while (!st.stop_requested()) 
    {
        cpt.recupererTemp();    
        double randomTemp = cpt.getTemp();//prendre une mesure
        std::cout <<"Temperature Dummy: " << randomTemp << " degres Celsius" << std::endl;
        //faire la difference etre la valeur et la consigne
        //la stocker
        //faire la moyenne des 5 valeurs 
        
    }
    std::cout << "Fin de la prise de temperature " << std::endl;
}

void chaudiereVie(std::stop_source source)
{
    DummyChaudiere ch = DummyChaudiere();
    ch.getStatus();
    std::cout << "Chaudiere en marche " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    source.request_stop();
}
int main(){
    
  //variables qui permettent l'interruption des threads
	std::stop_source stopSource;
  std::stop_token stopToken = stopSource.get_token();

	
	//creation d'un thread pour la Chaudiere
	std::jthread chaudiere (chaudiereVie,std::move(stopSource)); 
	
	//creation d'un thread pour la temperature
	std::jthread capTemp1 (capteurTempp,stopToken); 
	//
	
	
	return 0;
}

