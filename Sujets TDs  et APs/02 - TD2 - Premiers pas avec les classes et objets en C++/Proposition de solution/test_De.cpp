
#include <iostream>
#include "De.hpp"


int main(){
    std::cout << "-- Test classe Dé --\n";  /** Affichage */
    
    /** Test Dé par défaut (D6) - 1 seul tirage  */
    std::cout << "-- Test Dé par défaut --\n";  /** Affichage */
    De  MonDe_default{};        /** Création (construction) d'un dé "par défaut" - Utilisation du constructeur par défaut */
    for(int nb=0;nb<10;++nb) std::cout<< "Lancer " << nb << " : " << static_cast<int>(MonDe_default.Lancer()) << std::endl; /** Réalisation de 10 lancers. Affichage */

    /** Test Dé par défaut (D6) - Tirage multiple (4 D6)  */
    std::cout << "-- Test Tirage multiple 4 D6 --\n";   /** Affichage */
    std::vector<uint8_t> TirageD6{};    /** Création d'un vector (tableau) de uint8_t appelé TirageD6. Vide pour le moment */
    TirageD6 = MonDe_default.Lancer(4); /** Appel de la méthode Lancer surchargée. Récupération d'un vector de uint8_t */
    std::cout << "Résultat tirage de 4 D6 : ";  /** Affichage */
    for (uint8_t ValeurDe : TirageD6) std::cout << static_cast<int>(ValeurDe) << " "; /** Parcours du vector + affichage valeurs */
    std::cout << std::endl; /** Saut de ligne final */

    /** Test Dé quelconque (15 faces, valeurs de 1 à 15) - 1 seul tirage  */
    std::cout << "-- Test Dé quelconque --\n";  /** Affichage */
    De MonDe15{1,15};   /** Construction d'un Dé à 15 faces. Utilisation du constructeur adapté (uint8_t,uint8_t)*/
    for(int nb=0;nb<10;++nb) std::cout<< "Lancer " << nb << " : " << static_cast<int>(MonDe15.Lancer()) << std::endl;

    /** Test Dé construit à partir d'un typeDe_t (D30) */
    std::cout << "-- Test Dé construit avec TypeDe_t (D30) --\n";  /** Affichage */
    De MonDe30{De::TypeDe_t::D30};   /** Construction d'un Dé à 30 faces. Utilisation du constructeur adapté (TypeDe_t)*/
    for(int nb=0;nb<10;++nb) std::cout<< "Lancer " << nb << " : " << static_cast<int>(MonDe30.Lancer()) << std::endl;

    /** Test de la génération d'une exception si min = max */
    try{
        De MonDeCasse(4,4);
    }
    catch(const std::exception &e){
        std::cout << "Exception occured : " << e.what() << std::endl;
    }


    /** Test avec objets constants    */
    const De monD12ct{1,12};
    const De monD100ct(De::TypeDe_t::D100);

    std::cout << "Lancer D12 constant = " << static_cast<int>(monD12ct.Lancer()) << std::endl;
    std::cout << "Lancer D100 constant = " << static_cast<int>(monD100ct.Lancer()) << std::endl;

    return 0;
}
