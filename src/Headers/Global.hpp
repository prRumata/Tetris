#pragma once

constexpr unsigned char CELL_SIZE = 8;
constexpr unsigned char COLUMNS = 10;
constexpr unsigned char ROWS = 20;
constexpr unsigned char SCREEN_RESIZE = 4;

constexpr unsigned char CELL_COLORS_SIZE = 7;
enum CELL_COLORS
{
    CC_GREY        = 0,
    CC_RED         = 1,
    CC_GREEN       = 2,
    CC_BLUE        = 3,
    CC_YELLOW      = 4,
    CC_MAGENTA     = 5,
    CC_CYAN        = 6
};

constexpr unsigned int FALL_SPEED = 300;
constexpr unsigned int FALL_FASTER_SPEED = 50;
constexpr unsigned int MOVE_SPEED = 75;
