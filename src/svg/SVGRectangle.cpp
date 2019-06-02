#include <svg/SVGRectangle.h>
#include <svg/SVGStyle.h>

#include <ostream>

namespace svg {

SVGRectangle::SVGRectangle(const std::string& id,
                           float width,
                           float height,
                           float x,
                           float y,
                           float r) :
    SVGShape(id),
    m_x(x),
    m_y(y),
    m_width(width),
    m_height(height),
    m_r(r)
{
}

SVGRectangle::SVGRectangle(float width,
                           float height,
                           float x,
                           float y,
                           float r,
                           const std::string& id) :
    SVGShape(id),
    m_x(x),
    m_y(y),
    m_width(width),
    m_height(height),
    m_r(r)
{
}

float SVGRectangle::x() const
{
    return m_x;
}

float SVGRectangle::y() const
{
    return m_y;
}

float SVGRectangle::width() const
{
    return m_width;
}

float SVGRectangle::height() const
{
    return m_height;
}

float SVGRectangle::r() const
{
    return m_r;
}

void SVGRectangle::set_x(float x)
{
    m_x = x;
}

void SVGRectangle::set_y(float y)
{
    m_y = y;
}

void SVGRectangle::set_width(float width)
{
    m_width = width;
}

void SVGRectangle::set_height(float height)
{
    m_height = height;
}

void SVGRectangle::set_r(float r)
{
    m_r = r;
}

void SVGRectangle::print(std::ostream &os) const
{
    os << "<rect\n"
      << "id=\""       << m_id     << "\"\n"
      << "x=\""        << m_x      << "\"\n"
      << "y=\""        << m_y      << "\"\n"
      << "width=\""    << m_width  << "\"\n"
      << "height=\""   << m_height << "\"\n"
      << "rx=\""       << m_r      << "\"\n"
      << "style=\"";
    m_style->print(os);
    os << "\"/>";
}

} // namespace svg
