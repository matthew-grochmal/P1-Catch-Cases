//
// Created by matth on 9/17/2026.
//

#include "AVL.h"

#include <ios>
#include <bits/ios_base.h>

AVLTree::AVLTree() {
    root = nullptr;
}

Student::Student(string name, string id) {
    this->name = name;
    this->id = id;
    left = nullptr;
    right = nullptr;
    height = 1;
}

void AVLTree::insert(const string &name, const string &id) {
    //if empty, create leaf
    if (root == nullptr) {
        root = new Student (name, id);
    }
    //if not empty, check whether it's going left or right
    else {
        //moves us left or right
        if (id < root->id) {
            root = root->left;
        }
        else {
            root = root->right;
        }

        //recursive call
        insert(name, id);

        //rechecks height and balance if needed

    }


}

bool AVLTree::remove(string id) {
    return false;
}

string AVLTree::searchID(string id) {
    return "";
}

vector<string> AVLTree::searchName(string name) {
    return {};
}

vector<string> AVLTree::inorder() {
    return {};
}

vector<string> AVLTree::preorder() {
    return {};
}

vector<string> AVLTree::postorder() {
    return {};
}

int AVLTree::levelCount() {
    return 0;
}

bool AVLTree::removeInorder(int n) {
    return false;
}