#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
string str1,str2;
int N,ans;
int find(string a, string b) {
    while(a.size()) {
        if(a == b) {
            return 1;
        }
        a = mp[a];
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N-1;i++) {
        cin>>str1>>str2;
        mp[str1] = str2;
    }
    cin>>str1>>str2;
    if(str1 == "object" || str2 == "object") {
        ans = 1;
    }
    else {
        ans = find(str1,str2) || find(str2,str1);
    }
    cout<<ans<<"\n";
    return 0;
}