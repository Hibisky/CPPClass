/**
 *	@file		appThermostat.hpp
 * 	@brief 		header file for the Application Interface and ThermostatApp class
 * 	@author		
 * 	@date		
 * 
 */
#ifndef __APP_THERMOSTAT_H__
#define	__APP_THERMOSTAT_H__

#include <iostream>
#include <thread>
#include <array>
#include <mutex>

#include "DummyCapteurTemp.hpp"
#include "Chaudiere.hpp"

//----------------------------------------------------------------------
/**
 * 	Class Application
 * 
 * 	Interface to a "classic" embedded (or not) app 
 */
class Application{
	public:
		Application() = default;			/**<	Defaulted default Ctor	*/
		virtual ~Application() = default;	/**<	Defaulted Dtor	*/
		
		virtual void	Init() = 0;			/**<	Pure virtual function - Must include all init stuff	*/
		virtual void	Run() = 0;			/**<	Pure virtual function - Could include some code (or not...)	*/
};
//----------------------------------------------------------------------
/**
 * 	Class ThermostatApp
 * 
 * 	Concrete Thermostat app 
 */



class	ThermostatApp:public Application{

	private:
	
	public:
		ThermostatApp() = delete;											/**< Deleted default Ctor		*/
		virtual ~ThermostatApp() = default;
		

		ThermostatApp(Chaudiere *pChaudiere);

		/**
		 * 	Init function
		 * 		This function : 
		 * 			MUST be called once.
		 * 			Checks the pChaudiere pointer
		 * 			Creates and starts the threads 
		 * 	@throw	NoBoilerException if pChaudiere is a nullptr
		 * 
		 */
		virtual void	Init();
		
		/**
		 * 	Run function
		 * 		main task
		 * 		May be empty (multithreaded app)
		 */
		virtual void	Run();
	
	private:

    	DummyCapteurTemp capteur;
    	Chaudiere *pChaudiere = nullptr; // Corrected declaration syntax
		double hysteresis;
		double consigne;
    	// Mutex et condition_variable pour synchroniser les threads
    	std::mutex temperatureAmbiante;
    	std::condition_variable cv;

};

#endif	/* __APP_THERMOSTAT_H__ */
