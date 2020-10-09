#include <algorithm>
#include <ctype.h>
#include <stdio.h>
#include "tree.h"
using namespace std;

int main() {
	Tree<char> bst; 
	string input, password;
	cin >> input;
	for (char c : input) {
		if (isdigit(c)) break;
		bst.insert(c);	
	}
	bst.display(input);
	while(true) {
		char c;
		c = getchar();
		if (c == EOF) break;
		password += c;
	}
	password.erase(remove(password.begin(), password.end(), '\n'), password.end());
	for (char c : password) {
		if (input.find(c) == string::npos) {
			cout << "NOT SOLVABLE\n";
			return 1;
		}
	}
	for (char c : password) bst.search(c);
	cout << "Exit the dungeon!\n";
}
