#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        bool nogood = 0;
        
        int cnt[n];
        memset(cnt, 0, sizeof(cnt));
        
        for(int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            //we have the value we want to put int yay.
            //check if the difference is great...draw out scenarios from test cases and u will know hat I mean. 
            bool ch = 0;
            for(int i = 0; i < n; i++)
            {
                if(i!=(x-1))
                {
                    ch |= (cnt[x-1] > cnt[i]); //using bool and |= is a) cool b) ensures that ch will stay 1 forever.
                }
            }
            nogood |= ch;
            cnt[x-1]++;
        }
        
        if(nogood)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    
    return 0;
}
