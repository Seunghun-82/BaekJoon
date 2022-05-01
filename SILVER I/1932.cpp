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
    
    vector<int> dp[N];
    
    for(int i = 0; i < N; i++){
        vector<int> num;
        for(int j = 0; j < i + 1; j++){
            int tempt;
            scanf("%d", &tempt);
            num.push_back(tempt);
        }
        
        if(i == 0){
            dp[i].push_back(num[i]);
        }
        else{
            for(int j = 0; j < num.size(); j++){
                if(j == 0){
                    dp[i].push_back(dp[i - 1][j] + num[j]);
                }
                else if(j == num.size() - 1){
                    dp[i].push_back(dp[i - 1][j - 1] + num[j]);
                }
                else{
                    dp[i].push_back(max(dp[i - 1][j - 1], dp[i - 1][j]) + num[j]);
                }
            }
        }
    }
    
    int max_value = dp[N-1][0];
    
    for(int i = 1; i < N; i++){
        max_value = max(dp[N-1][i] , max_value);
    }
    
    printf("%d\n", max_value);
    
    return 0;
}