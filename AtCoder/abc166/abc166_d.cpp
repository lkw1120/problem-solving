#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll X;
ll check(ll x) {
    return x*x*x*x*x;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>X;
    for(ll a=-200;a<=200;a++) {
        for(ll b=-200;b<=200;b++) {
            if(check(a)-check(b) == X) {
                cout<<a<<" "<<b<<"\n";
                return 0;
            }
        }
    }
    return 0;
}