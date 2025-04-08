
#include <iostream>
#include <cstdint>
#include "lib_td1.hpp"


int main(){
    std::cout << "-- TD1 --\n";  /** Affichage */
    //-------------------------------------------------------------------------
    DireBonjour();
    DireBonjour("Toto");
    //-------------------------------------------------------------------------
    double Sortie{0};
    Sortie = CalculerSortieCapteur(25, 10e-3, 0);
    std::cout << "Old C++ : Sortie = " << std::to_string(Sortie) << std::endl;
    std::println("C++23 : Sortie = {0:f} ou {0:0.2f}",Sortie);
    //-------------------------------------------------------------------------
    std::println("--- Test fonctions swap (pointer et reference version) ---");
    int a{42}, b{66};
    //std::cout << "Avant swap a = " << std::to_string(a) << " et b = " << std::to_string(b) << std::endl;
    std::println("Avant swap a = {0:d} et b = {1:d}",a,b);
    Swap(&a,&b);
    //std::cout << "Après swap a = " << std::to_string(a) << " et b = " << std::to_string(b) << std::endl;  
    std::println("Après swap a = {0:d} et b = {1:d}",a,b);

    Swap(a,b);
    std::println("Après swap (reference version) a = {0:d} et b = {1:d}",a,b);
    //-------------------------------------------------------------------------
    std::println("--- Test fonctions TemplateSwap (pointer version) ---");
    int Size;

    uint8_t byteA{11}, byteB{22};
    //std::cout << "Avant swap a = " << std::to_string(byteA) << " et b = " << std::to_string(byteB) << std::endl;
    std::println("Avant swap a = {0:d} et b = {1:d}",byteA,byteB);
    Size = templateSwap<uint8_t>(&byteA,&byteB);
    //std::cout << "Après swap a = " << std::to_string(byteA) << " et b = " << std::to_string(byteB) << std::endl;
    std::println("Après swap a = {0:d} et b = {1:d}",byteA,byteB);
    //std::cout << "Taille <T> : " << std::to_string(Size) << std::endl;
    std::println("Taille <T> : {:d}",Size);

    double doubleA{11.11}, doubleB{22.22};
    //std::cout << "Avant swap a = " << std::to_string(doubleA) << " et b = " << std::to_string(doubleB) << std::endl;
    std::println("Avant swap a = {0:f} et b = {1:f}",doubleA,doubleB);
    Size = templateSwap<double>(&doubleA,&doubleB);
    //std::cout << "Après swap a = " << std::to_string(doubleA) << " et b = " << std::to_string(doubleB) << std::endl;
    std::println("Après swap a = {0:f} et b = {1:f}",doubleA,doubleB);
    //std::cout << "Taille <T> : " << std::to_string(Size) << std::endl;
    std::println("Taille <T> : {:d}",Size);
    //-------------------------------------------------------------------------
    std::println("--- Test fonctions TemplateSwap (Reference version) ---");
    
    //std::cout << "Avant swap a = " << std::to_string(byteA) << " et b = " << std::to_string(byteB) << std::endl;
    std::println("Avant swap a = {0:d} et b = {1:d}",byteA,byteB);
    Size = templateSwap<uint8_t>(byteA,byteB);
    //std::cout << "Après swap a = " << std::to_string(byteA) << " et b = " << std::to_string(byteB) << std::endl;
    std::println("Après swap a = {0:d} et b = {1:d}",byteA,byteB);
    //std::cout << "Taille <T> : " << std::to_string(Size) << std::endl;
    std::println("Taille <T> : {:d}",Size);

    //std::cout << "Avant swap a = " << std::to_string(doubleA) << " et b = " << std::to_string(doubleB) << std::endl;
    std::println("Avant swap a = {0:f} et b = {1:f}",doubleA,doubleB);
    Size = templateSwap<double>(doubleA,doubleB);
    //std::cout << "Après swap a = " << std::to_string(doubleA) << " et b = " << std::to_string(doubleB) << std::endl;
    std::println("Après swap a = {0:f} et b = {1:f}",doubleA,doubleB);
    //std::cout << "Taille <T> : " << std::to_string(Size) << std::endl;
    std::println("Taille <T> : {:d}",Size);

    std::string messA{"Tu deviendras"};
    std::string messB{"Un Jedi"};

    std::println("Normal version : {} {}",messA,messB);
    templateSwap(messA, messB);
    std::println("Master Yoda version : {} {}",messA,messB);

    return 0;
}


