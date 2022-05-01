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
    queue<pair<pair<int, int>,pair<int, int>>> q;
    
    vector<bool> visited(100001, false); // N, dist, vector idx, idx_parent
    
    vector<pair<pair<int, int>, pair<int, int>>> history;
    
    q.push(make_pair(make_pair(N, 0), make_pair(0, -1)));
    visited[N] = true;
    
    int index = 1;
    
    history.push_back(make_pair(make_pair(N, 0), make_pair (0, -1)));
    
    vector<int> result;
    
    while(q.empty() == false){
        pair<pair<int, int>, pair<int, int>> idx = q.front();
        q.pop();
        
        int tmp_N = idx.first.first;
        int tmp_dist = idx.first.second;
        
        if(tmp_N == K){
            
            cout << idx.first.second << "\n";
            
            int tmp_index = idx.second.first;
            
            while(1){
                
                if(tmp_index == -1){
                    break;
                }
                
                result.push_back(history[tmp_index].first.first);
                tmp_index = history[tmp_index].second.second;
            }
            
            break;
        }
        
        if(tmp_N > 0 && visited[tmp_N - 1] == false){
            q.push(make_pair(make_pair(tmp_N - 1, tmp_dist + 1),
                             make_pair(index, idx.second.first)));
            visited[tmp_N - 1] = true;
            history.push_back(make_pair(make_pair(tmp_N - 1, tmp_dist + 1),
                                        make_pair(index, idx.second.first)));
            index++;
        }
        if(tmp_N < 100000 && visited[tmp_N + 1] == false){
            q.push(make_pair(make_pair(tmp_N + 1, tmp_dist + 1),
                             make_pair(index, idx.second.second)));
            visited[tmp_N + 1] = true;
            history.push_back(make_pair(make_pair(tmp_N + 1, tmp_dist + 1),
                                        make_pair(index, idx.second.first)));
            index++;
        }
        if(tmp_N <= 50000 && visited[tmp_N * 2] == false){
            q.push(make_pair(make_pair(tmp_N * 2, tmp_dist + 1),
                             make_pair(index, idx.second.first)));
            visited[tmp_N * 2] = true;
            history.push_back(make_pair(make_pair(tmp_N * 2, tmp_dist + 1),
                                        make_pair(index, idx.second.first)));
            index++;
        }
    }
    
    auto size = result.size();
    
    for(int i = 0; i < size; i++){
        cout << result[size - 1 - i] << " ";
    }
    cout << "\n";
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    
    cin >> N >> K;
    
    bfs(N, K);
    
    
    
    return 0;
}