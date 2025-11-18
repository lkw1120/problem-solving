#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> games;
int score[5];
bool played[5][5];
int T,G,ans;
void dfs(int idx) {
    if(idx == games.size()) {
        for(int i=1;i<=4;i++) {
            if(i == T) continue;
            if(score[i] >= score[T]) {
                return;
            }
        }
        ans++;
        return;
    }
    auto [a,b] = games[idx];

    score[a]+=3;
    dfs(idx+1);
    score[a]-=3;

    score[b]+=3;
    dfs(idx+1);
    score[b]-=3;

    score[a]+=1;
    score[b]+=1;
    dfs(idx+1);
    score[a]-=1;
    score[b]-=1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T>>G;
    for (int i=0;i<G;i++) {
        int A,B,scoreA,scoreB;
        cin>>A>>B>>scoreA>>scoreB;
        played[A][B] = played[B][A] = true;
        if(scoreA > scoreB) {
            score[A]+=3;
        }
        else if(scoreA < scoreB) {
            score[B]+=3;
        }
        else {
            score[A]+=1;
            score[B]+=1;
        }
    }
    for(int i=1;i<=4;i++) {
        for(int j=i+1;j<=4;j++) {
            if(!played[i][j]) {
                games.push_back({i,j});
            }
        }
    }
    dfs(0);
    cout<<ans<<"\n";
    return 0;
}