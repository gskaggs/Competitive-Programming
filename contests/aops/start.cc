#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

// Helper methods
string find_path(const vector<vector<int>> & pyramid, long long target);
bool sub_path(int r, int c, long long product, long long target, string& path, const vector<vector<int>> & pyramid);

int main() {
    
    string header;
    getline(cin, header, ' ');

    long long target;
    getline(cin, header);
    target = stoll(header);

    int count = 1; // The current row number
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

    if (sub_path(r, c, product, target, res, pyramid)) 
        return res;

    return "No Path Found";
}


// Searches each sub path for the target 
bool sub_path(int r, int c, long long product, long long target, string & path, const vector<vector<int>> & pyramid) {
    product *= pyramid[r][c];
   
    // Base Case 
    if (r == pyramid.size()-1) 
        return product == target;

    // Go left
    path.push_back('L');
    if (sub_path(r+1, c, product, target, path, pyramid)) 
        return true;
    path.pop_back();

    // Go right
    path.push_back('R');
    if (sub_path(r+1, c+1, product, target, path, pyramid)) 
        return true;
    path.pop_back();

    return false;
}










