#include "readerKeyboard.h"


int ReaderKeyboard::clickHandler(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
            return 0;
        } else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
            return 1;
        }
    }

    return -1;
}
