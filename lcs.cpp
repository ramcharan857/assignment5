#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printDPTable(const vector<vector<int>>& dp, const string& str1, const string& str2) {
    cout << "   ";
    for (char ch : str2) {
        cout << ch << " "; 
    }
    cout << endl;

    for (int i = 0; i < dp.size(); i++) {
        if (i == 0) {
            cout << "  "; 
        } else {
            cout << str1[i - 1] << " ";  
        }

        for (int j = 0; j < dp[i].size(); j++) {
            cout << dp[i][j] << " "; 
        }
        cout << endl;
    }
}


string longestCommonSubstring(string str1, string str2) {
    int n = str1.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    int maxLength = 0; 
    int endIndex = 0;  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    printDPTable(dp, str1, str2);
    return str1.substr(endIndex - maxLength, maxLength);
}

int main() {
    string str1 = "ABAB";
    string str2 = "BABA";
    
    cout << "Input strings: " << endl;
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
    cout << endl;

    string result = longestCommonSubstring(str1, str2);
    cout << "Longest Common Substring: " << result << endl;

    return 0;
}
