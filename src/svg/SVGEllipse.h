#pragma once

#include <svg/SVGShape.h>

namespace svg {

class SVGEllipse : public SVGShape
{
public:
    SVGEllipse(const std::string& id,
               float x = 0,
               float y = 0,
               float rx = 0,
               float ry = 0);
    SVGEllipse(float x = 0,
               float y = 0,
               float rx = 0,
               float ry = 0,
               const std::string& id = "");

public:
    float x() const;
    float y() const;
    float rx() const;
    float ry() const;

    void set_x(float x);
    void set_y(float y);
    void set_rx(float rx);
    void set_ry(float ry);

public:
    virtual void print(std::ostream &os, int n) const override;

protected:
    float m_x;
    float m_y;
    float m_rx;
    float m_ry;
};

} // namespace svg
