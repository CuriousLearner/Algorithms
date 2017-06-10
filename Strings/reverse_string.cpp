#include <iostream>

using namespace std;


string reverse_and_print_str(string str) {
	int end = str.size();

	for(int i=0; i < end/2; i++) {
		swap(str[i], str[end-i-1]);
	}
	return str;
}

int main() {
	string str;
	int start, end;
	cout << "Enter string" << endl;
	cin >> str;
	str = reverse_and_print_str(str);
	cout << "Reversed string: " << str << endl;
	return 0;
}
