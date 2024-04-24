#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>M;
        v.push_back({M,i+1});
    }
    sort(v.begin(),v.end());
    for(auto item: v) {
        cout<<item.first-item.second<<"\n";
    }
    return 0;
}