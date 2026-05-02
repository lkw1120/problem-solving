#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll N,L,R,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>L>>R;
    cin>>str;
    vector<int> idx[26];
    for(int i=0;i<str.size();i++) {
        idx[str[i]-'a'].push_back(i);
    }
    ans = 0;
    for(int i=0;i<26;i++) {
        auto &v = idx[i];
        for(int j=0;j<v.size();j++) {
            int l = v[j]+L;
            int r = v[j]+R;
            auto left = lower_bound(v.begin(),v.end(),l);
            auto right = upper_bound(v.begin(),v.end(),r);
            ans+=(right-left);
        }
    }
    cout<<ans<<"\n";
    return 0;
}