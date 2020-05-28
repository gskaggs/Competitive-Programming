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

struct Node {
    Node* next[26];
    long long score;

    Node () : score(0) {
        for(int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }

    void addWord(string word, int n, int i) {
        if (i == word.size()) {
            score += n;
            return;
        }

        int nextChar = word[i] - 'A';
        if (next[nextChar] != nullptr) {
            cout << "hello" << endl;
            //next[nextChar]->addWord(word, n, i+1);
            return;
        }

        Node* cur = this;
        for (int index = i; index < word.size(); index++) {
            int curChar = word[index] - 'A';
            cur->next[curChar] = new Node();
            cur = cur->next[curChar];

            if (index == word.size() -1) 
                cur->score = n;
        }
    }

    long long maxScore() {
        long long res = score;
        for (int i = 0; i < 26; i++) {
            if (next[i] != nullptr)
                res = max(res, next[i]->maxScore());
        }
        return res;
    }

    long long maxPrefixScore(string prefix, int i) {
        if (i == prefix.size())
            return maxScore();

        int curChar = prefix[i] - 'A';
        if (next[curChar] == nullptr) 
            return 0;

        return next[curChar]->maxPrefixScore(prefix, i+1);
    }

};

class PrefixTree {

public:
    
    Node* head;
    PrefixTree() {
        head = new Node();
    }

    void addWord(string word, int n) {
        head->addWord(word, n, 0);
    }
    
    long long maxPrefixScore(string prefix) {
        return head->maxPrefixScore(prefix, 0);
    }

};

int main() {
    
    PrefixTree pt;
    pt.addWord("BOB", 5);

    cout << pt.head->score << endl;
    //pt.head->next['B' - 'A'] = new Node();
    cout << pt.head->next[1]->score << endl;
    cout << pt.head->next[1]->next['O' - 'A']->next[1]->score << endl;

    cout << pt.maxPrefixScore("A") << endl;
    cout << pt.maxPrefixScore("B") << endl;

    return 0;
}
