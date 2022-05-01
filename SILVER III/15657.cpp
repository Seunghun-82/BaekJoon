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

vector<int> num;

void dfs(int N, int M, int len, vector<int> arr){
    
    if(len == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 0; i < N; i++){
        if(len == 0){
            arr.push_back(num[i]);
            dfs(N, M, len + 1, arr);
            arr.erase(arr.begin() + len);
        }
        else{
            if(arr[len - 1] <= num[i]){
                arr.push_back(num[i]);
                dfs(N, M, len + 1, arr);
                arr.erase(arr.begin() + len);
            }
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }

    sort(num.begin(), num.end());
    
    vector<int> arr;
    
    dfs(N, M, 0, arr);
    
}