#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,a,b,c,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>a>>b>>c;
    for(int i=0;i<b;i++) {
        N = (N+1)/2;
    }
    for(int i=0;i<a;i++) {
        N = N/2;
    }
    for(int i=0;i<c;i++) {
        if(N > 0) {
            N = (N-1)/2;
        }
        else {
            N = 0;
        }
    }
    ans = N;
    cout<<ans<<"\n";
    return 0;
}