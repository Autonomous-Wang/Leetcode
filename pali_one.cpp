#include <iostream>
#include <string>
using namespace std;

string longestPalindromw(string s){
	string str = "", ans = "";
	int len = s.length();
	int maxl = -1, cnt;
	for (int i = 0; i < len; i++){
		str += '#';
		str += s[i];
	}
	str += '#';
	cout << str << endl;
	for (int i =1; i < 2 * len; i++){
		cnt = 0;
		while ((i - cnt >= 0) && (i + cnt <= 2 * len) && (str[i - cnt] == str[i + cnt]))
			cnt++;
		cnt--;
		if (cnt > maxl){
			maxl = cnt;
			ans = s.substr((i - cnt) /2, (i + cnt) / 2 - (i -cnt) / 2);
		}
	}
	return ans;
}

int main(){
	string s = "wwaannggnnaaw";
	string a = longestPalindromw(s);
	cout << a.length() << endl;
	cout << a << endl;

}