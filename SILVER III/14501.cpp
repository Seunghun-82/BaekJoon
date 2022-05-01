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

int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    
    scanf("%d", &N);
    
    vector<int> T;
    vector<int> P;
    
    T.push_back(0);
    P.push_back(0);
    
    for(auto i = 0; i < N; i++){
        int tempt_T, tempt_P;
        scanf("%d %d\n", &tempt_T, &tempt_P);
        
        T.push_back(tempt_T);
        P.push_back(tempt_P);
    }
    
    vector<int> profit(N + 2);
    profit[0] = 0;
    
    int max_value = 0;
    
    for(auto i = 1; i < N + 1; i++){
        if(i + T[i] <= N + 1){
            profit[i + T[i]] = max(profit[i + T[i]] , max(P[i] + profit[i], max_value + P[i]));
            for(int j = i + T[i]; j <= N+1; j++){
                profit[j] = max(profit[i + T[i]], profit[j]);
            }
        }
    }
    
    printf("%d\n", profit[N+1]);
    
    return 0;
}