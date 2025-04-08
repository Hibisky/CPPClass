#include "De.hpp"

//----------------------------------------------------------------------------
De::De(uint8_t FirstBoundary, uint8_t SecondBoundary){
    /** Exception de type "std::domain_error" si les deux bornes sont égales    */
    if (FirstBoundary == SecondBoundary) throw std::domain_error("Le nombre de faces ne peut être égal à 1 (FirstBoundary must not be equal to SecondeBoundary).");
    
    if (FirstBoundary < SecondBoundary) {
        this->MinValue = FirstBoundary;
        this->MaxValue = SecondBoundary;
    }
    else
    {
        this->MinValue = SecondBoundary;
        this->MaxValue = FirstBoundary;
    }
}
//----------------------------------------------------------------------------
De::De(TypeDe_t typeDe){
    switch(typeDe){
        case TypeDe_t::D4 : this->MinValue = 1; this->MaxValue = 4; break;
        case TypeDe_t::D6 : this->MinValue = 1; this->MaxValue = 6; break;
        case TypeDe_t::D8 : this->MinValue = 1; this->MaxValue = 8; break;
        case TypeDe_t::D10 : this->MinValue = 0; this->MaxValue = 9; break;
        case TypeDe_t::D12 : this->MinValue = 1; this->MaxValue = 12; break;
        case TypeDe_t::D20 : this->MinValue = 1; this->MaxValue = 20; break;
        case TypeDe_t::D30 : this->MinValue = 1; this->MaxValue = 30; break;
        case TypeDe_t::D100 : this->MinValue = 0; this->MaxValue = 99; break;
        default : throw std::domain_error("Le Dé est inconnu.");    /** Ne devrait en aucun cas pouvoir se produire, mais... */
    }
}
//----------------------------------------------------------------------------
uint8_t De::Lancer() const noexcept{
    std::uniform_int_distribution<uint8_t> d{this->MinValue, this->MaxValue};   /** Construction du "vrai générateur" de nombres aléatoires*/
    return d(this->e);
}
//----------------------------------------------------------------------------
std::vector<uint8_t>    De::Lancer(uint8_t NbDes) const noexcept{
    std::vector<uint8_t>    Tirage{};

    for (uint8_t i = 0; i < NbDes ; ++i) Tirage.push_back(this->Lancer());

    return Tirage;
}
//----------------------------------------------------------------------------



