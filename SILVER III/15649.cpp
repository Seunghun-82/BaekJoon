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

void dfs(int N, int M, int len, vector<bool> visited, vector<int> arr){
    
    if(len == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 1; i <= N; i++){
        if(visited[i] == false){
            visited[i] = true;
            arr.push_back(i);
            dfs(N, M, len + 1, visited, arr);
            arr.erase(remove(arr.begin(), arr.end(), i), arr.end());
            visited[i] = false;
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<bool> visited(N + 1);
    vector<int> arr;
    
    dfs(N, M, 0, visited, arr);
    
}