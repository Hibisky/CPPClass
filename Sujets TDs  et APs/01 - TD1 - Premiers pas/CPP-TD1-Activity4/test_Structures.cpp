
#include <iostream>
#include "lib_TD1_structures.hpp"


int main(){
    
    // Definition, no init
    /*
    point   Dummy;
    dump(Dummy);
    */

    // Simple definition, init to default
    point   A{};
    dump(A);

    // Accessing members
    A.x = 42;
    A.y = 66;

    A.Couleur.Red = 255;
    A.Couleur.Green = 127;
    A.Couleur.Blue = 0;

    dump(A);

    const   point   OriginWhite{0,0,White};
    dump(OriginWhite);

    //Move(OriginWhite,10,10);    // NOK car OriginWhite est un const point

    point   Traveler{1000,1000,0,0,0};  // Another way to init struct
    dump(Traveler);

    bool    Res;
    Res = Move(Traveler,100,100);   // Should be successfull
    if (Res == true) std::printf("Successfull move\n");
    else std::printf("Unsuccessfull move\n");
    dump(Traveler);


    Res = Move(Traveler,-10000,0);    // Should be unsuccessfull
    if (Res == true) std::printf("Successfull move\n");
    else std::printf("Unsuccessfull move\n");
    dump(Traveler);

    Res = Move(Traveler,0,-10000);      // Should be unsuccessfull
    if (Res == true) std::printf("Successfull move\n");
    else std::printf("Unsuccessfull move\n");
    dump(Traveler);

    Res = Move(Traveler,10000,100);   // Should be successfull
    if (Res == true) std::printf("Successfull move\n");
    else std::printf("Unsuccessfull move\n");
    dump(Traveler);

    Res = Move(Traveler,30000,0);   // Should be successfull
    if (Res == true) std::printf("Successfull move\n");
    else std::printf("Unsuccessfull move\n");
    dump(Traveler);

    Res = Move(Traveler,30000,0);   // Should now be unsuccessfull
    if (Res == true) std::printf("Successfull move\n");
    else std::printf("Unsuccessfull move\n");
    dump(Traveler);

    point   Toto{0,0,{0,0,0}};
    point   Titi{1024,512,{128,64,32}};
    point   Tata;

    Tata = Fuzz(Toto, Titi);
    dump(Tata);
    



    return 0;
}

