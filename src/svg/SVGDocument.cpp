#include <svg/SVGDocument.h>
#include <svg/Transform.h>
#include <svg/Transformable.h>
#include <svg/Color.h>
#include <svg/Style.h>
#include <svg/SVGRectangle.h>

#include <fstream>

namespace svg {

SVGDocument::SVGDocument(float width, float height) :
    SVGElement("main"),
    m_xmin(0),
    m_xmax(width),
    m_ymin(0),
    m_ymax(height),
    m_width(width),
    m_height(height)
{
}

SVGDocument::SVGDocument(float xmin, float xmax, float ymin, float ymax) :
    SVGElement("main"),
    m_xmin(xmin),
    m_xmax(xmax),
    m_ymin(ymin),
    m_ymax(ymax),
    m_width(xmax - xmin),
    m_height(ymax - ymin)
{
}

SVGDocument::SVGDocument(float xmin, float xmax, float ymin, float ymax, float width, float height) :
    SVGElement("main"),
    m_xmin(xmin),
    m_xmax(xmax),
    m_ymin(ymin),
    m_ymax(ymax),
    m_width(width),
    m_height(height)
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
    return m_width;
}

float SVGDocument::height() const
{
    return m_height;
}

void SVGDocument::set_viewbox(float xmin, float xmax, float ymin, float ymax)
{
    m_xmin = xmin;
    m_xmax = xmax;
    m_ymin = ymin;
    m_ymax = ymax;
}

void SVGDocument::set_viewport(float width, float height)
{
    m_width = width;
    m_height = height;
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

    for(auto& child : m_children)
    {
        // add virtual methods like is_*() and as_*() in SVGElement class
        auto childt = dynamic_cast<Transformable*>(child.get());
        if(childt)
        {
            childt->emplace_back(T);
        }
    }
}

void SVGDocument::add_background(float r, float g, float b, float a)
{
    auto rect = new SVGRectangle(xmin(), ymin(), xmax()-xmin(), ymax()-ymin());
    rect->style().set_fill(Color(r,g,b));
    rect->style().set_opacity(a);

    this->add_child_front_in_new_group("background", rect);
}

void SVGDocument::add_background_white(float a)
{
    this->add_background(1,1,1,a);
}

void SVGDocument::add_background_black(float a)
{
    this->add_background(0,0,0,a);
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
       << "   viewBox=\"" << m_xmin << " " << m_ymin << " " << m_xmax - m_xmin << " " << m_ymax - m_ymin << "\"\n"
       << "   height=\""  << m_height << "px\"\n"
       << "   width=\"" << m_width << "px\"\n"
       << "   xmlns:xlink=\"http://www.w3.org/1999/xlink\"\n"
       << "   xmlns:inkscape=\"http://www.inkscape.org/namespaces/inkscape\">\n";
    for(const auto& child : m_children)
    {
        child->print(os, 2);
        os << "\n";
    }
    os << "</svg>";
}

} // namespace svg
