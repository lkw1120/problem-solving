#include<bits/stdc++.h>
using namespace std;
int N,A,B,C;
bool check(int a, int b) {
    return ((a+1)%N == b) || ((b+1)%N == a);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>A>>B>>C;
    int d = 0;
    d+=!check(A,B);
    d+=!check(B,C);
    d+=!check(C,A);
    for(int i=0;i<N-3;i++) {
        cin>>A>>B>>C;
    }
    if((d == 1) || (N%2 == 0)) {
        cout<<"TAK"<<"\n";
    }
    else {
        cout<<"NIE"<<"\n";
    }
    return 0;
}