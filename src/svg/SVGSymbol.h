#pragma once

#include <svg/SVGElement.h>

namespace svg {

class SVGSymbol : public SVGElement
{
public:
    SVGSymbol(const std::string& id, int width = 100, int height = 100);

public:
    int width() const;
    int height() const;

    void set_width(int width);
    void set_height(int height);

public:
    virtual void print(std::ostream& os, int n) const override;

protected:
    int m_width;
    int m_height;

};

} // namespace svg
