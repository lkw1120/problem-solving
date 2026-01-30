#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    auto pos = str.find('/');
    ll a = stoll(str.substr(0,pos));
    ll b = stoll(str.substr(pos+1));
    ans = "";
    while(a != 1 || b != 1) {
        if(a < b) {
            ans.push_back('L');
            ll na = b-a;
            ll nb = a;
            a = na;
            b = nb;
        } 
        else {
            ans.push_back('R');
            ll na = b;
            ll nb = a-b;
            a = na;
            b = nb;
        }
    }
    cout<<ans<<"\n";
    return 0;
}