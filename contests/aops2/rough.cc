#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define INF INT_MAX
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

int main() {
    
    /*string header;
    int target;

    getline(cin, header);
    stringstream line(header); 
    getline(line, header, ' ');
    getline(line, header, ' ');
    target = stoi(header);

    //line >> header; // Target:
    //line >> target; // 720
    */
    while (true) {
        string str;
        getline(cin, str);
        if (str.empty()) 
            break;
        
        stringstream line(str);

        cout << str << endl;

        string token;

        getline(line,token);
        cout << token << " ";
        

        cout << endl;
    }

    return 0;
}
