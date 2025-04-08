#include <print>

#include "Sensor.hpp"

constexpr   uint32_t    SIMPLE_SENSOR_UID{0xAA000001};

int main(void){
    std::println("--- Test Sensor Classes ---");

    TC74    tc74a0(0x48);

    std::println("Sensor UID = {0:08x}",tc74a0.getUID());
    std::println("Sensor Unit : {0}",tc74a0.getUnit());

    for (uint8_t i=0;i<10;++i){
        tc74a0.elaborateNewValue();
        std::print(" {0:d} ",tc74a0.getOutputValue());
    }
    
    std::println("");

    LM35    lm35ca{};
    std::println("Sensor UID = {0:08x}",lm35ca.getUID());
    std::println("Sensor Unit : {0}",lm35ca.getUnit());

    for (uint8_t i=0;i<10;++i){
        lm35ca.elaborateNewValue();
        std::print(" {0:.02f} ",lm35ca.getOutputValue());
    }

    std::println("");

    ADT7310 myAdt(0x11223344);
    std::println("Sensor UID = {0:08x}",myAdt.getUID());
    std::println("Sensor Unit : {0}",myAdt.getUnit());

    for (uint8_t i=0;i<10;++i){
        myAdt.elaborateNewValue();
        std::println(" {0:04x} = {1:.02f} ",myAdt.getOutputValue(),myAdt.getConvertedTemperature());
    }

    std::println("");

    myAdt.setMode(ADT7310::ADT7310Mode::MODE16BITS);

    for (uint8_t i=0;i<10;++i){
        myAdt.elaborateNewValue();
        std::println(" {0:04x} = {1:.02f}",myAdt.getOutputValue(),myAdt.getConvertedTemperature());
    }

    std::println("");


}


