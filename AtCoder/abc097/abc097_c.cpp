#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> v;
ll K;
string S,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>S>>K;
    int size = S.size();
    for(int i=0;i<size;i++) {
        for(int j=1;j<=5;j++) {
            v.push_back(S.substr(i,j));
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    ans = v[K-1];
    cout<<ans<<"\n";
    return 0;
}