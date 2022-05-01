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

bool compare(pair<long long int, int> a, pair<long long int, int> b) {
    return a.first < b.first;
}

int max_v = -1000000;

vector<int> table[12];
vector<bool> visited[12];

void dfs(int N, int M, int K, int sum_v, int len){
    
    if(len == K){
        max_v = max(sum_v, max_v);
        return;
    }
    
    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < M + 1; j++){
            if(visited[i][j] == false){
                
                bool arr[4];
                
                visited[i][j] = true;
                
                arr[0] = visited[i - 1][j];
                arr[1] = visited[i + 1][j];
                arr[2] = visited[i][j - 1];
                arr[3] = visited[i][j + 1];
                
                visited[i - 1][j] = true;
                visited[i + 1][j] = true;
                visited[i][j - 1] = true;
                visited[i][j + 1] = true;
                dfs(N, M, K, sum_v + table[i][j], len + 1);
                visited[i][j] = false;
                visited[i - 1][j] = arr[0];
                visited[i + 1][j] = arr[1];
                visited[i][j - 1] = arr[2];
                visited[i][j + 1] = arr[3];
            }
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, K;
    int sum_v = 0;
    
    cin >> N >> M >> K;

    for(int i = 0; i < N + 2; i++){
        for(int j = 0; j < M + 2; j++){
            if(i == 0 || j == 0 || i == N + 1 || j == M + 1){
                table[i].push_back(-100000);
            }
            else{
                int tmp;
                cin >> tmp;
                table[i].push_back(tmp);
            }
            visited[i].push_back(false);
        }
    }
    
    dfs(N, M, K, sum_v, 0);
    
    cout << max_v << "\n";
    
}