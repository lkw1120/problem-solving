#include<bits/stdc++.h>
using namespace std;
int arr[101][3];
int order[101];
int dp[101][2];
int N;
bool compare(int a, int b) {
    return arr[a][0] > arr[b][0];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for (int i=0;i<N;i++) {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        order[i] = i;
    }
    sort(order,order+N,compare);
    int tmp = 0;
    for(int i=0;i<N;i++) {
        int x = order[i];
        dp[i][0] = arr[x][1];
        dp[i][1] = -1;
        for(int j=0;j<i;j++) {
            int y = order[j];
            if(arr[y][2] >= arr[x][2] && dp[j][0]+arr[x][1] > dp[i][0]) {
                dp[i][0] = dp[j][0]+arr[x][1];
                dp[i][1] = j;
            }
        }
        if(dp[tmp][0] < dp[i][0]) {
            tmp = i;
        }
    }
    vector<int> v;
    for(int i=tmp;i!=-1;i=dp[i][1]) {
        v.push_back(order[i]+1);
    }
    cout<<v.size()<<"\n";
    for(int item: v) {
        cout<<item<<"\n";
    }
    return 0;
}