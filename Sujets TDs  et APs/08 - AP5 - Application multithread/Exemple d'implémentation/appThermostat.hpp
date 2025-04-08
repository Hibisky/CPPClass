/**
 *	@file		appThermostat.hpp
 * 	@brief 		header file for the Application Interface and ThermostatApp class
 * 	@author		Alexis ROLLAND
 * 	@date		09/2024
 * 
 */
#ifndef __APP_THERMOSTAT_H__
#define	__APP_THERMOSTAT_H__


#define		DUMMY_SENSOR	1
#define		NETWORK_SENSOR	2
#define		SENSOR_TYPE  	DUMMY_SENSOR

#include <iostream>
#include <thread>
#include <array>
#include <mutex>
#include <chrono>

#include "DummyCapteurTemp.hpp"
#include "NetworkCapteurTemp.hpp"
#include "Chaudiere.hpp"

using namespace std::literals::chrono_literals;

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

class	NoBoilerException:public std::exception{};			/**< Exception thrown if no boiler exists	*/

constexpr	int filterSize = 5;
constexpr	float	defaultConsigne = 19.0;
constexpr	float	defaultHysteresis = 1.0;

constexpr	auto	measure_delay = 1s;
constexpr	auto	process_delay = 5s;

class	ThermostatApp:public Application{

	private:
		#if (SENSOR_TYPE == DUMMY_SENSOR)
			DummyCapteurTemp Capteur{};
		#elif (SENSOR_TYPE == NETWORK_SENSOR)
			NetworkCapteurTemp Capteur{};
		#else
		#endif
		
		Chaudiere *pChaudiere{nullptr};

		std::array<float,filterSize> tabTemp{};
		uint8_t	ptr{0};
		std::mutex arrayMutex{};
		uint8_t getptr(){return this->ptr;};
		void	setptr(uint8_t value){this->ptr = value;};
		void	addTemp(float temp);
		float	getTemp();

		float	Consigne{defaultConsigne};
		float	getConsigne(){return this->Consigne;};

		float	Hysteresis{defaultHysteresis};
		float	getHysteresis(){return this->Hysteresis;};

		std::jthread	measureThread;
		void _measureThread();

		std::jthread	processingThread;
		void _processingThread();

	public:
		ThermostatApp() = delete;											/**< Deleted default Ctor		*/
		ThermostatApp(Chaudiere* pChaudiere):pChaudiere{pChaudiere}{};
		virtual ~ThermostatApp() = default;
		
		

		/**
		 * 	Init function
		 * 		This function : 
		 * 			MUST be called once.
		 * 			Checks the pChaudiere pointer
		 * 			Creates and starts the threads 
		 * 	@throw	NoBoilerException if pChaudiere is a nullptr
		 * 
		 */
		virtual void	Init() override;
		
		/**
		 * 	Run function
		 * 		main task
		 * 		May be empty (multithreaded app)
		 */
		virtual void	Run() override;
	
	
};

#endif	/* __APP_THERMOSTAT_H__ */

