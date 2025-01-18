#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[21];
ll T,N,ans;
void init() {
    arr[2] = 1;
    for(int i=3;i<21;i++) {
        arr[i] = (i-1)*(arr[i-1]+arr[i-2]);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin>>T;
    while(T--) {
        cin>>N;
        ans = arr[N];
        cout<<ans<<"\n";
    }
    return 0;
}