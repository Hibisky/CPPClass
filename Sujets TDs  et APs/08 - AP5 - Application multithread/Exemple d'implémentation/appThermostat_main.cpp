/**
 *	@file		appThermostat_main.cpp
 * 	@brief 		main for the Thermostat App 
 * 	@author		Alexis ROLLAND
 * 	@date		09/2024
 * 
 */
#include <print>
#include <memory>

#include "appThermostat.hpp"
#include "Chaudiere.hpp"
#include "DummyCapteurTemp.hpp"
#include "NetworkCapteurTemp.hpp"

#include <cassert>

//#define		TEST_CHAUDIERE
//#define		TEST_DUMMY_CAPTEUR_TEMP
//#define		TEST_NETWORK_CAPTEUR_TEMP
#define		APPLICATION

//----------------------------------------------------------------------------
//--------------------- Unit test : Chaudiere	------------------------------
#ifdef	TEST_CHAUDIERE
int main(){
	bool Ok{false};

	std::println("Test unitaire - Chaudière");

	// Test Ctor
	DummyChaudiere	myBoiler{};
	//std::cout << "Etat Chaudière après construction : " << static_cast<int>(myBoiler.getStatus())  << " - Should be 1\n";		
	std::println ("Etat Chaudière après construction : {0:d} - Should be 1",static_cast<int>(myBoiler.getStatus()));
	assert(myBoiler.getStatus() == Chaudiere::Status::OFF);

	// Test SetON - OK
	myBoiler.setON();
	//std::cout << "Etat Chaudière après setON : " << static_cast<int>(myBoiler.getStatus())  << " - Should be 0\n";	
	std::println ("Etat Chaudière après construction : {0:d} - Should be 0",static_cast<int>(myBoiler.getStatus()));	
	assert(myBoiler.getStatus() == Chaudiere::Status::ON);

	// Test SetON - should throw an exception
	try
	{
		myBoiler.setON();
	}
	catch(const BoilerAlreadyONexception& e)
	{
		std::println("Exception catched OK\n");
		Ok = true;
	}
	assert (Ok == true);

	Ok = false;

	// Test SetOFF - OK
	myBoiler.setOFF();
	//std::cout << "Etat Chaudière après setOFF : " << static_cast<int>(myBoiler.getStatus())  << " - Should be 1\n";	
	std::println ("Etat Chaudière après construction : {0:d} - Should be 1",static_cast<int>(myBoiler.getStatus()));	
	assert(myBoiler.getStatus() == Chaudiere::Status::OFF);
	
	// Test SetOFF - should throw an exception
	try
	{
		myBoiler.setOFF();
	}
	catch(const BoilerAlreadyOFFexception& e)
	{
		std::println("Exception catched OK\n");
		Ok = true;
	}
	assert (Ok == true);

	std::cout << "Test unitaire Chaudière Validé\n";

	return 0;
}
#endif
//----------------------------------------------------------------------------
//--------------------- Unit test : DummyCapteurTemp	----------------------
#ifdef	TEST_DUMMY_CAPTEUR_TEMP
int main(){

	std::println("Test unitaire - DummyCapteurTemp");

	DummyCapteurTemp mySensor{};

	for (int i = 0; i<10; ++i) std::println("Tirage {0:d} : {1:0.1f}",i ,mySensor.getTemp());

	return 0;
}
#endif /* 	TEST_DUMMY_CAPTEUR_TEMP 	*/

//----------------------------------------------------------------------------
//--------------------- Unit test : NetworkCapteurTemp	----------------------
#ifdef	TEST_NETWORK_CAPTEUR_TEMP
int main(){
	float temp;
	std::cout << "Test unitaire - NetworkCapteurTemp\n";

	NetworkCapteurTemp mySensor{};

	while(true){
		std::this_thread::sleep_for(3s);
		temp = mySensor.getTemp();
		std::println("Temperature = {0:0.1f} °C",temp);
	}


	return 0;
}
#endif /* 	TEST_NETWORK_CAPTEUR_TEMP 	*/

//----------------------------------------------------------------------------
//--------------------------- Application ------------------------------------
#ifdef	APPLICATION
int main(){
	std::println("--- Gestion chaudière - main app - Starting---");

	std::unique_ptr<DummyChaudiere>	pBoiler = std::make_unique<DummyChaudiere>();	/**<  Création Objet Chaudiere avec unique_ptr */

	ThermostatApp	myApp(pBoiler.get());

	myApp.Init();
	myApp.Run();

	return 0;
}	
#endif		/* APPLICATION 	*/
//----------------------------------------------------------------------------









