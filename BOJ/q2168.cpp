#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll X,Y,ans;
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>X>>Y;
    ans = X+Y-gcd(X,Y);
    cout<<ans<<"\n";
    return 0;
}