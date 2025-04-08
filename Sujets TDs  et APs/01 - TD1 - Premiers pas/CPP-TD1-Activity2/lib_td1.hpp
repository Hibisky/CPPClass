/**
 *	@file	
 * 	@brief 	
 * 	@author	Alexis ROLLAND
 * 	@date	2024-04
 * 
 */

/** Code Guards : empêche les inclusions multiples - Idem C */
#ifndef __LIB_TD1_HPP__
#define __LIB_TD1_HPP__

#include <iostream>
#include <string>
#include <print>

//#define WITH_OVERLOAD
#define WITH_DEFAULT_VALUE


#ifdef  WITH_OVERLOAD
/**
 * @brief   Fonction DireBonjour
 *          
 * @param   Aucun
 * @return  Rien
*/
void    DireBonjour(void);

/**
 * @brief   Fonction DireBonjour
 *          
 * @param[in]       std::string Nom  
 * @return  Rien
*/
void    DireBonjour(std::string Nom);

#endif      /*  WITH_OVERLOAD   */

#ifdef  WITH_DEFAULT_VALUE
/**
 * @brief   Fonction DireBonjour
 *          
 * @param[in]       std::string Nom  / Default value = "" (empty string)
 * @return  Rien
*/
void    DireBonjour(std::string Nom="");
#endif  /*  WITH_DEFAULT_VALUE  */

/**
 * @brief   CalculerSortieCapteur
 *          Calcule la sortie d'un capteur en fonction de l'entrée, de sa sensibilité et d'un éventuel offset
 *          Sortie = (Entrée * Sensibilité) + offset         
 * 
 * @param[in]       double Entree : Valeur de l'entrée
 * @param[in]       double Sensibilite : Sensibilité du capteur
 * @param[in]       double Offset : offset du capteur / Default value = 0 
 * @return          Valeur de sortie du capteur (double)
*/
double  CalculerSortieCapteur(double Entree, double Sensibilite, double Offset = 0);

/**
 * @brief   Fonction Swap / Pointer version
 *          
 * @param[out]       int a : premier entier
 * @param[out]       int b : second entier
 * @return  Rien
*/
void    Swap(int* pa, int *pb);

/**
 * @brief   Fonction Swap / Reference version
 *          
 * @param[out]       int a : premier entier
 * @param[out]       int b : second entier
 * @return  Rien
*/
void    Swap(int &a, int &b);


/**
 * @brief   Fonction templateSwap (pointer version)
 *          
 * @param[out]       <T> a : premier objet
 * @param[out]       <T> b : second objet
 * @return      Taille de <T> (std::size_t)
*/
template<typename T>
std::size_t templateSwap(T *pa, T *pb){std::swap(*pa, *pb);return sizeof(T);};

/**
 * @brief   Fonction templateSwap (Reference version)
 *          
 * @param[out]       <T> a : premier objet
 * @param[out]       <T> b : second objet
 * @return      Taille de <T> (std::size_t)
*/
template<typename T>
std::size_t templateSwap(T &a, T &b){std::swap(a, b);return sizeof(T);};

#endif  /* __LIB_TD1_HPP__ */

