#pragma once

#include <svg/SVGElement.h>

namespace svg {

class SVGDocument : public SVGElement
{
public:
    SVGDocument(float width = 1920, float height = 1080);
    SVGDocument(float xmin, float xmax, float ymin, float ymax);
    SVGDocument(float xmin, float xmax, float ymin, float ymax, float width, float height);

public:
    float xmin() const;
    float xmax() const;
    float ymin() const;
    float ymax() const;

    float width() const;
    float height() const;

    void set_viewbox(float xmin, float xmax, float ymin, float ymax);
    void set_viewport(float width, float height);

    void flip();
    void add_background(float r = 1, float g = 1, float b = 1, float a = 1);
    void add_background_white(float a = 1);
    void add_background_black(float a = 1);

public:
    void print(const std::string& filename) const;
    virtual void print(std::ostream &os, int n = 0) const override;

protected:
    // viewBox
    float m_xmin;
    float m_xmax;
    float m_ymin;
    float m_ymax;
    // viewport
    float m_width;
    float m_height;
};

} // namespace svg
