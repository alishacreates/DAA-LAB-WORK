#include <iostream>
using namespace std;

int powerof(int b, int n){
    if(n == 0) 
        return 1;
    if(n % 2 == 0) {
        int h = powerof(b, n/2);
        return h * h;
    }
    else {
        return b * powerof(b, n-1);
    }
}
int main(){
    int base, power;
    cout<< "Enter base:"<<endl;
    cin>> base;
    cout << "Enter exponent:"<<endl;
    cin >>power;
    cout << "Power = " << powerof(base, power)<<endl;
    return 0;
}