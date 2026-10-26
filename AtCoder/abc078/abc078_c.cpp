#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    ans = ((M*1900)+((N-M)*100))*pow(2,M);
    cout<<ans<<"\n";
    return 0;
}