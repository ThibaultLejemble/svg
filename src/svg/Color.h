#pragma once

#include <string>

namespace svg {

class Color
{
public:
    Color(float r = 0, float g = 0, float b = 0);
    Color(const std::string& hexa);

    static Color from_255(int r, int g, int b);
    static Color from_hexa(const std::string& hexa);

public:
    float r() const;
    float g() const;
    float b() const;

    int r_255() const;
    int g_255() const;
    int b_255() const;

    void set(float r, float g, float b);
    void set_r(float r);
    void set_g(float g);
    void set_b(float b);

    void set_255(int r, int g, int b);
    void set_r_255(int r);
    void set_g_255(int g);
    void set_b_255(int b);

    std::string hexa() const;
    void set_hexa(const std::string& hexa);

protected:
    float m_r;
    float m_g;
    float m_b;

    static float m_norm_255;
};

} // namespace svg
