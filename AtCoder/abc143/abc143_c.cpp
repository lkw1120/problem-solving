#include<bits/stdc++.h>
using namespace std;
string str;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>str;
    char ch;
    ch = str[0];
    ans = 1;
    for(int i=1;i<N;i++) {
        if(ch != str[i]) {
           ans++;
           ch = str[i];
        }
    }
    cout<<ans<<"\n";
    return 0;
}