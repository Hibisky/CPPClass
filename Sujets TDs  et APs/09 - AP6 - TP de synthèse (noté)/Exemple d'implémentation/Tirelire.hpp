/**
 *	@file	
 * 	@brief 	
 * 	@author	Alexis ROLLAND
 * 	@date	2024-09
 * 
 */

/** Code Guards : empêche les inclusions multiples - Idem C */
#ifndef __TIRELIRE_HPP__
#define __TIRELIRE_HPP__

#include <iostream>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <algorithm>
#include <print>
/**
 * Tirelire class
 */
class Tirelire{
    public:
        enum class Piece : uint8_t {
            ONECENT = 1,                /**< 1 cent coin - Value is 1 cent          */
            TWOCENTS = 2,               /**< 2 cents coin - Value is 2 cents        */
            FIVECENTS = 5,              /**< 5 cents coin - Value is 5 cents        */
            TENCENTS = 10,              /**< 10 cents coin - Value is 10 cents      */
            TWENTYCENTS = 20,           /**< 20 cents coin - Value is 20 cents      */
            FIFTYCENTS = 50,            /**< 50 cents coin - Value is 50 cents      */
            ONEEURO = 100,              /**< 1 euro coin - Value is 100 cents       */
            TWOEUROS = 200              /**< 2 euros coin - Value is 100 cents      */
        };        		
    private:
        std::vector<Piece> Vault{};     
        [[nodiscard]] bool isCoinValid(Piece Coin) noexcept;

    public:
        Tirelire() = default;
        virtual ~Tirelire() = default;

        [[nodiscard]]   bool            estVide() noexcept {return this->Vault.empty();};
        [[nodiscard]]   auto            getNbCoins() noexcept {return this->Vault.size();};    /**< auto return type to automaticaly adjust to size() return type. Could ba a size_t or possibly an unsigned int */
        void    Add(Piece Coin);
        
        [[nodiscard]]   unsigned int    getTotal() noexcept;  
        [[nodiscard]]   unsigned int    countCoins(Piece CoinType); 
        void    retrieve(Piece CoinType);

        void    dump();
};




#endif  /*  __TIRELIRE_HPP__ */
