#include <svg/Transform.h>

#include <iostream>

namespace svg {

Transform::Transform(Type type) :
    m_type(type),
    m_data()
{
    reset();
}

void Transform::reset()
{
    switch(m_type)
    {
    case Type::None       : m_data = {0,0,0,0,0,0}; break;
    case Type::Matrix     : m_data = {1,0,0,1,0,0}; break;
    case Type::Translation: m_data = {0,0,0,0,0,0}; break;
    case Type::Scaling    : m_data = {1,1,0,0,0,0}; break;
    case Type::Rotation   : m_data = {0,0,0,0,0,0}; break;
    case Type::SkewX      : m_data = {0,0,0,0,0,0}; break;
    case Type::SkewY      : m_data = {0,0,0,0,0,0}; break;
    }
}

Type Transform::type() const
{
    return m_type;
}

void Transform::set_type(Type type)
{
    m_type = type;
    reset();
}

float Transform::a() const
{
    return m_data[0];
}

float Transform::b() const
{
    return m_data[1];
}

float Transform::c() const
{
    return m_data[2];
}

float Transform::d() const
{
    return m_data[3];
}

float Transform::e() const
{
    return m_data[4];
}

float Transform::f() const
{
    return m_data[5];
}

void Transform::set_a(float a)
{
    m_data[0] = a;
}

void Transform::set_b(float b)
{
    m_data[1] = b;
}

void Transform::set_c(float c)
{
    m_data[2] = c;
}

void Transform::set_d(float d)
{
    m_data[3] = d;
}

void Transform::set_e(float e)
{
    m_data[4] = e;
}

void Transform::set_f(float f)
{
    m_data[5] = f;
}

float Transform::tx() const
{
    return m_data[0];
}

float Transform::ty() const
{
    return m_data[1];
}

void Transform::set_tx(float tx)
{
    m_data[0] = tx;
}

void Transform::set_ty(float ty)
{
    m_data[1] = ty;
}

float Transform::sx() const
{
    return m_data[0];
}

float Transform::sy() const
{
    return m_data[1];
}

void Transform::set_sx(float sx)
{
    m_data[0] = sx;
}

void Transform::set_sy(float sy)
{
    m_data[1] = sy;
}

float Transform::angle() const
{
    return m_data[0];
}

float Transform::cx() const
{
    return m_data[1];
}

float Transform::cy() const
{
    return m_data[2];
}

void Transform::set_angle(float angle)
{
    m_data[0] = angle;
}

void Transform::set_cx(float cx)
{
    m_data[1] = cx;
}

void Transform::set_cy(float cy)
{
    m_data[2] = cy;
}

void Transform::print(std::ostream& os) const
{
    switch(m_type)
    {
    case Type::None       :                         break;
    case Type::Matrix     : print_matrix(os);       break;
    case Type::Translation: print_translation(os);  break;
    case Type::Scaling    : print_scaling(os);      break;
    case Type::Rotation   : print_rotation(os);     break;
    case Type::SkewX      : print_skewX(os);        break;
    case Type::SkewY      : print_skewY(os);        break;
    }
}

void Transform::print_matrix(std::ostream& os) const
{
    os << "matrix("
       << a() << " "
       << b() << " "
       << c() << " "
       << d() << " "
       << e() << " "
       << f() << ")";
}

void Transform::print_translation(std::ostream& os) const
{
    os << "translate(" << tx() << " " << ty() << ")";
}

void Transform::print_scaling(std::ostream& os) const
{
    os << "scale(" << sx() << " " << sy() << ")";
}

void Transform::print_rotation(std::ostream& os) const
{
    os << "rotate(" << angle() << " " << cx() << " " << cy() << ")";
}

void Transform::print_skewX(std::ostream& os) const
{
    os << "skewX(" << angle() << ")";
}

void Transform::print_skewY(std::ostream& os) const
{
    os << "skewY(" << angle() << ")";
}


} // namespace svg
