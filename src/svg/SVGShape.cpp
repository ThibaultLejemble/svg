#include <svg/SVGShape.h>
#include <svg/SVGStyle.h>

namespace svg {

SVGShape::SVGShape(const std::string& id) :
    SVGElement(id),
    m_style(std::make_shared<SVGStyle>())
{
}

const SVGStyle& SVGShape::style() const
{
    return *m_style.get();
}

SVGStyle& SVGShape::style()
{
    return *m_style.get();
}

std::shared_ptr<SVGStyle>& SVGShape::style_ptr()
{
    return m_style;
}

} // namespace svg
