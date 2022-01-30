//
//  window_mgr.hpp
//  primer_study
//
//  Created by 申皓方 on 2022/1/14.
//

#ifndef window_mgr_hpp
#define window_mgr_hpp

#include <stdio.h>
#include <vector>
#include <string>

class Screen;

class WindowMgr {
public:
    using ScreenIdx = std::vector<Screen>::size_type;
    void Clear(ScreenIdx);
    void AddScreen(Screen);
    Screen &GetScreen(ScreenIdx);
private:
    std::vector<Screen> screens;
};

#endif /* window_mgr_hpp */
