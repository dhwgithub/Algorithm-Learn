# include <iostream>
# include <cstring>
# include <string>
# include <set>
# include <algorithm>
# include <cmath>
# include <vector>

using namespace std;

/**
【问题描述】

        给定n个开关和m个灯，第i个开关只能打开部分灯。矩阵a包含n行m列，当aij=1时表示开关i可以打开灯j，否则aij=0。

   开始时所有的m个灯都是关着的。

   开关只能从状态"关"到"开"。这意味着，对于每个可以打开某个灯的开关，无论你按多少次，这个灯都是开的。

   确保当你按下所有开关时，所有的灯都能打开，考虑是否可以忽略其中某个开关也能打开所有的灯。

   你的任务是确定是否存在这样的开关可以忽略，而使用其余的n-1个开关来打开所有m个灯。

【输入形式】

         输入第1行包含两个整数n和m(1<=n, m<=2000)，表示开关的数量和灯的数量。

   接下来的n行，每行包含m个字符，字符aij=1时表示开关i可以打开灯j，否则aij=0。

【输出形式】

         如果存在这样的可以忽略的开关，而使用其他n-1个开关打开所有的m个灯，输出"YES"，否则输出"NO"。

【样例输入】

4 5
10101
01000
00111
10000

【样例输出】

YES
*/
int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> onOff[n]; 
	int light[m];
	memset(light, 0, sizeof(light));
	
	for (int i = 0; i < n; i ++) {
		string line;
		cin >> line;
		for (int j = 0; j < m; j ++) {
			if (line[j] == '1') {
				onOff[i].push_back(j);
				light[j] ++;
			}
		}
	}
	
	bool res = false;
	for (int i = 0; i < n; i ++) {
		bool isOk = true;
		for (int j = 0; j < onOff[i].size(); j ++) {
			if (light[onOff[i][j]] - 1 < 1) {
				isOk = false;
				break;
			}
		}
		if (isOk) {
			res = true;
			break;
		}
	}
	
	if (res) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}


