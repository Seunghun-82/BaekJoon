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

void bfs(int N, int K){
    
    pair<int, pair<int, int>> idx = make_pair(N, make_pair(0, 0));
    
    queue<pair<int, pair<int, int>>> q;
    q.push(idx);
    
    vector<int> visited[1001];
    
    while(!q.empty()){
        
        pair<int, pair<int, int>> tmp = q.front();
        
        q.pop();
        
        int tmp_emo = tmp.first;
        int tmp_clipboard = tmp.second.first;
        int tmp_cycle = tmp.second.second;
        
        if(tmp_emo == K){
            cout << tmp_cycle << "\n";
            return;
        }
        
        auto size = visited[tmp_emo].size();
        
        bool check_clipboard = false;
        bool check_delete = false;
        bool check_copy = false;
        
        for(auto i = 0; i < size; i++){
            if(visited[tmp_emo][i] == tmp_emo){
                check_clipboard = true;
            }
        }
        
        if(tmp_emo > 0){
            
            size = visited[tmp_emo - 1].size();
            
            for(auto i = 0; i < size; i++){
                if(visited[tmp_emo][i] == tmp_clipboard){
                    check_delete = true;
                }
            }
            
            if(check_delete == false){
                visited[tmp_emo - 1].push_back(tmp_clipboard);
                q.push(make_pair(tmp_emo - 1, make_pair(tmp_clipboard, tmp_cycle + 1)));
            }
        }
        if(tmp_emo + tmp_clipboard <= 1000){
            size = visited[tmp_emo + tmp_clipboard].size();
            
            for(auto i = 0; i < size; i++){
                if(visited[tmp_emo + tmp_clipboard][i] == tmp_clipboard){
                    check_copy = true;
                }
            }
            
            if(check_copy == false){
                visited[tmp_emo + tmp_clipboard].push_back(tmp_clipboard);
                q.push(make_pair(tmp_emo + tmp_clipboard, make_pair(tmp_clipboard, tmp_cycle + 1)));
            }
        }
        if(check_clipboard == false){
            visited[tmp_emo].push_back(tmp_emo);
            q.push(make_pair(tmp_emo, make_pair(tmp_emo, tmp_cycle + 1)));
        }
        
        
    }
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int S;
    
    cin >> S;
    
    bfs(1, S);
    
    
    
    return 0;
}