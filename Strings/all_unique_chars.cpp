# include <iostream>

using namespace std;

bool has_all_unique_chars(string str) {
	bool chs[256];

	memset(chs, false, sizeof(chs));

	for(int i=0; i < str.size(); i++) {
		if (chs[str[i]]) {
			return false;
		}
		chs[str[i]] = true;
	}
	return true;
}


int main() {

	string str;
	cout << "Enter a string to check for unique_chars" << endl;
	cin >> str;

	cout << "Given string has all unique_chars: " << has_all_unique_chars(str) << endl;
	return 0;
}

