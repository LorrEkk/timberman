#include "engine.h"


Engine::Engine() {
    window = new sf::RenderWindow(sf::VideoMode(1200, 1050), "Timberman", sf::Style::Close);
    tree = new Tree();
    display = new Display();
    currentPosition = true;
    gameStatus = false;
    points = 0;
    playerAnimationStatus = false;

//  uncomment one of the following lines to select control device
    reader = &readerKeyboard;
//    reader = &readerMouse;
}

Engine::~Engine() {
    delete window;
    delete tree;
    delete display;
    delete reader;
}

void Engine::play() {
    window->setFramerateLimit(60);

    sf::Time time = sf::milliseconds(40);

    while (window->isOpen()) {
        sf::Event event{};

        while (window->pollEvent(event)) {
            if (gameStatus && (event.type == sf::Event::KeyPressed ||
                event.type == sf::Event::MouseButtonPressed)) {
                playerAction(reader->clickHandler(event));
            } else if (!gameStatus && event.key.code == sf::Keyboard::Space ) {
                tree->loadArray();
                points = 0;
                gameStatus = true;
            } else if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        window->clear(sf::Color::White);
        display->drawBackground(window);

        if (!gameStatus) {
            display->drawInfo(window);
        }

        display->drawPoints(window, points);
        display->drawTree(window, tree);

        if (playerAnimationStatus && clock.getElapsedTime() > time) {
            display->playerAnimation(true);
            playerAnimationStatus = false;
        }

        display->drawPlayer(window);
        window->display();

    }
}

void Engine::playerAction(int position) {
    if (position != -1) {
        currentPosition = static_cast<bool>(position);

        display->playerAnimation(false);
        clock.restart();
        playerAnimationStatus = true;

        display->setPlayerPosition(currentPosition);
        cutTree();
    }
}

void Engine::cutTree() {
    int treeStatus = tree->getAndGenerate();

    if ((treeStatus == 1 && !currentPosition) || (treeStatus == 2 && currentPosition)) {
        gameStatus = false;
    } else {
        points++;
    }
}
