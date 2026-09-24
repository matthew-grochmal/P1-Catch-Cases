//
// Created by matth on 9/17/2026.
//

#include "AVL.h"

#include <ios>
#include <bits/ios_base.h>
#include <algorithm>

using namespace std;

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    deleteTree(root);
}

Student::Student(const string &name, const string &id) {
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

int AVLTree::getBalance(const Student* node) {
    if (node == nullptr) {
        return 0;
    }

    return getHeight(node->left) - getHeight(node->right);
}


Student* AVLTree::rightRotate(Student* subRoot) {
    Student* newRoot = subRoot->left;
    Student* tempNode = newRoot->right;

    newRoot->right = subRoot;
    subRoot->left = tempNode;

    subRoot->height = 1 + max(getHeight(subRoot->left),
                              getHeight(subRoot->right));

    newRoot->height = 1 + max(getHeight(newRoot->left),
                              getHeight(newRoot->right));
    return newRoot;
}

Student* AVLTree::leftRotate(Student* subRoot) {
    Student* newRoot = subRoot->right;
    Student* tempNode = newRoot->left;

    newRoot->left = subRoot;
    subRoot->right = tempNode;

    subRoot->height = 1 + max(getHeight(subRoot->left),
                              getHeight(subRoot->right));

    newRoot->height = 1 + max(getHeight(newRoot->left),
                              getHeight(newRoot->right));
    return newRoot;
}

Student* AVLTree::balance(Student* subRoot) {
    if (subRoot == nullptr) {
        return nullptr;
    }

    subRoot->height = 1 + max(getHeight(subRoot->left),
                              getHeight(subRoot->right));

    int balanceFactor = getBalance(subRoot);


    // Left heavy
    if (balanceFactor > 1) {

        // LR case
        if (getBalance(subRoot->left) < 0) {
            subRoot->left = leftRotate(subRoot->left);
        }
        // LL case
        return rightRotate(subRoot);
    }

    // Right heavy
    if (balanceFactor < -1) {

        // RL case
        if (getBalance(subRoot->right) > 0) {
            subRoot->right = rightRotate(subRoot->right);
        }
        // RR case
        return leftRotate(subRoot);
    }
    return subRoot;
}

Student* AVLTree::insertNode(Student* subRoot,
                             const string& name,
                             const string& id) {
    if (subRoot == nullptr) {
        return new Student(name, id);
    }

    if (id < subRoot->id) {
        subRoot->left = insertNode(subRoot->left, name, id);
    }
    else if (id > subRoot->id) {
        subRoot->right = insertNode(subRoot->right, name, id);
    }
    return balance(subRoot);
}

bool AVLTree::insert(const string& name, const string& id) {
    if (findNode(root, id) != nullptr) {
        return false;
    }
    root = insertNode(root, name, id);

    return true;
}

Student* AVLTree::findNode(Student* subRoot, const string& id) {
    if (subRoot == nullptr) {
        return nullptr;
    }

    if (id == subRoot->id) {
        return subRoot;
    }

    if (id < subRoot->id) {
        return findNode(subRoot->left, id);
    }
    return findNode(subRoot->right, id);
}

Student* AVLTree::findMin(Student* subRoot) {
    Student* current = subRoot;

    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Student* AVLTree::removeNode(Student* subRoot, const string& id) {
    if (subRoot == nullptr) {
        return nullptr;
    }

    if (id < subRoot->id) {
        subRoot->left = removeNode(subRoot->left, id);
    }
    else if (id > subRoot->id) {
        subRoot->right = removeNode(subRoot->right, id);
    }
    else {

        // No children
        if (subRoot->left == nullptr && subRoot->right == nullptr) {
            delete subRoot;
            return nullptr;
        }

        // One right child
        if (subRoot->left == nullptr) {
            Student* tempNode = subRoot->right;
            delete subRoot;
            return tempNode;
        }

        // One left child
        if (subRoot->right == nullptr) {
            Student* tempNode = subRoot->left;
            delete subRoot;
            return tempNode;
        }



        // Two children
        // Use inorder successor
        Student* successor = findMin(subRoot->right);

        subRoot->name = successor->name;
        subRoot->id = successor->id;

        subRoot->right = removeNode(subRoot->right, successor->id);
    }

    return balance(subRoot);
}

bool AVLTree::remove(const string& id) {
    if (findNode(root, id) == nullptr) {
        return false;
    }

    root = removeNode(root, id);

    return true;
}

string AVLTree::searchID(const string& id) const {
    Student* result = findNode(root, id);

    if (result == nullptr) {
        return "";
    }

    return result->name;
}

void AVLTree::searchNameHelper(const Student* subRoot,
                                const string& name,
                                vector<string>& result) {
    if (subRoot == nullptr) {
        return;
    }

    // Preorder
    if (subRoot->name == name) {
        result.push_back(subRoot->id);
    }

    searchNameHelper(subRoot->left, name, result);
    searchNameHelper(subRoot->right, name, result);
}

vector<string> AVLTree::searchName(const string& name) const {
    vector<string> result;

    searchNameHelper(root, name, result);

    return result;
}

void AVLTree::inorderNames(const Student* subRoot, vector<string>& result) {
    if (subRoot == nullptr) {
        return;
    }

    inorderNames(subRoot->left, result);
    result.push_back(subRoot->name);
    inorderNames(subRoot->right, result);
}

vector<string> AVLTree::inorder() const {
    vector<string> result;

    inorderNames(root, result);

    return result;
}

void AVLTree::preorderNames(const Student* subRoot, vector<string>& result) {
    if (subRoot == nullptr) {
        return;
    }

    result.push_back(subRoot->name);
    preorderNames(subRoot->left, result);
    preorderNames(subRoot->right, result);
}

vector<string> AVLTree::preorder() const {
    vector<string> result;
    preorderNames(root, result);
    return result;
}

void AVLTree::postorderNames(const Student* subRoot, vector<string>& result) {
    if (subRoot == nullptr) {
        return;
    }
    postorderNames(subRoot->left, result);
    postorderNames(subRoot->right, result);
    result.push_back(subRoot->name);
}

vector<string> AVLTree::postorder() const {
    vector<string> result;

    postorderNames(root, result);

    return result;
}

void AVLTree::inorderIDs(const Student* subRoot, vector<string>& result) {
    if (subRoot == nullptr) {
        return;
    }

    inorderIDs(subRoot->left, result);
    result.push_back(subRoot->id);
    inorderIDs(subRoot->right, result);
}

bool AVLTree::removeInorder(int n) {
    vector<string> ids;

    inorderIDs(root, ids);

    if (n < 0 || n >= static_cast<int>(ids.size())) {
        return false;
    }

    return remove(ids[n]);
}

int AVLTree::countLevels(const Student* subRoot) {
    if (subRoot == nullptr) {
        return 0;
    }

    int leftLevels = countLevels(subRoot->left);
    int rightLevels = countLevels(subRoot->right);

    return 1 + max(leftLevels, rightLevels);
}

int AVLTree::levelCount() const {
    return countLevels(root);
}

void AVLTree::deleteTree(const Student* subRoot) {
    if (subRoot == nullptr) {
        return;
    }

    deleteTree(subRoot->left);
    deleteTree(subRoot->right);
    delete subRoot;
}