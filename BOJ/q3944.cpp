#include<bits/stdc++.h>
using namespace std;
string str;
int T,B,ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>B>>str;
        int size = str.size();
        ans = 0;
        for(int i=0;i<size;i++) {
            ans+=str[i]-'0';
        }
        ans%=B-1;
        cout<<ans<<"\n";
    }
    return 0;
}