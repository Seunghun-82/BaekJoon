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

vector<int> output;

bool dfs(vector<int> edge[], vector<bool>& visited, int num, int dest){
    
    visited[num] = true;
    if(num == dest){
        return true;
    }
    
    bool check = false;
    
    for(int i = 0; i < edge[num].size(); i++){
        if(visited[edge[num][i]] == false){
            check = dfs(edge, visited, edge[num][i], dest);
            if(check == true){
                output.push_back(edge[num][i]);
                return check;
            }
        }
    }
    
    return check;
}

int main() {
    
    int N;
    
    scanf("%d", &N);
    
    vector<int> edge[N+1];
    
    int start, dest;
    
    scanf("%d %d", &start, &dest);
    
    int edge_num;
    vector<bool> visited(N+1);
    
    scanf("%d", &edge_num);
    
    for(auto i = 0; i < edge_num; i++){
        int node_1, node_2;
        scanf("%d %d", &node_1, &node_2);
        edge[node_1].push_back(node_2);
        edge[node_2].push_back(node_1);
    }
    
    bool result = dfs(edge, visited, start, dest);
    
    if(result){
        printf("%d\n", output.size());
    }
    else{
        printf("-1\n");
    }
    
    return 0;
}