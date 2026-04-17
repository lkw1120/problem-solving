#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[10];
ll N,K,ans;
int digits(int x) {
    if(x >= 10000000) return 8;
    if(x >= 1000000) return 7;
    if(x >= 100000) return 6;
    if(x >= 10000) return 5;
    if(x >= 1000) return 4;
    if(x >= 100) return 3;
    if(x >= 10) return 2;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    ans = 0;
    arr[0] = 1%K;
    for(int i=1;i<=8;i++) {
        arr[i] = (arr[i-1]*10)%K;
    }
    for(int i=1;i<=N;i++) {
        int d = digits(i);
        ans = (ans*arr[d]+i)%K;
    }
    cout<<ans<<"\n";
    return 0;
}