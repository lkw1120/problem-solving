#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string S;
ll ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>S;
    ll b = 0;
    int size = S.size();
    for(int i=size-1;i>=0;i--) {
        int d = S[i]-'0';
        ll r = b%10;
        if(r <= d) {
            b+=d-r;
        }
        else {
            b+=10-r+d;
        }
    }
    ans = size+b;
    cout<<ans<<"\n";
    return 0;
}