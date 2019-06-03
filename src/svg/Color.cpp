#include <svg/Color.h>

#include <sstream>
#include <iomanip>
#include <cmath>

namespace svg {

float Color::m_norm_255 = 1./255;

Color::Color(float r, float g, float b) :
    m_r(r),
    m_g(g),
    m_b(b)
{
}

Color::Color(const std::string& hexa) :
    m_r(),
    m_g(),
    m_b()
{
    set_hexa(hexa);
}

Color Color::from_255(int r, int g, int b)
{
    return Color(m_norm_255 * r,
                 m_norm_255 * g,
                 m_norm_255 * b);
}

Color Color::from_hexa(const std::string& hexa)
{
    return Color(hexa);
}

float Color::r() const
{
    return m_r;
}

float Color::g() const
{
    return m_g;
}

float Color::b() const
{
    return m_b;
}

int Color::r_255() const
{
    return std::round(m_r*255);
}

int Color::g_255() const
{
    return std::round(m_g*255);
}

int Color::b_255() const
{
    return std::round(m_b*255);
}

void Color::set(float r, float g, float b)
{
    m_r = r;
    m_g = g;
    m_b = b;
}

void Color::set_r(float r)
{
    m_r = r;
}

void Color::set_g(float g)
{
    m_g = g;
}

void Color::set_b(float b)
{
    m_b = b;
}

void Color::set_255(int r, int g, int b)
{
    m_r = m_norm_255*r;
    m_g = m_norm_255*g;
    m_b = m_norm_255*b;
}

void Color::set_r_255(int r)
{
    m_r = m_norm_255*r;
}

void Color::set_g_255(int g)
{
    m_g = m_norm_255*g;
}

void Color::set_b_255(int b)
{
    m_b = m_norm_255*b;
}

std::string Color::hexa() const
{
    std::stringstream r, g, b;
    r << std::hex << std::setfill('0') << std::setw(2) << r_255();
    g << std::hex << std::setfill('0') << std::setw(2) << g_255();
    b << std::hex << std::setfill('0') << std::setw(2) << b_255();
    return "#" + r.str() + g.str() + b.str();
}

void Color::set_hexa(const std::string& hexa)
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
