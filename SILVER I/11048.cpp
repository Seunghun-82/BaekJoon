//
//  main.cpp
//  BaekJoon
//
//  Created by seunghun on 2022/03/10.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        return a.second > b.second;
    }
};

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second;
}

void bfs(vector<int> arr[], int M, int N, pair<int, int> coin[]){
    
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    
    cin >> N >> M;
    
    vector<int> arr[N + 2];
    
    for(int i = 0; i < N + 2; i++){
        if(i == 0 || i == N + 1){
            for(int j = 0; j < M + 2; j++){
                arr[i].push_back(0);
            }
        }
        else{
            for(int j = 0; j < M + 2; j++){
                if(j == 0 || j == M + 1){
                    arr[i].push_back(0);
                }
                else{
                    int tmp;
                    cin >> tmp;
                    arr[i].push_back(tmp);
                }
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            arr[i][j] = max(max(arr[i - 1][j], arr[i - 1][j - 1]),
                            arr[i][j - 1]) + arr[i][j];
        }
    }

    cout << arr[N][M] << "\n";
    
    return 0;
}