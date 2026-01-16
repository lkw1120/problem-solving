#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll T,N,L,ans;
bool check(char c) {
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>str>>N;
        L = str.size();
        ans = 0;
        int len = 0;
        int last = -1;
        for(int i=0;i<L;i++) {
            if(check(str[i])) {
                len++;
            }
            else {
                len = 0;
            }
            if(len >= N) {
                last = i-N+1;
            }
            if(last != -1) {
                ans+=(last+1);
            }
        }
        cout<<"Case #"<<tc<<": "<<ans<<"\n";
    }
    return 0;
}