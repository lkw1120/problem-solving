#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
unordered_set<string> st;
string s0,s1,s2;
int N,ans;
int find(string s) {
    queue<string> q;
    q.push(s);
    int cnt = 0;
    while(!q.empty()) {
        string now = q.front();
        q.pop();
        if(!st.count(mp[now])) {
            cnt++;
            st.insert(mp[now]);
            q.push(mp[now]);
        }
    }
    if(st.count(s)) {
        return cnt; 
    }
    else {
        return 0;   
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>s0>>s1>>s2;
        mp[s1] = s2;
    }
    ans = 0;
    for(auto [a,b]:mp) {
        if(!st.count(a)) {
            ans = max(ans,find(a));
        }
    }
    if(0 < ans) {
        cout<<ans<<"\n";
    }
    else {
        cout<<"No trades possible"<<"\n";
    }
    return 0;
}