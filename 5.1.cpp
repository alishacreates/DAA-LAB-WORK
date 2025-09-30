#include <iostream>
using namespace std;

int powerof(int b, int n){
    int result = 1;
    for (int i = 1; i <= n; i++){
        result = result * b;
    }
    return result;
}
int main(){
    int base, power;
    cout << "Enter base:"<<endl;
    cin >> base;
    cout << "Enter exponent:"<<endl;
    cin >>power;
    cout << "Power = " << powerof(base, power)<<endl;
    return 0;
}
