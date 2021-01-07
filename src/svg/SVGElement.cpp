#include <svg/SVGElement.h>
#include <svg/SVGGroup.h>

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

const std::string& SVGElement::id() const
{
    return m_id;
}

void SVGElement::set_id(const std::string& id)
{
    m_id = id;
}

void SVGElement::set_id(std::string&& id)
{
    m_id = id;
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

void SVGElement::add_child_in_new_group(const std::string& name, SVGElement* element)
{
    auto g = new SVGGroup(name);
    g->add_child(element);
    this->add_child(g);
}

void SVGElement::add_child_front(SVGElement* element)
{
    m_children.insert(m_children.begin(), std::unique_ptr<SVGElement>(element));
}

void SVGElement::add_child_front_in_new_group(const std::string& name, SVGElement* element)
{
    auto g = new SVGGroup(name);
    g->add_child(element);
    add_child_front(g);
}

void SVGElement::remove_children()
{
    m_children.clear();
}

void SVGElement::remove_child(int i)
{
    m_children.erase(m_children.begin()+i);
}

} // namespace svg
