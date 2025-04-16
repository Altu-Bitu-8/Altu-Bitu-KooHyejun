#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a,b;
    cin >> a >> b;

    int carry = 0;
    string result = "";

    while (a.size() < b.size()) a = "0" + a;
    while (b.size() < a.size()) b = "0" + b;

    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result += (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry) result += carry + '0';

    reverse(result.begin(), result.end());
    cout << result << "\n";

    return 0;
}