#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;

umap <char, uset <char> > adjList;
vector <string> orders;
umap <char, bool> seen;

void addVertex(char v) {

    vector<string> next;
    for (string s : orders) {
        next.push_back(s + v);
        for (int i = s.size() - 1; i >= 0; i--) {
            if (adjList[v].count(s[i])) break;
            string temp = s;
            temp.insert(i, 1, v);
            next.push_back(temp);
        }
    }

    swap(next, orders);
}

void dfs(char v) {
    if (seen.count(v)) return;
    seen[v] = true;

    for (char next : adjList[v]) 
        dfs(next);

    addVertex(v);
}

int main() {
   int count = 0; 
    while (true) {
        string vertexes;
        getline(cin, vertexes);
        if (vertexes.empty()) break;
        
        if (count++ > 0) cout << endl;

        adjList.clear();
        orders.clear();
        orders.resize(1);
        seen.clear();

        string edges;
        getline(cin, edges);

        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i]].insert(edges[i+2]);
            //cout << edges[i] << " " << edges[i+2] << endl;
            i+=3;
        }

        for (int i = 0; i < vertexes.size(); i++) {
            dfs(vertexes[i]);
            i++;
        }
       
        for (int i = 0; i < orders.size(); i++) 
            reverse(orders[i].begin(), orders[i].end());

        sort(orders.begin(), orders.end());
        for (string good : orders)
            cout << good << endl;



    }
        

    
    return 0;
}
