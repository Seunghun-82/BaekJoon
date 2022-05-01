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
    
    int N;
    
    scanf("%d", &N);
    
    vector<int> RGB[3];
    for(int i = 0; i < N; i++){
        int R, G, B;
        scanf("%d %d %d", &R, &G, &B);
        RGB[0].push_back(R);
        RGB[1].push_back(G);
        RGB[2].push_back(B);
    }
    
    vector<int> dp [3];
    
    dp[0].push_back(0);
    dp[1].push_back(0);
    dp[2].push_back(0);
    
    for(int i = 0; i < N; i++){
        dp[0].push_back(min(dp[1][i], dp[2][i]) + RGB[0][i]);
        dp[1].push_back(min(dp[0][i], dp[2][i]) + RGB[1][i]);
        dp[2].push_back(min(dp[0][i], dp[1][i]) + RGB[2][i]);
    }
    
    printf("%d\n", min(dp[0][N], min(dp[1][N], dp[2][N])));
    
    return 0;
}