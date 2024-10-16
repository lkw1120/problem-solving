#include<bits/stdc++.h>
using namespace std;
int arr[100001];
vector<int> v;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+N);
    int idx = (N-1)/2;
    for(int i=0;i<N;i++) {
        if(i%2) {
            idx+=i;
        }
        else {
            idx-=i;
        }
        v.push_back(arr[idx]);
    }
    for(int i=0;i<N;i++) {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return 0;
}