#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    v.resize(K);
    int cnt = 0;
    for(int i=0;i<K;i++) {
        cin>>v[i];
        if(v[i] == 0) cnt++;
    }
    sort(v.begin(),v.end());
    int l,r;
    l = r = cnt;
    ans = 1+cnt;
    while(l <= r) {
        if(r == K) break;
        int tmp = v[r]-v[l]-1-(r-l-1);
        if(cnt < tmp) {
            l++;
        }
        else {
            ans = max(ans,v[r]-v[l]+1-tmp+cnt);
            r++;
        }
    }
    cout<<ans<<"\n";
    return 0;

}