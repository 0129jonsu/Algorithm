#include <iostream>
#include <string>

using namespace std;

int main() {
	int m; //생성자
	int n; //분해합
	int count = 0; //자릿수
	int ans = 0;  //출력값
	bool a = false;
	string str; //분해합-i string

	cin >> n;

	int tmp_n = n; // 분해합 tmp
	while (tmp_n != 0) {
		tmp_n /= 10;
		count++;
	}
	
	for (int i = count * 9; i > 0 ; i--) {
		m = n - i;
		tmp_n = m;
		str = to_string(m);
		for (int j = 0; j < count; j++) {
			if (str[j] != 0) {
				m = m + str[j] - '0';
			}
		}
		if (n == m) {
			ans = tmp_n;
			a = true;
			break;
		}
	}

	if (a == false) ans = 0;

	cout << ans;

	return 0;
 }