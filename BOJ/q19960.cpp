#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    if(N <= 5) {
        cout<<-1<<"\n";
    }
    else {
        for(int i=0;i<N-4;i++) cout<<0<<" ";
        cout<<"1 0 1 1"<<"\n";
    }
    return 0;
}