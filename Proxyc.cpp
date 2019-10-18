#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, d;
    string attendance;
    cin >> t;
    while(t--)
    {
        cin >> d;
        cin >> attendance;
        double actual = 0.0, desired = 0.0, need;
        for(int i = 0; i < attendance.length(); i++)
        {
            if(attendance[i] == 'P')
            {
                actual++;
            }
            
            if((desired/d) < 0.75)
            {
                desired++;
            }
        }
        need = desired - actual;
        
        
        int answer = need;
        if(need != 0 && need > 0)
        {
            for(int i = 2; i < d-2; i++)
        {
            if(attendance[i] == 'A')
            {
                if((attendance[i-2]=='P'|| attendance[i-1]=='P') && (attendance[i+1]=='P' || attendance[i+2]=='P'))
            {
                need--;
                if(need == 0){
                    cout << answer << endl;
                    break;
                }
            }
            //
            }
        }
        }//end if
        else if(need < 0)
        {
            
            cout << 0 << endl;
        }
        else {//need == 0
            cout << 0 << endl;
        }
        
        if(need!=0 && need > 0)
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
