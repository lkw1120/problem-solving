#include<bits/stdc++.h>
using namespace std;
int A[100003];
int B[100003];
int arr[1000003];
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
        B[i] = A[i];
    }
    sort(B+1,B+N+1);
    int MAX = B[N];
    int now,cnt;
    now = B[1];
    cnt = 1;
    for(int i=2;i<=N+1;i++) {
        if(B[i] != now || i == N+1) {
            for(int j=1;j*now<=MAX;j++) {
                arr[j*now]+=cnt;
            }
            now = B[i];
            cnt = 1;
        }
        else {
            cnt++;
        }
    }
    for(int i=1;i<=N;i++) {
        cout<<arr[A[i]]-1<<"\n";
    }
    return 0;
}