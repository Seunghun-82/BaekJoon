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

void dfs(vector<int> node[], vector<bool>& visited, vector<int>& left_right,int index, int dist, int N){
    
    auto size = node[index].size();
    
    for(int i = 0; i < size; i++){
        if(visited[node[index][i]] == false){
            visited[node[index][i]] = true;
            left_right[node[index][i]] = dist % 2;
            dfs(node, visited, left_right, node[index][i], dist + 1, N);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int K, V, E;
    
    cin >> K;
    while(K--){
        cin >> V >> E;
        
        vector<int> node[V + 1];
        
        for(int i = 0; i < E; i++){
            int tmp_1, tmp_2;
            
            cin >> tmp_1 >> tmp_2;
            
            node[tmp_1].push_back(tmp_2);
            node[tmp_2].push_back(tmp_1);
        }
        
        vector<bool> visited(V + 1, false);
        vector<int> left_right(V + 1, -1);
    
        
        for(int i = 1; i < V; i++){
            if(visited[i] == false){
                visited[i] = true;
                visited[i] = 0;
                dfs(node, visited, left_right, i, 1, V);
            }
        }
        
        bool check = true;
        
        for(int i = 1; i <= V; i++){
            int size = node[i].size();
            for(int j = 0; j < size; j++){
                if(left_right[i] == left_right[node[i][j]]){
                    check = false;
                    break;
                }
            }
            
            if(check == false){
                break;
            }
        }
        
        if(check == false){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
        
        
    }
    
    
}