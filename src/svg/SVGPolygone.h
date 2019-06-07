#pragma once

#include <svg/SVGShape.h>
#include <svg/Point.h>

namespace svg {

class SVGPolygone : public SVGShape
{
public:
    SVGPolygone(const std::string& id = "");
    SVGPolygone(const std::string& id, const std::vector<float>& points);
    SVGPolygone(const std::string& id, const std::vector<float>& x, const std::vector<float>& y);
    SVGPolygone(const std::vector<float>& points, const std::string& id = "");
    SVGPolygone(const std::vector<float>& x, const std::vector<float>& y, const std::string& id = "");

    const std::vector<Point>& points() const;
    std::vector<Point>& points();

public:
    virtual void print(std::ostream &os, int n) const override;

protected:
    std::vector<Point> m_points;
};

} // namespace svg
