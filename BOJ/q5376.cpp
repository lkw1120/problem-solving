#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll T,X,Y;
ll power(ll n, ll m) {
    ll res = 1;
    while(m--) {
        res*=n;
    }
    return res;
}
ll gcd(ll a, ll b) {
    return b == 0? a: gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>str;
        str = str.substr(2);
        ll size = str.size();
        ll a,b,n,m;
        a = b = -1;
        for(int i=0;i<size;i++) {
            if(str[i] == '(') a = i;
            if(str[i] == ')') b = i;
        }
        if(a < 0 && b < 0) {
            n = stoi(str);
            m = power(10,size);
        }
        else {
            string s1,s2;
            s1 = str.substr(0,a);
            s2 = str.substr(a+1,b-a-1);
            ll size1,size2;
            size1 = s1.size();
            size2 = s2.size();
            if(size1 == 0) {
                n = stoi(s2);
                m = power(10,size2)-1;
            }
            else {
                ll x,y,p;
                p = power(10,size2);
                x = stoi(s1)*p+stoi(s2);
                y = stoi(s1);
                n = x-y;
                m = power(10,size1+size2)-power(10,size1);
            }
        }
        ll d = gcd(n,m);
        X = n/d;
        Y = m/d;
        cout<<X<<"/"<<Y<<"\n";
    }
    return 0;
}