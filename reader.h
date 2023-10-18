#ifndef TIMBERMAN_READER_H
#define TIMBERMAN_READER_H

#include <SFML/Graphics.hpp>

class Reader {
public:
    Reader() = default;
    virtual ~Reader() = default;
    virtual int clickHandler(sf::Event event) = 0;

    Reader(const Reader& obj) = delete;
    Reader& operator=(const Reader& obj) = delete;

};


#endif //TIMBERMAN_READER_H
