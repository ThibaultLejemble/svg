#pragma once

#include <svg/SVGElement.h>

namespace svg {

class SVGRectangle : public SVGElement
{
public:
    SVGRectangle(const std::string& id,
                 float width = 1,
                 float height = 1,
                 float x = 0,
                 float y = 0,
                 float r = 0);
    SVGRectangle(float width = 1,
                 float height = 1,
                 float x = 0,
                 float y = 0,
                 float r = 0,
                 const std::string& id = "");

public:
    float x() const;
    float y() const;
    float width() const;
    float height() const;
    float r() const;

    void set_x(float x);
    void set_y(float y);
    void set_width(float width);
    void set_height(float height);
    void set_r(float r);

public:
    virtual void print(std::ostream &os) const override;

protected:
    float m_x;
    float m_y;
    float m_width;
    float m_height;
    float m_r;
};

} // namespace svg
