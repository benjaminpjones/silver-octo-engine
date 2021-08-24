#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "link_nodes.hpp"
#include "node_util.hpp"

#include <optional>

using std::nullopt;

TEST_CASE("Perfectly balanced 3 levels") {
    //      1
    //    /   \
    //   2     3
    //  / \   / \
    // 4   5 6   7
    Node* root = make_tree<Node>({1, 2, 3, 4, 5, 6, 7});

    LinkNodes(root);

    // level 0
    CHECK(root->next == nullptr);

    // level 1
    CHECK(root->left->next == root->right);
    CHECK(root->right->next == nullptr);

    // level 2
    CHECK(root->left->left->next == root->left->right);
    CHECK(root->left->right->next == root->right->left);
    CHECK(root->right->left->next == root->right->right);
    CHECK(root->right->right->next == nullptr);
}

TEST_CASE("Sparse tree") {
    //          1
    //       /     \
    //      2       3
    //     /       / \
    //    4       5   6
    //     \     / \   \
    //      7   8   9  10

    Node* root = make_tree<Node>({1, 2, 3, 4, nullopt, 5, 6, nullopt,
                                  7, 8, 9, nullopt, 10});

    LinkNodes(root);

    // level 0
    CHECK(root->next == nullptr);

    // level 1
    CHECK(root->left->next == root->right);
    CHECK(root->right->next == nullptr);

    // level 2
    CHECK(root->left->left->next == root->right->left);
    CHECK(root->right->left->next == root->right->right);
    CHECK(root->right->right->next == nullptr);

    // level 3
    CHECK(root->left->left->right->next == root->right->left->left);
    CHECK(root->right->left->left->next == root->right->left->right);
    CHECK(root->right->left->right->next == root->right->right->right);
    CHECK(root->right->right->right->next == nullptr);
}
