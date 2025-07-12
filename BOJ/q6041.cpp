#include<bits/stdc++.h>
using namespace std;
vector<tuple<string,int,int>> v;
int N,ans;
pair<int,int> check(string str, string g) {
    int c,w;
    c = w = 0;
    vector<char> a,b;
    for(int i=0;i<4;i++) {
        if(str[i] == g[i]) {
            c++;
        }
        else {
            a.push_back(str[i]);
            b.push_back(g[i]);
        }
    }
    map<char,int> cnt;
    for(char x: a) {
        cnt[x]++;
    }
    for(char x: b) {
        if(cnt[x]) { 
            w++; 
            cnt[x]--;
        }
    }
    return {c,w};
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        int g,c,w;
        cin>>g>>c>>w;
        v.push_back({to_string(g), c, w});
    }
    bool flag = false;
    for (int i=1000;i<=9999;i++) {
        string str = to_string(i);
        flag = true;
        for(auto [g,c,w]: v) {
            if(check(str,g) != make_pair(c,w)) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ans = i;
            break;
        }
    }
    if(flag) {
        cout<<ans<<"\n";
    }
    else {
        cout<<"NONE"<<"\n";
    }
    return 0;
}