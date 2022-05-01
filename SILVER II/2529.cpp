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

vector<char> comparer;
vector<bool> visited(10);

long long int min_v = 10000000000;
long long int max_v = 0;

void dfs(int len, int N, long long int num_pad){
    
    if(len == N){
        min_v = min(min_v, num_pad);
        max_v = max(max_v, num_pad);
    }
    
    int tmp = num_pad % 10;
    
    for(int i = 0; i < 10; i++){
        
        if(visited[i] == true){
            continue;
        }
        
        if(len != 0){
            if(comparer[len - 1] == '<'){
                if(tmp > i){
                    continue;
                }
            }
            else{
                if(tmp < i){
                    continue;
                }
            }
        }
        
        visited[i] = true;
        dfs(len + 1, N, num_pad * 10 + i);
        visited[i] = false;
    }
    
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    int check = 1;
    
    for(int i = 0; i < N; i++){
        char tmp;
        cin >> tmp;
        comparer.push_back(tmp);
        check = check * 10;
    }
    
    dfs(0, N + 1, 0);
    
    if(max_v < check){
        cout << "0" << max_v << "\n";
    }
    else{
        cout << max_v << "\n";
    }
    
    if(min_v < check){
        cout << "0" << min_v << "\n";
    }
    else{
        cout << min_v << "\n";
    }
    
    return 0;
    
}