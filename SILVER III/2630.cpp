#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> num;

int paper(int x, int y, int& white, int& blue, int width) {
	if (width == 1) {
		if (num[x][y] == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {

		width = width / 2;

		int first = paper(x, y, white, blue, width);
		int second = paper(x + width, y, white, blue, width);
		int third = paper(x, y + width, white, blue, width);
		int fourth = paper(x + width, y + width, white, blue, width);

		if (first == 1 && second == 1 && third == 1 && fourth == 1) {
			return 1;
		}
		if (first == 0 && second == 0 && third == 0 && fourth == 0) {
			return 0;
		}

		if (first == 1) {
			blue = blue + 1;
		}
		else if (first == 0) {
			white = white + 1;
		}

		if (second == 1) {
			blue = blue + 1;
		}
		else if (second == 0) {
			white = white + 1;
		}

		if (third == 1) {
			blue = blue + 1;
		}
		else if (third == 0) {
			white = white + 1;
		}

		if (fourth == 1) {
			blue = blue + 1;
		}
		else if (fourth == 0) {
			white = white + 1;
		}

		return 2;
	}
}

int main() {
	
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < N; j++) {
			int tempt;
			scanf("%d", &tempt);
			temp.push_back(tempt);
		}
		num.push_back(temp);
	}
	int white = 0;
	int blue = 0;

	int return_val = paper(0, 0, white, blue, N);

	if (return_val == 1) {
		blue++;
	}
	else if (return_val == 0) {
		white++;
	}

	printf("%d\n", white);
	printf("%d\n", blue);

	return 0;
}