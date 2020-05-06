#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<ll> q;
ll N,n,ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    if(N <= 1022) {
        ans = N;
        n = 0;
        for(int i=1;i<10;i++) {
            q.push(i);
            n++;
        }
        while(!q.empty()) {
            ll num = q.front();
            q.pop();
            for(int i=0;i<num%10;i++) {
                q.push(num*10+i);
                n++;
                if(n == N) {
                    ans = q.back();
                    break;
                }
            }
        }
    }
    else {
        ans = -1;
    }       
    cout<<ans<<"\n";
    return 0;
}