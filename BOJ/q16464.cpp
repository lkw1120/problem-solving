#include<bits/stdc++.h>
using namespace std;
int N,K,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    while(N--) {
        cin>>K;
        if(K%2) {
            cout<<"Gazua"<<"\n";
        }
        else {
            while(1 < K) {
                if(K%2) {
                    cout<<"Gazua"<<"\n";
                    break;
                }
                K/=2;
            }
            if(K == 1) {
                cout<<"GoHanGang"<<"\n";
            }
        }
    }
    return 0;
}