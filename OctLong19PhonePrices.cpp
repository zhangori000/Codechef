#include <iostream>
#include<climits>
#include<vector>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int> prices;
	    for(int i = 0; i<5; i++)
	    {
	        prices.push_back(INT_MAX); //simulate that unidentified prices are max. 
	    }
	    for(int i = 0; i < n; i++)
	    {
	        int input;
	        cin >> input;
	        prices.push_back(input);
	    }
	    int answerCount = 1; //trivial case when first day has to be good sequence. 
	    for(int i = 6; i < n+5; i++)
	    {
	        int dayCount = 0;
            for(int j = i; j > i-5; j--)
            {
                if(prices[i] < prices[j-1])
                {
                    dayCount++;
                }
                else
                {
                    break;
                }
            }
            if(dayCount == 5)
            {
                answerCount++;
            }
	        
	    }
	    cout << answerCount << endl;
	    
	}
	
	return 0;
}
