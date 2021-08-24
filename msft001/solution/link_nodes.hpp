#ifndef LINK_TREE_NODES_HPP
#define LINK_TREE_NODES_HPP

#include <string>

class Node {
public:
    Node() : left(nullptr), right(nullptr), next(nullptr), val(0) { }
    Node(int val) : left(nullptr), right(nullptr), next(nullptr), val(val) { }

    Node* left;
    Node* right;
    Node* next;
    int val;
};

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

void LinkNodes(Node* root) {
    // Breadth first search
    // We can use the newly created linked list for each row instead of
    // a queue to "remember" the previous row

    Node* first = root; // The first element of the previous row
    while (first != nullptr) {
        Node* curr_row_ptr = nullptr;
        Node* prev_row_ptr = first;
        first = nullptr;

        auto link = [&first](Node* prev, Node* curr) {
            if (prev == nullptr) {
                first = curr;
            } else {
                prev->next = curr;
            }
            return curr;
        };

        while (prev_row_ptr != nullptr) {
            if (prev_row_ptr->left != nullptr)
                curr_row_ptr = link(curr_row_ptr, prev_row_ptr->left);

            if (prev_row_ptr->right != nullptr)
                curr_row_ptr = link(curr_row_ptr, prev_row_ptr->right);

            prev_row_ptr = prev_row_ptr->next;
        }
    }
}

#endif  // LINK_TREE_NODES_HPP
