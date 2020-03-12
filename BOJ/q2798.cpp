#include<bits/stdc++.h>
using namespace std;
int card[100] = {0};
int N,M,ans;
void selectCard(bool* selected, int cnt, int sum) {
    if(cnt == 3) {
        if(ans < sum && sum <= M) ans = sum;
        return ;
    }
    else {
        for(int i=0;i<N;i++) {
            if(!selected[i]) {
                selected[i] = true;
                selectCard(selected,cnt+1,sum+card[i]);
                selected[i] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<N;i++) { 
        cin>>card[i];
    }
    ans = 0;
    bool selected[N] = {false};
    selectCard(selected,0,0);
    cout<<ans<<"\n";
    return 0;
}