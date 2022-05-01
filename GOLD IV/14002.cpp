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
    
    int N;
    
    cin >> N;
    
    vector<int> arr;
    vector<int> dp;
    vector<int> parent;
    
    dp.push_back(0);
    arr.push_back(-1);
    parent.push_back(-1);
    
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
        dp.push_back(0);
        parent.push_back(-1);
    }
    
    int max_v = 0;
    int max_index = 0;
    
    for(int i = 0; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            if(arr[i] < arr[j]){
                if(dp[j] < dp[i] + 1){
                    dp[j] = dp[i] + 1;
                    parent[j] = i;
                }
                if(dp[j] > max_v){
                    max_v = dp[j];
                    max_index = j;
                }
            }
        }
    }
    
    vector<int> result;
    
    while(max_index != 0){
        result.push_back(arr[max_index]);
        max_index = parent[max_index];
    }
    
    cout << max_v << "\n";
    
    for(int i = 0; i < max_v; i++){
        cout << result[max_v - i - 1] << " ";
    }
    
    cout << "\n";
    
    return 0;
    
}