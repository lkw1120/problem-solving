#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        ll a;
        cin>>a;
        v.push_back(63-__builtin_clzll(a)+1);
    }
    for(auto item: v) {
        cout<<item<<" ";
    }
    return 0;
}