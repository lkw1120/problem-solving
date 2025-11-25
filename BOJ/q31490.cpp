#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M,N,A,B;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N;
    A = B = 0;
    for(int i=0;i<M;i++) {
        ll a;
        cin>>a;
        A+=a+1;
    }
    for(int i=0;i<N;i++) {
        ll b;
        cin>>b;
        B+=b+1;
    }
    if(A > B) {
        cout<<"ALICE"<<"\n";
    } 
    else if(A == B) {
        cout<<"TIED"<<"\n";
    } 
    else {
        cout<<"BOB"<<"\n";
    }
    return 0;
}