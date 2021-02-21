//
// Created by batkiz on 2021/2/20.
//
#include <add/adder.hpp>
#include "Util/File.h"

using namespace toolkit;

int adder::adder::add(int a, int b) {
    return a+b;
}

bool adder::adder::isdir(const std::string& s) {
    auto y = s.c_str();
    auto a = File::is_dir(y);
    return a;
}

