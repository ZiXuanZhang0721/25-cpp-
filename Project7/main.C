#include "Bigint.h"
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // Test constructor 1: Bigint(size_t)
    cout << "=== Test 1: Bigint(size_t) Constructor ===" << endl;
    cout << "Enter an integer: ";
    int x; cin >> x;
    Bigint k = Bigint(x);
    cout << "Bigint 1: " << k << endl;
    
    // Test constructor 2: Bigint(const char*)
    cout << "\n=== Test 2: Bigint(const char*) Constructor ===" << endl;
    cout << "Enter digits one by one (enter -1 to stop, digits 0-9 only): " << endl;
    
    int i;
    char* s = new char[1000];
    int cnt = 0;
    
    cin >> i;
    while(i != -1) {
        if (i > 9 || i < 0) {
            cout << "Please enter a digit between 0-9: ";
            cin >> i;
            continue;
        }
        s[cnt] = i + '0';
        cnt++;
        cin >> i;
    }
    
    // Add null terminator
    s[cnt] = '\0';
    char* s1 = new char[cnt + 1];
    strcpy(s1, s);
    
    Bigint j = Bigint(s1);
    cout << "Bigint 2: " << j << endl;
    
    // Test arithmetic operations
    cout << "\n=== Test 3: Arithmetic Operations ===" << endl;
    cout << "bigint 1 + bigint 2 = " << (k + j) << endl;
    
    Bigint original_k = k;  
    k += j;
    cout << "bigint 1 += bigint 2: " << original_k << " += " << j << " = " << k << endl;
    Bigint num =(original_k*j);
    cout <<"bigint1 x bigint 2:  "<<num<<endl;
    
    // Test comparison operations
    cout << "\n=== Test 4: Comparison Operations ===" << endl;
    cout << "1 == 2? " << (k == j) << endl;
    cout << "1 > 2? " << (k > j) << endl;
    cout << "1 >= 2? " << (k >= j) << endl;
    cout << "1 < 2? " << (k < j) << endl;
    cout << "1 <= 2? " << (k <= j) << endl;
    
    // Test assignment operator
    cout << "\n=== Test 5: Assignment Operator ===" << endl;
    cout << "Before assignment: k = " << k << ", j = " << j << endl;
    k = j;
    cout << "After k = j: k = " << k << endl;
    cout << "1 == 2? " << (k == j) << endl;
    
    delete[] s;
    delete[] s1;
    
    cout << "\n=== All tests completed! ===" << endl;
    return 0;
}