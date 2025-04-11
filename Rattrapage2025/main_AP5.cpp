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
        std::this_thread::sleep_for(std::chrono::milliseconds(100));//tempo par ce qu eca fait plaisir 
    }
    std::cout << "Fin de la prise de temperature " << std::endl;
}

void processing(std::stop_source source,std::stop_token st)
{
    DummyChaudiere ch = DummyChaudiere();
    ch.getStatus();
    std::cout << "Chaudiere en marche " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // while(!st.stop_requested() )
    // {
    //   //fait la moyenne des valeur de temperature pour un capteur 
    //   //faire la difference etre la valeur de la temperature ambiante et la consigne
    //   //std::unique_lock lock()//permet de privatiser la ressource ici la chaudiere 
    // }
    //source.request_stop();
}

int main(){
    
  //variables qui permettent l'interruption des threads
	std::stop_source stopSource;
  std::stop_token stopToken = stopSource.get_token();

	
	//creation d'un thread pour la Chaudiere
	std::jthread chaudiere (processing,std::move(stopSource), stopToken); 
	
	//creation d'un thread pour la temperature
	std::jthread capTemp1 (capteurTempp,stopToken); 
	//
	
	
	return 0;
}

