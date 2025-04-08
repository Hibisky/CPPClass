/**
 * Bit class test file
 * 
 * Uses the doctest test framework
 */

//----------------------------------------------------------------------
// Tests unitaires à activer sucessivement.
#define	TEST00_STRUCTURE				// could be deactivated once passed

#define	TESTS_01_TO_03_READY		// Activate BEFORE tests 01 to 03 
#define	TEST01_DEFAULT_CTOR
//#define	TEST02_CTOR_WITH_VALUE
//#define	TEST03_TOSTRING_METHOD

//#define TESTS_04_TO_07_READY			// Activate BEFORE tests 04 to 07
//#define TEST04_SET_METHOD	
//#define TEST05_CLEAR_METHOD
//#define TEST06_DISCONNECT_METHOD
//#define TEST07_UNREGSITER_METHOD

//#define	TESTS_08_TO_09_READY		// Activate BEFORE tests 08 to 09
//#define	TEST08_CONST_BIT
//#define	TEST09_OUT_OPERATOR
//----------------------------------------------------------------------

//----------------------------------------------------------------------
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN	/*! Use if doctest with its own main function*/
#include "doctest.h"
//----------------------------------------------------------------------

#include "Bit.hpp"

//----------------------------------------------------------------------

//----------------------------------------------------------------------
#ifdef	TEST00_STRUCTURE
TEST_CASE("testing the Bit class : Structure only") {
	std::cout << "Structure OK\n"; 
}
#endif
//----------------------------------------------------------------------
#ifdef 	TESTS_01_TO_03_READY
TEST_CASE("testing the Bit class : Ctors, getValue accessor and toString method") {
	
	#ifdef TEST01_DEFAULT_CTOR
	// Default Ctor
	Bit	myBit;
	CHECK(myBit.getValue() == Bit::bit_t::X);
	#endif

	#ifdef TEST02_CTOR_WITH_VALUE
	// Ctor with bit value
	Bit* pBit = new Bit(Bit::bit_t::SET);
	CHECK(pBit->getValue() == Bit::bit_t::SET);
	delete pBit;
	
	pBit = new Bit(Bit::bit_t::CLEAR);
	CHECK(pBit->getValue() == Bit::bit_t::CLEAR);
	delete pBit;
	
	pBit = new Bit(Bit::bit_t::HIZ);
	CHECK(pBit->getValue() == Bit::bit_t::HIZ);
	delete pBit;
	
	pBit = new Bit(Bit::bit_t::X);
	CHECK(pBit->getValue() == Bit::bit_t::X);
	delete pBit;
	#endif
	
	#ifdef TEST03_TOSTRING_METHOD
	// toString()
	pBit = new Bit(Bit::bit_t::SET);
	CHECK(pBit->toString() == "SET");
	delete pBit;
	
	pBit = new Bit(Bit::bit_t::CLEAR);
	CHECK(pBit->toString() == "CLEAR");
	delete pBit;
	
	pBit = new Bit(Bit::bit_t::HIZ);
	CHECK(pBit->toString() == "HIZ");
	delete pBit;
	
	pBit = new Bit(Bit::bit_t::X);
	CHECK(pBit->toString() == "X");
	delete pBit;
	#endif
}
#endif
//----------------------------------------------------------------------
#ifdef 	TESTS_04_TO_07_READY
TEST_CASE("testing the Bit class : set(), clear(), disconnect() and unregister() methods") {
	
	Bit myBit;
	
	// Just get sure the Bit isn't SET yet
	REQUIRE(myBit.getValue() != Bit::bit_t::SET);
		
	#ifdef TEST04_SET_METHOD
	myBit.set();
	CHECK(myBit.getValue() == Bit::bit_t::SET);
	#endif
	
	#ifdef TEST05_CLEAR_METHOD
	myBit.clear();
	CHECK(myBit.getValue() == Bit::bit_t::CLEAR);
	#endif
	
	#ifdef TEST06_DISCONNECT_METHOD
	myBit.disconnect();
	CHECK(myBit.getValue() == Bit::bit_t::HIZ);
	#endif
	
	#ifdef TEST07_UNREGSITER_METHOD
	myBit.unregister();
	CHECK(myBit.getValue() == Bit::bit_t::X);
	#endif
}
#endif
//----------------------------------------------------------------------
#ifdef 	TESTS_08_TO_09_READY
TEST_CASE("testing the Bit class : constant Bit Objects, and << operator") {
	
	#ifdef TEST08_CONST_BIT
	const Bit HiZbit(Bit::bit_t::HIZ);
	CHECK(HiZbit.getValue() == Bit::bit_t::HIZ);
	#endif
	
	#ifdef TEST09_OUT_OPERATOR
	std::ostringstream str;
	str << HiZbit;
	CHECK(str.str() == "HIZ");
	#endif

}
#endif
//----------------------------------------------------------------------

