/**
 *	@file	De.hpp
 * 	@brief 	De class header file
 * 	@author	Alexis ROLLAND
 * 	@date	2023-09
 * 
 */

/** Code Guards : empêche les inclusions multiples - Idem C */
#ifndef __DE_HPP__
#define __DE_HPP__

#include <random>       /**< Inclusion des outils liés au moteur de génération de valeurs aléatoires */
#include <vector>       /**< Inclusion des éléments de la STL associés au type "vector"  */      
#include <stdexcept>    /**< Inclusion des éléments de la STL associés aux exceptions standard    */
#include <print>        /**< Inclusion des éléments de la bibliothèque print (C++23)   */

constexpr       uint8_t DEFAULT_MIN_VALUE{1};   /**< La valeur de MinValue par défaut, correspond à un D6    */
constexpr       uint8_t DEFAULT_MAX_VALUE{6};   /**< La valeur de MaxValue par défaut, correspond à un D6    */

class De{
    public:
        /**
        *	TypeDe_t 
        * 	enum as imbricated class - public area
        */
        enum class TypeDe_t:std::uint8_t {  D4,     /**< Dé à 4 faces (Tirages de 1 à 4) */
                                            D6,     /**< Dé à 4 faces (Tirages de 1 à 6) */
                                            D8,     /**< Dé à 8 faces (Tirages de 1 à 8) */
                                            D10,    /**< Dé à 10 faces (Tirages de 0 à 9)    */
                                            D12,    /**< Dé à 12 faces (Tirages de 1 à 12)   */
                                            D20,    /**< Dé à 20 faces (Tirages de 1 à 20)   */
                                            D30,    /**< Dé à 30 faces (Tirages de 1 à 30)   */
                                            D100    /**< Dé à 100 faces (Tirages de 0 à 99)  */
        };		
    private:
        uint8_t MinValue{DEFAULT_MIN_VALUE};    /**< MinValue initialisée avec DEFAULT_MIN_VALUE, pas de "magic number" */
        uint8_t MaxValue{DEFAULT_MAX_VALUE};    /**< idem pour MaxValue avec DEFAULT_MAX_VALUE   */

        /**
        *   rdev et e (respectivement de types random_device et default_random_engine) sont des objets 
        *   qui seront utilisés par l'objet de type uniform_int_distribution afin de garantir à la fois
        *   une qualité d'entropie suffisante et une distribution uniforme.
        *   Il n'y a pas besoin d'en savoir plus pour le moment.
        */
        std::random_device rdev{};
        mutable std::default_random_engine e{rdev()};   /**< mutable : e is modified when used, even if the object is const    */
        
    public:
        /**
        *   Constructeur par défaut (sans paramètres)
        *   le fait d'ajouter " = default " a pour effet d'obliger le compilateur a définir lui-même cette méthode.
        *   Dans le cas contraire, il eut fallu définir nous-mêmes ce constructeur (qui aurait été vide...)    
        */
        De() = default;     
        
        /**
        * Constructeur "standard" pour un dé.
        * 
        * Les champs MinValue et MaxValue de l'objet "De" sont affectées respectivement de la plus petite valeur et de la la
        * plus grande valeur passées en paramètres (De{1,6} et De{6,1} auront le même effet).
        * Seul le cas où ces deux valeurs sont égales génère une erreur (levée d'exception).  
        * 
        * @param[in]	FirstBoundary Valeur du premier extremum
        * @param[in]	SecondBoundary Valeur du secondextremum
        * 
        * @throw 	std::domain_error("Le nombre de faces ne peut être égal à 1 (FirstBoundary must not be equal to SecondeBoundary).")
        *           si les deux extrema sont égaux (dé à 1 face)
        */
        De(uint8_t FirstBoundary, uint8_t SecondBoundary); 

        /**
        * Constructeur surchargé pour un dé.
        * 
        * Selon le type de dé, les valeurs des champs de l'objet sont initialisées avec les bonnes valeurs. 
        * 
        * @param[in]	typeDe      "descripteur" du dé (type enuméré TypeDe_t)
        *         
        * @throw std::domain_error("Le Dé est inconnu.");   Exception levée si d'aventure la valeur passée n'était pas connue.
        * 
        * Rq : explicit (specifier) : interdit au compilateur de faire de la conversion implicite de type ou équivalent pour le
        *                               paramètre d'entrée. Dans ce cas, cela impose d'appeler ce constructeur avec uniquement
        *                               un objet de type "TypeDe_t". Un int, par exemple, sera rejeté à la compilation.
        *                               Il s'agit d'une bonne pratique du C++ principalement recommandée pour les constructeurs
        *                               avec un seul paramètre d'entrée.
        *                               Ce point est un point important pour la sécurité du code et des applications.
        */ 
        explicit De(TypeDe_t typeDe);    /**< Constructeur prenant comme paramètre un type de dé - explicit : oblige l'appel avec rigoureusement le type attendu. */
        
        /**
        * Destructeur : ~De 
        * 
        * Tout comme le constructeur par défaut, il est " = default", la définition du destructeur est donc de la responsabilité
        * du compilateur (ce n'est pas à nous de le coder).
        *         
        * Les bonnes pratiques du C++ recommandent qu'un constructeur soit toujours "virtual", cela permet de résoudre d'éventuels
        * problèmes liés à des redéfinitions lors d'une éventuelle spécialisation de classe. 
        * Ce point est un point important pour la sécurité du code et des applications.
        */
        virtual ~De() = default;        /**< Destructeur par défaut */   
        
        /**
        * Méthode exécutant un lancer du dé défini [MinValue;MaxValue]
        * 
        * @return Valeur du tirage entre MinValue et MaxValue
        * 
        * rq : const : La méthode peut être utilisée dans le cas ou un objet constant est construint (const De MonDeConstant{...}; )
        *               Une méthode non qualifiée de "const" ne pourra jamais être invoquée avec un objet constant.
        *               Ce point est un point important pour la sécurité du code et des applications.
        * 
        * rq : noexcept : Indique, à la fois au compilateur et à l'utilisateur (lecteur) de la classe que cette méthode ne
        *                   lève aucune exception. Information intéressante à connaître pour l'utilisateur, car il sait 
        *                   immédiatement qu'il n'aura pas à gérer d'éventuelles exceptions lors de l'appel de la méthode (ou fonction)
        *                   donc, pas de try/catch, etc...
        * 
        * rq : [[nodiscard]] (attribute) : "Impose" (warning généré a minima) à celui qui appelle la méthode/fonction d'utiliser
        *                                   la valeur de retour. 
        *                                   Il est intéressant de se poser la question de la nécessité de l'exploitation de cette valeur.
        *                                   Souvent, si cette exploitation n'apparaît pas "obligatoire" c'est qu'il y a possiblement une
        *                                   erreur d'analyse.
        *                                   Bonne pratique C++ : toutes les fonctions/méthodes retournant une valeur doivent être
        *                                   associées à cet attribut.  
        */ 
        [[nodiscard]] uint8_t Lancer() const noexcept;           
        
        /**
        * Méthode exécutant un lancer simultané de NbDes du dé défini (3D6, 2D100, par exemple)
        * 
        * @param[in]	NbDes       Nombre de dés à lancer
        * 
        * @return       Valeur du tirage sous forme d'un vector<uint8_t> contenant NbDes valeurs comprises entre MinValue et MaxValue
        * 
        * rq : const, noexcept, [[nodiscard]] : cf plus ci-dessus.
        */ 
        [[nodiscard]] std::vector<uint8_t>    Lancer(uint8_t NbDes) const noexcept;  /** Un seul lancer de plusieurs (NbDes) dés    */



};




#endif  /*  __DE_HPP__ */
