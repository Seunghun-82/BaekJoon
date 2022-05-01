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

void bfs(vector<int> arr[], int M, int N, pair<int, int> coin[]){
    
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K, L;
    
    cin >> N;
    
    vector<int> arr[N + 2]; // 벽은 -1, 사과는 1, 아무것도 없는 곳은 0, 뱀 몸이 있으면 2
    
    for(int i = 0; i < N + 2; i++){
        for(int j = 0; j < N + 2; j++){
            if(i == 0 || i == N + 1){
                arr[i].push_back(-1);
            }
            else if(j == 0 || j == N + 1){
                arr[i].push_back(-1);
            }
            else{
                arr[i].push_back(0);
            }
        }
    }
    
    cin >> K;
    
    for(int i = 0; i < K; i++){
        int x, y;
        cin >> y >> x;
        arr[y][x] = 1;
    }
    
    cin >> L;
    
    vector<pair<int, char>> direction;
    
    for(int i = 0; i < L; i++){
        int tmp;
        char direc;
        cin >> tmp >> direc;
        direction.push_back(make_pair(tmp, direc));
    }
    
    pair<int, int> head = make_pair(1, 1);
    pair<int, int> tail = make_pair(1, 1);
    
    char move = 'R';
    
    arr[1][1] = 2;
    int time = 0;
    int index = 0;
    int next_time_elapse = direction[0].first;
    
    while(1){
        if(head.first == 0 || head.first == N + 2 ||
           head.second == 0 || head.second == N + 2){
            break;
        }
        else{
            if(time == next_time_elapse){
                if(move == 'R'){
                    if(direction[index].second == 'L'){
                        move = 'U';
                    }
                    else{
                        move = 'D';
                    }
                }
                else if(move == 'L'){
                    if(direction[index].second == 'L'){
                        move = 'D';
                    }
                    else{
                        move = 'U';
                    }
                }
                else if(move == 'U'){
                    if(direction[index].second == 'L'){
                        move = 'L';
                    }
                    else{
                        move = 'R';
                    }
                }
                else{
                    if(direction[index].second == 'L'){
                        move = 'R';
                    }
                    else{
                        move = 'L';
                    }
                }
                index++;
                next_time_elapse = direction[index].first;
            }
            
            time++;
            
            if(move == 'L'){
                arr[head.second][head.first] = 3;
                if(arr[head.second][head.first - 1] != 0 && arr[head.second][head.first - 1] != 1){
                    break;
                }
                else{
                    if(arr[head.second][head.first - 1] == 0){
                        if(arr[tail.second][tail.first] == 2){
                            arr[tail.second][tail.first] = 0;
                            tail.first += 1;
                        }
                        else if(arr[tail.second][tail.first] == 3){
                            arr[tail.second][tail.first] = 0;
                            tail.first -= 1;
                        }
                        else if(arr[tail.second][tail.first] == 4){
                            arr[tail.second][tail.first] = 0;
                            tail.second -= 1;
                        }
                        else{
                            arr[tail.second][tail.first] = 0;
                            tail.second += 1;
                        }
                    }
                    arr[head.second][head.first - 1] = 3;
                    head.first -= 1;
                }
            }
            
            if(move == 'R'){
                arr[head.second][head.first] = 2;
                if(arr[head.second][head.first + 1] != 0 && arr[head.second][head.first + 1] != 1){
                    break;
                }
                else{
                    if(arr[head.second][head.first + 1] == 0){
                        if(arr[tail.second][tail.first] == 2){
                            arr[tail.second][tail.first] = 0;
                            tail.first += 1;
                        }
                        else if(arr[tail.second][tail.first] == 3){
                            arr[tail.second][tail.first] = 0;
                            tail.first -= 1;
                        }
                        else if(arr[tail.second][tail.first] == 4){
                            arr[tail.second][tail.first] = 0;
                            tail.second -= 1;
                        }
                        else{
                            arr[tail.second][tail.first] = 0;
                            tail.second += 1;
                        }
                    }
                    arr[head.second][head.first + 1] = 2;
                    head.first += 1;
                }
            }
            
            if(move == 'U'){
                arr[head.second][head.first] = 4;
                if(arr[head.second - 1][head.first] != 0 && arr[head.second - 1][head.first] != 1){
                    break;
                }
                else{
                    if(arr[head.second - 1][head.first] == 0){
                        if(arr[tail.second][tail.first] == 2){
                            arr[tail.second][tail.first] = 0;
                            tail.first += 1;
                        }
                        else if(arr[tail.second][tail.first] == 3){
                            arr[tail.second][tail.first] = 0;
                            tail.first -= 1;
                        }
                        else if(arr[tail.second][tail.first] == 4){
                            arr[tail.second][tail.first] = 0;
                            tail.second -= 1;
                        }
                        else{
                            arr[tail.second][tail.first] = 0;
                            tail.second += 1;
                        }
                    }
                    arr[head.second - 1][head.first] = 4;
                    head.second -= 1;
                }
            }
            
            if(move == 'D'){
                arr[head.second][head.first] = 5;
                if(arr[head.second + 1][head.first] != 0 && arr[head.second + 1][head.first] != 1){
                    break;
                }
                else{
                    if(arr[head.second + 1][head.first] == 0){
                        if(arr[tail.second][tail.first] == 2){
                            arr[tail.second][tail.first] = 0;
                            tail.first += 1;
                        }
                        else if(arr[tail.second][tail.first] == 3){
                            arr[tail.second][tail.first] = 0;
                            tail.first -= 1;
                        }
                        else if(arr[tail.second][tail.first] == 4){
                            arr[tail.second][tail.first] = 0;
                            tail.second -= 1;
                        }
                        else{
                            arr[tail.second][tail.first] = 0;
                            tail.second += 1;
                        }
                    }
                    arr[head.second + 1][head.first] = 5;
                    head.second += 1;
                }
            }
        }
    }
    
    cout << time << "\n";
    
    return 0;
}