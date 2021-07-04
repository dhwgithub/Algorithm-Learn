# include <iostream>
# include <cstring>
# include <string>
# include <set>
# include <algorithm>
# include <cmath>
# include <vector>

using namespace std;

/**
������������

        ����n�����غ�m���ƣ���i������ֻ�ܴ򿪲��ֵơ�����a����n��m�У���aij=1ʱ��ʾ����i���Դ򿪵�j������aij=0��

   ��ʼʱ���е�m���ƶ��ǹ��ŵġ�

   ����ֻ�ܴ�״̬"��"��"��"������ζ�ţ�����ÿ�����Դ�ĳ���ƵĿ��أ������㰴���ٴΣ�����ƶ��ǿ��ġ�

   ȷ�����㰴�����п���ʱ�����еĵƶ��ܴ򿪣������Ƿ���Ժ�������ĳ������Ҳ�ܴ����еĵơ�

   ���������ȷ���Ƿ���������Ŀ��ؿ��Ժ��ԣ���ʹ�������n-1��������������m���ơ�

��������ʽ��

         �����1�а�����������n��m(1<=n, m<=2000)����ʾ���ص������͵Ƶ�������

   ��������n�У�ÿ�а���m���ַ����ַ�aij=1ʱ��ʾ����i���Դ򿪵�j������aij=0��

�������ʽ��

         ������������Ŀ��Ժ��ԵĿ��أ���ʹ������n-1�����ش����е�m���ƣ����"YES"���������"NO"��

���������롿

4 5
10101
01000
00111
10000

�����������

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


