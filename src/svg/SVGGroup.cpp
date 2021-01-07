#include <svg/SVGGroup.h>

#include <ostream>

namespace svg {

SVGGroup::SVGGroup(const std::string& id) :
    SVGElement(id)
{
}

void SVGGroup::print(std::ostream& os, int n) const
{
    std::string s(n, ' ');
    os << s << "<g id=\"" << m_id << "\"\n"
       << s << "   inkscape:label=\"" << m_id << "\"\n"
       << s << "   inkscape:groupmode=\"layer\"\n";
    if(!m_transforms.empty())
    {
        os << "\n";
        print_transforms(os, 3);
    }
    os << ">\n";
    {
        for(const auto& child : m_children)
        {
            child->print(os, n+2);
            os << "\n";
        }
    }
    os << s << "</g>";
}

} // namespace svg
