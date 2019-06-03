#pragma once

#include <vector>
#include <memory>

namespace svg {

class Transform;

class Transformable
{
public:
    Transformable();

public:
    int size() const;

    const Transform& transform(int i) const;
    Transform& transform(int i);

    const Transform& front() const;
    Transform& front();

    const Transform& back() const;
    Transform& back();

    std::shared_ptr<Transform>& transform_ptr(int i);

public:
    void emplace_back();
    void emplace_back(const Transform& t);
    void emplace_back(std::shared_ptr<Transform>& ptr);

public:
    void print_transforms(std::ostream& os, int n) const;

protected:
    std::vector<std::shared_ptr<Transform>> m_transforms;
};

} // namespace svg
