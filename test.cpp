//
// Created by sylva on 13-Nov-18.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "ClojExp.h"

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {

    REQUIRE( Factorial(0) == 1 );
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE( "Addtion and multiplication", "[clojure]" ) {
    ClojExp exp1("(+ 4 (+ 5 4 (* 6 7)) 2)");
    exp1.eval();
    REQUIRE( exp1.get_result() == 57 );
}

TEST_CASE( "Variable definition", "[clojure]" ) {

    ClojExp exp2("(def a = 10)");
    exp2.eval();
    REQUIRE( ClojExp::get_symbol_value("a") == 10 );

}