#pragma once

#include <svg/Color.h>

#include <vector>

namespace svg {

enum class Cap
{
    Butt = 0,
    Round,
    Square
};

enum class Join
{
    Miter = 0,
    Round,
    Bevel
};

enum class Order
{
    Normal = 0
};

class Style
{
public:
    Style();

    static std::string to_string(Cap cap);
    static std::string to_string(Join join);
    static std::string to_string(Order order);
    static std::string to_string(const std::vector<int> dasharray);

public:
    float opacity() const;
    void set_opacity(float opacity);

    bool is_filled() const;
    void set_filled(bool filled = true);

    const Color& fill() const;
    void set_fill(const Color& fill);

    float fill_opacity() const;
    void set_fill_opacity(float opacity);

    bool is_stroked() const;
    void set_stroked(bool stroked = true);

    const Color& stroke() const;
    void set_stroke(const Color& stroke);

    float stroke_width() const;
    void set_stroke_width(float width);

    Cap stroke_linecap() const;
    void set_stroke_linecap(Cap linecap);

    Join stroke_linejoin() const;
    void set_stroke_linejoin(Join linejoin);

    int stroke_miterlimit() const;
    void set_stroke_miterlimit(int miterlimit);

    bool is_stroke_dashed() const;
    void set_stroke_dashed(bool dashed = true);

    const std::vector<int>& stroke_dasharray() const;
    void set_stroke_dasharray(const std::vector<int>& dasharray);

    int stroke_dashoffset() const;
    void set_stroke_dashoffset(int dashoffset);

    float stroke_opacity() const;
    void set_stroke_opacity(float opacity);

    Order paint_order() const;
    void set_paint_order(Order order);

public:
    void print(std::ostream& os) const;

protected:
    float            m_opacity;

    bool             m_filled;
    Color            m_fill;
    float            m_fill_opacity;

    bool             m_stroked;
    Color            m_stroke;
    float            m_stroke_width;
    Cap              m_stroke_linecap;
    Join             m_stroke_linejoin;
    int              m_stroke_miterlimit;

    bool             m_stroke_dashed;
    std::vector<int> m_stroke_dasharray;
    int              m_stroke_dashoffset;
    float            m_stroke_opacity;

    Order            m_paint_order;
};

} // namespace svg
