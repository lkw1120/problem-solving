#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
char ans;
char solve(ll n) {
    ll x = n-1;
    int sum = 0;
    while(x > 0) {
        sum+=x%3;
        x/=3;
    }
    int a = sum%3;
    int b = (a+1)%3;
    if(b == 0) return 'R';
    if(b == 1) return 'P';
    return 'S';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin>>N;
        if(N == 0) break;
        ans = solve(N);
        cout<<ans<<"\n";
    }
    return 0;
}