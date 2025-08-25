#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX];
vector<int> v;
int N,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1;i<=M;i++) {
        cin>>arr[i];
    }
    for(int i=1;i<=M;i++) {
        int cnt = arr[i]-arr[i-1];
        while(0 < cnt) {
            v.push_back(i);
            cnt--;
        }
    }
    for(int i=0;i<N;i++) {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return 0;
}