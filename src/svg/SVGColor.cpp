#include <svg/SVGColor.h>

#include <sstream>
#include <iomanip>
#include <cmath>

namespace svg {

float SVGColor::m_norm_255 = 1./255;

SVGColor::SVGColor(float r, float g, float b) :
    m_r(r),
    m_g(g),
    m_b(b)
{
}

SVGColor::SVGColor(const std::string& hexa) :
    m_r(),
    m_g(),
    m_b()
{
    set_hexa(hexa);
}

SVGColor SVGColor::from_rgb255(int r, int g, int b)
{
    return SVGColor(m_norm_255 * r,
                    m_norm_255 * g,
                    m_norm_255 * b);
}

SVGColor SVGColor::from_hexa(const std::string& hexa)
{
    return SVGColor(hexa);
}

float SVGColor::r() const
{
    return m_r;
}

float SVGColor::g() const
{
    return m_g;
}

float SVGColor::b() const
{
    return m_b;
}

int SVGColor::r_255() const
{
    return std::round(m_r*255);
}

int SVGColor::g_255() const
{
    return std::round(m_g*255);
}

int SVGColor::b_255() const
{
    return std::round(m_b*255);
}

void SVGColor::set(float r, float g, float b)
{
    m_r = r;
    m_g = g;
    m_b = b;
}

void SVGColor::set_r(float r)
{
    m_r = r;
}

void SVGColor::set_g(float g)
{
    m_g = g;
}

void SVGColor::set_b(float b)
{
    m_b = b;
}

void SVGColor::set_255(int r, int g, int b)
{
    m_r = m_norm_255*r;
    m_g = m_norm_255*g;
    m_b = m_norm_255*b;
}

void SVGColor::set_r_255(int r)
{
    m_r = m_norm_255*r;
}

void SVGColor::set_g_255(int g)
{
    m_g = m_norm_255*g;
}

void SVGColor::set_b_255(int b)
{
    m_b = m_norm_255*b;
}

std::string SVGColor::hexa() const
{
    std::stringstream r, g, b;
    r << std::hex << std::setfill('0') << std::setw(2) << r_255();
    g << std::hex << std::setfill('0') << std::setw(2) << g_255();
    b << std::hex << std::setfill('0') << std::setw(2) << b_255();
    return "#" + r.str() + g.str() + b.str();
}

void SVGColor::set_hexa(const std::string& hexa)
{
    if(hexa.size() == 7)
    {
        std::string rstr = hexa.substr(1,2);
        std::string gstr = hexa.substr(3,2);
        std::string bstr = hexa.substr(5,2);
        int r = std::strtol(rstr.c_str(), nullptr, 16);
        int g = std::strtol(gstr.c_str(), nullptr, 16);
        int b = std::strtol(bstr.c_str(), nullptr, 16);
        set_255(r, g, b);
    }
    else
    {
        set(0,0,0);
    }
}

} // namespace svg
