#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int arr[MAX];
int sum[MAX];
int low[MAX];
double avg[MAX];
vector<int> v;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>arr[i];
        sum[i] = sum[i-1]+arr[i];
        low[i] = arr[i];
    }
    for(int i=N-1;i>0;i--) {
        low[i] = min(low[i+1],low[i]);
    }
    double tmp = 0;
    for(int i=2;i<N;i++) {
        avg[i] = (double)(sum[N]-sum[i-1]-low[i])/(N-i);
        tmp = max(avg[i],tmp);
    }
    for(int i=1;i<=N;i++) {
        if(tmp == avg[i]) {
            v.push_back(i-1);
        }
    }
    for(auto res: v) {
        cout<<res<<"\n";
    }
    return 0;
}