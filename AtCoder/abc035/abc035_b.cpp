#include<bits/stdc++.h>
using namespace std;
string str;
int T,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str>>T;
    int x,y;
    x = y = 0;
    int tmp = 0;
    for(char ch: str) {
        if(ch == 'L') x--;
        if(ch == 'R') x++;
        if(ch == 'U') y++;
        if(ch == 'D') y--;
        if(ch == '?') tmp++;
    }
    int dist = abs(x)+abs(y);
    ans = 0;
    if(T == 1) {
        ans = dist+tmp;
    } 
    else {
        if(dist >= tmp) {
            ans = dist-tmp;
        }
        else {
            ans = (tmp-dist)%2;
        }
    }
    cout<<ans<<"\n";
    return 0;
}