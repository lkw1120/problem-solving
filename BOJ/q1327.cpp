#include<bits/stdc++.h>
using namespace std;
vector<int> v;
map<string,bool> mp;
int N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    bool flag = true;
    for(int i=0;i<N;i++) {
        flag = (i+1 != v[i])? false: flag;
    }
    ans = -1;
    if(flag) {
        ans = 0;
    }
    else {
        string str = "";
        string res = "";
        for(int i=0;i<N;i++) {
            str+='0'+v[i];
            res+='0'+i+1;
        }
        queue<pair<string,int>> q;
        q.push({str,0});
        mp[str] = true;
        while(!q.empty()) {
            str = q.front().first;
            int d = q.front().second;
            q.pop();
            if(str == res) {
                ans = d;
                break;
            }
            for(int i=0;i<N-K+1;i++) {
                string tmp = str;
                reverse(tmp.begin()+i,tmp.begin()+i+K);
                if(!mp[tmp]) {
                    mp[tmp] = true;
                    q.push({tmp,d+1});
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}