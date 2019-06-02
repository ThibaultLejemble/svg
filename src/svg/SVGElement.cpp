#include <svg/SVGElement.h>

namespace svg {

SVGElement::SVGElement(const std::string& id) :
    m_id(id),
    m_children()
{
}

bool SVGElement::has_id() const
{
    return !m_id.empty();
}

void SVGElement::set_id(const std::string& id)
{
    m_id = id;
}

void SVGElement::set_id(std::string&& id)
{
    m_id = id;
}

const std::string& SVGElement::id() const
{
    return m_id;
}

bool SVGElement::has_children() const
{
    return !m_children.empty();
}

int SVGElement::children_count() const
{
    return m_children.size();
}

SVGElement* SVGElement::child(int i)
{
    return m_children[i].get();
}

const SVGElement* SVGElement::child(int i) const
{
    return m_children[i].get();
}

void SVGElement::add_child(SVGElement* element)
{
    m_children.emplace_back(element);
}

void SVGElement::remove_children()
{
    m_children.clear();
}

void SVGElement::remove_child(int i)
{
    m_children.erase(m_children.begin()+i);
}

void SVGElement::print(std::ostream& /*os*/, int /*n*/) const
{
}

} // namespace svg
