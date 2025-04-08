#include "Sensor.hpp"

//-----------------------------------------------------------------------------
void    ADT7310::elaborateNewValue(){
    uint16_t    Temp;
    // Crée un générateur de nombres pseudo-aléatoires avec un "seed" unique pour chaque exécution
    std::random_device rd;  
    std::mt19937 gen(rd()); 

    // Définir une distribution uniforme entre ...
    if (this->getMode() == ADT7310Mode::MODE13BITS){
        std::uniform_int_distribution<uint16_t> distrib(0, 0x1FFF);
        Temp = distrib(gen);
    } 
    else{
        std::uniform_int_distribution<uint16_t> distrib(0, 0xFFFF);
        Temp = distrib(gen);
    }

    this->setOutputValue(Temp);
}
//-----------------------------------------------------------------------------
double  ADT7310::getConvertedTemperature() const noexcept{
    double Temp;
    uint16_t    rawTemp = this->getOutputValue();

    if (this->getMode() == ADT7310Mode::MODE13BITS){
        if (rawTemp < 0x1000) Temp = rawTemp / 16.0;        // Temperature is positive
        else Temp = (rawTemp - 8192) / 16.0;                 // Temperature is negative
    }
    else{
        if (rawTemp < 0x8000) Temp = rawTemp / 128.0;        // Temperature is positive
        else Temp = (rawTemp - 65536) / 128.0;                 // Temperature is negative
    }

    return Temp;    
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void    TC74::elaborateNewValue(){

    // Crée un générateur de nombres pseudo-aléatoires avec un "seed" unique pour chaque exécution
    std::random_device rd;  
    std::mt19937 gen(rd()); 

    // Définir une distribution uniforme entre -65 et 127
    std::uniform_int_distribution<int> distrib(-65, 127);

    // Générer un nombre aléatoire dans l'intervalle
    int8_t Temp = distrib(gen);

    this->setOutputValue(Temp);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void    LM35::elaborateNewValue(){

    // Crée un générateur de nombres pseudo-aléatoires avec un "seed" unique pour chaque exécution
    std::random_device rd;  
    std::mt19937 gen(rd()); 

    // Définir une distribution uniforme entre -55 et 150
    std::uniform_real_distribution<double> distrib(-55.0, 150.0);

    // Générer un nombre réel aléatoire dans l'intervalle
    double Temp = distrib(gen);
    this->setOutputValue(Temp);
}
//-----------------------------------------------------------------------------

