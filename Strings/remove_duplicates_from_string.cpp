# include <iostream>

using namespace std;


string removeDuplicates(string str) {
	bool chs[256];

	memset(chs, false, sizeof chs);
	int j = 0;
	for(int i=0; i < str.size(); i++) {
		if(chs[str[i]]) {
			continue;
		}
		chs[str[i]] = true;
		str[j++] = str[i];
	}
	return str.substr(0, j);
}


int main() {
	string str;
	cout << "Enter string to remove duplicates: " << endl;
	cin >> str;
	cout << "String after removing duplicates: " << removeDuplicates(str) << endl;
	return 0;
}

