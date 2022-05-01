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

bool compare(int a, int b) {
    return a > b;
}

int main() {

    int N;
    
    scanf("%d\n", &N);

    vector<int> edge;
    for(auto i = 0 ; i < N; i++){
        int tempt;
        scanf("%d\n", &tempt);
        edge.push_back(tempt);
    }
    
    sort(edge.begin(), edge.end(), compare);
    
    int check = -1;
    
    for(auto i = 0; i < N - 2; i++){
        if(edge[i] < edge[i + 1] + edge[i + 2]){
            check = i;
            break;
        }
    }
    
    if(check == -1){
        printf("-1\n");
    }
    else{
        printf("%d\n", edge[check] + edge[check + 1] + edge[check + 2]);
    }
    
    return 0;
}