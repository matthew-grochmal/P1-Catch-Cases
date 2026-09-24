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

    Student(const string &name, const string &id);
};

class AVLTree {
private:
    Student* root;
    static int getHeight(const Student* node);
    static int getBalance(const Student* node);
    static Student* balance(Student* subRoot);
    static Student* rightRotate(Student* subRoot);
    static Student* leftRotate(Student* subRoot);
    Student* insertNode(Student* subRoot, const string& name, const string& id);
    static Student* findNode(Student* subRoot, const string& id);
    Student* findMin(Student* subRoot);

    Student* removeNode(Student* subRoot, const string& id);
    static void inorderNames(const Student* subRoot, vector<string>& result);
    static void preorderNames(const Student* subRoot, vector<string>& result);
    static void postorderNames(const Student* subRoot, vector<string>& result);
    static void inorderIDs(const Student* subRoot, vector<string>& result);
    static void searchNameHelper(const Student* subRoot, const string& name,
                                 vector<string>& result);
    static int countLevels(const Student* subRoot);
    static void deleteTree(const Student* subRoot);

public:
    AVLTree();
    ~AVLTree();
    bool insert(const string& name, const string& id);
    bool remove(const string& id);
    string searchID(const string& id) const;
    vector<string> searchName(const string& name) const;
    vector<string> inorder() const;
    vector<string> preorder() const;
    vector<string> postorder() const;
    int levelCount() const;
    bool removeInorder(int n);
};

#endif