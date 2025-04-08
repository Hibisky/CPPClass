#include "lib_TD1_structures.hpp"

//----------------------------------------------------------------------------
void    dump(const point &Point){
    std::printf("Point (x,y,r,v,b) : %d %d %d %d %d\n",Point.x, Point.y, Point.Couleur.Red, Point.Couleur.Green, Point.Couleur.Blue); 
}
//----------------------------------------------------------------------------
bool    Move(point &Point, int16_t DeltaX, int16_t DeltaY){
    int32_t tmp;
    bool    Success{true};
    // Traitement X
    tmp = static_cast<int32_t>(Point.x) + static_cast<int32_t>(DeltaX);
    
    if (tmp < 0) {
        tmp = 0;
        Success = false;
    }
    if (tmp > 65535) {
        tmp = 65535;
        Success = false;
    }
    Point.x = static_cast<uint16_t>(tmp);

    // Traitement Y
    tmp = static_cast<int32_t>(Point.y) + static_cast<int32_t>(DeltaY);
    
    if (tmp < 0) {
        tmp = 0;
        Success = false;
    }
    if (tmp > 65535) {
        tmp = 65535;
        Success = false;
    }
    Point.y = static_cast<uint16_t>(tmp);


    return Success;
}
//----------------------------------------------------------------------------
point   Fuzz(const point &p1, const point &p2){
    point iPoint;

    iPoint.x = std::round( (p1.x + p2.x) / 2.0);
    iPoint.y = std::round( (p1.y + p2.y) / 2.0);

    iPoint.Couleur.Red = std::round( (p1.Couleur.Red + p2.Couleur.Red) / 2.0);
    iPoint.Couleur.Green = std::round( (p1.Couleur.Green + p2.Couleur.Green) / 2.0);
    iPoint.Couleur.Blue = std::round( (p1.Couleur.Blue + p2.Couleur.Blue) / 2.0);

    return iPoint;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------