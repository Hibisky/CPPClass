
#include <iostream>
#include <thread>
#include <chrono>

#include "Tirelire.hpp"
//----------------------------------------------------------------------------
void _Voleur(Tirelire &Victime){
    using namespace std::chrono_literals;
    Tirelire::Piece Msc;    /** Most Significant Coin   :)  */
    while(!Victime.estVide()){
        std::this_thread::sleep_for(5s);
        std::cout << "Tentative de vol...\n";
        if (Victime.countCoins(Tirelire::Piece::TWOEUROS) > 0) Msc = Tirelire::Piece::TWOEUROS;
        else if (Victime.countCoins(Tirelire::Piece::ONEEURO) > 0) Msc = Tirelire::Piece::ONEEURO;
        else if (Victime.countCoins(Tirelire::Piece::FIFTYCENTS) > 0) Msc = Tirelire::Piece::FIFTYCENTS;
        else if (Victime.countCoins(Tirelire::Piece::TWENTYCENTS) > 0) Msc = Tirelire::Piece::TWENTYCENTS;
        else if (Victime.countCoins(Tirelire::Piece::TENCENTS) > 0) Msc = Tirelire::Piece::TENCENTS;
        else if (Victime.countCoins(Tirelire::Piece::FIVECENTS) > 0) Msc = Tirelire::Piece::FIVECENTS;
        else if (Victime.countCoins(Tirelire::Piece::TWOCENTS) > 0) Msc = Tirelire::Piece::TWOCENTS;
        else if (Victime.countCoins(Tirelire::Piece::ONECENT) > 0) Msc = Tirelire::Piece::ONECENT;

        Victime.retrieve(Msc);

        std::cout << "J'ai volé une pièce de valeur " << static_cast<int>(Msc) << " centimes.\n";



        
    }
    std::cout << "Plus rien à voler, je m'en vais...\n";
}
//----------------------------------------------------------------------------
int main(){
    Tirelire    SpiderCochon{};
     

    SpiderCochon.Add(Tirelire::Piece::FIFTYCENTS);
    SpiderCochon.Add(Tirelire::Piece::ONEEURO);
    SpiderCochon.Add(Tirelire::Piece::TENCENTS);
    SpiderCochon.Add(Tirelire::Piece::ONEEURO);

    std::jthread   tVoleur(_Voleur, std::ref(SpiderCochon));




    return 0;    
}
//----------------------------------------------------------------------------



