#include<bits/stdc++.h>
using namespace std;
vector<string> v;
string S,T,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>S>>T;
    int size1 = S.size();
    int size2 = T.size();
    for(int i=0;i<size1-size2+1;i++) {
        bool flag = true;
        for(int j=0;j<size2;j++) {
            if(S[i+j] != '?' && S[i+j] != T[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            string str = S;
            for(int j=0;j<size2;j++) {
                str[i+j] = T[j];
            }
            for(int j=0;j<size1;j++) {
                if(str[j] == '?') str[j] = 'a';
            }
            v.push_back(str);
        }
    }
    if(v.empty()) {
        ans = "UNRESTORABLE";
    }
    else {
        sort(v.begin(),v.end());
        ans = v[0];
    }
    cout<<ans<<"\n";
    return 0;
}