#include <svg/SVGPolygon.h>
#include <svg/Style.h>

#include <ostream>

namespace svg {

SVGPolygon::SVGPolygon(const std::string& id) :
    SVGShape(id),
    m_points()
{
}

SVGPolygon::SVGPolygon(const std::string& id, const std::vector<float>& points) :
    SVGShape(id),
    m_points()
{
    int count = 0.5*points.size();
    m_points.reserve(count);
    for(int i=0; i<count; ++i)
    {
        m_points.push_back({points[i*2], points[i*2+1]});
    }
}

SVGPolygon::SVGPolygon(const std::string& id, const std::vector<float>& x, const std::vector<float>& y) :
    SVGShape(id),
    m_points()
{
    int count = std::min(x.size(), y.size());
    m_points.reserve(count);
    for(int i=0; i<count; ++i)
    {
        m_points.push_back({x[i], y[i]});
    }
}

SVGPolygon::SVGPolygon(const std::vector<float>& points, const std::string& id) :
    SVGPolygon(id, points)
{
}

SVGPolygon::SVGPolygon(const std::vector<float>& x, const std::vector<float>& y, const std::string& id) :
    SVGPolygon(id, x, y)
{
}

const std::vector<Point>& SVGPolygon::points() const
{
    return m_points;
}

std::vector<Point>& SVGPolygon::points()
{
    return m_points;
}

void SVGPolygon::print(std::ostream &os, int n) const
{
    std::string s(n, ' ');
    os <<s << "<polygon\n"
       <<s << "   points=\"";
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
