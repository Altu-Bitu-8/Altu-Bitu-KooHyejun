#include <iostream>
#include <set>

using namespace std;

int main() {
    string A;
    cin >> A;

    set<string> substring;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 1; j <= A.size() - i; j++) {
            substring.insert(A.substr(i, j));
        }
    }
    cout << substring.size() << '\n';
}