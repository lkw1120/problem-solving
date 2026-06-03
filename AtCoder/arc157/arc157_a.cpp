#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,A,B,C,D;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>A>>B>>C>>D;
    if(B == 0 && C == 0) {
        if(A == N-1 || D == N-1) {
            cout<<"Yes"<<"\n";
        }
        else {
            cout<<"No"<<"\n";
        }
    } 
    else {
        if(abs(B-C) <= 1) {
            cout<<"Yes"<<"\n";
        }
        else {
            cout<<"No"<<"\n";
        }
    }
    return 0;
}