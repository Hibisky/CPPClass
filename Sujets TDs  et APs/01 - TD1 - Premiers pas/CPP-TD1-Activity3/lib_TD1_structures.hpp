/**
 *	@file	
 * 	@brief 	
 * 	@author	Alexis ROLLAND
 * 	@date	2024-04
 * 
 */

/** Code Guards : empêche les inclusions multiples - Idem C */
#ifndef __TD1_STRUCTURES_HPP__
#define __TD1_STRUCTURES_HPP__

#include <iostream>
#include <cstdint>
#include <cmath>

struct couleur_t{
    uint8_t     Red;    /**< Red component  */
    uint8_t     Green;  /**< Green component  */
    uint8_t     Blue;   /**< Blue component */
};

struct point{
    uint16_t    x;          /**< x position */
    uint16_t    y;          /**< y position */
    couleur_t   Couleur;    /**< Color */
};

/**
 * @brief   Affichage coordonnées d'un point
 *          
 * @param[in]   const point& : Objet "point" pour lequel afficher les coordonnées
 * @return      Rien
*/
void    dump(const point &Point);

/**
 * @brief   Déplacement d'un point - Limitation entre 0 et 65535
 *          
 * @param[out]  point& : Objet point à déplacer
 * @param       int16_t : Valeur du déplacement en X
 * @param       int16_t : Valeur du déplacement en Y 
 * @return      true si succès, false si une limite a été atteinte.
*/
bool    Move(point &Point, int16_t DeltaX, int16_t DeltaY);

/**
 * @brief   Moyennage des couleurs du point
 *          
 * @param[in]       const point& : premier point
 * @param[in]       const point& : Second point
 * @return          point : nouveau point, avec la nouvelle couleur 
*/
point   Fuzz(const point &p1, const point &p2);


#endif  /*  __TD1_STRUCTURES_HPP__ */
