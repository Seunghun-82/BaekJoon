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

vector<int> node[2000];

bool dfs(vector<bool> visited, int index, int dist){
    if(dist == 4){
        return true;
    }
    else{
        for(int i = 0; i < node[index].size(); i++){
            if(visited[node[index][i]] == false){
                visited[node[index][i]] = true;
                bool ret_val = dfs(visited, node[index][i], dist + 1);
                visited[node[index][i]] = false;
                if(ret_val == true){
                    return ret_val;
                }
            }
        }
    }
    
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    
    cin >> N >> M;
    
    vector<bool> visited(N);
    
    for(int i = 0; i< M; i++){
        int tmp_1, tmp_2;
        cin >> tmp_1 >> tmp_2;
        
        node[tmp_1].push_back(tmp_2);
        node[tmp_2].push_back(tmp_1);
    }
    
    bool check = false;
    
    for(int i = 0; i < N; i++){
        visited[i] = true;
        bool ret_val = dfs(visited, i, 0);
        visited[i] = false;
        if(ret_val == true){
            check = true;
            break;
        }
    }
    
    if(check == true){
        cout << "1\n";
    }
    else{
        cout << "0\n";
    }
    
    
    
}