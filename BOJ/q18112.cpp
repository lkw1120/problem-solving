#include<bits/stdc++.h>
using namespace std;
map<int,bool> mp;
string str1,str2;
int N,M,ans;
string makeString(int n) {
    string str;
    while(n) {
        str+='0'+n%2;
        n/=2;
    }
    reverse(str.begin(),str.end());
    return str;
}
int makeInt(string str) {
    int n = 0;
    for(auto ch: str) {
        n<<=1;
        if(ch == '1') n++;
    }
    return n;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>str1>>str2;
    N = makeInt(str1);
    queue<pair<int,int>> q;
    q.push({N,0});
    mp[N] = true;
    while(!q.empty()) {
        int n = q.front().first;
        int t = q.front().second;
        q.pop();
        if(makeString(n) == str2) {
            ans = t;
            break;
        }
        else {
            string str = makeString(n);
            int size = str.size();
            for(int i=0;i<size-1;i++) {
                int m = n^1<<i;
                if(!mp[m]) {
                    mp[m] = true;
                    q.push({m,t+1});
                }
            }
            if(n < 1024 && !mp[n+1]) {
                mp[n+1] = true;
                q.push({n+1,t+1});
            }
            if(0 < n && !mp[n-1]) {
                mp[n-1] = true;
                q.push({n-1,t+1});
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}