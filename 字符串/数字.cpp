# include <iostream>
# include <sstream>

using namespace std;

/**
������������

��� ����n ������n�ı�����������

��������ʽ��

������ m,n��0<m��n<1000000��

�������ʽ��

��С�������еĲ����� m ������������������n��������n�ı�������

����������1��

20 7
���������1��

7 14 17
����������2��

200 11
���������2��

11 22 33 44 55 66 77 88 99 110 111 112 113 114 115 116 117 118 119 121 132 143 154 165 176 187 198
������˵����

����n�������Կ���ʹ���ַ������ҽ��
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


