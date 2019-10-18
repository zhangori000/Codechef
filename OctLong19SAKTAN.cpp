#include <bits/stdc++.h>

typedef long long int lli;
using namespace std;

int main() {
// your code goes here
int t;
cin >> t;
while(t--){
   lli n, m, q;
   cin >> n >> m >> q;
   bool x[n];
   bool y[m];
   
        for(lli i=0; i<n; i++){
            x[i] = false;
        }
        for(lli i=0; i<m; i++){
            y[i] = false;
        }
   
   while(q--){
       lli xinput, yinput;
       cin >> xinput >> yinput;
       x[xinput-1] = !x[xinput-1];
       y[yinput-1] = !y[yinput-1];
   }
   lli xcount = 0;
   lli ycount = 0;
   
   for(lli i=0; i<n; i++){
       if(x[i]){
           xcount++;
       }
   }
   for(long i=0; i<m; i++){
       if(y[i]){
           ycount++;
       }
   }
   
   cout << (n*m) - (xcount*ycount) - ((n-xcount)*(m-ycount)) << endl;
   
}
return 0;
}
