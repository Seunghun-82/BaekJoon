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

int cropping(vector<int> paper[], int x, int y, int width, vector<int>& output){
    
    if(width == 1){
        return paper[x][y];
    }
    else{
        vector<int> result(9);
        
        width = width / 3;
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                result[3 * i + j] = cropping(paper, x + j * width, y + i * width, width, output);
            }
        }
        
        bool check = true;
        
        for(int i = 0; i < 9; i++){
            if(result[i] != 1){
                check = false;
                break;
            }
        }
        
        if(check){
            return 1;
        }
        
        check = true;
        
        for(int i = 0; i < 9; i++){
            if(result[i] != 0){
                check = false;
                break;
            }
        }
        
        if(check){
            return 0;
        }
        
        check = true;
        
        for(int i = 0; i < 9; i++){
            if(result[i] != -1){
                check = false;
                break;
            }
        }
        
        if(check){
            return -1;
        }
        
        for(int i = 0; i < 9; i++){
            if(result[i] == 1){
                output[2]++;
            }
            else if(result[i] == 0){
                output[1]++;
            }
            else if(result[i] == -1){
                output[0]++;
            }
        }
        
        return -2;
    }
}

int main() {
    
    int N;
    
    scanf("%d", &N);
    
    vector<int> paper[N];
    vector<int> output;
    
    output.push_back(0);
    output.push_back(0);
    output.push_back(0);
    
    for(auto i = 0; i < N; i++){
        for(auto j = 0; j < N; j++){
            int tempt;
            scanf("%d", &tempt);
            paper[i].push_back(tempt);
        }
    }
    
    int result = cropping(paper, 0, 0, N, output);
    
    if(result == 1 || result == 0 || result == -1){
        output[result + 1]++;
    }
    
    for(int i = 0; i < output.size(); i++){
        printf("%d\n", output[i]);
    }
    
    return 0;
}