#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,X,Y,Z;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>X>>Y>>Z;
        ll sum = X+Y+Z;
        if(sum & 1LL) {
            cout<<"NO"<<"\n";
        }
        else {
            cout<<"YES"<<"\n";
        }
    }
    return 0;
}