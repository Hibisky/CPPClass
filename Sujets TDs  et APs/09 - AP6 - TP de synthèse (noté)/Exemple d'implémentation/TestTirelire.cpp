//----------------------------------------------------------------------
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN	/*! Use if doctest with its own main function*/
#include "doctest.h"
//----------------------------------------------------------------------

#include "Tirelire.hpp"

TEST_CASE("Tirelire tests"){
    Tirelire SpiderCochon{};

    CHECK(SpiderCochon.estVide() == true);

    CHECK_NOTHROW(SpiderCochon.Add(Tirelire::Piece::ONECENT));
    CHECK(SpiderCochon.estVide() == false);
    
    CHECK_NOTHROW(SpiderCochon.Add(Tirelire::Piece::TWOCENTS));
    CHECK_NOTHROW(SpiderCochon.Add(Tirelire::Piece::FIVECENTS));
    CHECK_NOTHROW(SpiderCochon.Add(Tirelire::Piece::TENCENTS));
    CHECK_NOTHROW(SpiderCochon.Add(Tirelire::Piece::TWENTYCENTS));
    CHECK_NOTHROW(SpiderCochon.Add(Tirelire::Piece::ONEEURO));
    CHECK_NOTHROW(SpiderCochon.Add(Tirelire::Piece::TWOEUROS));

    CHECK_THROWS_WITH_AS(SpiderCochon.Add(static_cast<Tirelire::Piece>(25)),"Coin is not valid",std::out_of_range);

    CHECK(SpiderCochon.getNbCoins() == 7);

    CHECK_NOTHROW(SpiderCochon.retrieve(Tirelire::Piece::ONECENT));
    


}





