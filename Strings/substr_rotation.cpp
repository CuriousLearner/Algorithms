/* 
Assume you have a method isSubstring which checks
if one word is a substring of another string. 
Given two strings s1, and s2. write code to check
if s2 is a rotation of s1 using only one call to
isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).
*/

# include <iostream>

using namespace std;

bool isSubstring(string str1, string str2) {
	return (str1.find(str2) != string::npos);
}

bool isRotation(string s1, string s2) {
	string tmp = s1 + s1;

	return isSubstring(tmp, s2);
}

int main() {
	string str1 = "erbottlewat";
	string str2 = "waterbottle";

	cout << "Is Rotation? " << isRotation(str1, str2);
}
