#pragma once

#include <string>
#include <memory>
#include <vector>

namespace svg {

class SVGElement
{
public:
    SVGElement(const std::string& id = "");

public:
    bool has_id() const;
    void set_id(const std::string& id);
    void set_id(std::string&& id);
    const std::string& id() const;

public:
    bool has_children() const;
    int children_count() const;
    SVGElement* child(int i);
    const SVGElement* child(int i) const;
    void add_child(SVGElement* element);
    void remove_children();
    void remove_child(int i);

public:
    virtual void print(std::ostream& os, int n) const = 0;

protected:
    std::string m_id;
    std::vector<std::unique_ptr<SVGElement>> m_children;
};

} // namespace svg
