
#ifndef TREE_NODE_UTILS_HPP
#define TREE_NODE_UTILS_HPP

template <typename NodeT>
NodeT* make_node(std::optional<int> opt) {
    if (opt)
        return new NodeT(*opt);
    return nullptr;
}

// Creates a tree from a level-order vector representation
//
// Example Input: {1, 2, 3, nullopt, 4, 5}
//        Output:     1
//                  /   \
//                 2     3
//                  \   /
//                   4 5

template <typename NodeT>
NodeT* make_tree(std::vector<std::optional<int>> v) {
    if (!v.size())
        return nullptr;

    NodeT* head = make_node<NodeT>(v[0]);

    if (!head) return nullptr;

    std::deque<NodeT*> level = {head};

    size_t i = 1;

    while (!level.empty() && i < v.size()) {
        NodeT* t = level.front();
        level.pop_front();

        if (i < v.size()) {
            t->left = make_node<NodeT>(v[i]);
            if (t->left)
                level.push_back(t->left);
        }
        ++i;

        if (i < v.size()) {
            t->right = make_node<NodeT>(v[i]);
            if (t->right)
                level.push_back(t->right);
        }
        ++i;
    }

    return head;
}

#endif // TREE_NODE_UTILS_H
