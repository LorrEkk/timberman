#include "tree.h"


Tree::Tree() {
    loadArray();
}

void Tree::loadArray() {
    tree.clear();
    tree.push_back(0);
    tree.push_back(0);

    for (int i = 0; i < 5; ++i) {
        tree.push_back(generate());
    }
}

int Tree::generate() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::discrete_distribution<int> distrib({2, 1, 1});

    return distrib(gen);
}

int Tree::getAndGenerate() {
    int temp = tree[1];

    tree.erase(tree.begin());
    tree.push_back(generate());

    return temp;
}

int Tree::get(int index) {
    return tree[index];
}