#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "fraction.h"

TEST_CASE("constructor 1", "[fraction]") {

    SECTION("prime numbers") {
        mc::fraction p(1, 3);
        REQUIRE(p.numerator() == 1);
        REQUIRE(p.denominator() == 3);
    }

    SECTION("yet another") {
        mc::fraction p(12, 5);
        REQUIRE(p.numerator() == 12);
        REQUIRE(p.denominator() == 5);
    }

    SECTION("normalize") {
        mc::fraction p(15, 36);
        REQUIRE(p.numerator() == 5);
        REQUIRE(p.denominator() == 12);
    }

    SECTION("yet another normalize") {
        mc::fraction p(12, 3);
        REQUIRE(p.numerator() == 4);
        REQUIRE(p.denominator() == 1);
    }

    SECTION("with sign") {
        mc::fraction p(12, -20);
        REQUIRE(p.numerator() == -3);
        REQUIRE(p.denominator() == 5);
    }
};

TEST_CASE("constructor 2", "[fraction]") {

    SECTION("very first") {
        mc::fraction p(0.333333);
        REQUIRE(p.numerator() == 333333);
        REQUIRE(p.denominator() == 1000000);
    }

    SECTION("normalize") {
        mc::fraction p(0.25);
        REQUIRE(p.numerator() == 1);
        REQUIRE(p.denominator() == 4);
    }

    SECTION("with sign") {
        mc::fraction p(-0.5);
        REQUIRE(p.numerator() == -1);
        REQUIRE(p.denominator() == 2);
    }
};

TEST_CASE("compare", "[fraction]") {

    SECTION("equal") {
        mc::fraction p1(2, 3);
        mc::fraction p2(4, 6);
        REQUIRE(p1 == p2);
    }

    SECTION("ordering") {
        mc::fraction p1(0.25);
        mc::fraction p2(1, 3);
        mc::fraction p3(-0.25);
        REQUIRE(p1 > p3);
        REQUIRE(p1 < p2);
    }
};

TEST_CASE("arithmetical", "[fraction]") {

    SECTION("+") {
        mc::fraction p1(1, 3);
        mc::fraction p2(1, 6);
        mc::fraction result = p1 + p2;
        REQUIRE(result.numerator() == 1);
        REQUIRE(result.denominator() == 2);
    }

    SECTION("-") {
        mc::fraction p1(1, 3);
        mc::fraction p2(1, 12);
        mc::fraction result = p1 - p2;
        REQUIRE(result.numerator() == 1);
        REQUIRE(result.denominator() == 4);
    }

    SECTION("*") {
        mc::fraction p1(2, 3);
        mc::fraction p2(1, 6);
        mc::fraction result = p1 * p2;
        REQUIRE(result.numerator() == 1);
        REQUIRE(result.denominator() == 9);
    }

    SECTION("/") {
        mc::fraction p1 = 3;
        mc::fraction p2(1, 3);
        mc::fraction result = p1 / p2;
        REQUIRE(result.numerator() == 9);
        REQUIRE(result.denominator() == 1);
    }
};