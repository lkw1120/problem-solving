#include<bits/stdc++.h>
using namespace std;
string str;
int N,K,R,U,X,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cin>>str;
    R = U = X = 0;
    for(int i=0;i<N;i++) {
        if(str[i] == 'U') U++;
        if(str[i] == 'R') R++;
        if(str[i] == 'X') X++;
    }
    cin>>K;
    ans = 0;
    for(int i=0;i<K;i++) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(y <= U+X && x <= R+X && x-y <= R && y-x <= U) {
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}