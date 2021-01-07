#include <svg/SVGDocument.h>
#include <svg/Transform.h>

#include <fstream>

namespace svg {

SVGDocument::SVGDocument(float width, float height) :
    SVGElement("main"),
    Transformable(),
    m_xmin(0),
    m_xmax(width),
    m_ymin(0),
    m_ymax(height)
{
}

SVGDocument::SVGDocument(float xmin, float xmax, float ymin, float ymax) :
    SVGElement("main"),
    Transformable(),
    m_xmin(xmin),
    m_xmax(xmax),
    m_ymin(ymin),
    m_ymax(ymax)
{
}

float SVGDocument::xmin() const
{
    return m_xmin;
}

float SVGDocument::xmax() const
{
    return m_xmax;
}

float SVGDocument::ymin() const
{
    return m_ymin;
}

float SVGDocument::ymax() const
{
    return m_ymax;
}

float SVGDocument::width() const
{
    return m_xmax - m_xmin;
}

float SVGDocument::height() const
{
    return m_ymax - m_ymin;
}

void SVGDocument::set_width(float width)
{
    m_xmax = m_xmin + width;
}

void SVGDocument::set_height(float height)
{
    m_ymax = m_ymin + height;
}

void SVGDocument::flip()
{
    Transform T(Type::Matrix);
    T.set_a( 1);
    T.set_b( 0);
    T.set_c( 0);
    T.set_d(-1);
    T.set_e( 0);
    T.set_f(m_ymin + m_ymax);

    emplace_back(T);
}

void SVGDocument::print(const std::string& filename) const
{
    std::ofstream ofs(filename);
    if(ofs.is_open())
    {
        this->print(ofs);
    }
    ofs.close();
}

void SVGDocument::print(std::ostream &os, int) const
{
    os << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n";
    os << "<svg\n"
       << "   id=\"" << m_id << "\"\n"
       << "   version=\"1.1\"\n"
       << "   viewBox=\"" << xmin() << " " << ymin() << " " << width() << " " << height() << "\"\n"
       << "   height=\""  << height() << "px\"\n"
       << "   width=\""   << width()  << "px\"";
    if(!m_transforms.empty())
    {
        os << "\n";
        print_transforms(os, 3);
    }
    os << ">\n";
    for(const auto& child : m_children)
    {
        child->print(os, 2);
        os << "\n";
    }
    os << "</svg>";
}

} // namespace svg
