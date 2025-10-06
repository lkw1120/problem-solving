#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int a;
    for(int i=0;i<N;i++) {
        cin>>a;
    }
    if((a-N) & 1) {
        cout<<"First"<<"\n";
    }
    else {
        cout<<"Second"<<"\n";
    }
    return 0;
}