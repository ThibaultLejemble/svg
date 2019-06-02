#pragma once

#include <svg/SVGShape.h>

namespace svg {

class SVGCircle : public SVGShape
{
public:
    SVGCircle(const std::string& id,
              float x = 0,
              float y = 0,
              float r = 0);
    SVGCircle(float x = 0,
              float y = 0,
              float r = 0,
              const std::string& id = "");

public:
    float x() const;
    float y() const;
    float r() const;

    void set_x(float x);
    void set_y(float y);
    void set_r(float r);

public:
    virtual void print(std::ostream &os, int n) const override;

protected:
    float m_x;
    float m_y;
    float m_r;
};

} // namespace svg
