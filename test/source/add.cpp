//
// Created by batkiz on 2021/2/20.
//
#include <catch2/catch.hpp>

#include "add/adder.hpp"

TEST_CASE("1+2=3") {
    int a = 1;
    int b = 2;

    REQUIRE(3==adder::adder::add(a,b));
}