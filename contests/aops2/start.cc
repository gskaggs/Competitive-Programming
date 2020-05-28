#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

// Canidate and Hash are used to keep the solutions to sub-problem in this bottom-up DP solution.
struct Canidate {
    long long product;
    string path;

    bool operator == (const Canidate & c) const {
        return product == c.product; // As long as products are equivalent, then path chosen is arbitrary.
    }
};

struct Hash {
    size_t operator()(const Canidate & c) const {
        return hash<long long> ()(c.product);
    }
};

// Helper method
string find_path(const vector<vector<int>> & pyramid, long long target);

int main() {
    
    string header;
    getline(cin, header, ' ');

    long long target;
    getline(cin, header);
    target = stoll(header);

    int  count = 1; // The current row number
    vector<vector<int>> pyramid;

    // Construct pyramid of ints
    while (true) {
        vector<int> row; 
        stringstream line;
        string str;
        getline(cin, str);

        if (str.empty()) break;
        line << str;

        for (int i = 0; i < count; i++) {
            getline(line, str, ',');
            int num = stoi(str);
            row.push_back(num);
        }

        pyramid.push_back(row);
        count++; 
    }

    // Print the correct output
    cout << find_path(pyramid, target) << endl; 

    return 0;
}

// Returns the necessary path to get "target" or an appropriate error message
string find_path(const vector<vector<int>> & pyramid, long long target) {
    if (pyramid.size() == 0) 
        return "Invalid Input Size";

    int N = pyramid.size();
    vector<unordered_set<Canidate, Hash>> dp (N);

    // initialize dp 
    for (int c = 0; c < N; c++) 
        dp[c].insert({pyramid[N-1][c], ""});

    for (int r = N-2; r >= 0; r--) {
        int R = pyramid[r].size(); // The size of the current row
        vector<unordered_set<Canidate, Hash>> cur (R);

        for (int c = 0; c < R; c++) {
            // Look left 
            for (Canidate sub : dp[c]) { 
                sub.path.push_back('L');
                sub.product *= pyramid[r][c];
                cur[c].insert(sub);
            }

            // Look right 
            for (Canidate sub : dp[c+1]) { 
                sub.path.push_back('R');
                sub.product *= pyramid[r][c];
                cur[c].insert(sub);
            }
        }

        // O(1) Swap function
        swap(dp, cur);
    }

    // Now dp should have just one element in it.
    for (const Canidate & canidate : dp[0]) 
        if (canidate.product == target) {
            // must be reversed because we started at bottom
            string res = canidate.path;
            reverse(res.begin(), res.end()); 
            return res; 
        } 

    return "No Path Found";
}






