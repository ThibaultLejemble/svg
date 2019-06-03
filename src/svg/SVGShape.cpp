#include <svg/SVGShape.h>

#include <ostream>

namespace svg {

SVGShape::SVGShape(const std::string& id) :
    SVGElement(id),
    Stylable(),
    Transformable()
{
}

void SVGShape::print_attributes(std::ostream& os, int n) const
{
    print_style(os,n);
    if(!m_transforms.empty())
    {
        os << "\n";
        print_transforms(os,n);
    }
}

} // namespace svg
