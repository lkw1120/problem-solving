#include<bits/stdc++.h>
using namespace std;
string S;
int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>S;
    ans = 0;
    bool flag = false;
    for(char ch: S) {
        if(ch == '0') {
            flag = true;
        }
        else if(ch == '+') {
            if(!flag) {
                ans++;
            }
            flag = false;
        }
    }
    if(!flag) {
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}