#pragma once

#include <svg/SVGElement.h>

namespace svg {

class SVGStyle;

class SVGShape : public SVGElement
{
public:
    SVGShape(const std::string& id = "");

public:
    const SVGStyle& style() const;
    SVGStyle& style();

    std::shared_ptr<SVGStyle>& style_ptr();

protected:
    std::shared_ptr<SVGStyle> m_style;
};

} // namespace svg
