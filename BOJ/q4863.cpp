#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
int A,B;
ld ans;
ld combine(int n, int k) {
    if(k < 0 || n < k) {
        return 0.0L;
    }
    k = min(k,n-k);
    ld res = 1.0L;
    for(int i=1;i<=k;i++) {
        res*=(ld)(n - k + i);
        res/=(ld)i;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ld total = combine(26,13);
    cout<<fixed<<setprecision(8);
    while(true) {
        cin>>A>>B;
        if(A == -1 && B == -1) break;
        int cnt = A+B;
        ld tmp = combine(cnt,A)*combine(26-cnt,13-A);
        if(A != B) tmp*=2.0L;
        ans = tmp/total;
        cout<<A<<"-"<<B<<" split: "<<ans<<"\n";
    }
    return 0;
}