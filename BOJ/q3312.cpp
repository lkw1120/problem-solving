#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str1,str2;
vector<int> v[26];
int N,M;
ll ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str1>>str2;
    M = str1.size();
    N = str2.size();
    for(int i=0;i<M;i++) {
        v[str1[i]-'a'].push_back(i);
    }
    int tmp = N-M;
    ans = 0;
    for(int j=0;j<N;j++) {
        int a = str2[j]-'a';
        int low = max(0,j-tmp);
        int high = min(M-1,j);
        auto h = upper_bound(v[a].begin(),v[a].end(),high);
        auto l = lower_bound(v[a].begin(),v[a].end(),low); 
        ans+=h-l;
    }
    cout<<ans<<"\n";
    return 0;
}