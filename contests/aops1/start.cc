#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

// Canidate and Hash are used to keep the memoization table for this top-bottom DP solution.
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

// Helper methods
string find_path(const vector<vector<int>> & pyramid, long long target);
bool sub_path(int r, int c, long long product, long long target, string& path, const vector<vector<int>> & pyramid, vector<vector<unordered_set<Canidate, Hash>>> & mem);

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

    int r = 0, c = 0;
    long long product = 1;
    string res;

    int N = pyramid.size();
    vector<vector<unordered_set<Canidate, Hash>>> mem (N, vector<unordered_set<Canidate, Hash>> (N));

    if (sub_path(r, c, product, target, res, pyramid, mem)) 
        return res;

    return "No Path Found";
}


// Searches each sub path for the target 
bool sub_path(int r, int c, long long product, long long target, string & path, const vector<vector<int>> & pyramid, vector<vector<unordered_set<Canidate, Hash>>> & mem) {
   
    // Base Case 
    if (r == pyramid.size()-1) {
        mem[r][c].insert({pyramid[r][c], ""});
        return product * pyramid[r][c] == target;
    }
    

    // Use the memoization table
    if (!mem[r][c].empty()) {
        for (const Canidate & sub : mem[r][c]) {
            if (product * sub.product == target) {
                // We must reverse the sub path because it was made from the bottom going up
                string sub_path = sub.path;
                reverse(sub_path.begin(), sub_path.end());
                path.append(sub_path);
                return true;
            }
        }
        return false; 
    }

    // Otherwise, we must recurse
    product *= pyramid[r][c];

    // Go left
    path.push_back('L');
    if (sub_path(r+1, c, product, target, path, pyramid, mem)) 
        return true;
    path.pop_back();

    // Go right
    path.push_back('R');
    if (sub_path(r+1, c+1, product, target, path, pyramid, mem)) 
        return true;
    path.pop_back();

    // Fill in our mem table
    unordered_set<Canidate, Hash> & cur = mem[r][c];

    // sub is passed by value not by reference, so as to not destroy previous entries in mem.
    for (Canidate sub : mem[r+1][c]) { 
        sub.path.push_back('L');
        sub.product *= pyramid[r][c];
        cur.insert(sub);
    }

    for (Canidate sub : mem[r+1][c+1]) {
        sub.path.push_back('R');
        sub.product *= pyramid[r][c];
        cur.insert(sub);
    }

    return false;
}







