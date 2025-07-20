#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A,B,C;
bool check(ll x) {
    return 1 < x && (x&(x-1)) == 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>A>>B>>C;
    ll D = B*B-4*A*C;
    if(D <= 0) {
        cout<<"둘다틀렸근"<<"\n";
        return 0;
    }
    ll sqrtD = (ll)(sqrt((double)D)+0.5);
    if(sqrtD*sqrtD != D) {
        cout<<"둘다틀렸근"<<"\n";
        return 0;
    }
    ll num1 = -B+sqrtD;
    ll num2 = -B-sqrtD;
    ll a2 = 2*A;
    if(num1%a2 != 0 || num2%a2 != 0) {
        cout<<"둘다틀렸근"<<"\n";
        return 0;
    }
    if(check(num1/a2) && check(num2/a2)) {
        cout<<"이수근"<<"\n";
    }
    else {
        cout<<"정수근"<<"\n";
    }
    return 0;
}