#include<bits/stdc++.h>
using namespace std;
int N,num,cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    vector<int> v(N+1,0);
    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j+=i) {
            v[j]++;
        }
    }
    num = cnt = 0;
    for(int i=1;i<=N;i++) {
        if(cnt < v[i]) {
            cnt = v[i];
            num = i;
        }
    }
    cout<<num<<"\n";
    cout<<cnt<<"\n";
    return 0;
}