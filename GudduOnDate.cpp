#include <bits/stdc++.h>
using namespace std;

unsigned long long int digitsum(unsigned long long int n);
int main()
{
    int t;
    unsigned long long int n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        unsigned long long int sumofdigits = digitsum(n) % 10;
        if(sumofdigits == 0)
        {
            cout << n*10 << endl;
        }
        else
        {
            cout << n*10 + (10 - digitsum(n) % 10) << endl;
        }
        
    }
    
    return 0;
}
unsigned long long int digitsum(unsigned long long int n){
    unsigned long long int total = 0;
    while(n!=0)
    {
        unsigned long long int lastnum = n % 10;
        total += lastnum;
        n/=10; //removes last number.
    }
    return total;
}
