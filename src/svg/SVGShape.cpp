#include <svg/SVGShape.h>
#include <svg/Style.h>

namespace svg {

SVGShape::SVGShape(const std::string& id) :
    SVGElement(id),
    Stylable()
{
}

} // namespace svg
