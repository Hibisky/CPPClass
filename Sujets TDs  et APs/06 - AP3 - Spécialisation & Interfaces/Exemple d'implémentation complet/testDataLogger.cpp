#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <print>

#include "VectorDataLogger.hpp"
#include "FileDataLogger.hpp"   


TEST_CASE("Event class tests"){
    Event::date_of_event_t TimePoint{std::chrono::system_clock{}.now()};
    std::string DummyMessage{"Dummy Message."};

    SUBCASE("Default Ctor & accessors"){
        Event   myEvent{};

        CHECK(myEvent.getLevel() == Event::level_t::INFO);
        CHECK(myEvent.getWhat() == "");
        CHECK(myEvent.getDate() == Event::date_of_event_t{} );

        myEvent.setLevel(Event::level_t::ERROR);
        CHECK(myEvent.getLevel() == Event::level_t::ERROR);

        myEvent.setWhat(DummyMessage);
        CHECK(myEvent.getWhat() == DummyMessage);

        myEvent.setDate(TimePoint);
        CHECK(myEvent.getDate() == TimePoint);
    }

    SUBCASE("Full Ctor"){
        Event myEvent(TimePoint, DummyMessage, Event::level_t::WARNING);

        CHECK(myEvent.getLevel() == Event::level_t::WARNING);
        CHECK(myEvent.getWhat() == DummyMessage);
        CHECK(myEvent.getDate() == TimePoint); 
    }

    SUBCASE("toString Method"){
        /* To be implemented (no time for now, but must be OK) */
    }
}   /* TEST_CASE("Event class tests") */   

TEST_CASE("Test VectorDataLogger"){
    Event::date_of_event_t TimePoint{};
    Event   myEvent{};   
    VectorDataLogger    myLogger{};

    SUBCASE("Test Add Method, getNbEvents & dump"){
        CHECK(myLogger.getNbEvents() == 0);

        myEvent.setLevel(Event::level_t::INFO);
        myEvent.setWhat("CBA - Event Number 1");

        // Check exception throwing if date is not valid
        CHECK_THROWS_AS(myLogger.AddEvent(myEvent, false),std::invalid_argument);

        myEvent.setDate(std::chrono::system_clock{}.now());

        myLogger.AddEvent(myEvent);
        CHECK(myLogger.getNbEvents() == 1);

        myEvent.setLevel(Event::level_t::WARNING);
        myEvent.setWhat("ABC - Event Number 2");
        myEvent.setDate(std::chrono::system_clock{}.now());

        myLogger.AddEvent(myEvent);
        CHECK(myLogger.getNbEvents() == 2);
    
        myEvent.setLevel(Event::level_t::ERROR);
        myEvent.setWhat("BCA - Event Number 3");
        myEvent.setDate(std::chrono::system_clock{}.now());

        myLogger.AddEvent(myEvent);
        CHECK(myLogger.getNbEvents() == 3);

        myLogger.dumpLog();
    }

    SUBCASE("Test Sorting"){
        REQUIRE(myLogger.getNbEvents() == 0);

        // Fill the log with 3 Events
        myEvent.setLevel(Event::level_t::INFO);
        myEvent.setWhat("CBA - Event Number 1");
        myEvent.setDate(std::chrono::system_clock{}.now());
        myLogger.AddEvent(myEvent);
        
        myEvent.setLevel(Event::level_t::WARNING);
        myEvent.setWhat("ABC - Event Number 2");
        myEvent.setDate(std::chrono::system_clock{}.now());
        myLogger.AddEvent(myEvent);
            
        myEvent.setLevel(Event::level_t::ERROR);
        myEvent.setWhat("BCA - Event Number 3");
        myEvent.setDate(std::chrono::system_clock{}.now());
        myLogger.AddEvent(myEvent);

        REQUIRE(myLogger.getNbEvents() == 3);

        /* Sorting by What */
        std::println("Initial log (not sorted)");
        myLogger.dumpLog();

        myLogger.sortByWhat();
        std::println("log sorted by what (ascending direction) : ABC... must be first, then BCA... and finally CBA...");
        myLogger.dumpLog();

        myLogger.sortByWhat(false);
        std::println("log sorted by what (descending direction) : CBA... must be first, then BCA... and finally ABC...");
        myLogger.dumpLog();

        myLogger.sortByCriticity();
        std::println("log sorted by criticity (ascending direction) : INFO, then WARNING, then ERROR");
        myLogger.dumpLog();

        myLogger.sortByCriticity(false);
        std::println("log sorted by criticity (descendig direction) : ERROR, then WARNING, then INFO");
        myLogger.dumpLog();

        myLogger.sortByDate();
        std::println("log sorted by date (ascending direction) : first event first");
        myLogger.dumpLog();
    
        myLogger.sortByDate(false);
        std::println("log sorted by date (descendig direction) : last event first");
        myLogger.dumpLog();
    }

}

TEST_CASE("Test FileDataLogger"){
    Event   myEvent{};

    std::string FileName{"./data.log"};
    
    if(std::filesystem::exists(FileName)){
        std::filesystem::remove(FileName);
    }
    REQUIRE(!std::filesystem::exists(FileName));

    FileDataLogger  myLogger{FileName};

    myEvent.setLevel(Event::level_t::INFO);
    myEvent.setWhat("CBA - Event Number 1");

    // Check exception throwing if date is not valid
    CHECK_THROWS_AS(myLogger.AddEvent(myEvent, false),std::invalid_argument);

    myEvent.setDate(std::chrono::system_clock{}.now());
    myLogger.AddEvent(myEvent);
    CHECK(std::filesystem::exists(FileName));

    auto size = std::filesystem::file_size(FileName);
    CHECK( size > 0);

    myEvent.setLevel(Event::level_t::WARNING);
    myEvent.setWhat("BCA - Event Number 2");
    myEvent.setDate(std::chrono::system_clock{}.now());
    myLogger.AddEvent(myEvent);
    CHECK(std::filesystem::file_size(FileName) > size); /**< New File must now be bigger than the old one */

    auto logSize = myLogger.getNbEvents();
    CHECK (logSize == 2);

    std::println("Now printing the log content with dumpLog()");
    myLogger.dumpLog();

    myEvent.setLevel(Event::level_t::ERROR);
    myEvent.setWhat("ABC - Event Number 3");
    myEvent.setDate(std::chrono::system_clock{}.now());
    myLogger.AddEvent(myEvent);

    logSize = myLogger.getNbEvents();
    CHECK (logSize == 3);

    std::println("Now printing the log content with dumpLog()");
    myLogger.dumpLog();

}
