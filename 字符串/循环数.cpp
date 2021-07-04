# include <iostream>
# include <cstring>
# include <string>
# include <set>

using namespace std;

/**
【问题描述】

      循环数是n位长度的整数，当乘以从1到n的任何整数时，产生原始数字的“循环”。也就是说，如果考虑最后一个数字之后的数字“绕”回到第一个数字，两个数字中的数字序列将是相同的，尽管它们可能从不同的位置开始。例如，数字142857是循环的，如下表所示： 

        142857 *1 = 142857
        142857 *2 = 285714
        142857 *3 = 428571
        142857 *4 = 571428
        142857 *5 = 714285
        142857 *6 = 857142 

       编写一个程序来确定数字是否是循环数。

【输入形式】

       输入一个数，长度在2到60位之间(请注意，前面的零不应该被删除，它们被认为是确定n的大小和计数的一部分，因此，“01”是一个两位数的数字，与“1”是一个一位数的数字不同。) 。

【输出形式】

       对于每个输入，输出一行(Yes或No)标识它是否是循环数。 

【样例输入】

142857
【样例输出】

Yes
*/
string loopFun(string s, int i, int len) {
	return s.substr(i, len) + s.substr(0, i);
}

string multi(string num, int n) {
	char ans[65];
	int index = 0;
	int len = num.size();
	
	int add = 0;
	for (int i = len - 1; i >= 0; i --) {
		int temp = (num[i] - '0') * n;
		ans[index ++] = ((temp + add) % 10) + '0';
		add = (temp + add) / 10;
	}
	
	if (add != 0) {
		ans[index ++] = add + '0';
	}
	ans[index] = '\0';
	
	for (int i = 0; i < index / 2; i ++) {
		char c = ans[i];
		ans[i] = ans[index - i - 1];
		ans[index - i - 1] = c;
	}
	
	string res = ans;
	return res;
}

int main() {
	string num;
	cin >> num;
	
	// save all loop number
	int len = num.size();
	set<string> loopSet;
	for (int i = 0; i < len; i ++) {
		loopSet.insert(loopFun(num, i, len));
	}
	
	bool flag = true;
	for (int i = 2; i <= len; i ++) {
		string res = multi(num, i);
		if (loopSet.count(res) == 0) {
			flag = false;
			break;
		}
	}
	
	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}


