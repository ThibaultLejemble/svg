#pragma once

#include <svg/SVGShape.h>
#include <svg/Point.h>

namespace svg {

class SVGPolygone : public SVGShape
{
public:
    SVGPolygone(const std::string& id = "");

    const std::vector<Point>& points() const;
    std::vector<Point>& points();

public:
    virtual void print(std::ostream &os) const override;

protected:
    std::vector<Point> m_points;
};

} // namespace svg
