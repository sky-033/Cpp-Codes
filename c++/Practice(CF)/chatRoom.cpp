#include <iostream>
#include <string>
using namespace std;

bool canSayHello(const string &s) {
    string hello = "hello";
    int j = 0; 

    for (char c : s) {
        if (c == hello[j]) {
            j++;
        }
        if (j == hello.size()) { 
            return true;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s; 

    if (canSayHello(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
