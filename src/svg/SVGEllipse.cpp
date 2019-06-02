#include <svg/SVGEllipse.h>
#include <svg/SVGStyle.h>

#include <ostream>

namespace svg {

SVGEllipse::SVGEllipse(const std::string& id,
                      float x,
                      float y,
                      float rx,
                      float ry) :
    SVGShape(id),
    m_x(x),
    m_y(y),
    m_rx(rx),
    m_ry(ry)
{
}

SVGEllipse::SVGEllipse(float x,
                       float y,
                       float rx,
                       float ry,
                       const std::string& id) :
    SVGShape(id),
    m_x(x),
    m_y(y),
    m_rx(rx),
    m_ry(ry)
{
}

float SVGEllipse::x() const
{
    return m_x;
}

float SVGEllipse::y() const
{
    return m_y;
}

float SVGEllipse::rx() const
{
    return m_rx;
}

float SVGEllipse::ry() const
{
    return m_ry;
}

void SVGEllipse::set_x(float x)
{
    m_x = x;
}

void SVGEllipse::set_y(float y)
{
    m_y = y;
}

void SVGEllipse::set_rx(float rx)
{
    m_rx = rx;
}

void SVGEllipse::set_ry(float ry)
{
    m_ry = ry;
}

void SVGEllipse::print(std::ostream &os, int n) const
{
    std::string s(n, ' ');
    os << s << "<circle\n"
       << s << "   id=\"" << m_id << "\"\n"
       << s << "   cx=\"" << m_x  << "\"\n"
       << s << "   cy=\"" << m_y  << "\"\n"
       << s << "   rx=\"" << m_rx << "\"\n"
       << s << "   ry=\"" << m_ry << "\"\n"
       << s << "   style=\"";
    m_style->print(os);
    os << "\"/>";
}

} // namespace svg
