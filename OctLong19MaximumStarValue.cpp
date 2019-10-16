/*
makes use of counting all divisors in a list.
In fact we first iterate thru the list BACKWARDS and mark read and unread. Like for example
if we have clacualted that arr[i] has star value of x and that x is maximum. 
then if we find another arr[j] with the same like value as arr[i], then the starvalue will never increase (hence useless isnce problem wants ut 
to obtain the MAXIMUM starvalue)
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    
	
	
	int t;
	cin >> t;
	while(t--)
	{
	    // your code goes here
    	int cnt[1002000];
    	int a[100200];
    	bool vis[1002000];
    	bool good[100200];
    	
    	memset(cnt, 0, sizeof(cnt));
    	memset(vis, 0, sizeof(vis));
    	memset(good, 0, sizeof(good));
	    int ans = 0;
	    int n;
	    cin >> n;
	    for(int i = 1; i <= n; i++)
	    {
	        cin >> a[i];
	    }
	    
	    for(int i = n; i > 0; i--)
	    {
	        good[i] = !vis[a[i]]; //if we have visited we shouldn't do anything
	        vis[a[i]] = 1;
	    }
	    
	    for(int i = 1; i <= n; i++)
	    {
	        if(good[i]) //if we have not visited this number yet.
	        {
	            int star = 0;
    	        for(int j = a[i]; j <= 1000000; j += a[i])
    	        {
    	            star += cnt[j];
    	        }
    	        ans = max(ans, star);
    	       
	        }
	        cnt[a[i]]++;
	    }
	    
	    cout << ans << endl;
	    
	}
	return 0;
}


