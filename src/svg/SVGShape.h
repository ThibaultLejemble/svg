#pragma once

#include <svg/SVGElement.h>

namespace svg {

class Style;

class SVGShape : public SVGElement
{
public:
    SVGShape(const std::string& id = "");

public:
    const Style& style() const;
    Style& style();

    std::shared_ptr<Style>& style_ptr();

protected:
    std::shared_ptr<Style> m_style;
};

} // namespace svg
