//
//  main.cpp
//  Workplace
//
//  Created by Иван Клочков on 12.02.2024.
//

#include <iostream>
#include "MyString.hpp"

int main() {
    MyString s1("Hello, ");
    MyString s2("world!");
    MyString s3;
    MyString s4("abc");
    MyString s5 = s1 + s2;
    MyString s6 = s5 - s4;
    MyString s7 = s1 * 3;
    MyString s9("Google");
    MyString s10;

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;
    std::cout << "s4: " << s4 << std::endl;
    std::cout << "s5 (s1 + s2): " << s5 << std::endl;
    std::cout << "s6 (s5 - s4): " << s6 << std::endl;
    std::cout << "s7 (s1 * 3): " << s7 << std::endl;

    size_t pos1 = s5("ll");
    std::cout << "Position of substring 'll' in s5: " << pos1 << std::endl;

    size_t pos2 = s6("mama");
    if (pos2 == MyString::npos) {
        std::cout << "Substring 'mama' not found in s6." << std::endl;
    } else {
        std::cout << "Position of substring 'mama' in s6: " << pos2 << std::endl;
    }
    
    s10 = !s9;
    std::cout << "Inverted case string: " << s10 << std::endl;

    MyString s8;
    std::cout << "Enter a string: ";
    std::cin >> s8;
    std::cout << "You entered: " << s8 << std::endl;

    return 0;
}


