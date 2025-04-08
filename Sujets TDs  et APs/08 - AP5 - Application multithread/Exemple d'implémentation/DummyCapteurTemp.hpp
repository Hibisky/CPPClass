/**
 *	@file	DummyCapteurTemp.hpp
 * 	@brief 	Header file for the DummyCapteurTemp concrete class
 *          (based on CapteurTemp interface)
 * 	@author	Alexis ROLLAND
 * 	@date	09/2024
 * 
 */

#ifndef __DUMMY_CAPTEUR_TEMP_H__
#define	__DUMMY_CAPTEUR_TEMP_H__

#include <random>

#include "CapteurTemp.hpp"

constexpr   int16_t defaultTmin{-200};          /**<	Default min temperature - in 1/10°C			*/
constexpr   int16_t defaultTmax{+700};          /**<	Default max temperature - in 1/10°C			*/
constexpr   uint16_t defaultDeltaMax{40};       /**<	Default max Delta temparature - in 1/10°C	*/
constexpr   int16_t defaultStartTemp{+200};     /**<	Default start temperature - in 1/10°C			*/

class DummyCapteurTemp:public CapteurTemp{
    private:
        mutable std::default_random_engine  generator{};
        int16_t Tmin{defaultTmin};
        int16_t Tmax{defaultTmax};
        uint16_t DeltaMax{defaultDeltaMax};
        mutable int16_t prevTemp{defaultStartTemp};

        int16_t getTmin() const noexcept {return this->Tmin;}; 
        int16_t getTmax() const noexcept {return this->Tmax;}; 
        
        uint16_t getDeltaMax() const noexcept {return this->DeltaMax;};
        
        int16_t getprevTemp() const noexcept {return this->prevTemp;};
        void    setprevTemp(int16_t prevtemp) const noexcept {this->prevTemp = prevtemp;};

    public:
        DummyCapteurTemp() = default; 
        virtual ~DummyCapteurTemp() = default; 

        DummyCapteurTemp(int16_t Tmin,int16_t Tmax,uint16_t Delta,int16_t StartTemp):Tmin{Tmin},Tmax{Tmax},DeltaMax{Delta},prevTemp{StartTemp}{};

        virtual float getTemp() const noexcept override; 

} ;




#endif   /*  __DUMMY_CAPTEUR_TEMP_H__ */

