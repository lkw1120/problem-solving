#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll R,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>R>>X>>Y;
    ll dist2 = X*X+Y*Y;
    ll r2 = R*R;
    if(dist2 == r2) {
        ans = 1;
    }
    else if(dist2 < r2) {
        ans = 2;
    }
    else {
        ll cnt = 1;
        while(cnt*cnt*r2 < dist2) {
            cnt++;
        }
        ans = cnt;
    }
    cout<<ans<<"\n";
    return 0;
}