#include "display.h"


Display::Display() {
    loadSprites();
    setPlayerPosition(true);
}

void Display::loadSprites() {
    if (!treeTexture0.loadFromFile("../assets/textures/tree0.png") ||
            !treeTexture1.loadFromFile("../assets/textures/tree1.png") ||
            !treeTexture2.loadFromFile("../assets/textures/tree2.png") ||
            !playerTexture1.loadFromFile("../assets/textures/player.png") ||
            !playerTexture2.loadFromFile("../assets/textures/player1.png") ||
            !backgroundTexture.loadFromFile("../assets/textures/background.png") ||
            !font.loadFromFile("../assets/font/PressStart2P-Regular.ttf")) {
        std::cerr << "Texture loading error" << std::endl;
        exit(2);
    }

    treeSprite0.setTexture(treeTexture0);
    treeSprite1.setTexture(treeTexture1);
    treeSprite2.setTexture(treeTexture2);
    playerSprite.setTexture(playerTexture1);
    backgroundSprite.setTexture(backgroundTexture);

    treeSprite0.setOrigin((sf::Vector2f)treeTexture0.getSize() / 2.0f);
    treeSprite1.setOrigin((sf::Vector2f)treeTexture1.getSize() / 2.0f);
    treeSprite2.setOrigin((sf::Vector2f)treeTexture2.getSize() / 2.0f);
    playerSprite.setOrigin((sf::Vector2f)playerTexture1.getSize() / 2.0f);

    textPoints.setFont(font);
    textPoints.setCharacterSize(30);
    textPoints.setFillColor(sf::Color::Black);
    textPoints.setPosition(20.0, 50.0);

    textInfo.setFont(font);
    textInfo.setCharacterSize(30);
    textInfo.setFillColor(sf::Color::Black);
    textInfo.setPosition(1000.0, 50.0);
    textInfo.setString("START\nSpace");
}

void Display::setPlayerPosition(bool position) {
    if (position) { //right
        playerSprite.setScale(1.1,1.1);
        playerSprite.setPosition(800.0, 900.0);
    } else { //left
        playerSprite.setScale(-1.1,1.1);
        playerSprite.setPosition(400.0, 900.0);
    }
}

void Display::drawInfo(sf::RenderWindow* window) {
    window->draw(textInfo);
}

void Display::drawBackground(sf::RenderWindow *window) {
    window->draw(backgroundSprite);
}

void Display::drawPoints(sf::RenderWindow* window, int points) {
    textPoints.setString("Points: " + std::to_string(points));
    window->draw(textPoints);
}

void Display::drawPlayer(sf::RenderWindow* window) {
    window->draw(playerSprite);
}

void Display::drawTree(sf::RenderWindow *window, Tree* tree) {
    float posY = 900.0;

    for (int i = 0; i < 7; ++i) {
        int node = tree->get(i);

        if (node == 0) {
            treeSegments.push_back(treeSprite0);
        } else if (node == 1) {
            treeSegments.push_back(treeSprite1);
        } else if (node == 2) {
            treeSegments.push_back(treeSprite2);
        } else {
            continue;
        }

        treeSegments[i].setPosition(600.0, posY);

        window->draw(treeSegments[i]);

        posY -= 150.0;
    }

    treeSegments.clear();
}

void Display::playerAnimation(bool status) {
    if (!status) {
        playerSprite.setTexture(playerTexture2);
    } else {
        playerSprite.setTexture(playerTexture1);
    }
}
