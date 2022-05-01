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

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tetrimino_x[19][4] = {
        {0, 1, 2, 3}, {0, 0, 0, 0},
        {0, 1, 0, 1},
        {0, 0, 0, 1}, {0, 1, 2, 0}, {0, 1, 1, 1}, {0, 1, 2, 2},
        {0, 0, 0, -1}, {0, 1, 2, 2}, {0, 0, 0, 1}, {0, 1, 2, 0},
        {0, 0, 1, 1}, {0, 1, 1, 2}, {0, 1, 1, 2}, {0, 0, 1, 1},
        {0, 1, 2, 1}, {0, 0, 0, -1}, {0, 1, 2, 1}, {0, 0, 0, 1}
    };
    int tetrimino_y[19][4] = {
        {0, 0, 0, 0}, {0, 1, 2, 3},
        {0, 0, 1, 1},
        {0, 1, 2, 2}, {0, 0, 0, 1}, {0, 0, 1, 2}, {0, 0, 0, -1},
        {0, 1, 2, 2}, {0, 0, 0, 1}, {0, 1, 2, 0}, {0, 0, 0, -1},
        {0, 1, 1, 2}, {0, 0, -1, -1}, {0, 0, 1, 1}, {0, 1, 0, -1},
        {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}, {0, 1, 2, 1}
    };
    
    int N, M;
    cin >> N >> M;
    
    vector<int> num[N + 6];
    
    for(int i = 0; i < N + 6; i++){
        for(int j = 0; j < M + 6; j++){
            if(i < 3 || j < 3 || i > N + 2 || j > M + 2){
                num[i].push_back(-10000);
            }
            else{
                int tmp;
                cin >> tmp;
                num[i].push_back(tmp);
            }
        }
    }
    
    int max_v = 0;
    
    for(int i = 3; i < N + 3; i++){
        for(int j = 3; j < M + 3; j++){
            for(int k = 0; k < 19; k++){
                int sum = 0;
                for(int m = 0; m < 4; m++){
                    int x = tetrimino_x[k][m] + j;
                    int y = tetrimino_y[k][m] + i;
                    
                    sum += num[y][x];
                    
                }
                
                max_v = max(max_v, sum);
            }
        }
    }
    
    cout << max_v << "\n";
    
    return 0;
}