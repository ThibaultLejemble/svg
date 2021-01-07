#pragma once

#include <svg/SVGElement.h>
#include <svg/Transformable.h>

namespace svg {

class SVGDocument : public SVGElement, public Transformable
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
