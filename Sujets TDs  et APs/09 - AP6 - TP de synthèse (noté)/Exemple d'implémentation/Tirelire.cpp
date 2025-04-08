#include "Tirelire.hpp"

//----------------------------------------------------------------------------
[[nodiscard]] bool Tirelire::isCoinValid(Piece Coin) noexcept{
    switch(Coin){
        case Piece::ONECENT:
        case Piece::TWOCENTS:
        case Piece::FIVECENTS:
        case Piece::TENCENTS:
        case Piece::TWENTYCENTS:
        case Piece::FIFTYCENTS:
        case Piece::ONEEURO:
        case Piece::TWOEUROS:
            return true;break;
        default : 
            return false;break;
    }
}
//----------------------------------------------------------------------------
void    Tirelire::Add(Piece Coin) {
    if (!this->isCoinValid(Coin)) throw std::out_of_range("Coin is not valid");
    else this->Vault.push_back(Coin);
}
//----------------------------------------------------------------------------
[[nodiscard]]   unsigned int    Tirelire::countCoins(Piece CoinType){
    if (this->isCoinValid(CoinType)) return std::count (this->Vault.begin(), this->Vault.end(), CoinType);
    else throw std::out_of_range("Coin is not valid");
}
//----------------------------------------------------------------------------
[[nodiscard]]   unsigned int    Tirelire::getTotal() noexcept{
    unsigned int Somme{0};

    for (unsigned int i = 0; i < this->Vault.size(); ++i){
        Somme += static_cast<unsigned int>(this->Vault.at(i));  /**< Is it possible to use accumulate algorithm ??? */
    }

    return Somme;
}  
//----------------------------------------------------------------------------
void    Tirelire::retrieve(Piece CoinType){
    if (!this->isCoinValid(CoinType)) throw std::out_of_range("Coin is not valid");
    if (this->countCoins(CoinType) < 1) throw std::underflow_error("No corresponding coins inside the vault.");

    std::vector<Piece>::iterator it;
    it = std::find(this->Vault.begin(),this->Vault.end(),CoinType);

    this->Vault.erase(it);

}
//----------------------------------------------------------------------------
void    Tirelire::dump(){

    for(Piece p : this->Vault)  std::cout<< " " << static_cast<int>(p);
    std::cout << std::endl; 
  
}
//----------------------------------------------------------------------------
