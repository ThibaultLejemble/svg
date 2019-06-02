#include <svg/SVGStyle.h>

#include <ostream>

namespace svg {

SVGStyle::SVGStyle() :
    m_opacity(1),
    m_filled(true),
    m_fill(0,0,0),
    m_fill_opacity(1),
    m_stroked(false),
    m_stroke(0,0,0),
    m_stroke_width(1),
    m_stroke_linecap(Cap::Butt),
    m_stroke_linejoin(Join::Miter),
    m_stroke_miterlimit(4),
    m_stroke_dashed(false),
    m_stroke_dasharray({}),
    m_stroke_dashoffset(0),
    m_stroke_opacity(1),
    m_paint_order(Order::Normal)
{
}

std::string SVGStyle::to_string(Cap cap)
{
    switch(cap)
    {
    case Cap::Butt  : return "butt";
    case Cap::Round : return "round";
    case Cap::Square: return "square";
    default:          return "error";
    }
}

std::string SVGStyle::to_string(Join join)
{
    switch(join)
    {
    case Join::Miter: return "miter";
    case Join::Round: return "round";
    case Join::Bevel: return "bevel";
    default:          return "error";
    }
}

std::string SVGStyle::to_string(Order order)
{
    switch(order)
    {
    case Order::Normal: return "normal";
    default:            return "error";
    }
}

std::string SVGStyle::to_string(const std::vector<int> dasharray)
{
    std::string res;
    for(size_t idx=0; idx<dasharray.size(); ++idx)
    {
        res += std::to_string(dasharray[idx]);
        if(idx < dasharray.size()-1)
            res += ",";
    }
    return res;
}

float SVGStyle::opacity() const
{
    return m_opacity;
}

void SVGStyle::set_opacity(float opacity)
{
    m_opacity = opacity;
}

bool SVGStyle::is_filled() const
{
    return m_filled;
}

void SVGStyle::set_filled(bool filled)
{
    m_filled = filled;
}

const SVGColor& SVGStyle::fill() const
{
    return m_fill;
}

void SVGStyle::set_fill(const SVGColor& fill)
{
    m_fill = fill;
}

float SVGStyle::fill_opacity() const
{
    return m_fill_opacity;
}

void SVGStyle::set_fill_opacity(float opacity)
{
    m_fill_opacity = opacity;
}

bool SVGStyle::is_stroked() const
{
    return m_stroked;
}

void SVGStyle::set_stroked(bool stroked)
{
    m_stroked = stroked;
}

const SVGColor& SVGStyle::stroke() const
{
    return m_stroke;
}

void SVGStyle::set_stroke(const SVGColor& stroke)
{
    m_stroke = stroke;
}

float SVGStyle::stroke_width() const
{
    return m_stroke_width;
}

void SVGStyle::set_stroke_width(float width)
{
    m_stroke_width = width;
}

Cap SVGStyle::stroke_linecap() const
{
    return m_stroke_linecap;
}

void SVGStyle::set_stroke_linecap(Cap linecap)
{
    m_stroke_linecap = linecap;
}

Join SVGStyle::stroke_linejoin() const
{
    return m_stroke_linejoin;
}

void SVGStyle::set_stroke_linejoin(Join linejoin)
{
    m_stroke_linejoin = linejoin;
}

int SVGStyle::stroke_miterlimit() const
{
    return m_stroke_miterlimit;
}

void SVGStyle::set_stroke_miterlimit(int miterlimit)
{
    m_stroke_miterlimit = miterlimit;
}

bool SVGStyle::is_stroke_dashed() const
{
    return m_stroke_dashed;
}

void SVGStyle::set_stroke_dashed(bool dashed)
{
    m_stroke_dashed = dashed;
}

const std::vector<int>& SVGStyle::stroke_dasharray() const
{
    return m_stroke_dasharray;
}

void SVGStyle::set_stroke_dasharray(const std::vector<int>& dasharray)
{
    m_stroke_dasharray = dasharray;
}

int SVGStyle::stroke_dashoffset() const
{
    return m_stroke_dashoffset;
}

void SVGStyle::set_stroke_dashoffset(int dashoffset)
{
    m_stroke_dashoffset = dashoffset;
}

float SVGStyle::stroke_opacity() const
{
    return m_stroke_opacity;
}

void SVGStyle::set_stroke_opacity(float opacity)
{
    m_stroke_opacity = opacity;
}

Order SVGStyle::paint_order() const
{
    return m_paint_order;
}

void SVGStyle::set_paint_order(Order order)
{
    m_paint_order = order;
}

void SVGStyle::print(std::ostream& os) const
{
    os << "opacity:"            << m_opacity                                << ";"
       << "fill:"               << (m_filled ? m_fill.hexa() : "none")      << ";"
       << "fill-opacity:"       << m_fill_opacity                           << ";"
       << "stroke:"             << (m_stroked? m_stroke.hexa() : "none")    << ";"
       << "stroke-width:"       << m_stroke_width                           << ";"
       << "stroke-linecap:"     << to_string(m_stroke_linecap)              << ";"
       << "stroke-linejoin:"    << to_string(m_stroke_linejoin)             << ";"
       << "stroke-miterlimit:"  << m_stroke_miterlimit                      << ";"
       << "stroke-dasharray:"   << (m_stroke_dashed?to_string(m_stroke_dasharray):"non") << ";"
       << "stroke-dashoffset:"  << m_stroke_dashoffset                      << ";"
       << "stroke-opacity:"     << m_stroke_opacity                         << ";"
       << "paint-order:"        << to_string(m_paint_order);
}

} // namespace svg
