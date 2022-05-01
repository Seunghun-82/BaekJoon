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

bool compare(int a, int b) {
    return a > b;
}

int main() {
    
    int N;
    
    scanf("%d\n", &N);
    
    vector<int> shift;
    vector<bool> visited;
    
    for(auto i = 0; i < N; i++){
        int tempt;
        scanf("%d", &tempt);
        shift.push_back(tempt);
        visited.push_back(false);
    }
    
    vector<int> output;
    
    int target = 0;
    
    for(auto i = 0; i < N; i++){
        
        visited[target] = true;
        output.push_back(target);
        
        if(i == N - 1){
            break;
        }
        
        int shift_num = shift[target];
        int real_shift_num = 0;
        if(shift_num > 0){
            for(auto j = 0; j < shift_num; j++){
                
                if(target == N - 1){
                    if(visited[0]){
                        j--;
                    }
                }
                else{
                    if(visited[target + 1]){
                        j--;
                    }
                }
                
                target++;
                
                if(target == N){
                    target -= N;
                }
                
            }
        }
        else{
            for(auto j = 0; j < -1 * shift_num; j++){
                
                if(target == 0){
                    if(visited[N - 1]){
                        j--;
                    }
                }
                else{
                    if(visited[target - 1]){
                        j--;
                    }
                }
                
                target--;
                
                if(target == -1){
                    target += N;
                }
            }
        }
        
    }
    
    for(auto i = 0; i < N; i++){
        printf("%d ", output[i] + 1);
    }
    
    return 0;
}