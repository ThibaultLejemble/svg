#pragma once

#include <svg/SVGElement.h>

namespace svg {

class SVGDocument : public SVGElement
{
public:
    SVGDocument(float width = 210, float height = 297);
    SVGDocument(float xmin, float xmax, float ymin, float ymax);

public:
    float xmin() const;
    float xmax() const;
    float ymin() const;
    float ymax() const;

    float width() const;
    float height() const;

    void set_width(float width);
    void set_height(float height);

    void flip();
    void add_background(float r = 1, float g = 1, float b = 1, float a = 1);
    void add_background_white(float a = 1);
    void add_background_black(float a = 1);

public:
    void print(const std::string& filename) const;
    virtual void print(std::ostream &os, int n = 0) const override;

protected:
    float m_xmin;
    float m_xmax;
    float m_ymin;
    float m_ymax;
};

} // namespace svg
