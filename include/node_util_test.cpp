#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "node_util.hpp"

#include <optional>

using std::nullopt;

class TreeNode {
public:
    TreeNode(int val) : val(val) { }

    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    int val = 0;
};

TEST_CASE("make_tree") {
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7
    TreeNode* root = make_tree<TreeNode>({1, 2, 3, 4, 5, 6, 7});
    
    CHECK(root != nullptr);
    CHECK(root->val == 1);

    CHECK(root->left != nullptr);
    CHECK(root->left->val == 2);
    CHECK(root->right != nullptr);
    CHECK(root->right->val == 3);

    CHECK(root->left->left != nullptr);
    CHECK(root->left->left->val == 4);
    CHECK(root->left->right != nullptr);
    CHECK(root->left->right->val == 5);

    CHECK(root->right->left != nullptr);
    CHECK(root->right->left->val == 6);
    CHECK(root->right->right != nullptr);
    CHECK(root->right->right->val == 7);

    CHECK(root->left->left->left == nullptr);
    CHECK(root->left->left->right == nullptr);
    CHECK(root->left->right->left == nullptr);
    CHECK(root->left->right->right == nullptr);
    CHECK(root->right->left->left == nullptr);
    CHECK(root->right->left->right == nullptr);
    CHECK(root->right->right->left == nullptr);
    CHECK(root->right->right->right == nullptr);
}

TEST_CASE("unbalanced make_tree") {
    //   1
    //  /
    // 2
    //  \
    //   3
    //  /
    // 4
    TreeNode* root = make_tree<TreeNode>({1, 2, nullopt, nullopt, 3, 4});

    CHECK(root->val == 1);
    CHECK(root->left != nullptr);
    CHECK(root->right == nullptr);

    CHECK(root->left->val == 2);
    CHECK(root->left->left == nullptr);
    CHECK(root->left->right != nullptr);

    CHECK(root->left->right->val == 3);
    CHECK(root->left->right->left != nullptr);
    CHECK(root->left->right->right == nullptr);

    CHECK(root->left->right->left->val == 4);
    CHECK(root->left->right->left->left == nullptr);
    CHECK(root->left->right->left->right == nullptr);
}
