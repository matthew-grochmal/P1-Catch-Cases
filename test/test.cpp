#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "AVL.h"
using namespace std;

//Matthew Grochmal
//UF ID: 35490862

TEST_CASE("Invalid Operations and Edge Cases", "[SEARCH][INSERT][REMOVAL]") {

    AVLTree tree;

    // valid insert
    REQUIRE(tree.insert("Alice Smith", "12345678"));
    // dupe id
    REQUIRE_FALSE(tree.insert("Bob Jones", "12345678"));
    // invalid remove id
    REQUIRE_FALSE(tree.remove("99999999"));
    // invalid search id
    REQUIRE(tree.searchID("99999999") == "");
    // invalid searchi id
    REQUIRE(tree.searchName("Nobody").empty());
    // remove out of range
    REQUIRE_FALSE(tree.removeInorder(10));
    // remove negative
    REQUIRE_FALSE(tree.removeInorder(-1));
    // valid search
    REQUIRE(tree.searchID("12345678") == "Alice Smith");
}



TEST_CASE("All Four AVL Rotations", "[ROTATIONS]")  {

    // right
    {
        AVLTree tree;

        REQUIRE(tree.insert("C", "00000030"));
        REQUIRE(tree.insert("B", "00000020"));
        REQUIRE(tree.insert("A", "00000010"));

        vector<string> result = tree.preorder();

        REQUIRE(result.size() == 3);
        REQUIRE(result[0] == "B");
        REQUIRE(tree.levelCount() == 2);
    }

    // left
    {
        AVLTree tree;

        REQUIRE(tree.insert("A", "00000010"));
        REQUIRE(tree.insert("B", "00000020"));
        REQUIRE(tree.insert("C", "00000030"));

        vector<string> result = tree.preorder();

        REQUIRE(result.size() == 3);
        REQUIRE(result[0] == "B");
        REQUIRE(tree.levelCount() == 2);
    }

    // left-right
    {
        AVLTree tree;

        REQUIRE(tree.insert("C", "00000030"));
        REQUIRE(tree.insert("A", "00000010"));
        REQUIRE(tree.insert("B", "00000020"));

        vector<string> result = tree.preorder();

        REQUIRE(result.size() == 3);
        REQUIRE(result[0] == "B");
        REQUIRE(tree.levelCount() == 2);
    }

    // right-left
    {
        AVLTree tree;

        REQUIRE(tree.insert("A", "00000010"));
        REQUIRE(tree.insert("C", "00000030"));
        REQUIRE(tree.insert("B", "00000020"));

        vector<string> result = tree.preorder();

        REQUIRE(result.size() == 3);
        REQUIRE(result[0] == "B");
        REQUIRE(tree.levelCount() == 2);
    }
}



TEST_CASE("All Three Deletion Cases", "[DELETION]") {

    //none
    {
        AVLTree tree;

        REQUIRE(tree.insert("A", "00000010"));
        REQUIRE(tree.insert("B", "00000020"));

        REQUIRE(tree.remove("00000020"));

        REQUIRE(tree.searchID("00000020") == "");
        REQUIRE(tree.searchID("00000010") == "A");
    }

    // 1
    {
        AVLTree tree;

        REQUIRE(tree.insert("A", "00000020"));
        REQUIRE(tree.insert("B", "00000010"));
        REQUIRE(tree.insert("C", "00000005"));

        REQUIRE(tree.remove("00000010"));

        REQUIRE(tree.searchID("00000010") == "");
        REQUIRE(tree.searchID("00000005") == "C");
        REQUIRE(tree.searchID("00000020") == "A");
    }

    // 2
    {
        AVLTree tree;

        REQUIRE(tree.insert("A", "00000050"));
        REQUIRE(tree.insert("B", "00000030"));
        REQUIRE(tree.insert("C", "00000070"));
        REQUIRE(tree.insert("D", "00000060"));
        REQUIRE(tree.insert("E", "00000080"));

        REQUIRE(tree.remove("00000050"));

        REQUIRE(tree.searchID("00000050") == "");
        REQUIRE(tree.searchID("00000060") == "D");
        REQUIRE(tree.searchID("00000030") == "B");
        REQUIRE(tree.searchID("00000070") == "C");
        REQUIRE(tree.searchID("00000080") == "E");
    }
}



TEST_CASE("Search Traversals and Inorder Removal", "[SEARCH][INSERT][ORDER][REMOVAL]") {

    AVLTree tree;

    //insert
    REQUIRE(tree.insert("Alice", "12345678"));
    REQUIRE(tree.insert("Bob", "23456789"));
    REQUIRE(tree.insert("Alice", "34567890"));
    // id search
    REQUIRE(tree.searchID("12345678") == "Alice");
    REQUIRE(tree.searchID("23456789") == "Bob");
    // name search
    vector<string> aliceIDs = tree.searchName("Alice");

    REQUIRE(aliceIDs.size() == 2);

    // inorder
    vector<string> inorder = tree.inorder();

    REQUIRE(inorder.size() == 3);
    REQUIRE(inorder[0] == "Alice");
    REQUIRE(inorder[1] == "Bob");
    REQUIRE(inorder[2] == "Alice");

    // preorder
    vector<string> preorder = tree.preorder();

    REQUIRE(preorder.size() == 3);

    // postorder
    vector<string> postorder = tree.postorder();

    REQUIRE(postorder.size() == 3);

    // level counting
    REQUIRE(tree.levelCount() >= 2);

    // remove by inorder
    REQUIRE(tree.removeInorder(0));

    REQUIRE(tree.searchID("12345678") == "");
    REQUIRE(tree.inorder().size() == 2);
}



TEST_CASE("100 Insertions and 10 Removals", "[INSERTION][REMOVAL][ORDER]") {
    AVLTree tree;

    // 100 insertions
    for (int i = 0; i < 100; i++) {

        string id = to_string(10000000 + i);

        REQUIRE(tree.insert("Student " + to_string(i), id));
    }

    // check 100 nodes
    vector<string> inorder = tree.inorderIDs();

    REQUIRE(inorder.size() == 100);

    // 10 removals
    REQUIRE(tree.remove("10000010"));
    REQUIRE(tree.remove("10000020"));
    REQUIRE(tree.remove("10000030"));
    REQUIRE(tree.remove("10000040"));
    REQUIRE(tree.remove("10000050"));
    REQUIRE(tree.remove("10000060"));
    REQUIRE(tree.remove("10000070"));
    REQUIRE(tree.remove("10000080"));
    REQUIRE(tree.remove("10000090"));
    REQUIRE(tree.remove("10000099"));

    // 90 nodes
    inorder = tree.inorderIDs();

    REQUIRE(inorder.size() == 90);

    // sort?
    for (size_t i = 1; i < inorder.size(); i++) {
        REQUIRE(inorder[i - 1] < inorder[i]);
    }

    // removal
    REQUIRE(tree.searchID("10000010") == "");
    REQUIRE(tree.searchID("10000020") == "");
    REQUIRE(tree.searchID("10000030") == "");
    REQUIRE(tree.searchID("10000040") == "");
    REQUIRE(tree.searchID("10000050") == "");
    REQUIRE(tree.searchID("10000060") == "");
    REQUIRE(tree.searchID("10000070") == "");
    REQUIRE(tree.searchID("10000080") == "");
    REQUIRE(tree.searchID("10000090") == "");
    REQUIRE(tree.searchID("10000099") == "");
}