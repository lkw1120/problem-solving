#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[500001];
int cnt[8001];
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    ll sum = 0;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
        sum+=arr[i];
        cnt[arr[i]+4000]++;
    }
    double avg = (double)sum/N;
    int am = avg < 0? avg-0.5: avg+0.5;
    sort(arr, arr+N);
    int median = arr[N/2];
    int maxCnt = *max_element(cnt,cnt+8001);
    int mode,tmp;
    mode = tmp = 0;
    for(int i=0;i<8001;i++) {
        if(cnt[i] == maxCnt) {
            tmp++;
            mode = i-4000;
            if(tmp == 2) break;
        }
    }
    int range = arr[N-1]-arr[0];
    cout<<am<<"\n";
    cout<<median<<"\n";
    cout<<mode<<"\n";
    cout<<range<<"\n";
    return 0;
}