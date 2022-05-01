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
    
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    vector<long long int> dp_table[N + 1];
    
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(i == 0 || j == 0){
                dp_table[i].push_back(0);
            }
            else{
                int tempt;
                scanf("%d", &tempt);
                dp_table[i].push_back(dp_table[i][j - 1] + dp_table[i - 1][j] - dp_table[i - 1][j - 1] + tempt);
            }
        }
    }
    
    for(int i = 0; i < M; i++){
        int start_x, start_y;
        int dest_x, dest_y;
        
        scanf("%d %d %d %d", &start_x, &start_y, &dest_x, &dest_y);
        
        printf("%lld\n", dp_table[dest_x][dest_y] - dp_table[start_x - 1][dest_y] - dp_table[dest_x][start_y - 1] + dp_table[start_x - 1][start_y - 1]);
    }
    
    
    
    return 0;
}