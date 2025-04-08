#include <iostream>
#include <print>
#include "Config.hpp"

int main(){
    std::println ("-- Test classe Config --");  /**< Affichage */
    
    Config myConfig{};  /**< New Config Object */

    Config::pic24_register  TRISA{"TRISA",0xff00};

    myConfig.add(TRISA);
    myConfig.dump(); 

    try{
        myConfig.add(TRISA);
    }
    catch(const std::exception &e){
        std::println("Trying to add an existing register - Exception catched : {}",e.what());
    }
    myConfig.dump();
    std::println("Size = {0:d}",myConfig.getSize());

    TRISA.second = 0xAA55;
    myConfig.add(TRISA,true);
    myConfig.dump();

    try{
        myConfig.remove("LATA");
    }
    catch(const std::exception &e){
        std::println("Trying to remove a non existing register - Exception catched : {}",e.what());
    }
    myConfig.dump();

    myConfig.remove(TRISA);
    if (myConfig.isEmpty()) std::println("Config is now empty - OK");


    myConfig.add(TRISA);
    myConfig.dump();

    myConfig.add({"TRISB",0x000});
    myConfig.dump();
    std::println("Size = {0:d}",myConfig.getSize());

    std::println("--- End Test ---");


    return 0;
}
