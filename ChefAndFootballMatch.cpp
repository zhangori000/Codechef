#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        lli n;
        cin >> n;
        lli totalA = -1 , totalB = -1;
        for(lli i = 0; i < n; i++)
        {
            lli form;
            lli a, b;
            cin >> form >> a >> b;
            
            if(form == 1)
            {
                totalA = a;
                totalB = b;
                cout << "YES" << endl;
            }
            else
            {
                if(a == b) // they are tied, we know for sure at least
                {
                    totalA = a;
                    totalB = b;
                    cout << "YES" << endl;
                }
                else if(min(a, b) < max(totalA, totalB))
                {
                    totalA = min(a, b);
                    totalB = max(a, b);
                    cout << "YES" << endl;
                }
                else
                {
                    /* once u get here, its over.. 
                    just set the totalA and totalB into values that will always
                    produce "NO" for an answer.
                    unless.... we hit type == 1 again!
                    */
                    totalA = -1; 
                    totalB = -1;
                    cout << "NO" << endl;
                }
            }
            
        }
    }
    return 0;
}
