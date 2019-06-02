#pragma once

#include <svg/SVGShape.h>
#include <svg/Point.h>

namespace svg {

class SVGPolyLine : public SVGShape
{
public:
    SVGPolyLine(const std::string& id = "");

    const std::vector<Point>& points() const;
    std::vector<Point>& points();

public:
    virtual void print(std::ostream &os) const override;

protected:
    std::vector<Point> m_points;
};

} // namespace svg
