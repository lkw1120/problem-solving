#include<bits/stdc++.h>
using namespace std;
int prefix[200002];
int N,T,X,Y;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    prefix[1] = 1;
    for(int i=2;i<=N+1;i++) {
        cin>>T>>X>>Y;
        int cnt = prefix[Y] - prefix[X-1];
        bool flag;
        if(T == 1) {
            flag = (cnt == (Y-X+1));
        }
        else {
            flag = (cnt == 0);
        }
        prefix[i] = prefix[i-1];
        if(flag) prefix[i]++;
        if(flag) {
            cout<<"Yes"<<"\n";
        }
        else {
            cout<<"No"<<"\n";
        }
    }
    return 0;
}