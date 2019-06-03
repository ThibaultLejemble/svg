#include <svg/Stylable.h>
#include <svg/Style.h>

#include <ostream>

namespace svg {

Stylable::Stylable() :
    m_style(std::make_shared<Style>())
{
}

const Style& Stylable::style() const
{
    return *m_style.get();
}

Style& Stylable::style()
{
    return *m_style.get();
}

std::shared_ptr<Style>& Stylable::style_ptr()
{
    return m_style;
}

void Stylable::print_style(std::ostream& os, int n) const
{
    os << std::string(n,' ') << "style=\"";
    {
        m_style->print(os);
    }
    os << "\"";
}

} // namespace svg
