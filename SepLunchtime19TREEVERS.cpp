#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MX = (1 << 20);

bool cmp(pair<int, int> A, pair<int, int> B);
void dfs(int x, int p);

//these need to be global because void dfs() uses them.
lli dp[MX]; //this is number of inversions given node (which is represented by index)
lli sz[MX]; //size of ever subtree x (x is an index)
vector<int> v[MX]; //this is our graph (an array of lists)
lli col[MX]; // this is our array of 0 and 1's
lli cnt[MX][2];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        lli n;
        cin >> n;

        for(lli i = 1; i <= n; i++)
        {
            v[i].clear();
        }
        for(lli i = 1; i <= n; i++)
        {
            cin >> col[i];
        }

        for(int i = 1; i < n; i++)
        {
            lli a, b;
            cin >> a >> b; 
            assert(a != b); //this nesures that a is = to b lol
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        /* our dfs function will do all the work 
        we will call it on our root node (1), the previous subtree is undefined
        (-1). 
        */
        dfs(1, -1);
        assert(sz[1] == n); //if size of first node is not = to given n thats bad
        cout << dp[1] << endl; //number of inversions for subtree of node 1 
        
        
    }
    return 0;
}

void dfs(int x, int p)
{
    /* 
    we are passing in a node (numbered 1 to N)
    so we should think about the properties of each node:
    each node has a number of zeros and ones (hence our 2d arary of cnt)
    and initally, the number of ones and zeroes are 0.
    also, we are actually analyzing subtrees not individual nodes
    so intially our subtree is of size 1 (they will grow as we go iwnard)
    and initally our subtree sould contain 0 inversions
    */
    dp[x] = 0;
    sz[x] = 1;
    cnt[x][0] = cnt[x][1] = 0; 
    
    //depending on the weight of our curret node we add 1 or 0 
    cnt[x][col[x]]++;
    
    /*
    the point of this for loop is to update our subtree to it's 
    correct size, number of inversions etc, and the way to do that is to
    add up stats from the subtrees roots, and the roots also apply the same
    procedure
    */
    vector<pair<int, int>> vec; 
    /* the point of this vector is to store information about the different 
    subtrees and their containing 0 and 1's. 
    */
    for(auto nxt : v[x]) //for every node connected to current node
    {
        if(nxt == p)
        {
            continue; //nodes with no children only have one connection (p)
        }
        dfs(nxt, x); //we go deeper. 
        /* so this dfs function essentially helps us update the "nxt" nodes
        we need the nxt nodes information because we are updating our 
        current x node
        */
        
        cnt[x][0]+=cnt[nxt][0];
        cnt[x][1]+=cnt[nxt][1];
        vec.push_back({cnt[nxt][0], cnt[nxt][1]});
        dp[x] += dp[nxt];
        sz[x] += sz[nxt];
    }
    
    /*
    after the for loop finished, waht this means is that we have 
    alreayd looped through eveyr single child of the node and have 
    created a vector of all the possible combinations of each node.
    */
    
    //vec is empty if the for loop never ran(if node had no chilren)
    sort(vec.begin(), vec.end(), cmp); //this sorts it to best ordering. 
    
    int current = col[x];  //current amount of ones.
    for(auto pp : vec)//if vec is empty this will never run. 
    {
        dp[x] += 1ll*current * pp.first; //number of current ones times # of 0
        current+=pp.second; //update the amount of ones. 
    }
}
bool cmp(pair<int, int> A, pair<int, int> B)
{
    return 1ll * B.first * A.second < 1ll * A.first * B.second;
}

