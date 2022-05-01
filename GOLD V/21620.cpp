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

struct cmp{
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        return a.second > b.second;
    }
};

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second;
}

int bfs(vector<int> arr[], int M, int N, vector<pair<int, int>> virus){
    
    queue<pair<int, int>> q;
    
    auto size = virus.size();
    
    for(auto i = 0; i < size; i++){
        q.push(virus[i]);
    }
    
    while(!q.empty()){
        
        pair<int, int> idx = q.front();
        q.pop();
        
        if(idx.first == 0 || idx.first == M + 1 || idx.second == 0 || idx.second == N + 1){
            continue;
        }
        else{
            int x = idx.first;
            int y = idx.second;
            if(arr[y][x - 1] == 0){
                arr[y][x - 1] = 2;
                q.push(make_pair(x - 1, y));
            }
            if(arr[y][x + 1] == 0){
                arr[y][x + 1] = 2;
                q.push(make_pair(x + 1, y));
            }
            if(arr[y - 1][x] == 0){
                arr[y - 1][x] = 2;
                q.push(make_pair(x , y - 1));
            }
            if(arr[y + 1][x] == 0){
                arr[y + 1][x] = 2;
                q.push(make_pair(x, y + 1));
            }
        }
        
    }
    
    int security = 0;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(arr[i][j] == 0){
                security++;
            }
        }
    }
    
    return security;
}

void initialize(vector<int> arr[], vector<int> copy[], int M, int N){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            arr[i][j] = copy[i][j];
        }
    }
    
    return;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    
    cin >> N >> M;
    
    vector<int> arr[N];
    vector<pair<int,int>> move;
    vector<bool> prev[N];
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int tmp;
            cin >> tmp;
            arr[i].push_back(tmp);
            prev[i].push_back(false);
        }
    }
    
    for(int i = 0; i < M; i++){
        int tmp_direc, tmp_move;
        cin >> tmp_direc >> tmp_move;
        move.push_back(make_pair(tmp_direc, tmp_move));
    }
    
    for(int i = 0; i <= M; i++){
        vector<pair<int, int>> cloud;
        if(i == 0){
            cloud.push_back(make_pair(0, N - 2));
            cloud.push_back(make_pair(1, N - 2));
            cloud.push_back(make_pair(0, N - 1));
            cloud.push_back(make_pair(1, N - 1));
        }
        else{
            for(int j = 0; j < N; j++){
                for(int k = 0; k < N; k++){
                    if(arr[j][k] >= 2 && prev[j][k] == false){
                        arr[j][k] -= 2;
                        cloud.push_back(make_pair(k, j));
                    }
                }
            }
        }
        
        if(i == M){
            break;
        }
        
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                prev[j][k] = false;
            }
        }
        
        auto size = cloud.size();
        
        if(move[i].first == 1){
            for(int j = 0; j < size; j++){
                cloud[j].first -= move[i].second;
            }
        }
        else if(move[i].first == 2){
            for(int j = 0; j < size; j++){
                cloud[j].first -= move[i].second;
                cloud[j].second -= move[i].second;
            }
        }
        else if(move[i].first == 3){
            for(int j = 0; j < size; j++){
                cloud[j].second -= move[i].second;
            }
        }
        else if(move[i].first == 4){
            for(int j = 0; j < size; j++){
                cloud[j].first += move[i].second;
                cloud[j].second -= move[i].second;
            }
        }
        else if(move[i].first == 5){
            for(int j = 0; j < size; j++){
                cloud[j].first += move[i].second;
            }
        }
        else if(move[i].first == 6){
            for(int j = 0; j < size; j++){
                cloud[j].first += move[i].second;
                cloud[j].second += move[i].second;
            }
        }
        else if(move[i].first == 7){
            for(int j = 0; j < size; j++){
                cloud[j].second += move[i].second;
            }
        }
        else{
            for(int j = 0; j < size; j++){
                cloud[j].first -= move[i].second;
                cloud[j].second += move[i].second;
            }
        }
        
        for(int j = 0; j < size; j++){
            while(cloud[j].first < 0){
                cloud[j].first += N;
            }
            while(cloud[j].first >= N){
                cloud[j].first -= N;
            }
            
            while(cloud[j].second < 0){
                cloud[j].second += N;
            }
            while(cloud[j].second >= N){
                cloud[j].second -= N;
            }
            
            prev[cloud[j].second][cloud[j].first] = true;
            arr[cloud[j].second][cloud[j].first] += 1;
        }
        
        for(int j = 0; j < size; j++){
            int x = cloud[j].first;
            int y = cloud[j].second;
            
            int add_num = 0;
            
            if(x - 1 >= 0 && x - 1 < N && y - 1 >= 0 && y - 1 < N){
                if(arr[y-1][x-1] > 0){
                    add_num++;
                }
            }
            if(x + 1 >= 0 && x + 1 < N && y - 1 >= 0 && y - 1 < N){
                if(arr[y-1][x+1] > 0){
                    add_num++;
                }
            }
            if(x - 1 >= 0 && x - 1 < N && y + 1 >= 0 && y + 1 < N){
                if(arr[y+1][x-1] > 0){
                    add_num++;
                }
            }
            if(x + 1 >= 0 && x + 1 < N && y + 1 >= 0 && y + 1 < N){
                if(arr[y+1][x+1] > 0){
                    add_num++;
                }
            }
            
            arr[y][x] += add_num;
        }
        
    }
    
    int output = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            output += arr[i][j];
        }
    }
    
    cout << output << "\n";
    
    return 0;
}