#pragma once

#include <iostream>

// ! Note: I did not include fully optimized keywords preceeding the function declarations as this would be more syntax heavy
// !  rather than for helping with understanding how binary trees work.

/**
 * @brief A class representing a binary tree of integers. It supports the simple operations you'd expect to find in a binary tree.
 *       ()
 *      /  \
 *     ()  ()
 *    / \ / \
 *  () ()() ()
 * 
 */
class BinaryTree {
    private:
        /**
         * @brief A struct representing a node of the tree. Each Node will have a max of 2 children.
         * Be sure you initialize the pointers to the desired values when inserting a new node or you may segfault.
         * If you wish, you could add a Node constructor to initialize the pointers more easily.
         * However, this would add extra overhead to the Node struct (making it have the overhead of a C++ class rather than a C struct).
         * 
         */
        struct Node {
            int element; // the data stored at this node
            Node* left = nullptr; // the left child of the node
            Node* right = nullptr; // the right child of the node
        };

        Node* root; // The root node of the tree. If the tree is empty, this should be nullptr.
        size_t size; // The number of nodes in the tree.

    public:
        /**
         * @brief Default constructor which initializes an empty tree.
         * 
         * This should run in O(1) time.
         * 
         */
        BinaryTree();

        /**
         * @brief Copy constructor for the BinaryTree class. This should perform a deep copy of the tree.
         * If you are not sure what a copy constructor is, look into the rule of three (or rule of five).
         * Further, looking into l-values could be helpful for understanding the difference between a copy constructor
         *  and a move constructor.
         * Finally, the reason I pass the parameter as a constant refernece (const &) is to avoid making a copy of the parameter.
         * If the object does not have a trivial copy constructor, this can be expensive.
         * 
         * This should run in O(bt.size) time.
         * 
         * @param bt The binary tree to make a copy of.
         */
        BinaryTree(BinaryTree const &bt);

        /**
         * @brief Move constructor for the BinaryTree class. This should move the data from the parameter into the new object.
         * If you are not sure what a move constructor is, look into the rule of five.
         * Further, looking into r-values could be helpful for understanding the difference between a copy constructor.
         * Finally, the syntax on the parameter (&&) is an r-value reference. An r-value refernece can be thought of as a
         *  temporary object, and should not be used after calling the constructor or assignment operator it's passed to.
         * 
         * This shoud run in O(1) time.
         * 
         * @param bt The binary tree to move the data from.
         */
        BinaryTree(BinaryTree &&bt);

        /**
         * @brief Copy assignment operator for the BinaryTree class. This should perform a deep copy of the tree.
         * The comment for the copy constructor applies here, too.\
         * 
         * This should run in O(bt.size) time.
         * 
         * @param bt The binary tree to make a copy of.
         * @return (BinaryTree) A reference to the new BinaryTree.
         */
        BinaryTree& operator = (BinaryTree const &bt);

        /**
         * @brief Move assignment operator for the BinaryTree class. This should move the data from the parameter into the new object.
         * The comment for the move constructor applies here, too.
         * 
         * This should run in O(1) time.
         * 
         * @param bt The binary tree to move the data from.
         * @return (BinaryTree) A reference to the new BinaryTree.
         */
        BinaryTree& operator = (BinaryTree &&bt);

        /**
         * @brief The binary tree's destructor. This should free the memory used by the tree.
         * 
         * This should run in O(size) time.
         * 
         */
        ~BinaryTree();

        /**
         * @brief Return the minimum value contained in the tree. If the tree is empty, return 0.
         * 
         * This should run in O(log(size)) time in a balanced tree and O(size) time for a specific type of unbalanced tree.
         * 
         * @return (int) The min value.
         */
        int min() const;

        /**
         * @brief Return the maximum value contained in the tree. If the tree is empty, return 0.
         * 
         * This should run in O(log(size)) time in a balanced tree and O(size) time for a specific type of unbalanced tree.
         * 
         * @return (int) The max value.
         */
        int max() const;

        /**
         * @brief Return the value at the root of the tree. If the tree is empty, return 0.
         * 
         * This should run in O(1) time.
         * 
         * @return (int) The value at the root.
         */
        int root() const;

        /**
         * @brief Determine if the tree contains the value n.
         * 
         * This should run in O(log(size)) time in a balanced tree and O(size) time for a specific type of unbalanced tree.
         * 
         * @param n The integer value to search for.
         * @return 1 is the value is in the tree, and 0 if it is not. (Note: in C++ 1 = true, 0 = false)
         */
        bool contains(int n) const;

        /**
         * @brief Return a pointer to the node containing the value n. If the value is not in the tree, return nullptr.
         * 
         * This should run in O(log(size)) time in a balanced tree and O(size) time for a specific type of unbalanced tree.
         * 
         * @param n The value to find in the tree.
         * @return (Node*) The pointer to the node containing the value n.
         */
        Node* find (int n) const;

        /**
         * @brief Determine if the tree is empty.
         * 
         * This should run in O(1) time.
         * 
         * @return 1 if the tree is empty, and 0 if it is not.
         */
        bool empty() const;

        /**
         * @brief Return the number of nodes in the tree.
         * 
         * This should run in O(1) time.
         * 
         * @return (size_t) The number of nodes in the tree.
         */
        size_t size() const;

        /**
         * @brief Clear the tree of all nodes. This should free the memory used by these nodes, too.
         * 
         * This should run in O(size) time.
         * 
         */
        void clear();

        /**
         * @brief Insert a new value into the tree. If the tree already contains the value, n should not be added.
         * 
         * @param n The value to add to the tree.
         */
        void insert(int n);

        /**
         * @brief Remove a value from the tree. If the value is not in the tree, nothing should happen.
         * Be sure to properly update the tree after removing the value so that every node is still connected.
         * 
         * @param n The value to remove from the tree.
         */
        void remove(int n);
};
