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

void bfs(vector<int> arr[], vector<int> visited[], int M, int N){
    
    pair<pair<int, int>, int> tmp = make_pair(make_pair(1, 1), 0);
    
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>,int>> ,cmp> q;
    
    q.push(tmp);
    
    visited[1][1] = 0;
    
    while(!q.empty()){
        pair<pair<int, int>, int> idx = q.top();
        q.pop();
        
        int x = idx.first.first;
        int y = idx.first.second;
        
        int broken = idx.second;
        
        if(x == M && y == N){
            cout << broken << "\n";
            return;
        }
        
        if(x < M && (visited[y][x + 1] != -1 && (visited[y][x + 1] > broken + arr[y][x + 1]))){
            visited[y][x + 1] = broken + arr[y][x + 1];
            q.push(make_pair(make_pair(x + 1, y), broken + arr[y][x + 1]));
        }
        if(x > 1 && (visited[y][x - 1] != -1 && (visited[y][x - 1] > broken + arr[y][x - 1]))){
            visited[y][x - 1] = broken + arr[y][x - 1];
            q.push(make_pair(make_pair(x - 1, y), broken + arr[y][x - 1]));
        }
        if(y < N && (visited[y + 1][x] != -1 && (visited[y + 1][x] > broken + arr[y + 1][x]))){
            visited[y + 1][x] = broken + arr[y + 1][x];
            q.push(make_pair(make_pair(x, y + 1), broken + arr[y + 1][x]));
        }
        if(y > 1 && (visited[y - 1][x] != -1 && (visited[y - 1][x] > broken + arr[y - 1][x]))){
            visited[y - 1][x] = broken + arr[y - 1][x];
            q.push(make_pair(make_pair(x, y - 1), broken + arr[y - 1][x]));
        }
        
    }
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int M, N;
    
    cin >> M >> N;
    
    vector<int> arr[N + 2];
    vector<int> visited[N + 2];
    
    for(int i = 0; i < N + 2; i++){
        if(i == 0 || i == N + 1){
            arr[i].push_back(0);
            visited[i].push_back(-1);
        }
        else{
            string tmp;
            cin >> tmp;
            arr[i].push_back(0);
            visited[i].push_back(-1);
            for(int j = 0; j < M; j++){
                if(tmp[j] == '0'){
                    arr[i].push_back(0);
                }
                else{
                    arr[i].push_back(1);
                }
                visited[i].push_back(100000);
                
            }
            arr[i].push_back(0);
            visited[i].push_back(-1);
        }
    }
    
    bfs(arr, visited, M, N);
    
    return 0;
}