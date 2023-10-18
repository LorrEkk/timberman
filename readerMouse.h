#ifndef TIMBERMAN_READERMOUSE_H
#define TIMBERMAN_READERMOUSE_H

#include "reader.h"

class ReaderMouse : public Reader {
public:
    ReaderMouse() = default;
    int clickHandler(sf::Event event) override;

    ReaderMouse(const ReaderMouse& obj) = delete;
    ReaderMouse& operator=(const ReaderMouse& obj) = delete;

};


#endif //TIMBERMAN_READERMOUSE_H
