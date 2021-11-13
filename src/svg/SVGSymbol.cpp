#include <svg/SVGSymbol.h>

#include <ostream>

namespace svg {

SVGSymbol::SVGSymbol(const std::string& id, int width, int height) :
    SVGElement(id),
    m_width(width),
    m_height(height)
{
}

int SVGSymbol::width() const
{
    return m_width;
}

int SVGSymbol::height() const
{
    return m_height;
}

void SVGSymbol::set_width(int width)
{
    m_width = width;
}

void SVGSymbol::set_height(int height)
{
    m_height = height;
}

void SVGSymbol::print(std::ostream& os, int n) const
{
    std::string s(n, ' ');
    os << s << "<symbol id=\"" << m_id << "\"\n"
       << s << "   viewBox=\"0 0 " << m_width << " " << m_height << "\">\n";
    {
        for(const auto& child : m_children)
        {
            child->print(os, n+2);
            os << "\n";
        }
    }
    os << s << "</symbol>\n";
}

} // namespace svg
