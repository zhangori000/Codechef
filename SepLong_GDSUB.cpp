/* key notes ----
problem statement:
https://www.codechef.com/SEPT19B/problems/GDSUB <-- find everything including constraints, examples, etc.
summary: given a sequence of prime numbers less than 8000, and a number k,  find the number of "good" subsequences
(subsequecnes that are of size k, and only have distinct integers inside it) of at most k..

O(n^2) time
O(n^2) space
#include<bits/stdc++.h>

typedef long long int lli;
#define MODULUS 1000000007;
lli dp[1008][1008]; //since there are only 1007 prime numbers under 8000, there are only 1007 distinct numbers at max.
using namespace std;

int main() {
    

	

	    lli n, k;
	    cin >> n >> k;
	    if(k > 1007)
	    {
	        k = 1007; 
	    }
	    map<lli, lli> m; //this will store the count of the distinct elmements
	    
	    lli input;
	    for(int i = 0; i < n; i++)
	    {
	        cin >> input;
	        m[input]++; 
	    }
	
	    vector<lli> buckets; 
	    //buckets.size() = 2;
	    //buckets[0] = 4 //means that there are 2 distinct integers, 4 of kind 1
	    //buckets[1] = 3// and 3 of kind 2. 
	    for(auto i = m.begin(); i != m.end(); i++)
	    {
	        buckets.push_back(i->second);
	    }
	    for(int i = 0; i < k; i++) 
	    {
	        for(int j = i; j < buckets.size(); j++)
	        {
	            if(i==0 && j==0)
	            {
	                dp[i][j] = buckets[j] % MODULUS;
	                //printf("dp[%d][%d] is: %d ", i, j, dp[i][j]);
	            }
	            else if(i==0)
	            {
	                dp[i][j] += dp[i][j-1] + buckets[j];
	                dp[i][j] %= MODULUS;
	                //printf("dp[%d][%d] is: %d ", i, j, dp[i][j]);
	            }
	           // if we are on row 1 (size 2 subseq), we need j to be bigger than 1. 
	            else
	            {
	                dp[i][j] += dp[i][j-1];
	                dp[i][j] %= MODULUS;
	                dp[i][j] += dp[i-1][j-1]*buckets[j];
	                dp[i][j] %= MODULUS;
	                //printf("dp[%d][%d] is: %d ", i, j, dp[i][j]);
	            }
	            
	        }
	    }
	    
	    lli ans = 0;
	    for(int inc = 0; inc < k; inc++) //the answer is the sum of "good" subsequences of length 1, 2, 3...k
	    {
	        ans += dp[inc][buckets.size()-1];
	        ans %= MODULUS; 
	    }
	    cout << ans+1 << endl; //plus one for the empty set. 
	    
	    
	    
	
	return 0;
}


