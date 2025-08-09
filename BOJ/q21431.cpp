#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
ll N,K;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K;
    v.resize(N-1,1);
    while(true) {
        ll sum = 0;
        int size = v.size();
        for(int i=size-(N-1);i<size;i++) {
            sum+=v[i];
        }
        if(K < sum) break;
        v.push_back(sum);
    }
    cout<<v.size()<<"\n";
    for(auto item: v) {
        cout<<item<<" ";
    }
    cout<<"\n";
    return 0;
}