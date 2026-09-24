#include <iostream>
#include "AVL.h"
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

bool validName(const string& name) {
	if (name.empty()) {
		return false;
	}

	for (char c : name) {
		if (!isalpha(c) && c != ' ') {
			return false;
		}
	}

	return true;
}

bool validID(const string& id) {
	if (id.length() != 8) {
		return false;
	}
	for (char c : id) {
		if (!isdigit(c)) {
			return false;
		}
	}

	return true;
}

int main(){
	AVLTree tree;

	int commands;
	cin >> commands;
	cin.ignore();

	for (int i = 0; i < commands; ++i) {
		string line;
		getline(cin, line);

		stringstream ss(line);

		string command;
		ss >> command;

		if (command == "insert") {
			string name;
			string id;

			ss >> ws;
			ss.get();
			getline(ss, name, '"');

			ss >> id;

			if (validName(name) && validID(id)) {
				if (tree.insert(name, id)) {
					cout << "successful" << endl;
				}
				else {
					cout << "unsuccessful" << endl;
				}
			}
			else {
				cout << "unsuccessful" << endl;
			}
		}

		else if (command == "remove") {
			string id;
			ss >> id;

			if (validID(id) && tree.remove(id)) {
				cout << "successful" << endl;
			}
			else {
				cout << "unsuccessful" << endl;
			}
		}

		else if (command == "search") {
			string searchValue;
			ss >> ws;

			if (ss.peek() == '"') {
				ss.get();
				getline(ss, searchValue, '"');

				vector<string> results = tree.searchName(searchValue);

				if (results.empty()) {
					cout << "unsuccessful" << endl;
				}
				else {
					for (string id : results) {
						cout << id << endl;
					}
				}
			}
			else {
				ss >> searchValue;

				if (!validID(searchValue)) {
					cout << "unsuccessful" << endl;
				}
				else {
					string result = tree.searchID(searchValue);

					if (result.empty()) {
						cout << "unsuccessful" << endl;
					}
					else {
						cout << result << endl;
					}
				}
			}
		}
		else if (command == "printInorder") {
			vector<string> results = tree.inorder();

			for (size_t j = 0; j < results.size(); j++) {
				cout << results[j];

				if (j != results.size() - 1) {
					cout << ", ";
				}
			}

			cout << endl;
		}

		else if (command == "printPreorder") {
			vector<string> results = tree.preorder();

			for (size_t j = 0; j < results.size(); j++) {
				cout << results[j];

				if (j != results.size() - 1) {
					cout << ", ";
				}
			}

			cout << endl;
		}

		else if (command == "printPostorder") {
			vector<string> results = tree.postorder();

			for (size_t j = 0; j < results.size(); j++) {
				cout << results[j];

				if (j != results.size() - 1) {
					cout << ", ";
				}
			}

			cout << endl;
		}

		else if (command == "printLevelCount") {
			cout << tree.levelCount() << endl;
		}

		else if (command == "removeInorder") {
			int n;
			ss >> n;

			if (tree.removeInorder(n)) {
				cout << "successful" << endl;
			}
			else {
				cout << "unsuccessful" << endl;
			}
		}

		else {
			cout << "unsuccessful" << endl;
		}
	}

	return 0;
}
