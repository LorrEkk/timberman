#ifndef TIMBERMAN_ENGINE_H
#define TIMBERMAN_ENGINE_H

#include <SFML/Graphics.hpp>
#include "tree.h"
#include "display.h"
#include "reader.h"
#include "readerKeyboard.h"
#include "readerMouse.h"


class Engine {
public:
    Engine();
    ~Engine();
    void play();

    Engine(const Engine& obj) = delete;
    Engine& operator=(const Engine& obj) = delete;

private:
    void playerAction(int position);
    void cutTree();

    Tree* tree;
    Display* display;
    Reader* reader;
    ReaderKeyboard readerKeyboard;
    ReaderMouse readerMouse;
    sf::RenderWindow* window;
    sf::Clock clock;
    bool currentPosition, playerAnimationStatus;
    bool gameStatus; //false - stopped, true - game running
    int points;
};


#endif //TIMBERMAN_ENGINE_H
