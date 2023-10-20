#ifndef TIMBERMAN_TREE_H
#define TIMBERMAN_TREE_H

#include <vector>
#include <random>


class Tree {
public:
    Tree();
    void loadArray();
    int getAndGenerate();
    int get(int index);

    std::vector<int> tree; // 0 - empty, 1 - left branch, 2 - right branch

    Tree(const Tree& obj) = delete;
    Tree& operator=(const Tree& obj) = delete;

private:
    int generate();
};

#endif //TIMBERMAN_TREE_H
