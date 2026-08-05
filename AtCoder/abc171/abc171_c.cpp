#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
string ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    while(0 < N) {
        N--;
        ans+=('a'+N%26);
        N/=26;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<"\n";
    return 0;
}