#pragma once

#include <svg/SVGShape.h>

namespace svg {

class SVGLine : public SVGShape
{
public:
    SVGLine(const std::string& id,
            float x1 = 0,
            float y1 = 0,
            float x2 = 1,
            float y2 = 1);
    SVGLine(float x1 = 0,
            float y1 = 0,
            float x2 = 1,
            float y2 = 1,
            const std::string& id = "");

public:
    float x1() const;
    float y1() const;
    float x2() const;
    float y2() const;

    void set_x1(float x1);
    void set_y1(float y1);
    void set_x2(float x2);
    void set_y2(float y2);

public:
    virtual void print(std::ostream &os, int n) const override;

protected:
    float m_x1;
    float m_y1;
    float m_x2;
    float m_y2;
};

} // namespace svg
