#include<bits/stdc++.h>
using namespace std;
unordered_map<string,vector<string>> mp;
string str1,str2;
int N,T;
string find(string s1, string s2) {
    queue<pair<string,string>> q;
    q.push({s1,s1.substr(0,1)});
    string res;
    while(!q.empty()) {
        string now = q.front().first;
        string str = q.front().second;
        q.pop();
        if(now == s2) {
            res = str;
            break;
        }
        for(auto next: mp[now]) {
            q.push({next,str+next[0]});
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>T;
    for(int i=0;i<N;i++) {
        cin>>str1>>str2;
        mp[str1].push_back(str2);
        mp[str2].push_back(str1);
    }
    for(int t=0;t<T;t++) {
        cin>>str1>>str2;
        cout<<find(str1,str2)<<"\n";
    }
    return 0;
}