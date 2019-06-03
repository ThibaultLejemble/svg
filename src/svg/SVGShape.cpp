#include <svg/SVGShape.h>
#include <svg/Style.h>

namespace svg {

SVGShape::SVGShape(const std::string& id) :
    SVGElement(id),
    m_style(std::make_shared<Style>())
{
}

const Style& SVGShape::style() const
{
    return *m_style.get();
}

Style& SVGShape::style()
{
    return *m_style.get();
}

std::shared_ptr<Style>& SVGShape::style_ptr()
{
    return m_style;
}

} // namespace svg
