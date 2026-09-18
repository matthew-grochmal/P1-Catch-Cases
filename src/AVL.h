//
// Created by matth on 9/17/2026.
//

#ifndef AVL_H
#define AVL_H

#include <string>
#include <vector>
using namespace std;

struct Node {
    string name;
    string id;
    Node* left;
    Node* right;

    Node(string name, string id) {
        this->name = name;
        this->id = id;
        left = nullptr;
        right = nullptr;
    }
};

class AVLTree {
private:
    Node* root;

public:
    AVLTree();
    bool insert(string name, string id);
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