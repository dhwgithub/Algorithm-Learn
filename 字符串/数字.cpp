# include <iostream>
# include <sstream>

using namespace std;

/**
【问题描述】

输出 包含n 或者是n的倍数的所有数

【输入形式】

正整数 m,n（0<m，n<1000000）

【输出形式】

从小到大排列的不大于 m 的特殊正整数（包含n，或者是n的倍数）。

【样例输入1】

20 7
【样例输出1】

7 14 17
【样例输入2】

200 11
【样例输出2】

11 22 33 44 55 66 77 88 99 110 111 112 113 114 115 116 117 118 119 121 132 143 154 165 176 187 198
【样例说明】

包含n的数可以考虑使用字符串查找解决
*/
string intToString(int n) {
	stringstream stream;
	stream << n;
	return stream.str();
}

int main() {
	
	int m, n;
	cin >> m >> n;
	if (m < n) {
		return 0;
	}
	
	cout << n;
	for (int i = n + 1; i <= m; i ++) {
		if (i % n == 0) {
			cout << " " << i;
		}
		else if (intToString(i).find(intToString(n)) < 10){
			cout << " " << i;
		}
	}
	cout << endl;
	return 0;
}


