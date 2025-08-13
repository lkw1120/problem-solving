#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,C,S;
ll sum(ll x) {
    ll res = 0;
    while(x) {
        res+=x%10;
        x/=10;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A;
    int size = to_string(A).size();
    if(size == 1) {
        B = 0;
        C = A;
    }
    else {
        ll tmp = 1;
        for(int i=1;i<=size-1;i++) {
            tmp*=10;
        }
        B = tmp-1;
        C = A-B;
    }
    S = sum(B)+sum(C);
    cout<<S<<"\n";
    cout<<B<<" "<<C<<"\n";
    return 0;
}