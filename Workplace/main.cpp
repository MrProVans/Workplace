//
//  main.cpp
//  Workplace
//
//  Created by Иван Клочков on 28.01.2024.
//  First step to development on Xcode
#include <iostream>

using namespace std;


int main() {
    cout << "Hello, World!\n";
    const int ftInMile=5280;
    const double kmInMile=1.609344;
    int dMile,dFt,dKm,dM;
    cout<<"Mile: ";
    cin>>dMile;
    cout<<"Funt: ";
    cin>>dFt;
    double distMile=dMile+(double)dFt/ftInMile;
    double distKm=distMile*kmInMile;
    dKm=(int)distKm;
    dM=(int)((distKm-dKm)*1000);
    cout<<"Kilometres: "<<dKm<<endl;
    cout<<"metres: "<<dM<<endl;
    return 0;
}
