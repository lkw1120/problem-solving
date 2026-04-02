#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    if(N < 20 || (30 <= N && N <= 39) || N == 59) {
        ans = -1;
    } 
    else {
        ans = N/20;
    }
    cout<<ans<<"\n";
    return 0;
}