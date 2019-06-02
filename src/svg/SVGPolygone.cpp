#include <svg/SVGPolygone.h>
#include <svg/SVGStyle.h>

#include <ostream>

namespace svg {

SVGPolygone::SVGPolygone(const std::string& id) :
    SVGShape(id),
    m_points()
{
}

const std::vector<Point>& SVGPolygone::points() const
{
    return m_points;
}

std::vector<Point>& SVGPolygone::points()
{
    return m_points;
}

void SVGPolygone::print(std::ostream &os, int n) const
{
    std::string s(n, ' ');
    os <<s << "<polygone\n"
       <<s << "   points=\"";
    for(size_t idx=0; idx<m_points.size(); ++idx)
    {
        os << m_points[idx].x << "," << m_points[idx].y;
        if(idx < m_points.size()-1)
            os << " ";
    }
    os << "\"\n"
       << s << "   style=\"";
    m_style->print(os);
    os << "\"/>";
}

} // namespace svg
