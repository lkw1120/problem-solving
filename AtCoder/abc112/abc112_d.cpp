#include<bits/stdc++.h>
using namespace std;
int N,M,ans;
vector<int> submultiples(int n) {
    vector<int> res;
    for(int i=1;1LL*i*i<=n;i++) {
        if (n%i == 0) {
            res.push_back(i); 
            if (i*i != n) {
                res.push_back(n/i);
            }
        }
    }
    sort(res.begin(),res.end());
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    ans = 0;
    auto list = submultiples(M);
    for(auto div:list) {
        if(N <= M/div) {
            ans = max(ans,div);
        }
    }
    cout<<ans<<"\n";
    return 0;
}