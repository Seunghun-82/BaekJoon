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

bool compare(long long int a, long long int b) {
    return a > b;
}

int main() {

    int N, stu;
    
    scanf("%d\n", &N);

    vector<bool> button;
    for(auto i = 0 ; i < N; i++){
        int tempt;
        scanf("%d ", &tempt);
        if(tempt == 1){
            button.push_back(true);
        }
        else{
            button.push_back(false);
        }
    }
    
    scanf("%d", &stu);
    
    for(auto i = 0; i < stu; i++){
        int gender, num;
        scanf("%d %d\n", &gender, &num);
        
        if(gender == 1){
            int multi = num;
            for(auto j = multi; j <= N; j = j + multi){
                button[j - 1] = !button[j - 1];
            }
        }
        else{
            int j = 0;
            int button_num = num;
            while(1){
                if(button_num - 1 - j == -1 || button_num - 1 + j == N){
                    break;
                }
                
                if(button[button_num - 1 - j] == button[button_num - 1 + j]){
                    if(j == 0){
                        button[button_num - 1 - j] = !button[button_num - 1 - j];
                    }
                    else{
                        button[button_num - 1 - j] = !button[button_num - 1 - j];
                        button[button_num - 1 + j] = !button[button_num - 1 + j];
                    }
                    j++;
                }
                else{
                    break;
                }
            }
        }
    }
    
    for(int i = 1 ; i <= N; i++){
        if(i % 20 == 0){
            if(button[i - 1] == true){
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
        else{
            if(button[i - 1] == true){
                printf("1 ");
            }
            else{
                printf("0 ");
            }
        }
    }
    
    
    return 0;
}