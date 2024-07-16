#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
string str;
int N,ans;
void init() {
    string s = "abcdefghi";
    int i = 0;
    do {
        mp[s] = ++i;
    } while(next_permutation(s.begin(),s.end()));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>str;
        ans = mp[str];
        cout<<ans<<"\n";
    }
    return 0;
}