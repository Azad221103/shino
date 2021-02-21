//
// Created by batkiz on 2021/2/20.
//
#include "add/adder.hpp"
#include "fmt/core.h"

int main() {
    fmt::print("isdir: {}", adder::adder::isdir(R"(C:\code)"));
    return 0;
}