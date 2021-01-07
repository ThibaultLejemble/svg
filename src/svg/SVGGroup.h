#pragma once

#include <svg/SVGElement.h>
#include <svg/Transformable.h>

namespace svg {

class SVGGroup : public SVGElement, public Transformable
{
public:
    SVGGroup(const std::string& id = "");
    virtual ~SVGGroup(){}

    virtual void print(std::ostream& os, int n) const override;
};

} // namespace svg
