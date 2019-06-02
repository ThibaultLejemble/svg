#include <svg/SVGDocument.h>

#include <fstream>

namespace svg {

SVGDocument::SVGDocument(float width, float height) :
    SVGElement("main"),
    m_width(width),
    m_height(height)
{
}

float SVGDocument::width() const
{
    return m_width;
}

float SVGDocument::height() const
{
    return m_height;
}

void SVGDocument::set_width(float width)
{
    m_width = width;
}

void SVGDocument::set_height(float height)
{
    m_height = height;
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
       << "   viewBox=\"0 0 " << m_width << " " << m_height << "\"\n"
       << "   height=\"" << m_height << "mm\"\n"
       << "   width=\"" << m_width << "mm\">\n";
    {
        for(const auto& child : m_children)
        {
            child->print(os, 2);
            os << "\n";
        }
    }
    os << "</svg>";
}

} // namespace svg
