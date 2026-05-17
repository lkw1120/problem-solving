#include<bits/stdc++.h>
using namespace std;
map<int,int,greater<int>> mp;
vector<int> v;
int N,A;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>A;
        mp[A]++;
    }
    v.resize(N);
    int k = 0;
    for(auto [a,b]: mp) {
        v[k] = b;
        k++;
    }
    for(auto item: v) {
        cout<<item<<"\n";
    }
    return 0;
}