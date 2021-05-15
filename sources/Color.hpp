#pragma once

namespace pandemic
{
    enum Color
    {
        Blue,
        Yellow,
        Red,
        Black
    };
    int color_to_int(Color color)
    {
        return static_cast<int>(color);
    }
    Color int_to_color(int color)
    {
        return static_cast<Color>(color);
    }
}