#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000];
int N,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int cnt0,cnt1;
    cnt0 = cnt1 = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin>>arr[i][j];
            if(arr[i][j]) {
                cnt1++;
            }
            else {
                cnt0++;
            }
        }
    }
    auto check = [&]() {
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(i+1 < N && arr[i][j] == arr[i+1][j]) {
                    return true;
                }
                if(j+1 < M && arr[i][j] == arr[i][j+1]) {
                    return true;
                }
            }
        }
        return false;
    };
    if(cnt0%2 == 0 && cnt1%2 == 0 && check()) {
        cout<<1<<"\n";
    } 
    else {
        cout<<-1<<"\n";
    }
    return 0;
}