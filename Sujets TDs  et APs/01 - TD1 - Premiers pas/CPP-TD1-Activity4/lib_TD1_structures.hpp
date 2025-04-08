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

constexpr   couleur_t   Black{0,0,0};
constexpr   couleur_t   White{255,255,255};



void    dump(const point &Point);

bool    Move(point &Point, int16_t DeltaX, int16_t DeltaY);

point   Fuzz(const point &p1, const point &p2);


#endif  /*  __TD1_STRUCTURES_HPP__ */
