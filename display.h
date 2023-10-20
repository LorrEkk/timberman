#ifndef TIMBERMAN_DISPLAY_H
#define TIMBERMAN_DISPLAY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "tree.h"


class Display {
public:
    Display();
    void setPlayerPosition(bool position);
    void playerAnimation(bool status);
    void drawInfo(sf::RenderWindow* window);
    void drawPoints(sf::RenderWindow* window, int points);
    void drawPlayer(sf::RenderWindow* window);
    void drawTree(sf::RenderWindow* window, Tree* tree);
    void drawBackground(sf::RenderWindow* window);

    Display(const Display& obj) = delete;
    Display& operator=(const Display& obj) = delete;

private:
    void loadSprites();

    std::vector<sf::Sprite> treeSegments;
    sf:: Texture treeTexture0, treeTexture1, treeTexture2, playerTexture1, playerTexture2, backgroundTexture; //tree-empty, tree-left, tree-right, player, background
    sf::Sprite treeSprite0, treeSprite1, treeSprite2, playerSprite, backgroundSprite; //tree-empty, tree-left, tree-right, player, background
    sf::Text textPoints, textInfo;
};


#endif //TIMBERMAN_DISPLAY_H
