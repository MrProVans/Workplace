//
//  MyString.hpp
//  Workplace
//
//  Created by Иван Клочков on 12.02.2024.
//

#ifndef MyString_hpp
#define MyString_hpp

#include <iostream>
#include <cstring>

class MyString {
private:
    char* data;

public:
    // Constructors
    MyString(const char* str = nullptr);
    MyString(std::string str);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    MyString(char ch);

    // Destructor
    ~MyString();

    // Methods
    size_t length() const;
    const char* get() const;

    // Operator overloads
    MyString operator+(const MyString& other) const;
    MyString operator-(const MyString& other) const;
    MyString operator*(int n) const;
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>=(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    MyString operator!() const;
    char operator[](int index) const;
    size_t operator()(const MyString& substring) const;
    friend std::istream& operator>>(std::istream& is, MyString& obj);
    friend std::ostream& operator<<(std::ostream& os, const MyString& obj);

    // Static member variable npos
    static const size_t npos = -1;
};

#endif /* MyString_hpp */
