#include <iostream>

using namespace std;

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

unsigned int Sum( unsigned int number1, unsigned int number2 ) {
    return number1+number2;
}

TEST_CASE( "Sums are computed", "[Sum]" ) {
    REQUIRE( Sum(1,2) == 3 );
    REQUIRE( Sum(2,4) == 6 );
    REQUIRE( Sum(3,4) == 6 );
    REQUIRE( Sum(10,1) == 11 );
}
