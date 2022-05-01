//
//  main.cpp
//  BaekJoon
//
//  Created by seunghun on 2022/03/10.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

void dfs(vector<int> node[], vector<bool>& visited, int num){
    visited[num] = true;
    for(auto i = 0; i < node[num].size(); i++){
        if(visited[node[num][i]] == false){
            dfs(node, visited, node[num][i]);
        }
    }
    
    return;
}

int main() {

    int com, N;
    
    scanf("%d\n", &com);
    scanf("%d\n", &N);
    

    vector<int> node[com + 1];
    
    vector<bool> visited(com + 1);
    
    for(int i = 0; i < N; i++){
        int node_1, node_2;
        scanf("%d %d\n", &node_1, &node_2);
        node[node_1].push_back(node_2);
        node[node_2].push_back(node_1);
    }
    
    dfs(node, visited, 1);
    
    int output = 0;
    
    for(auto i = 1; i <= com; i++){
        if(visited[i] == true){
            output++;
        }
    }
    
    printf("%d\n", output - 1);
    
    return 0;
}