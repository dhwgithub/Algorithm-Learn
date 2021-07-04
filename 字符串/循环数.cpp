# include <iostream>
# include <cstring>
# include <string>
# include <set>

using namespace std;

/**
������������

      ѭ������nλ���ȵ������������Դ�1��n���κ�����ʱ������ԭʼ���ֵġ�ѭ������Ҳ����˵������������һ������֮������֡��ơ��ص���һ�����֣����������е��������н�����ͬ�ģ��������ǿ��ܴӲ�ͬ��λ�ÿ�ʼ�����磬����142857��ѭ���ģ����±���ʾ�� 

        142857 *1 = 142857
        142857 *2 = 285714
        142857 *3 = 428571
        142857 *4 = 571428
        142857 *5 = 714285
        142857 *6 = 857142 

       ��дһ��������ȷ�������Ƿ���ѭ������

��������ʽ��

       ����һ������������2��60λ֮��(��ע�⣬ǰ����㲻Ӧ�ñ�ɾ�������Ǳ���Ϊ��ȷ��n�Ĵ�С�ͼ�����һ���֣���ˣ���01����һ����λ�������֣��롰1����һ��һλ�������ֲ�ͬ��) ��

�������ʽ��

       ����ÿ�����룬���һ��(Yes��No)��ʶ���Ƿ���ѭ������ 

���������롿

142857
�����������

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


