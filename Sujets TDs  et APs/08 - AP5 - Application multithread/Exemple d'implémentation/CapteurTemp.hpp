/**
 *	@file	CapteurTemp.hpp
 * 	@brief 	Header file for the CapteurTemp interface
 * 	@author	Alexis ROLLAND
 * 	@date	09/2024
 * 
 */

#ifndef __CAPTEUR_TEMP_H__
#define	__CAPTEUR_TEMP_H__

class CapteurTemp{
	
	public:
		CapteurTemp() = default;			/**<	Defaulted default Ctor	*/
		virtual ~CapteurTemp() = default;	/**<	Defaulted Dtor			*/
				
		/**
		*	getTemp() function - pure virtual function
		* 		gets the temperature 
		*
		*	@return  Temperature in °C (float)
		*/			
		virtual float 	getTemp() const = 0;
	
};


#endif	/* __CAPTEUR_TEMP_H__ */
