#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,M,L,R;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int tmp = INT_MAX;
    for(int i=0;i<M;i++) {
        cin>>L>>R;
        tmp = min(tmp,R-L+1);
    }
    for(int i=0;i<N;i++) {
        v.push_back(i%tmp+1);
    }
    for(auto item: v) {
        cout<<item<<" ";
    }
    cout<<"\n";
    return 0;
}