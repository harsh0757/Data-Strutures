#include<iostream>
using namespace std;

template <typename T>

T add(T a, T b){
    return a + b;
}

int main() {
    cout << "Int: " << add(5, 3) << endl;            // 8
    cout << "Float: " << add(2.5f, 1.5f) << endl;    // 4.0
    cout << "Double: " << add(3.14, 2.71) << endl;   // 5.85
    return 0;
}