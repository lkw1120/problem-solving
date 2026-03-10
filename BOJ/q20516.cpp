#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll k = N/3;
    ll a,b,c;
    if(N%3 == 0) {
        a = k-1;
        b = k;
        c = k+1;
    }
    else if(N%3 == 1) {
        a = k-1;
        b = k;
        c = k+2;
    } 
    else {
        a = k-1;
        b = k+1;
        c = k+2;
    }
    cout<<a<<" "<<b<<" "<<c<<"\n";
    return 0;
}