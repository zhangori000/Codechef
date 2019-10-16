/* this problem is a graph problem

all u need to do is do a couple of tests to se that...
when edge is even. k = 1. it's a trivila case, u litreally need to do nothing. 

what about when edge is odd? well. if u do some tests, u start to realize that if you find any vertex with degree that is odd....
take that vertext with the odd degree and create a set with JUST that element in it. Yep just that one. 
and now, make anothe rset with the REMAINING vertices. E - deg(v) = even. (figure this one out)

what if the graph is a circle? meaning that there are no vertices such that deg(v) is even. In that case, very simple. Create... 
TWO SINGLETON subsets that are connected together with an edge. And create the third subset with the REMAINING elmenets. 
*/

#include<bits/stdc++.h>

typedef int lli;

using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
	    lli n;
	    lli m;
	    lli u, v;
	    cin >> n >> m;
	    lli deg[n+1]; //print out the degree of vertices I put in. 
	    for(int i = 1; i <= n; i++)
	    {
	        deg[i] = 0; //initalize them all to zero(it helps for finding the parity)
	    }
	    
	    for(lli i = 1; i <= m; i++)
	    {
	        
	        cin >> u >> v;

	        deg[u] ^= 1; //changes the parity
	        deg[v] ^= 1; //since adding an edge u and v increases the degree of u and v by 1
	  
	    }
	    
	    while(true)
	    {
	        //if m is even..
    	    if(!(m&1))
    	    {
    	        cout << '1' << endl; //only one subset, and vertices point to that.
    	        for(lli i = 1; i <= n; i++)
    	        {
    	            cout << '1' << " ";
    	        }
    	        cout << endl;
    	        break;
    	    }
    	    bool breakme = false;
    	    for(lli i = 1; i <= n; i++)
    	    {
    	        //find the first vertice whose degree is odd
    	  
    	        if(deg[i])
    	        {
    	            cout << '2' << endl;
    	            for(lli j = 1; j <= n; j++)
    	            {
    	                if(j!=i)
    	                {
    	                    cout << '1' << " ";
    	                }
    	                else
    	                {
    	                    cout << '2' << " ";
    	                }
    	            }
    	            cout << endl;
    	            breakme = true; //this break is for after the big for iton loop.
    	            break; //only run this thing once or u get all differnet sets.
    	           
    	        }
    	        
    	    }
    	    if(breakme)
    	    {
    	        break; // equivalet to returning in a voidfucntin 
    	    }
    	    
    	    //if every single deg is even...
    	    cout << '3' << endl; //we know that k = 3;
    	    for(lli i = 1; i <= n; i++)
    	    {
    	        if(i==u) //u and v are the last set of vertices our program accepted. this can work for literally any vertices. 
    	        {
    	            cout << '2' << " ";
    	        }
    	        else if (i == v)
    	        {
    	            cout << '3' << " ";
    	        }
    	        else
    	        {
    	            cout << '1' << " ";
    	        }
    	    }
    	    cout << endl;
    	    break;
	    }
    	    
	    
	    
	}
	return 0;
}





