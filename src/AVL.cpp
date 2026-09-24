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

int AVLTree::getHeight(const Student* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int AVLTree::getBalance(Student* node) {
    if (node == nullptr) {
        return 0;
    }

    return getHeight(node->left) - getHeight(node->right);
}


Student* AVLTree::balance(Student* subRoot) {
    AVLTree tempTree = AVLTree();

    //right rotation or left-right rotation
    if (getHeight(subRoot->left) - getHeight(subRoot->right) > 1) {
        //normal right rotation
        if (subRoot->left->right == nullptr) {
            Student* tempNode = subRoot->left->right;
            tempTree.root = subRoot->left;
            tempTree.root->right = subRoot;
            subRoot->left = tempNode;
        }
        else {
            tempTree.root = subRoot->left->right;
            tempTree.insert(subRoot->left->name, subRoot->left->id);
            tempTree.insert(subRoot->name, subRoot->id);
        }
    }

    //left rotation or right-left rotation
    else if (getHeight(subRoot->right) - getHeight(subRoot->left) > 1) {
        //normal right rotation
        if (subRoot->right->left == nullptr) {
            Student* tempNode = subRoot->right->left;
            tempTree.root = subRoot->right;
            tempTree.root->left = subRoot;
            subRoot->right = tempNode;
        }
        else {
            tempTree.root = subRoot->right->left;
            tempTree.insert(subRoot->right->name, subRoot->right->id);
            tempTree.insert(subRoot->name, subRoot->id);
        }
    }
    return tempTree.root;
}

Student* AVLTree::insert(const string &name, const string &id) {
    //for root creation
    if (root == nullptr) {
        root = new Student (name, id);
        return root;
    }

    //recursive call, moves us down the tree checking left or right
    else {
        Student* current = root;

        //moves us left or right
        if (id < current->id) {
            //if empty, fills, if not, moves down one and checks again
            if (current->left == nullptr) {
                current->left = new Student (name, id);
            }
            else {
                current = current->left;
                insert(name, id);
            }
        }
        else {
            //if empty, fills, if not, moves down one and checks again
            if (current->right == nullptr) {
                current->right = new Student (name, id);
            }
            else {
                current = current->right;
                insert(name, id);
            }
        }


        //rechecks height and balance if needed
        current = balance(current);
        current->height = 1 + max(getHeight(current->left), getHeight(current->right));
        return current;
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