#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    int size = str.size();
    N = stoll(str);
    for(ll i=N-9*size;i<=N;i++) {
        ll n,sum;
        n = sum = i;
        while(n != 0) {
            sum+=n%10;
            n/=10;
        }
        if(sum == N) {
            ans = i;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}