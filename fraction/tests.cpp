#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "fraction.h"

TEST_CASE("create fraction", "[fraction]") {

    SECTION("first constructor") {
        mc::fraction p(1, 3);
        REQUIRE(p.numerator() == 1);
        REQUIRE(p.denominator() == 3);
    }

    SECTION("second constructor") {
        mc::fraction p(0.2);
        REQUIRE(p.numerator() == 1);
        REQUIRE(p.denominator() == 5);
    }
}