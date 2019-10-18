#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
int main() {
	// your code goes here
    lli n;
    cin >> n;
    lli arr[n+1];
    memset(arr, 0, sizeof(arr)); //intialize eveyrhting to zero
    
    for(lli i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    
    lli ans = 0;
    lli diff = 0; //initally zero. 
    //diff(i) is simply the sum of differences for all (i,j) where j < i  
    
    /* 
    Essentially what happens is this. If we sort out the array, tehn..
    using hte defintion of diff(i) we get an intersting property.
    for somethig of n = 4; //index by 1 in example, 
    diff(1) = 0; since for all (i,j) j < 1, nothing is less than 1 
    diff(2) = (2,1); the only j less than 2 is 1 
    diff(3) = (3,2) + (3,1)
    diff(4) = (4,3) + (4,2) + (4,1) 
    what we see is that summing all the diff(i) for each i, gives us n choose 2 
    ways to add up. So.. teh answer basically. 
    If you simply try to write out eveyrhting by hand, you will see a 
    relatipnship between diff(2) and diff(1). 
    
    so if it looks confusing, my code it's because I didn't go into detail
    on how to derive that forumula (it's not hard trust me, just try)
    
    */
    sort(arr+1, arr+n+1);
    
    for(lli i = 2; i <= n; i++)
    {
        diff = diff + (arr[i]-arr[i-1])*(i-1); 
        //diff on the right side is "previous" diff.
        ans += diff;
    }
    
    
    
    cout << ans;
    
	return 0;
}
