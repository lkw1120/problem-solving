#include<bits/stdc++.h>
using namespace std;
int arr[501];
vector<int> v;
int N,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        int a,b;
        cin>>a>>b;
        arr[b]++;
    }
    for(int i=1;i<=N;i++) {
        if(arr[i] == 0) {
            v.push_back(i);
        }
    }
    cout<<v.size()<<"\n";
    for(auto item: v) {
        cout<<item<<" ";
    }
    cout<<"\n";
    return 0;
}