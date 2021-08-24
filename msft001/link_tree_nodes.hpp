#ifndef LINK_TREE_NODES_HPP
#define LINK_TREE_NODES_HPP

#include <string>

class Node {
public:
    Node() : left(nullptr), right(nullptr), next(nullptr), val(0);
    Node(int val) : left(nullptr), right(nullptr), next(nullptr), val(val);

    Node* left;
    Node* right;
    Node* next;
    int val;
}

// Given a tree made by `Node`s (as defined above), link each node to the next
// one on the same level.  If a node is the right-most Node in the level, it
// does not need to have a next node.
//
// Example:
//   Input:   A            Output:   A
//          /   \                  /   \
//         B     C                B---->C
//        /     / \              /     / \
//       D     E   F            D---->E-->F

void LinkNodesInTree(Node* root) {
    // Your code here
}

#endif  // LINK_TREE_NODES_HPP
