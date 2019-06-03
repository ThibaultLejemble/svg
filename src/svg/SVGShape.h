#pragma once

#include <svg/SVGElement.h>
#include <svg/Stylable.h>
#include <svg/Transformable.h>

namespace svg {

class Style;

class SVGShape : public SVGElement, public Stylable, public Transformable
{
public:
    SVGShape(const std::string& id = "");

    void print_attributes(std::ostream& os, int n) const;
};

} // namespace svg
