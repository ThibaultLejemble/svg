#include <svg/SVGPolyLine.h>
#include <svg/Style.h>

#include <ostream>

namespace svg {

SVGPolyLine::SVGPolyLine(const std::string& id) :
    SVGShape(id),
    m_points()
{
    m_style->set_filled(false);
    m_style->set_stroked(true);
}

SVGPolyLine::SVGPolyLine(const std::string& id, const std::vector<float>& points) :
    SVGShape(id),
    m_points()
{
    int count = 0.5*points.size();
    m_points.reserve(count);
    for(int i=0; i<count; ++i)
    {
        m_points.push_back({points[i*2], points[i*2+1]});
    }
    m_style->set_filled(false);
    m_style->set_stroked(true);
}

SVGPolyLine::SVGPolyLine(const std::string& id, const std::vector<float>& x, const std::vector<float>& y) :
    SVGShape(id),
    m_points()
{
    int count = std::min(x.size(), y.size());
    m_points.reserve(count);
    for(int i=0; i<count; ++i)
    {
        m_points.push_back({x[i], y[i]});
    }
    m_style->set_filled(false);
    m_style->set_stroked(true);
}

SVGPolyLine::SVGPolyLine(const std::vector<float>& points, const std::string& id) :
    SVGPolyLine(id, points)
{
}

SVGPolyLine::SVGPolyLine(const std::vector<float>& x, const std::vector<float>& y, const std::string& id) :
    SVGPolyLine(id, x, y)
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

void SVGPolyLine::print(std::ostream &os, int n) const
{
    std::string s(n, ' ');
    os << s << "<polyline\n"
       << s << "   points=\"";
    for(size_t idx=0; idx<m_points.size(); ++idx)
    {
        os << m_points[idx].x << "," << m_points[idx].y;
        if(idx < m_points.size()-1)
            os << " ";
    }
    os << "\"\n";
    print_attributes(os, n+3);
    os << "/>";
}

} // namespace svg
