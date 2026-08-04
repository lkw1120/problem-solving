#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<1000000;i++) {
        string str = to_string(i);
        ll x = stoll(str+str);
        if(x <= N) {
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}