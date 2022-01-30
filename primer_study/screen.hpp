//
//  screen.hpp
//  primer_study
//
//  Created by 申皓方 on 2022/1/14.
//

#ifndef screen_hpp
#define screen_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

#include "window_mgr.hpp"

extern const std::string::size_type PosEOF;
class Screen {
    friend void WindowMgr::Clear(WindowMgr::ScreenIdx);
public:
    using Pos = std::string::size_type;
    Screen() = default;
    Screen(Pos w, Pos h): width(w), height(h), contents(w*h, '\0'){};
    Screen(Pos w, Pos h, const char c): width(w), height(h), contents(w*h, c){};
    char Get() const {return contents[cursor];}
    char Get(Pos row, Pos col) const {
        if (col >= width || row >= height){
            return '\0';
        }
        return contents[row*width+col];
    }
    Screen &Move(Pos row, Pos col);
    inline bool Next(){
        if (cursor == PosEOF || cursor == width*height - 1){
            cursor = PosEOF;
            return false;
        }
        ++cursor;
        return true;
    }
    void ResetCursor(){
        cursor = 0;
    }
    const Screen &Display(std::ostream &os) const {
        doDisplay(os);
        return *this;
    }
    Screen &Display(std::ostream &os){
        doDisplay(os);
        return *this;
    }
    Screen &Set(char c) {
        if (cursor == PosEOF) {
            return *this;
        }
        contents[cursor] = c;
        return *this;
    }
    Screen &Set(Pos row, Pos col, char c){
        if (row >= height || col >= width) {
            return *this;
        }
        contents[row*width+col] = c;
        return *this;
    }
private:
    Pos cursor = 0;
    Pos height = 0, width = 0;
    std::string contents;
    void doDisplay(std::ostream &os) const {
        os << contents;
    }
};

inline Screen &Screen::Move(Screen::Pos row, Screen::Pos col){
    if (col >= width || row >= height){
        return *this;
    }
    cursor = row*width+col;
    return *this;
}
#endif /* screen_hpp */
