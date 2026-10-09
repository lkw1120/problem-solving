#include<bits/stdc++.h>
using namespace std;
vector<int> a,b,v;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    a.resize(N);
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>a[i];
        v[i] = a[i];
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(auto item: a) {
        auto it = lower_bound(v.begin(),v.end(),item);
        b.push_back(it-v.begin());
    }
    for(auto item: b) {
        cout<<item<<"\n";
    }
    return 0;
}