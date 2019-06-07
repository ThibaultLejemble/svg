#pragma once

#include <svg/SVGShape.h>
#include <svg/Point.h>

namespace svg {

class SVGPolyLine : public SVGShape
{
public:
    SVGPolyLine(const std::string& id = "");
    SVGPolyLine(const std::string& id, const std::vector<float>& points);
    SVGPolyLine(const std::string& id, const std::vector<float>& x, const std::vector<float>& y);
    SVGPolyLine(const std::vector<float>& points, const std::string& id = "");
    SVGPolyLine(const std::vector<float>& x, const std::vector<float>& y, const std::string& id = "");

    const std::vector<Point>& points() const;
    std::vector<Point>& points();

public:
    virtual void print(std::ostream &os, int n) const override;

protected:
    std::vector<Point> m_points;
};

} // namespace svg
