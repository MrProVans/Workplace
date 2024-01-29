//
//  workplace1.cpp
//  Workplace
//
//  Created by Иван Клочков on 29.01.2024.
//

#include <iostream>

using namespace std;


bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


int main () {
    int start, end;
    
    cin>>start;
    cin>>end;
    cout<<"\n";
    
//  vector<int> primeNumbers;  вектор
    
    int n = 0;
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
//          primeNumbers.push_back(i); вектор
            n++;
            
        }
    }
    
    int* primeNumbers = new int[n];
    
    int currentIndex = 0;
        for (int i = start; i <= end; ++i) {
            if (isPrime(i)) {
                primeNumbers[currentIndex++] = i;
            }
        }

//    for (int prime : primeNumbers) {  вектор
//        cout << prime << " ";
//    }
    for (int i = 0; i < n; ++i) {
        std::cout << primeNumbers[i] << " ";
    }

    delete[] primeNumbers;

    return 0;
}
