#pragma once

#include <array>
#include <fstream>

namespace svg {

enum class Type
{
    None,
    Matrix,
    Translation,
    Scaling,
    Rotation,
    SkewX,
    SkewY
};

class Transform
{
public:
    Transform(Type type = Type::None);

    void reset();

    Type type() const;
    void set_type(Type type);

    float a() const;
    float b() const;
    float c() const;
    float d() const;
    float e() const;
    float f() const;
    void set_a(float a);
    void set_b(float b);
    void set_c(float c);
    void set_d(float d);
    void set_e(float e);
    void set_f(float f);

    float tx() const;
    float ty() const;
    void set_tx(float tx);
    void set_ty(float ty);

    float sx() const;
    float sy() const;
    void set_sx(float sx);
    void set_sy(float sy);

    float angle() const;
    float cx() const;
    float cy() const;
    void set_angle(float angle);
    void set_cx(float cx);
    void set_cy(float cy);

public:
    void print(std::ostream& os) const;

protected:
    void print_matrix(std::ostream& os) const;
    void print_translation(std::ostream& os) const;
    void print_scaling(std::ostream& os) const;
    void print_rotation(std::ostream& os) const;
    void print_skewX(std::ostream& os) const;
    void print_skewY(std::ostream& os) const;

protected:
    Type m_type;
    std::array<float,6> m_data;
    //                  0   1   2   3   4   5
    // Matrix     :     a,  b,  c,  d,  e,  f
    // Translation:    tx, ty
    // Scaling    :    sx, sy
    // Rotation   : angle, cx, cy
    // SkewX      : angle
    // SkewY      : angle

};

} // namespace svg
