#include <algorithm>
#include <iostream>

struct Rational
{
    Rational(int numerator = 0, int denominator = 1)
        : numerator_(numerator)
        , denominator_(denominator)
    {}

    void add(Rational rhs);
    void sub(Rational rhs);
    void mul(Rational rhs);
    void div(Rational rhs);

    bool isNegative()
    {
        return (numerator_ < 0) ^ (denominator_ < 0);
    }

    void neg();
    void inv();
    double to_double() const;

    operator double() const {return to_double();}

    int numerator() const   {return numerator_;}
    int denominator() const {return denominator_;}

    Rational& operator+=(const Rational& rhs)
    {
        add(rhs);
        return *this;
    }

    Rational& operator-=(const Rational& rhs)
    {
        sub(rhs);
        return *this;
    }

    Rational& operator*=(const Rational& rhs)
    {
        mul(rhs);
        return *this;
    }

    Rational& operator/=(const Rational& rhs)
    {
        div(rhs);
        return *this;
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator-(Rational rational)
{
    rational.neg();
    return rational;
}

Rational operator+(Rational rational)
{
    return rational;
}

void Rational::neg()
{
    numerator_ = -numerator_;
}

void Rational::add(Rational rhs)
{
    numerator_ = numerator_ * rhs.denominator() + rhs.numerator()*denominator();
    denominator_ = denominator() * rhs.denominator();
}

void Rational::sub(Rational rhs)
{
    rhs.neg();
    add(rhs);
}

void Rational::mul(Rational rhs)
{
    numerator_ = numerator_ * rhs.numerator();
    denominator_ = denominator() * rhs.denominator();
}

void Rational::inv()
{
    const auto temp = numerator_;
    numerator_ = denominator_;
    denominator_ = temp;
    //    std::swap(numerator_, denominator_);
}

void Rational::div(Rational rhs)
{
    rhs.inv();
    mul(rhs);
}

double Rational::to_double() const
{
    return static_cast<double>(numerator_) / static_cast<double>(denominator_);
}

Rational operator+(Rational lhs, const Rational rhs)
{
    return lhs += rhs;
}

Rational operator-(Rational lhs, const Rational& rhs)
{
    return lhs -= rhs;
}

Rational operator*(Rational lhs, const Rational& rhs)
{
    return lhs *= rhs;
}

Rational operator/(Rational lhs, const Rational& rhs)
{
    return lhs /= rhs;
}

bool operator==(const Rational& lhs, const Rational& rhs)
{
    return lhs.numerator() == rhs.numerator() &&
           lhs.denominator() == rhs.denominator();
}

bool operator!=(const Rational& lhs, const Rational& rhs)
{
    return !(lhs == rhs);
}

bool operator<(Rational lhs, const Rational& rhs)
{
    lhs -= rhs;

    return lhs.isNegative();
}

bool operator>(Rational lhs, const Rational& rhs)
{
    return rhs < lhs;
}

bool operator<=(Rational lhs, const Rational& rhs)
{
    return !(lhs > rhs);
}

bool operator>=(Rational lhs, const Rational& rhs)
{
    return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& cout, const Rational& rational)
{
    std::cout << rational.numerator() << "/" << rational.denominator();
}


