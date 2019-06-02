#pragma once

#include <svg/SVGElement.h>

namespace svg {

class SVGGroup : public SVGElement
{
public:
    SVGGroup(const std::string& id = "");

    virtual void print(std::ostream& os) const override;
};

} // namespace svg
