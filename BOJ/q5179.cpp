#include<bits/stdc++.h>
using namespace std;
int solved[501];
int score[501];
int failed[501][11];
bool solvedProblem[501][11];
int K,M,N,P;
bool compare(int a, int b) {
    if(solved[a] != solved[b]) {
        return solved[a] > solved[b];
    }
    else {
        return score[a] < score[b];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>K;
    for(int k=1;k<=K;k++) {
        fill(solved,solved+501,0);
        fill(score,score+501,0);
        fill_n(&failed[0][0],501*11,0);
        fill_n(&solvedProblem[0][0],501*11,0);
        cin>>M>>N>>P;
        for(int i=0;i<N;i++) {
            int p,t,j;
            char m;
            cin>>p>>m>>t>>j;
            int idx = m - 'A';
            if(!solvedProblem[p][idx]) {
                if(j == 1) {
                    solvedProblem[p][idx] = true;
                    solved[p]++;
                    score[p]+=t+failed[p][idx]*20;
                } 
                else {
                    failed[p][idx]++;
                }
            }
        }
        vector<int> v;
        for (int i=1;i<=P;i++) {
            v.push_back(i);
        }
        sort(v.begin(),v.end(),compare);
        cout<<"Data Set "<<k<<":\n";
        for(auto p: v) {
            cout<<p<<" "<<solved[p]<<" "<<score[p]<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}