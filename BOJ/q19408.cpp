#include<bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    if(N < 4) {
        cout<<-1<<"\n";
    }
    else {
        cout<<4<<" "<<2<<" "<<3<<" "<<1;
        for(int i=5;i<=N;i++) {
            cout<<" "<<i;
        }
        cout<<"\n";
    }
    return 0;
}