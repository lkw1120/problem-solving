#include<bits/stdc++.h>
using namespace std;
int X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>X>>Y;
    int half = Y/2;
    ans = 0;
    for(int i=0;i<=half;i++) {
        int tmp = (X+3*i)/50;
        if(i <= 16*tmp) {
            ans = max(ans,tmp);
        }
    }
    cout<<ans<<"\n";
    return 0;
}