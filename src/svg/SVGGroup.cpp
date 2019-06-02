#include <svg/SVGGroup.h>

#include <ostream>

namespace svg {

SVGGroup::SVGGroup(const std::string& id) :
    SVGElement(id)
{
}

void SVGGroup::print(std::ostream& os) const
{
    os << "<g id=\"" << m_id << "\">\n";
    {
        for(const auto& child : m_children)
        {
            child->print(os);
            os << "\n";
        }
    }
    os << "</g>";
}

} // namespace svg
