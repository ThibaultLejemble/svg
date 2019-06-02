#pragma once

#include <svg/SVGElement.h>

namespace svg {

class SVGDocument : public SVGElement
{
public:
    SVGDocument(float width = 210, float height = 297);

public:
    float width() const;
    float height() const;

    void set_width(float width);
    void set_height(float height);

public:
    void print(const std::string& filename) const;
    virtual void print(std::ostream &os, int n = 0) const override;

protected:
    float m_width;
    float m_height;
};

} // namespace svg
