#pragma once
#include <ncurses.h>
#include <string>

class StatusBar
{
    WINDOW *_parent;
    std::string _text;
    attr_t _attributes;

public:
    StatusBar(WINDOW *parent = stdscr)
    {
        _parent = parent;
        _text = "";
    }

    std::string getText()
    {
        return _text;
    }

    void setText(std::string text, attr_t attributes = 0)
    {
        _text = text;
        if (attributes != 0)
        {
            _attributes = attributes;
        }
    }

    attr_t getAttributes()
    {
        return _attributes;
    }

    void setAttributes(attr_t attributes)
    {
        _attributes = attributes;
    }

    void draw()
    {
        int output_row = _parent->_maxy - 1;
        attron(_attributes);
        mvwprintw(_parent, output_row, 0, getText().c_str());
        attroff(_attributes);
    }
};