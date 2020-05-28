#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define trav(a, x) for (auto& a : x)
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define INF 1000000000 
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

const int Size = 10000005;              // size of nodes array
const int biggestRange = 100001;        // largest possible range 

struct Node
{
    int maxHeight, minHeight;
    // The height will be applied to all children
    bool isLazy;
};

Node allNodes[Size];

void ApplyLazyUpdate(int index, int newHeight)
{
    allNodes[index].maxHeight = allNodes[index].minHeight = newHeight;
    allNodes[index].isLazy = true;
}

void PushLazyUpdate(int index)
{
    if (!allNodes[index].isLazy)
        return;
    
    // Apply lazy to both children
    // minHeight == maxHeight
    ApplyLazyUpdate(index * 2, allNodes[index].minHeight);
    ApplyLazyUpdate(index * 2 + 1, allNodes[index].minHeight);
    
    allNodes[index].isLazy = false;
}

// Inclusive on both starts and ends
int RangeUpdate(int index, int nodeStart, int nodeEnd, int queryStart, int queryEnd, int newHeight)
{
    if (nodeEnd < queryStart || nodeStart > queryEnd)
        return 0;
    
    // Should only push lazy update when it isn't a single node - could go too deep, and will never go that low anyway
    if (nodeStart != nodeEnd)
        PushLazyUpdate(index);
    
    int middle = (nodeStart + nodeEnd) / 2;
    
    // This index is contained completely
    if (nodeStart >= queryStart && nodeEnd <= queryEnd)
    {
        if (allNodes[index].maxHeight <= newHeight)
        {
            ApplyLazyUpdate(index, newHeight);
            
            return nodeEnd - nodeStart + 1;
        }
        else if (allNodes[index].minHeight <= newHeight)
        {
            // Some children will have been changed
            int cost = RangeUpdate(index * 2, nodeStart, middle, queryStart, queryEnd, newHeight) +
                       RangeUpdate(index * 2 + 1, middle + 1, nodeEnd, queryStart, queryEnd, newHeight);
            
            allNodes[index].minHeight = min(allNodes[index * 2].minHeight, allNodes[index * 2 + 1].minHeight);
            allNodes[index].maxHeight = max(allNodes[index * 2].maxHeight, allNodes[index * 2 + 1].maxHeight);
            return cost;
        }
        
        // Should never continue farther in this function from inside this if.
        return 0;
    }
    
    
    // In this case, only part of the grid is contained
    // So keep going down until reach a part that is completely contained
    int cost = RangeUpdate(index * 2, nodeStart, middle, queryStart, queryEnd, newHeight) +
               RangeUpdate(index * 2 + 1, middle + 1, nodeEnd, queryStart, queryEnd, newHeight);
    
    allNodes[index].minHeight = min(allNodes[index * 2].minHeight, allNodes[index * 2 + 1].minHeight);
    allNodes[index].maxHeight = max(allNodes[index * 2].maxHeight, allNodes[index * 2 + 1].maxHeight);
    
    
    return cost;
}

// Inclusive on both starts and ends
// Returns sums of heights across the range
int RangeQuery(int index, int nodeStart, int nodeEnd, int queryStart, int queryEnd)
{
    if (nodeEnd < queryStart || nodeStart > queryEnd)
        return 0;
    
    // Should only push lazy update when it isn't a single node - could go too deep, and will never go that low anyway
    if (nodeStart != nodeEnd)
        PushLazyUpdate(index);
    
    int middle = (nodeStart + nodeEnd) / 2;
    
    // This index is contained completely
    if (nodeStart >= queryStart && nodeEnd <= queryEnd)
    {
        return allNodes[index].maxHeight;
    }
    
    // In this case, only part of the grid is contained
    // So keep going down until reach a part that is completely contained
    int best = max(RangeQuery(index * 2, nodeStart, middle, queryStart, queryEnd),
                   RangeQuery(index * 2 + 1, middle + 1, nodeEnd, queryStart, queryEnd));
    
    return best;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        for (int i = 0; i < Size; ++i)
        {
            allNodes[i].maxHeight = allNodes[i].minHeight = 0;
            allNodes[i].isLazy = true;
        }
        
        int N;
        cin >> N;
        
        int count = 0;
        while (N--)
        {
            int start, end, height;
            cin >> start >> end >> height;
            
            --end;
            int orig = count;
            count += RangeUpdate(1, 0, biggestRange, start, end, height);
        }
        
        cout << count << '\n';
    }
}
