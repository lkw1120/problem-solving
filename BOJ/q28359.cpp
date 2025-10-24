#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    vector<int> cnt(N+1,0);
    int sum = 0;
    for(int i=0;i<N;i++) {
        cin>>v[i];
        sum+=v[i];
        cnt[v[i]]++;
    }
    int tmp = 0;
    for(int i=1;i<=N;i++) {
        tmp = max(tmp,i*cnt[i]);
    }
    sort(v.begin(),v.end());
    ans = sum+tmp;
    cout<<ans<<"\n";
    for(auto item: v) {
        cout<<item<<" ";
    }
    cout<<"\n";
    return 0;
}