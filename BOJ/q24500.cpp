#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cout.tie(0);
    cin>>N;
    ll n,cnt;
    n = N;
    cnt = 0;
    while(n) {
        n/=2;
        cnt++;
    }
    n = 1;
    while(cnt) {
        n*=2;
        cnt--;
    }
    n--;
    if(N == n) {
        cout<<1<<"\n";
        cout<<N<<"\n";
    }
    else {
        cout<<2<<"\n";
        cout<<n-N<<" "<<N<<"\n";
    }
    return 0;
}