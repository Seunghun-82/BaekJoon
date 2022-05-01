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

int bfs(vector<int> arr[], int M, int N, vector<pair<int, int>> virus){
    
    queue<pair<int, int>> q;
    
    auto size = virus.size();
    
    for(auto i = 0; i < size; i++){
        q.push(virus[i]);
    }
    
    while(!q.empty()){
        
        pair<int, int> idx = q.front();
        q.pop();
        
        if(idx.first == 0 || idx.first == M + 1 || idx.second == 0 || idx.second == N + 1){
            continue;
        }
        else{
            int x = idx.first;
            int y = idx.second;
            if(arr[y][x - 1] == 0){
                arr[y][x - 1] = 2;
                q.push(make_pair(x - 1, y));
            }
            if(arr[y][x + 1] == 0){
                arr[y][x + 1] = 2;
                q.push(make_pair(x + 1, y));
            }
            if(arr[y - 1][x] == 0){
                arr[y - 1][x] = 2;
                q.push(make_pair(x , y - 1));
            }
            if(arr[y + 1][x] == 0){
                arr[y + 1][x] = 2;
                q.push(make_pair(x, y + 1));
            }
        }
        
    }
    
    int security = 0;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(arr[i][j] == 0){
                security++;
            }
        }
    }
    
    return security;
}

void initialize(vector<int> arr[], vector<int> copy[], int M, int N){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            arr[i][j] = copy[i][j];
        }
    }
    
    return;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<int> arr[N + 2];
    vector<int> copy[N + 2];
    
    vector<pair<int, int>> virus;
    
    for(int i = 0; i < N + 2; i++){
        for(int j = 0; j < M + 2; j++){
            if(i == 0 || i == N + 1){
                arr[i].push_back(1);
                copy[i].push_back(1);
            }
            else if (j == 0 || j == M + 1){
                arr[i].push_back(1);
                copy[i].push_back(1);
            }
            else{
                int tmp;
                cin >> tmp;
                if(tmp == 2){
                    virus.push_back(make_pair(j, i));
                }
                arr[i].push_back(tmp);
                copy[i].push_back(tmp);
            }
        }
    }
    
    int max_security = 0;
    
    for(int i = 0; i < N * M; i++){
        for(int j = i + 1; j < N * M; j++){
            for(int k = j + 1; k < N * M; k++){
                pair<int, int> first_index = make_pair(i % M + 1, i / M + 1 );
                pair<int, int> second_index = make_pair(j % M + 1, j / M + 1);
                pair<int, int> third_index = make_pair(k % M + 1, k / M + 1);
                if(arr[first_index.second][first_index.first] != 0){
                    continue;
                }
                if(arr[second_index.second][second_index.first] != 0){
                    continue;
                }
                if(arr[third_index.second][third_index.first] != 0){
                    continue;
                }
                
                arr[first_index.second][first_index.first] = 1;
                arr[second_index.second][second_index.first] = 1;
                arr[third_index.second][third_index.first] = 1;
                
                int tmp_security = bfs(arr, M, N, virus);
                max_security = max(max_security, tmp_security);
                initialize(arr, copy, M, N);
            }
        }
    }
    
    cout << max_security << "\n";
    
    return 0;
}