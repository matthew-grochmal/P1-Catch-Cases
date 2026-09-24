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
    int getHeight(const Student* node);
    int getBalance(Student* node);

    Student* balance(Student* subRoot);
    Student* rightRotate(Student* subRoot);
    Student* leftRotate(Student* subRoot);
    Student* insertNode(Student* subRoot, const string& name, const string& id);
    Student* findNode(Student* subRoot, const string& id);
    Student* findMin(Student* subRoot);

    Student* removeNode(Student* subRoot, const string& id);
    void inorderNames(Student* subRoot, vector<string>& result);
    void preorderNames(Student* subRoot, vector<string>& result);
    void postorderNames(Student* subRoot, vector<string>& result);

    void inorderIDs(Student* subRoot, vector<string>& result);
    void searchNameHelper(Student* subRoot, const string& name,
                          vector<string>& result);
    int countLevels(Student* subRoot);
    void deleteTree(Student* subRoot);

public:
    AVLTree();
    ~AVLTree();
    bool insert(const string& name, const string& id);
    bool remove(const string& id);

    string searchID(const string& id);
    vector<string> searchName(const string& name);
    vector<string> inorder();
    vector<string> preorder();
    vector<string> postorder();

    int levelCount();
    bool removeInorder(int n);
};

#endif