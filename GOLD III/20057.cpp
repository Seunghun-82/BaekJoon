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
#include <cmath>

using namespace std;

struct cmp{
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        return a.second > b.second;
    }
};

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second;
}

int x_direction[4][9] = {
    {0, -1, 0, 1, -2, -1, 0, 1, 0}, {-2, -1, -1, -1, 0, 1, 1, 1, 2},
    {0, 1, 0, -1, 2, 1, 0, -1, 0}, {2, 1, 1, 1, 0, -1, -1, -1, -2}
};
int y_direction[4][9] = {
    {-2, -1, -1, -1, 0, 1, 1, 1, 2}, {0, 1, 0, -1, 2, 1, 0, -1, 0},
    {2, 1, 1, 1, 0, -1, -1, -1, -2}, {0, -1, 0, 1, -2, -1, 0, 1, 0}
};

int percentage[9] = {2, 10, 7, 1, 5, 10, 7, 1, 2};

void update_table(vector<int> table[], int N, int direction, int x, int y){
    
    int original = table[y][x];
    table[y][x] = 0;
    int sum = 0;
    
    int target = N / 2 + 2;
    
    if(direction == 4){
        direction = 0;
    }
    
    for(int i = 0; i < 9; i++){
        int tmp_x = x + x_direction[direction][i];
        int tmp_y = y + y_direction[direction][i];
        
        int tmp_int = percentage[i] * original / 100;
        
        sum += tmp_int;
        
        table[tmp_y][tmp_x] += tmp_int;
        
    }
    
    if(direction == 0){
        table[y][x - 1] += (original - sum);
    }
    else if(direction == 1){
        table[y + 1][x] += (original - sum);
    }
    else if(direction == 2){
        table[y][x + 1] += (original - sum);
    }
    else if(direction == 3){
        table[y - 1][x] += (original - sum);
    }
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    vector<int> table[N + 4];
    
    for(int i = 0; i < N + 4; i++){
        for(int j = 0; j < N + 4; j++){
            if(i <= 1 || i > N + 1 || j <= 1 || j > N + 1){
                table[i].push_back(0);
            }
            else{
                int tmp;
                cin >> tmp;
                table[i].push_back(tmp);
            }
        }
    }
    
    int move_num = 1;
    int direction = 0;  // 0 -> left, 1 -> down, 2 -> right, 3 -> up
    
    int x = N / 2 + 2;
    int y = N / 2 + 2;
    
    while(1){
        for(int i = 0; i < move_num; i++){
            if(direction == 0){
                x--;
            }
            else if(direction == 1){
                y++;
            }
            else if(direction == 2){
                x++;
            }
            else if(direction == 3){
                y--;
            }
            else{
                x--;
            }
            
            update_table(table, N, direction, x, y);
            
        }
        
        if(direction == 1){
            direction++;
            move_num++;
        }
        else if(direction == 3){
            if(move_num == N - 1){
                direction = 4;
            }
            else{
                direction = 0;
                move_num++;
            }
        }
        else if(direction == 4){
            break;
        }
        else{
            direction++;
        }
        
    }
    
    int result = 0;
    
    for(int i = 0; i < N + 4; i++){
        for(int j = 0; j < N + 4; j++){
            if(i <= 1 || i > N + 1 || j <= 1 || j > N + 1){
                result += table[i][j];
            }
        }
    }
    
    cout << result << "\n";
    
}