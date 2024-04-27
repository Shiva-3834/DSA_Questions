#include <bits/stdc++.h>
using namespace std;

void generateParentheses(vector<string>& result, string current, int open, int close, int n) {
    if (current.size() == 2 * n) {
        result.push_back(current);
        return;
    }

    if (open < n) {
        generateParentheses(result, current + '(', open + 1, close, n);
    }   
    if (close < open) {
        generateParentheses(result, current + ')', open, close + 1, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParentheses(result, "", 0, 0, n);
    return result;
}

int main() {
    int n = 3;
    vector<string> combinations = generateParenthesis(n);
    for (const string& combination : combinations) {
        cout << combination << endl;
    }
    return 0;
}
