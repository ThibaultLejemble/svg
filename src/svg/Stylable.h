#pragma once

#include <memory>

namespace svg {

class Style;

class Stylable
{
public:
    Stylable();

public:
    const Style& style() const;
    Style& style();

    std::shared_ptr<Style>& style_ptr();

protected:
    std::shared_ptr<Style> m_style;
};

} // namespace svg
