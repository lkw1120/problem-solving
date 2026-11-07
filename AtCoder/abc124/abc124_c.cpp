#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string str;
int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    int size = str.size();
    int cnt1,cnt2;
    cnt1 = cnt2 = 0;
    for(int i=0;i<size;i++) {
        if(i%2) {
            s1+="0";
            s2+="1";
        }
        else {
            s1+="1";
            s2+="0";
        }
        if(s1[i] != str[i]) {
            cnt1++;	
        }
        if(s2[i] != str[i]) {
            cnt2++;	
        }
    }
    ans = min(cnt1,cnt2);
    cout<<ans<<"\n";
    return 0;
}