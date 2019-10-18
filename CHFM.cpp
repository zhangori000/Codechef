#include<bits/stdc++.h>
using namespace std;
typedef long double ll;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		ll ototal = 0;
		vector<ll> numbers;
		vector<ll> differences;
		for(int i= 0; i < n; i++)
		{
			ll input;
			cin >>input;
			numbers.push_back(input);
			ototal+=input;
		}
		
		
		
		for(int i = 0; i < n; i++)
		{
			differences.push_back(ototal - numbers[i]);
		}
		
		
		double omean = ototal / double(n);
		
		
		bool print = true;
		double minindex = INT_MAX;
		double min = INT_MAX;
		for(int i=0; i < n; i++)
		{
			
			double comparison = differences[i] / double((n-1));
		
			if(comparison == omean)
			{
			    
				if(comparison < min)
				{
				    minindex = i;
				    min = comparison;
				    print = false;
				}
				
			}
			
		}
		if(print)
		{
			cout << "Impossible" << endl;
		}
		else
		{
		    cout << minindex+1 << endl;
		}
		
	}
	return 0;
}
