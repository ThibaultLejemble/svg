#include <svg/SVGCircle.h>

#include <ostream>

namespace svg {

SVGCircle::SVGCircle(const std::string& id,
                     float x,
                     float y,
                     float r) :
    SVGElement(id),
    m_x(x),
    m_y(y),
    m_r(r)
{
}

SVGCircle::SVGCircle(float x,
                     float y,
                     float r,
                     const std::string& id) :
    SVGElement(id),
    m_x(x),
    m_y(y),
    m_r(r)
{
}

float SVGCircle::x() const
{
    return m_x;
}

float SVGCircle::y() const
{
    return m_y;
}

float SVGCircle::r() const
{
    return m_r;
}

void SVGCircle::set_x(float x)
{
    m_x = x;
}

void SVGCircle::set_y(float y)
{
    m_y = y;
}

void SVGCircle::set_r(float r)
{
    m_r = r;
}

void SVGCircle::print(std::ostream &os) const
{
    os << "<circle\n";
    os << "id=\"" << m_id << "\"\n";
    os << "cx=\"" << m_x << "\"\n";
    os << "cy=\"" << m_y << "\"\n";
    os << "r=\"" << m_r << "\"/>";
}

} // namespace svg
