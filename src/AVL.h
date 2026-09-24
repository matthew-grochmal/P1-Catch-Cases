//
// Created by matth on 9/17/2026.
//

#ifndef AVL_H
#define AVL_H

#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    string id;
    int height;
    Student* left;
    Student* right;

    Student(string name, string id);
};

class AVLTree {
private:
    Student* root;

public:
    AVLTree();
    static int getHeight(const Student* node);
    static Student* balance(Student *subRoot);
    Student* insert(const string &name, const string &id);
    bool remove(string id);
    string searchID(string id);
    vector<string> searchName(string name);
    vector<string> inorder();
    vector<string> preorder();
    vector<string> postorder();
    int levelCount();
    bool removeInorder(int n);
};

#endif