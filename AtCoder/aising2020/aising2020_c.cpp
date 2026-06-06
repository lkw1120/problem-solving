#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N+1);
    for(int i=1;i<=100;i++) {
        for(int j=1;j<=100;j++) {
            for(int k=1;k<=100;k++) {
                int n = i*i+j*j+k*k+i*j+j*k+k*i;
                if(n <= N) {
                    v[n]++;
                }
            }
        }
    }
    for(int i=1;i<=N;i++) {
        cout<<v[i]<<"\n";
    }
    return 0;
}