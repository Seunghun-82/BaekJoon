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

vector<int> start[20];

int min_v = 1000000;
int sum = 0;

void dfs(int N, int idx, int team_num, vector<bool> visited){
    
    if(team_num * 2 == N){
        vector<int> start_member;
        vector<int> link_member;
        
        for(int i = 0; i < N; i++){
            if(visited[i] == true){
                start_member.push_back(i);
            }
            else{
                link_member.push_back(i);
            }
        }
        
        int start_team = 0;
        int link_team = 0;
        for(int i = 0; i < N / 2; i++){
            for(int j = 0; j < N / 2; j++){
                if(i == j){
                    continue;
                }
                start_team += start[start_member[i]][start_member[j]];
                link_team += start[link_member[i]][link_member[j]];
            }
        }
        
        min_v = min(min_v, abs(start_team - link_team));
        
        return;
    }
    
    for(int i = idx; i < N; i++){
        if(visited[i] == false){
            visited[i] = true;
            dfs(N, i, team_num + 1, visited);
            visited[i] = false;
        }
    }
    
    
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    vector<bool> visited(N);
    vector<int> num;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int tmp;
            cin >> tmp;
            sum += tmp;
            start[i].push_back(tmp);
        }
    }
    
    dfs(N, 0, 0, visited);
    
    cout << min_v << "\n";
    
    return 0;
}