#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
ll P,Q,N;
string ans;
char change(int x) {
    if(0 <= x && x <= 9) {
        return '0'+x;
    }
    x-=10;
    if(0 <= x && x <= 25) {
        return 'A'+x;
    }
    x-=26;
    return 'a'+x;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>P>>Q>>N;
    while(0 < N) {
        int x = N%P;
        v.push_back(x);
        N = (N-x)/P;
        N = N*Q;
    }
    reverse(v.begin(),v.end());
    ans = "";
    for(auto item: v) {
        ans+=change(item);
    }
    cout<<ans<<"\n";
    return 0;
}