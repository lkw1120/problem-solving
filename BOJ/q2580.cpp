#include<bits/stdc++.h>
using namespace std;
const int MAX = 9;
vector<pair<int,int>> arr;
int matrix[MAX][MAX] = {0};
int ans[MAX][MAX] = {0};
bool check(int v, int h, int n) {
    for(int h=0;h<MAX;h++) {
        if(matrix[v][h] == n) { 
            return false;
        }
    }
    for(int v=0;v<MAX;v++) {
        if(matrix[v][h] == n) {
            return false;
        }
    }
    v = v/3;
    h = h/3;
    for(int hh=h*3;hh<(h*3)+3;hh++) {
        for(int vv = v*3;vv<(v*3)+3;vv++) {
            if(matrix[vv][hh] == n) {
                return false;
            }
        }
    }
    return true;
}
void sudoku(int i) {
    if(i == arr.size()) {
        for(int v=0;v<MAX;v++) {
            for(int h=0;h<MAX;h++) {
                cout<<matrix[v][h]<<" ";
            }
            cout<<"\n";
        }
        exit(0);
    }
    for(int n=1;n<=MAX;n++) {
        int v = arr[i].first;
        int h = arr[i].second;
        if(check(v,h,n)) {
            matrix[v][h] = n;
            sudoku(i+1);
            matrix[v][h] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) {
            cin>>matrix[i][j];
            if(matrix[i][j] == 0) {
                arr.push_back({i,j});
            }
        }
    }
    sudoku(0);
    return 0;
}