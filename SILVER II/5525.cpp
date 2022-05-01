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
    
    string str;
    
    cin >> str;
    
    vector<int> index;
    
    for(int i = 0; i < M; i++){
        if(str[i] == 'I'){
            index.push_back(i);
        }
    }
    
    int output = 0;
    int size = index.size();
    int accum = 0;
    
    for(int i = 0; i < size - 1; i++){
        if(index[i] + 2 == index[i + 1]){
            accum += 2;
        }
        else{
            accum = 0;
        }
        
        if(accum >= N * 2){
            output++;
        }
        
    }
    
    printf("%d\n", output);
    
    return 0;
}