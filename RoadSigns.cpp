#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;



long powoftwo(long k);
int main() {
	int t;
	long k;
	cin >> t;
	while(t--)
	{
	    
	    cin >> k;
        unsigned long long int answer = 5*powoftwo(k);
	    cout << (answer % mod) << endl;
	}
	
	return 0;
}
long powoftwo(long k)
{
    
    if(k==0)
    {
        return 1;
    }
    else if(k%2 == 0)
    {
        return (powoftwo(k/2)%mod) * (powoftwo(k/2)%mod);
    }
    else
    {
        return (2%mod) * (powoftwo(k/2)%mod)*(powoftwo(k/2)%mod);
    }
}
