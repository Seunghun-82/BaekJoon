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

bool compare(int a, int b) {
    return a > b;
}

void dfs(vector<int> node[], vector<bool>& visited, int num, int& visited_num){
    visited[num] = true;
    visited_num++;
    for(int i = 0; i < node[num].size(); i++){
        if(visited[node[num][i]] == false){
            dfs(node, visited, node[num][i], visited_num);
        }
    }
    
    return;
}

int main() {
    
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    vector<int> node[N + 1];
    vector<bool> visited(N+1);
    int visited_num = 0;
    
    for(int i = 0; i < M; i++){
        int node_1, node_2;
        scanf("%d %d", &node_1, &node_2);
        node[node_1].push_back(node_2);
        node[node_2].push_back(node_1);
    }
    
    int output = 0;
    
    int num = 1;
    
    while(visited_num != N){
        dfs(node, visited, num, visited_num);
        
        for(int i = 1; i <= N; i++){
            if(visited[i] == false){
                num = i;
                break;
            }
        }
        
        output++;
    }
    
    printf("%d\n", output);
    
    return 0;
}