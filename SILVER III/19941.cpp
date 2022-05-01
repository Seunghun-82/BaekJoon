#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(long long int a, long long int b) {
	return a > b;
}

int main() {

	int N, K;

	scanf("%d %d\n", &N, &K);

	vector<char> str;
	vector<bool> visited;

	for (auto i = 0; i < N; i++) {
		char tempt;
		scanf("%c", &tempt);
		str.push_back(tempt);
		visited.push_back(false);
	}

	int output = 0;

	for (auto i = 0; i < N; i++) {
		if (str[i] == 'P') {
			for (auto index = -K + i; index <= i + K; index++)
			{
				if (index >= 0 && index < N && visited[index] == false && str[index] == 'H') {
					visited[index] = true;
					output++;
					break;
				}
			}
		}
	}

	printf("%d", output);

	return 0;
}