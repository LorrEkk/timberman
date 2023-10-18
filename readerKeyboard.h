#ifndef TIMBERMAN_READERKEYBOARD_H
#define TIMBERMAN_READERKEYBOARD_H


#include "reader.h"

class ReaderKeyboard : public Reader {
public:
    ReaderKeyboard() = default;
    int clickHandler(sf::Event event) override;

    ReaderKeyboard(const ReaderKeyboard& obj) = delete;
    ReaderKeyboard& operator=(const ReaderKeyboard& obj) = delete;

};


#endif //TIMBERMAN_READERKEYBOARD_H
