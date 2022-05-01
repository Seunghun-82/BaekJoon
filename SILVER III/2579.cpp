//
//  main.cpp
//  BaekJoon
//
//  Created by seunghun on 2022/03/10.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int S;
    
    scanf("%d", &S);
    
    vector<int> score;
    
    score.push_back(0);
    
    for(auto i = 0; i < S; i++){
        int tempt;
        scanf("%d", &tempt);
        score.push_back(tempt);
    }
    
    vector<int> dp(S + 1); // second.first  -> 이전 것을 골랐냐, second.second -> 현재 i 것을 골랐냐
    
    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    dp[3] = max(score[1] + score[3], score[2] + score[3]);
    
    for(auto i = 4 ; i <= S; i++){
        dp[i] = max(dp[i - 3] + score[i - 1] + score[i], dp[i - 2] + score[i]);
    }
    
    printf("%d\n", dp[S]);
    
}