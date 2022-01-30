//
//  window_mgr.cpp
//  primer_study
//
//  Created by 申皓方 on 2022/1/14.
//

#include "window_mgr.hpp"

#include "screen.hpp"

void WindowMgr::Clear(WindowMgr::ScreenIdx idx) {
    if (idx >= screens.size()){
        return;
    }
    Screen &s = screens[idx];
    s.contents = std::string(s.width * s.height, ' ');
}

void WindowMgr::AddScreen(Screen s){
    screens.push_back(s);
}

Screen &WindowMgr::GetScreen(WindowMgr::ScreenIdx idx){
    if (idx >= screens.size()){
        throw std::runtime_error("idx is out of range");
    }
    return screens[idx];
}
