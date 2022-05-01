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

vector<int> dfs_output;
vector<int> bfs_output;

void dfs(vector<int> node[], vector<bool>& visited_dfs, int num){
    visited_dfs[num] = true;
    dfs_output.push_back(num);
    for(auto i = 0; i < node[num].size(); i++){
        if(visited_dfs[node[num][i]] == false){
            dfs(node, visited_dfs, node[num][i]);
        }
    }
    return;
}

void bfs(vector<int> node[], vector<bool>& visited_bfs, int num){
    queue<int> q;
    q.push(num);
    visited_bfs[num] = true;
    
    while(!q.empty()){
        int nod = q.front();
        q.pop();
    
        bfs_output.push_back(nod);
        
        for(auto i = 0; i < node[nod].size(); i++){
            if(visited_bfs[node[nod][i]] == false){
                q.push(node[nod][i]);
                visited_bfs[node[nod][i]] = true;
            }
        }
        
    }
    
    return;
}

bool compare(int a, int b) {
    return a > b;
}

int main() {
    
    int N, M, V;
    
    scanf("%d %d %d\n", &N, &M, &V);
    
    vector<int> node[N + 1];
    vector<bool> visited_bfs;
    vector<bool> visited_dfs;
    
    for(auto i = 0 ; i < M; i++){
        int node_1, node_2;
        scanf("%d %d\n", &node_1, &node_2);
        node[node_1].push_back(node_2);
        node[node_2].push_back(node_1);
    }
    
    for(auto i = 0; i <= N; i++){
        sort(node[i].begin(), node[i].end());
        visited_bfs.push_back(false);
        visited_dfs.push_back(false);
    }
    
    dfs(node, visited_dfs, V);
    bfs(node, visited_bfs, V);
    
    for(auto i = 0; i < dfs_output.size(); i++){
        printf("%d ", dfs_output[i]);
    }
    
    printf("\n");
    
    for(auto i = 0; i < bfs_output.size(); i++){
        printf("%d ", bfs_output[i]);
    }
    
    return 0;
}