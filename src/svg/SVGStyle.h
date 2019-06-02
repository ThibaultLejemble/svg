#pragma once

#include <svg/SVGColor.h>

namespace svg {

class SVGStyle
{
public:



protected:
    float       m_opacity;

    bool        m_filled;
    SVGColor    m_fill;
    float       m_fill_opacity;

    bool        m_stroked;
    SVGColor    m_stroke;
    float       stroke_width;
//    stroke-linecap    ex: round
    int stroke_miterlimit;
//    stroke-dasharray  ex: none, (a,b)
    int stroke_dashoffset;
    float stroke_opacity;
//    paint-order   ex: normal
};

} // namespace svg
