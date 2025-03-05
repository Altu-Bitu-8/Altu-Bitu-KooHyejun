#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& str) {
    stack<char> s;
    for (char ch : str) {
        if (ch == '(' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')') {
            if (s.empty() || s.top() != '(') return false;
            s.pop();
        }
        else if (ch == ']') {
            if (s.empty() || s.top() != '[') return false;
            s.pop();
        }
    }
    return s.empty();
}
int main() {
    string line;
    while (true) {
        getline(cin, line);
        if (line == ".") break;

        cout << (isBalanced(line) ? "yes" : "no") << "\n";
    }
    return 0;
}