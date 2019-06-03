#include <svg/Transformable.h>
#include <svg/Transform.h>

#include <ostream>

namespace svg {

Transformable::Transformable() :
    m_transforms()
{
}

int Transformable::size() const
{
    return m_transforms.size();
}

const Transform& Transformable::transform(int i) const
{
    return *m_transforms[i].get();
}

Transform& Transformable::transform(int i)
{
    return *m_transforms[i].get();
}

const Transform& Transformable::front() const
{
    return *m_transforms.front().get();
}

Transform& Transformable::front()
{
    return *m_transforms.front().get();
}

const Transform& Transformable::back() const
{
    return *m_transforms.back().get();
}

Transform& Transformable::back()
{
    return *m_transforms.back().get();
}

std::shared_ptr<Transform>& Transformable::transform_ptr(int i)
{
    return m_transforms[i];
}

void Transformable::emplace_back()
{
    return m_transforms.emplace_back();
}

void Transformable::emplace_back(const Transform& t)
{
    return m_transforms.emplace_back(std::make_shared<Transform>(t));
}

void Transformable::emplace_back(std::shared_ptr<Transform>& ptr)
{
    return m_transforms.emplace_back(ptr);
}

void Transformable::print_transforms(std::ostream& os, int n) const
{
    if(!m_transforms.empty())
    {
        os << std::string(n,' ') << "transform=\"";
        {
            for(size_t i=0; i<m_transforms.size(); ++i)
            {
                m_transforms[i]->print(os);
                if(i < m_transforms.size())
                    os << " ";
            }
        }
        os << "\"";
    }
}

} // namespace svg
