/**
 *	@file	CapteurTemp.hpp
 * 	@brief 	Header file for temperature sensor interface
 * 	@author		
 * 	@date	
 * 
 */

#ifndef __CAPTEUR_TEMP_H__
#define	__CAPTEUR_TEMP_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
/**
 * 	CapteurTemp Class (Interface)
 * 
 * 
 */
class CapteurTemp{
	
	public:
		CapteurTemp() = default;
		virtual ~CapteurTemp() = default;
		
		
		virtual double 	getTemp() = 0;

	private:
		const int consigne = 19;//On souhaite que la salle soit a 19 degres	
};


#endif	/* __CAPTEUR_TEMP_H__ */


