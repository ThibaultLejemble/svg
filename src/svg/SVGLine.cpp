#include <svg/SVGLine.h>
#include <svg/Style.h>

#include <ostream>

namespace svg {

SVGLine::SVGLine(const std::string& id,
                 float x1,
                 float y1,
                 float x2,
                 float y2) :
    SVGShape(id),
    m_x1(x1),
    m_y1(y1),
    m_x2(x2),
    m_y2(y2)
{
    m_style->set_filled(false);
    m_style->set_stroked(true);
}

SVGLine::SVGLine(float x1,
                 float y1,
                 float x2,
                 float y2,
                 const std::string& id) :
    SVGShape(id),
    m_x1(x1),
    m_y1(y1),
    m_x2(x2),
    m_y2(y2)
{
    m_style->set_filled(false);
    m_style->set_stroked(true);
}

float SVGLine::x1() const
{
    return m_x1;
}

float SVGLine::y1() const
{
    return m_y1;
}

float SVGLine::x2() const
{
    return m_x2;
}

float SVGLine::y2() const
{
    return m_y2;
}

void SVGLine::set_x1(float x1)
{
    m_x1 = x1;
}

void SVGLine::set_y1(float y1)
{
    m_y1 = y1;
}

void SVGLine::set_x2(float x2)
{
    m_x2 = x2;
}

void SVGLine::set_y2(float y2)
{
    m_y2 = y2;
}

void SVGLine::print(std::ostream &os, int n) const
{
    std::string s(n, ' ');
    os << s << "<line\n"
       << s << "   x1=\"" << m_x1 << "\"\n"
       << s << "   y1=\"" << m_y1 << "\"\n"
       << s << "   x2=\"" << m_x2 << "\"\n"
       << s << "   y2=\"" << m_y2 << "\"\n";
    print_attributes(os, n+3);
    os << "/>";
}

} // namespace svg
