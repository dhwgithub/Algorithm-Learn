# include <iostream>
# include <cstring>

using namespace std;

/**
需要你编写程序解决的问题是：已知一个二叉树的前序遍历和中序遍历的结果，给出该二叉树的后序遍历的结果。

【输入形式】

有多组测试数据，每组测试数据三行，每组测试数据第一行只有一个正整数n，表示二叉树节点的数目，n=0意味着输入结束并且不需要处理。

每组测试数据第二行是二叉树的前序遍历的结果，是一个长度为n的字符串，每个节点由一个字符表示，字符是大小写英文字母及10个数字,不同的节点用不同的字符表示，也即无论前序遍历和中序遍历的字符串中没有重复的字符。

每组测试数据第二行是二叉树的中序遍历的结果，也是一个长度为n的字符串。

40%的测试数据1 ≤ n≤ 10；

30%的测试数据1 ≤ n≤ 20；


20%的测试数据1 ≤ n≤ 40；

10%的测试数据1 ≤ n≤ 62；

【输出形式】

对于每组测试数据，输出一行，是一个长度为n的字符串，表示二叉树后序遍历的结果。

【样例输入】


8
12457836
42758136
4
abcd
abcd
4
abcd
dcba
0
【样例输出】


47852631
dcba
dcba
*/
void binaryTree(char* pre, char* mid, int s, int e, int rootIndex) {
	if (s <= e) {
		int i = s;
		while (mid[i] != pre[rootIndex]) {
			i ++;
		}
		
		binaryTree(pre, mid, s, i - 1, rootIndex + 1);
		binaryTree(pre, mid, i + 1, e, rootIndex + 1 + (i - s));
		
		cout << mid[i];
	}   
}

int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		
		char pre[65], mid[65];
		cin >> pre;
		cin >> mid;
		
		binaryTree(pre, mid, 0, strlen(mid) - 1, 0);
		cout << endl;
	}
    return 0;
}


