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

void dfs(vector<int> node[], vector<bool> visited, vector<bool>& output_in, vector<int>& output, int num, int height){
    
    if(height > 2){
        return;
    }
    else{
        for(int i = 0; i < node[num].size(); i++){
            if(visited[node[num][i]] == false && height < 2){
                visited[node[num][i]] = true;
                if(output_in[node[num][i]] == false){
                    output.push_back(node[num][i]);
                    output_in[node[num][i]] = true;
                }
                dfs(node, visited, output_in, output, node[num][i], height + 1);
            }
        }
    }
}

int main() {
    
    int N, M;
    
    scanf("%d", &N);
    scanf("%d", &M);
    
    vector<int> node[N + 1];
    vector<bool> visited(N + 1);
    vector<bool> output_in(N + 1);
    vector<int> output;
    
    for(int i = 0 ; i < M; i++){
        int node_1, node_2;
        scanf("%d %d", &node_1, &node_2);
        node[node_1].push_back(node_2);
        node[node_2].push_back(node_1);
    }
    
    visited[1] = true;
    
    dfs(node, visited, output_in, output, 1, 0);
    
    printf("%d\n", output.size());
    
    return 0;
}