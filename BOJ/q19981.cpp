#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll x;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>x;
    if(x == 0) {
        cout<<1<<"\n";
        cout<<0<<"\n";
    }
    else {
        while(x != 0){
            int bit = x&1;
            v.push_back(bit);
            x = (x-bit)/-2;
        }
        int n = v.size();
        cout<<n<<"\n";
        for(auto item: v) {
            cout<<item<<" ";
        }
    }
    return 0;
}