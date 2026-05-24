module;
// Global module fragment — traditional headers go here
#include <iostream>
#include <string>
#include <sstream>
#include <print>
#include <cstddef> // Required for std::size_t

export module io;
export using string = std::string;
export using std::print;
export using std::println;
export using std::size_t; // Export size_t to importing files

// Base
export string readLine() {
    string input;
    std::getline(std::cin, input);
    return input;
}

// Typed
export template<typename T>
T readLine() {
    std::istringstream ss(readLine());
    T value{};
    ss >> value;
    return value;
}