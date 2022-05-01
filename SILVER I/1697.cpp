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

vector<bool> visited(100001);

int bfs(int N, int K){
    
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    visited[N] = true;
    
    while(!q.empty()){
        pair<int, int> num = q.front();
        q.pop();
        
        if(num.first == K){
            return num.second;
        }
        
        if(num.first - 1 >= 0 && visited[num.first - 1] == false){
            q.push(make_pair(num.first - 1, num.second + 1));
            visited[num.first - 1] = true;
        }
        if(num.first + 1 <= 100000 && visited[num.first + 1] == false){
            q.push(make_pair(num.first + 1, num.second + 1));
            visited[num.first + 1] = true;
        }
        if(num.first * 2 <= 100000 && visited[num.first * 2] == false){
            q.push(make_pair(num.first * 2, num.second + 1));
            visited[num.first * 2] = true;
        }
    }
    
    return -1;
    
}

int main() {
    
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    int result = bfs(N, M);
    
    printf("%d\n", result);
    
    return 0;
}