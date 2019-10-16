#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

/*

to solve A1 + A4 this equals A1 + A2 + A3 + A4 subtract A2 + A3 (B1 - B2 + B3);
doesn't work for odd nubers.

*/
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli t;
	cin >> t;
	while(t--)
	{
	    lli n, q;
	    cin >> n >> q;
	    lli B[n+1];
	    lli S[n+1]; //we are going to be using the zeroth index. so make 
	    
	    memset(S, 0, sizeof(S));
	    
	    //input the sequence. B.
	    for(lli i = 1; i < n; i++)
	    {
	        cin >> B[i];
	        
	    }
	    
	    //make the s sequence.
	    for(lli i = 1, c = 1; i <= n; i++, c*=-1)
	    {
	        S[i] = c*B[i] + S[i-1];
	    }
	    
	    for(lli i = 0; i < q; i++)
	    {
	        lli a, b;
	        cin >> a >> b;
	        
	        
	        if(a > b)
	        {
	            swap(a, b); //this will prove helpful
	        }
	        if((b-a)%2 == 0)
	        {
	            cout << "UNKNOWN" << endl;
	        }
	        
	        else if( a%2 )
	        {
	            cout << S[b-1] - S[a-1] << endl;
	        }
	        else
	        {
	            cout << -1 * S[b-1] + S[a-1] << endl;
	        }
	    }
	    
	}
	return 0;
}






