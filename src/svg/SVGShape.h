#pragma once

#include <svg/SVGElement.h>
#include <svg/Stylable.h>

namespace svg {

class Style;

class SVGShape : public SVGElement, public Stylable
{
public:
    SVGShape(const std::string& id = "");
};

} // namespace svg
