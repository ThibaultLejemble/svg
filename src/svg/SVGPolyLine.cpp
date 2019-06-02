#include <svg/SVGPolyLine.h>
#include <svg/SVGStyle.h>

#include <ostream>

namespace svg {

SVGPolyLine::SVGPolyLine(const std::string& id) :
    SVGShape(id),
    m_points()
{
}

const std::vector<Point>& SVGPolyLine::points() const
{
    return m_points;
}

std::vector<Point>& SVGPolyLine::points()
{
    return m_points;
}

void SVGPolyLine::print(std::ostream &os) const
{
    os << "<polyline\n"
       << "points=\"";
    for(size_t idx=0; idx<m_points.size(); ++idx)
    {
        os << m_points[idx].x << "," << m_points[idx].y;
        if(idx < m_points.size()-1)
            os << " ";
    }
    os << "\"\n"
       << "style=\"";
    m_style->print(os);
    os << "\"/>";
}

} // namespace svg
