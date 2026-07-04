#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string B;
ll A,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B;
    int b = 0;
    for(char ch: B) {
        if(ch == '.') continue;
        b = b*10+(ch-'0');
    }
    ans = A*b/100;
    cout<<ans<<"\n";
    return 0;
}