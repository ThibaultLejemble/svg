#include <svg/SVGUse.h>

#include <ostream>

namespace svg {

SVGUse::SVGUse(const std::string& ref, int x, int y, int width, int height, const std::string& id) :
    SVGElement(id),
    m_ref(ref),
    m_x(x),
    m_y(y),
    m_width(width),
    m_height(height)
{
}

SVGUse::SVGUse(const std::string& id, const std::string& ref, int x, int y, int width, int height) :
    SVGUse(ref, x, y, width, height, id)
{
}

void SVGUse::print(std::ostream& os, int n) const
{
    std::string s(n, ' ');
    os << s << "<use\n"
       << s << "   id=\""     << m_id     << "\"\n"
       << s << "   x=\""      << m_x      << "\"\n"
       << s << "   y=\""      << m_y      << "\"\n"
       << s << "   width=\""  << m_width  << "\"\n"
       << s << "   height=\"" << m_height << "\"\n"
       << s << "   href=\"#"  << m_ref    << "\"/>";
}

} // namespace svg
