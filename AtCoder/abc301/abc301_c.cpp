#include<bits/stdc++.h>
using namespace std;
int s[26],t[26];
bool check[26];
string atcoder = "atcoder";
string S,T,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>S>>T;
    int size = S.size();
    int sa,ta;
    sa = ta = 0;
    for(int i=0;i<size;i++) {
        if(S[i] == '@') {
            sa++;
        }
        else {
            s[S[i]-'a']++;
        }
    }
    for(int i=0;i<size;i++) {
        if(T[i] == '@') {
            ta++;
        }
        else {
            t[T[i]-'a']++;
        }
    }
    for(auto ch: atcoder) {
        check[ch-'a'] = true;
    }
    bool flag = true;
    for(int i=0;i<26;i++) {
        if(s[i] == t[i]) continue;
        if(!check[i]) {
            flag = false;
            break;
        }
        if(s[i] < t[i]) {
            int cnt = t[i]-s[i];
            sa-=cnt;
        }
        else {
            int cnt = s[i]-t[i];
            ta-=cnt;
        }
        if(sa < 0 || ta < 0) {
            flag = false;
            break;
        }
    }
    ans = flag? "Yes": "No";
    cout<<ans<<"\n";
    return 0;
}