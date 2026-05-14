#include<bits/stdc++.h>
using namespace std;
vector<int> a,v;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    a.resize(N+1);
    for(int i=1;i*i<=N;i++) {
        for(int j=i+1;i*i+j*j<=N;j++) {
            int n = i*i+j*j;
            if(a[n] < 2) a[n]++;
        }
    }
    for(int i=1;i<=N;i++) {
        if(a[i] == 1) {
            v.push_back(i);
        }
    }
    int size = v.size();
    cout<<size<<"\n";
    for(auto item: v) {
        cout<<item<<" ";
    }
    cout<<"\n";
    return 0;
}