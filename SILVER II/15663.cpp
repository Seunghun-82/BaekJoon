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

void dfs(vector<int> arr, vector<bool>& visited, vector<int>& output_arr, int cnt, int N, int M){
    if(cnt == M){
        for(int i = 0; i < M; i++){
            printf("%d ", output_arr[i]);
        }
        printf("\n");
        
        return;
    }
    
    for(int i = 0; i < N; i++){
        if(i > 0){
            if(visited[i] == false){
                if(arr[i] != arr[i - 1])
                {
                    visited[i] = true;
                    output_arr[cnt] = arr[i];
                    dfs(arr, visited, output_arr, cnt + 1, N, M);
                    visited[i] = false;
                }
                else{
                    if(visited[i - 1] == true){
                        visited[i] = true;
                        output_arr[cnt] = arr[i];
                        dfs(arr, visited, output_arr, cnt + 1, N, M);
                        visited[i] = false;
                    }
                }
            }
        }
        else{
            if(visited[i] == false){
                visited[i] = true;
                output_arr[cnt] = arr[i];
                dfs(arr, visited, output_arr, cnt + 1, N, M);
                visited[i] = false;
            }
        }
    }
    
}

int main() {
    
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    vector<int> arr;
    vector<bool> visited(N);
    
    vector<int> output_arr(N);
    
    for(auto i = 0; i < N; i++){
        int tempt;
        scanf("%d", &tempt);
        arr.push_back(tempt);
    }
    
    sort(arr.begin(), arr.end());
    
    dfs(arr, visited, output_arr, 0, N, M);
    
    return 0;
}