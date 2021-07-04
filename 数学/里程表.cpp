# include <iostream>
# include <cstring>
# include <cmath>

using namespace std;

/**
【问题描述】

三月八日，小明买了台新车。但很快小明发现汽车的里程表有问题：里程表上每一位都不显示数字3和数字8，也就是说直接从数字2跳到数字4，直接从数字7跳到数字9。小明纳闷：这车到底行驶里程是多少。

现在，小明向你求助：根据里程表显示的数字，给出真实的行驶里程。

【输入形式】

输入有多组测试数据。

输入第一行正整数T，表示有多少组测试数据。

后面有T行，每行一个非负整数，表示里程表显示数字，里面不含有数字3和8。该数字不超过10位。

40%的测试数据组数T  10≤T≤ 102；

30%的测试数据组数T  102≤T≤ 103；

20%的测试数据组数T  103≤T≤ 104；

10%的测试数据组数T  104≤T≤ 105；

【输出形式】

对于每组测试数据，输出一个整数占一行：真实的行程里程。

【样例输入】


6
0
1
12
159
111224459
124567976
【样例输出】


0
1
10
103
19212007
21913077
*/
int main(){
	/**
	八进制，但须处理最后值的真实值 
	*/
	
	int t;
	scanf("%d", &t);
	
	for (int i = 0; i < t; i ++) {
		char num[15];
		scanf("%s", num);
		
		int len = strlen(num);
		for (int j = 0; j < len; j ++) {
			switch (num[j]) {
				case '4': num[j] = '3'; break;
				case '5': num[j] = '4'; break;
				case '6': num[j] = '5'; break;
				case '7': num[j] = '6'; break;
				case '9': num[j] = '7'; break;
			}
		}
		
		int ans = 0;
		for (int j = len - 1, k = 0; j >= 0; j --, k ++) {
			ans += int(pow(8, k) * (num[j] - '0'));
		}
		
		printf("%d\n", ans);
	}
	return 0;
} 

