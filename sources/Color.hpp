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
    unsigned int color_to_int(Color color)
    {
        return static_cast<unsigned int>(color);
    }
    Color int_to_color(unsigned int color)
    {
        return static_cast<Color>(color);
    }
}