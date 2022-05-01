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

int main() {
    
    int N, M;
    
    scanf("%d %d", &M, &N);
    
    vector<int> arr[N + 2];
    vector<bool> visited[N + 2];
    queue<pair<pair<int, int>, int>> q;
    
    for(int i = 0; i < N + 2; i++){
        for(int j = 0; j < M + 2; j++){
            if(i == 0 || i == N + 1 || j == 0 || j == M + 1){
                arr[i].push_back(-1);
                visited[i].push_back(true);
            }
            else{
                int tempt;
                scanf("%d", &tempt);
                arr[i].push_back(tempt);
                if(tempt == -1 || tempt == 1){
                    if(tempt == 1){
                        q.push(make_pair(make_pair(j, i), 0));
                    }
                    visited[i].push_back(true);
                }
                else{
                    visited[i].push_back(false);
                }
            }
        }
    }
    
    int max_step = 0;
    
    while(!q.empty()){
        pair<pair<int, int>, int> num = q.front();
        q.pop();
        
        int x = num.first.first;
        int y = num.first.second;
        
        int step = num.second;
        
        max_step = max(step, max_step);
        
        if(visited[y][x - 1] == false){
            visited[y][x - 1] = true;
            q.push(make_pair(make_pair(x - 1, y), step + 1));
        }
        if(visited[y][x + 1] == false){
            visited[y][x + 1] = true;
            q.push(make_pair(make_pair(x + 1, y), step + 1));
        }
        if(visited[y - 1][x] == false){
            visited[y - 1][x] = true;
            q.push(make_pair(make_pair(x, y - 1), step + 1));
        }
        if(visited[y + 1][x] == false){
            visited[y + 1][x] = true;
            q.push(make_pair(make_pair(x, y + 1), step + 1));
        }
    }
    
    bool check = true;
    
    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < M + 1; j++){
            if(visited[i][j] == false)
            {
                check = false;
                break;
            }
        }
    }
    
    if(check == false){
        printf("-1\n");
    }
    else{
        printf("%d\n", max_step);
    }
    
    return 0;
}