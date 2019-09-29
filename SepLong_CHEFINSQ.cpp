/* 
CONTEST URL: https://www.codechef.com/SEPT19B?order=desc&sortBy=successful_submissions
PROBLEM URL: https://www.codechef.com/SEPT19B/problems/CHEFINSQ
        after you sort, it is gaurenteed that the smallest k elements of the list contains the numbers that make up
        a "interesting subsequence"
        
        
         so the solution to the problem becomes this: find combinations of the ways you can pick the k smallest array elmeents
         to fit into size k
        (1,1,1,1) k = 2: kth smallest array elments is (1,1). How many ways can we choose 2 ones? C(4, 2) (four ones, 
        we choose two of them)
        (1,2,2,2) k = 2: kth smal: (1,1). How many ways can we chose one 1, and one 2? Well. 
        We don't even need to consider how many ways to choose 1, since we know that the list is sorted, 
        and nothing will be greater than one, only equal. we only consider the two. So now the problem
        becomes this: we know our length=2
        interesting subsequence will look like (1, some number) in this case some number would be 2. 
        Therefore the answer would be C(3, 1)
*/
#include <bits/stdc++.h>

typedef long long int lli;
using namespace std;

lli dp[55][55]; //implementing pascals triangle with dp to calualte combinations
//given constraints not too big, we could use dp to calculate a factorials array but whatever.
int main() {
	// your code goes here
	lli t;
	cin >> t;
	while(t--)
    {
        lli n, k;
        cin >> n >> k;
        //initialize combinations dp array
        //using recurrence relation c(i,j) = c(i-1,j-1)+c(i-1,j)
        for(int i = 0; i < 55; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(i==j)
                {
                    dp[i][j] = 1;
                }
                else if(j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
            }
        }
        //
        //use ordered map to count number of integers
        map<lli, lli> m;
        //use an array to store sequence
        lli arr[50];
        lli input;
        for(int i = 0; i < n; i++)
        {
            cin >> input;
            arr[i] = input;
            m[input]++;
        }
        //sort the array using in build quicksort method
        sort(arr, arr+n);
        
        
        lli others = 0; //others besides our k element.
        for(int i = 0; i < k-1; i++)
        {
            if(arr[i] != arr[k-1])
            {
                others++;
            }
        }
        
        //Z = largest element among the smallest k elmenets.
        //answer would be C(cnt(Z), k-others);
        // it loks messy but really study it, u will understand.
        lli ans = dp[m[arr[k-1]]][k-others];
        cout << ans << endl;
        
        
        
    }
	return 0;
}
