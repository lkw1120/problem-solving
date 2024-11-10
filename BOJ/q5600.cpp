#include<bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>> v[2];
int arr[301];
int A,B,C,N,X,Y,Z,R;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>A>>B>>C;
    cin>>N;
    fill(arr,arr+301,2);
    for(int i=0;i<N;i++) {
        cin>>X>>Y>>Z>>R;
        v[R].push_back({X,Y,Z});
    }
    for(auto [a,b,c]: v[1]) {
        arr[a] = 1;
        arr[b] = 1;
        arr[c] = 1;
    }
    for(auto [a,b,c]: v[0]) {
        if(arr[a] == 1 && arr[b] == 1) {
            arr[c] = 0;
        }
        if(arr[a] == 1 && arr[c] == 1) {
            arr[b] = 0;
        }
        if(arr[b] == 1 && arr[c] == 1) {
            arr[a] = 0;
        }
    }
    for(int i=1;i<=A+B+C;i++) {
        cout<<arr[i]<<"\n";
    }
    return 0;
}