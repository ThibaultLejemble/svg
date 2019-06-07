#pragma once

#include <svg/SVGShape.h>
#include <svg/Point.h>

namespace svg {

class SVGPolygon : public SVGShape
{
public:
    SVGPolygon(const std::string& id = "");
    SVGPolygon(const std::string& id, const std::vector<float>& points);
    SVGPolygon(const std::string& id, const std::vector<float>& x, const std::vector<float>& y);
    SVGPolygon(const std::vector<float>& points, const std::string& id = "");
    SVGPolygon(const std::vector<float>& x, const std::vector<float>& y, const std::string& id = "");

    const std::vector<Point>& points() const;
    std::vector<Point>& points();

public:
    virtual void print(std::ostream &os, int n) const override;

protected:
    std::vector<Point> m_points;
};

} // namespace svg
