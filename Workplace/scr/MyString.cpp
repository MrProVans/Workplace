//
//  MyString.cpp
//  Workplace
//
//  Created by Иван Клочков on 12.02.2024.
//

#include "MyString.hpp"

// Constructor with one parameter (default nullptr)
MyString::MyString(const char* str) : data(nullptr) {
    if (str != nullptr) {
        data = new char[strlen(str) + 1];
        if (data != nullptr) {
            std::strcpy(data, str);
        } else {
            std::cerr << "Failed to allocate memory" << std::endl;
        }
    }
}

// Constructor with one parameter (std::string)
MyString::MyString(std::string str) : data(nullptr) {
    data = new char[str.length() + 1];
    if (data != nullptr) {
        std::strcpy(data, str.c_str());
    } else {
        std::cerr << "Failed to allocate memory" << std::endl;
    }
}

// Copy constructor
MyString::MyString(const MyString& other) : data(nullptr) {
    data = new char[other.length() + 1];
    if (data != nullptr) {
        std::strcpy(data, other.data);
    } else {
        std::cerr << "Failed to allocate memory" << std::endl;
    }
}

// Move constructor
MyString::MyString(MyString&& other) noexcept : data(other.data) {
    other.data = nullptr;
}

// Constructor with one parameter (character)
MyString::MyString(char ch) : data(nullptr) {
    data = new char[2];
    if (data != nullptr) {
        data[0] = ch;
        data[1] = '\0';
    } else {
        std::cerr << "Failed to allocate memory" << std::endl;
    }
}

// Destructor
MyString::~MyString() {
    delete[] data;
}

// Method to get the length of the string
size_t MyString::length() const {
    return (data != nullptr) ? std::strlen(data) : 0;
}

// Method to get the pointer to the data
const char* MyString::get() const {
    return data;
}

// Operator overload for concatenation
MyString MyString::operator+(const MyString& other) const {
    MyString result;
    if (data != nullptr && other.data != nullptr) {
        result.data = new char[length() + other.length() + 1];
        if (result.data != nullptr) {
            std::strcpy(result.data, data);
            std::strcat(result.data, other.data);
        } else {
            std::cerr << "Failed to allocate memory" << std::endl;
        }
    } else if (data != nullptr) {
        result = *this;
    } else if (other.data != nullptr) {
        result = other;
    }
    return result;
}

// Operator overload for removal of characters
MyString MyString::operator-(const MyString& other) const {
    MyString result;
    size_t len = length();
    for (size_t i = 0; i < len; ++i) {
        char currentChar = data[i];
        if (std::strchr(other.data, currentChar) == nullptr) {
            result = result + MyString(currentChar);
        }
    }
    return result;
}

// Operator overload for multiplication by an integer
MyString MyString::operator*(int n) const {
    MyString result;
    for (int i = 0; i < n; ++i) {
        result = result + *this;
    }
    return result;
}

// Copy assignment operator
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        data = new char[other.length() + 1];
        if (data != nullptr) {
            std::strcpy(data, other.data);
        } else {
            std::cerr << "Failed to allocate memory" << std::endl;
        }
    }
    return *this;
}

// Move assignment operator
MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}

// Operator overload for equality check
bool MyString::operator==(const MyString& other) const {
    return std::strcmp(data, other.data) == 0;
}

// Operator overload for inequality check
bool MyString::operator!=(const MyString& other) const {
    return !(*this == other);
}

// Operator overload for greater than
bool MyString::operator>(const MyString& other) const {
    return std::strcmp(data, other.data) > 0;
}

// Operator overload for less than
bool MyString::operator<(const MyString& other) const {
    return std::strcmp(data, other.data) < 0;
}

// Operator overload for greater than or equal to
bool MyString::operator>=(const MyString& other) const {
    return !(*this < other);
}

// Operator overload for less than or equal to
bool MyString::operator<=(const MyString& other) const {
    return !(*this > other);
}

// Operator overload for case inversion
MyString MyString::operator!() const {
    MyString result = *this;
    for (size_t i = 0; i < length(); ++i) {
        if (std::isalpha(result.data[i])) {
            if (std::isupper(result.data[i])) {
                result.data[i] = std::tolower(result.data[i]);
            } else {
                result.data[i] = std::toupper(result.data[i]);
            }
        }
    }
    return result;
}

// Operator overload for access by index
char MyString::operator[](int index) const {
    if (index >= 0 && static_cast<size_t>(index) < length()) {
        return data[index];
    } else {
        return '\0';
    }
}

// Operator overload for substring search
size_t MyString::operator()(const MyString& substring) const {
    const char* result = std::strstr(data, substring.data);
    return (result != nullptr) ? (result - data) : npos;
}

// Operator overload for reading from stream
std::istream& operator>>(std::istream& is, MyString& obj) {
    char buffer[1024];
    is >> buffer;
    obj = MyString(buffer);
    return is;
}

// Operator overload for writing to stream
std::ostream& operator<<(std::ostream& os, const MyString& obj) {
    if (obj.data != nullptr) {
        os << obj.data;
    }
    return os;
}


