//
//  workplace1.cpp
//  Workplace
//
//  Created by Иван Клочков on 29.01.2024.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Ввод двух строк
    string str1, str2;
    
    getline(cin, str1);
    getline(cin, str2);

    if (str1.length() == str2.length()) {
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        if (str1 == str2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}


