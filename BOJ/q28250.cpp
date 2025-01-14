#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e5+1;
ll arr[MAX];
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
    }
    ll a,b,c;
    a = b = c = 0;
    for(int i=1;i<=N;i++) {
        if(0 == arr[i]) a++;
        if(1 == arr[i]) b++;
        if(2 <= arr[i]) c++;
    }
    ans = 0;
    ans+=a*(a-1)/2;
    ans+=a*b*2;
    ans+=a*c;
    cout<<ans<<"\n";
    return 0;
}