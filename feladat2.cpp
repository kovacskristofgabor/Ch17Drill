#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

ostream& print_array(ostream& os, int* a, int n)
{
    for (int i = 0; i < n; ++i) os << a[i] << '\n';
    return os;
}

int main()
try {

    int x = 7;
    int* p1 = &x;

    cout << "p1 pointer " << p1 << " erre az értékre mutat " << *p1 << '\n';

    int* p2 = new int[7];   //free store inicializáció int-re, 7 elemű tömb

    x = 1;  //x értéke 1 lesz
    for (int i = 0; i < 7; ++i) {  //i értéke 0, ha i kisebb mint 7 adjon hozzá 1-et
        p2[i] = x;  //a p2 i-edik eleme legyen egyenlő x-el
        x*= 2;  //szorozza 2-vel
    }

    cout << "p2 elemei " << p2 << '\n';

    for (int j = 0; j < 7; ++j)
        cout << p2[j] << '\t';

    cout << '\n';

    int* p3 = p2;
    p2 = p1;
    p2 = p3;

    cout << "p1 pointer " << p1 << " erre az értékre mutat " << *p1 << '\n';
    cout << "p2 pointer " << p2 << " erre az értékre mutat " << *p2 << '\n';

    delete[] p2;

    p1 = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    p2 = new int[10];

    for (int m = 0; m < 10; ++m)
        p2[m] = p1[m];
    
    for (int k = 0; k < 10; ++k)
        cout << p2[k] << '\t';
    cout << '\n';

    vector<int> v1 {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    vector<int> v2 (10);
    v2 = v1;

    for (int v : v2) cout << v << '\t';

    cout << '\n';
}
catch(exception& e) {
    cerr << "Kivétel: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Ismeretlen kivétel\n";
    return 2;
}