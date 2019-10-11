/*  contest url https://www.codechef.com/OCT19B/problems/MARM
Chef is really interested in the XOR operation. He wants to take a sequence A0,A1,…,AN−1 and for each i from 0 to K−1 inclusive (in this order, one by one), perform the following operation:

Let's denote a=Ai%N and b=AN−(i%N)−1 before this operation.
Change Ai%N to a⊕b, i.e. a XOR b.
Since Chef is busy, he asked you to find the final sequence he should get after performing these operations.
*/
/* naive approach */
#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while(t--)
	{
	    int n = 3;
	    int k;
	    
    	
    	vector<int> A;
    	for(int i = 0; i < n; i++)
    	{
    	    int input;
    	    cin >> input;
    	    A.push_back(input);
    	}
        
        vector<int> original = A;
        
    	for(k = 1; k < 61; k++)
    	{   
    	    printf("k=%d\n", k);
    	    A = original;
    	    for(int i = 0; i < k; i++)
        	{
        	    int a = A[i%n];
        	    int b = A[n-(i%n)-1];
        	    A[i%n] = a^b;
        	}
        	
        	for(int i = 0; i < n; i++)
        	{
        	    cout << A[i] << " ";
        	}
        	cout << endl;
    	}
        	
    	
    	//print
        	
    }
	return 0;
}


//O(n) solution.


