#include<bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    while(N--) {
        string str;
        cin>>str;
        int x,y,sum;
        x = y = sum = 0;
        for(char ch: str) {
            int dx = x;
            int dy = y;
            if(ch == 'E') dx++;
            if(ch == 'W') dx--;
            if(ch == 'N') dy++;
            if(ch == 'S') dy--;
            sum+=x*dy-dx*y;
            x = dx;
            y = dy;
        }
        if(0 < sum) {
            cout<<"CCW"<<"\n";
        }
        else {
            cout<<"CW"<<"\n";
        }
    }
    return 0;
}