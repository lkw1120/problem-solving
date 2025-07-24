#include<bits/stdc++.h>
using namespace std;
int arr[500001];
int M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>M;
    for(int i=1;i<=M;i++) {
        cin>>arr[i];
    }
    int max_up,max_down;
    max_up = max_down = 0;
    int up,down;
    up = down = 0;
    for(int i=2;i<=M;i++) {
        if(arr[i-1] < arr[i]) {
            up++;
            max_up = max(max_up,up);
            down = 0;
        }
        else if(arr[i] < arr[i-1]) {
            down++;
            max_down = max(max_down,down);
            up = 0;
        }
    }
    ans = max(max_up,max_down)+1;
    cout<<ans<<"\n";
    return 0;
}