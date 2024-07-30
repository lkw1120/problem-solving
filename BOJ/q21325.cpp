#include<bits/stdc++.h>
using namespace std;
vector<int> v[100001];
bool check[100001];
int N,M,X,ans;
int find(int n) {
    if(check[n]) return 1;
    int res = 0;
    for(auto item: v[n]) {
        res+=find(item);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++) {
        cin>>X;
        v[X].push_back(i);
    }
    for(int i=1;i<=M;i++) {
        cin>>X;
        check[X] = true;
    }
    ans = find(0);
    cout<<ans<<"\n";
    return 0;
}