#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "AVL.h"
using namespace std;

//Matthew Grochmal
//35490862
// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
TEST_CASE("5 Invalid insert commands", "[insert]"){
	// instantiate any class members that you need to test here
	AVLTree tree;

	// anything that evaluates to false in a REQUIRE block will result in a failing test
	REQUIRE(tree.insert("Jimmy John", "1234567") == false);
	REQUIRE(tree.insert("Jimmy John", "123456789") == false);
	REQUIRE(tree.insert("Jim123", "12345678") == false);
	REQUIRE(tree.insert("Jimmy John", "1234abcd") == false);
	tree.insert("Jimmy John", "12345678");
	REQUIRE(tree.insert("Jimmy John", "12345678") == false);

	// all REQUIRE blocks must evaluate to true for the whole test to pass

}

TEST_CASE("Basic insertion/inorder traversal", "[insert]"){

	AVLTree tree;

	REQUIRE(tree.insert("Jimmy", "45678888") == true);
	REQUIRE(tree.insert("Jonathan", "12348888") == true);
	REQUIRE(tree.insert("John", "12345678") == true);
	REQUIRE(tree.insert("Jack", "12345679") == true);
	REQUIRE(tree.insert("Jayden", "13456789") == true);

vector <string> expected =
	{"Jimmy", "Jonathan", "John", "Jack", "Jayden"};
	REQUIRE(tree.inorder() == expected);
	// each section runs the setup code independently to ensure that they don't affect each other
}

// you must write 5 unique, meaningful tests for credit on the testing portion of this project!

// the provided test from the template is below.

TEST_CASE("AVL Double Left", "[rotate]"){
	AVLTree tree;

	tree.insert("Three", "33333333");
	tree.insert("Two", "22222222");
	tree.insert("One", "11111111");

	vector<string> expected {
	"Two", "One", "Three"};

	REQUIRE(tree.preorder() == expected);
}

TEST_CASE("AVL Double Right", "[rotate]") {
	AVLTree tree;

	tree.insert("One", "11111111");
	tree.insert("Two", "22222222");
	tree.insert("Three", "33333333");

	vector<string> expected{
	"Two", "One", "Three"};

	REQUIRE(tree.preorder() == expected);
}

TEST_CASE("AVL Left-Right", "[rotate]") {
	AVLTree tree;

	tree.insert("Three", "33333333");
	tree.insert("One", "11111111");
	tree.insert("Two", "22222222");

	vector<string> expected{
	"Two", "One", "Three"};

	REQUIRE(tree.preorder() == expected);
}

TEST_CASE("AVL Right-Left", "[rotate]") {
	AVLTree tree;

	tree.insert("One", "11111111");
	tree.insert("Three", "33333333");
	tree.insert("Two", "22222222");

	vector<string> expected{
	"Two", "One", "Three"};

	REQUIRE(tree.preorder() == expected);
}

TEST_CASE("Insert/Remove", "[large]") {
	AVLTree tree;

	for (int i = 0; i< 100; i++) {
		string id = to_string(10000000 + i);

		REQUIRE(tree.insert("Random Dude", id) == true);
	}

	vector<string> result = tree.inorder();

	REQUIRE(result.size() == 100);
	REQUIRE(tree.remove("10000005") == true);
	REQUIRE(tree.remove("10000012") == true);
	REQUIRE(tree.remove("10000023") == true);
	REQUIRE(tree.remove("10000031") == true);
	REQUIRE(tree.remove("10000044") == true);
	REQUIRE(tree.remove("10000057") == true);
	REQUIRE(tree.remove("10000063") == true);
	REQUIRE(tree.remove("10000076") == true);
	REQUIRE(tree.remove("10000088") == true);
	REQUIRE(tree.remove("10000095") == true);

	result = tree.inorder();

	REQUIRE(result.size() == 90);
}

TEST_CASE("Remove Node", "[remove]") {
	AVLTree tree;

	tree.insert("Four", "44444444");
	tree.insert("Two", "22222222");
	tree.insert("Six", "66666666");
	tree.insert("One", "11111111");
	tree.insert("Five", "55555555");
	tree.insert("Seven", "77777777");

	REQUIRE(tree.remove("44444444") == true);

	vector<string> expected ={
		"Five", "Two", "One", "Three", "Six", "Seven"
	};

	REQUIRE(tree.preorder() == expected);
}