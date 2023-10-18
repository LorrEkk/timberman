#include "readerMouse.h"


int ReaderMouse::clickHandler(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Button::Left) {
            return 0;
        } else if (event.mouseButton.button == sf::Mouse::Button::Right) {
            return 1;
        }
    }

    return -1;
}