#pragma once

#include <svg/SVGElement.h>

namespace svg {

class SVGUse : public SVGElement
{
public:
    SVGUse(const std::string& ref, int x = 0, int y = 0, int width = 1, int height = 1, const std::string& id = "");
    SVGUse(const std::string& id, const std::string& ref, int x = 0, int y = 0, int width = 1, int height = 1);

public:
    virtual void print(std::ostream& os, int n) const override;

protected:
    std::string m_ref;
    int m_x;
    int m_y;
    int m_width;
    int m_height;
};

} // namespace svg
