#include "internal/io.h"

struct Number;
struct BinaryOperation;

struct Visitor
{
    virtual void Visit(const Number* number) = 0;
    virtual void Visit(const BinaryOperation* operation) = 0;

    virtual ~Visitor() = default;
//    virtual void VisitNumber(const Number* number) = 0;
//    virtual void VisitBinaryOperation(const BinaryOperation* operation) = 0;
};

struct Expression
{
    virtual double Evaluate() const = 0;

    virtual void Visit(Visitor* visitor) const = 0;

    virtual ~Expression() = default;
};

struct Number : Expression
{
    Number(double value)
        : m_value(value) {};

    double Evaluate() const override {return m_value;}

    double Get() const {return m_value;}

    void Visit(Visitor* visitor) const override
    {
        visitor->Visit(this);
    }

private:
    double m_value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const* left, char operation, Expression const* right)
        : m_left(left)
        , m_operation(operation)
        , m_right(right) {}

    ~BinaryOperation() override
    {
        delete m_left;
        delete m_right;
    }

    double Evaluate() const override
    {
        switch (m_operation)
        {
            case '+': return m_left->Evaluate() + m_right->Evaluate();
            case '-': return m_left->Evaluate() - m_right->Evaluate();
            case '*': return m_left->Evaluate() * m_right->Evaluate();
            case '/': return m_left->Evaluate() / m_right->Evaluate();
            default : return 0;
        }
    }

    Expression const* GetLeft()  const {return m_left;}
    Expression const* GetRight() const {return m_right;}

    char GetOperation() const {return m_operation;}

    void Visit(Visitor* visitor) const override
    {
        visitor->Visit(this);
    }

private:
    Expression const* m_left;
    Expression const* m_right;
    char m_operation;
};

struct PrintVisitor : Visitor
{
    void Visit(Number const* number) override
    {
        const auto value = number->Get();
        if (value < 0)
            std::cout << "(";
        std::cout << number->Get();
        if (value < 0)
            std::cout << ")";
    }

    void Visit(BinaryOperation const* binaryOperation) override
    {
        bool lowPriority = binaryOperation->GetOperation() == '+' || binaryOperation->GetOperation() == '-';

        if (lowPriority)
            std::cout << "(";

        binaryOperation->GetLeft()->Visit(this);

        std::cout << binaryOperation->GetOperation();

        binaryOperation->GetRight()->Visit(this);

        if (lowPriority)
            std::cout << ")";
    }
};

int main()
{
    Expression* expression1 = new BinaryOperation(new Number(4.5), '+', new Number(5));
    Expression* expression2 = new BinaryOperation(new Number(-3), '*', expression1);
    Expression* expression3 = new BinaryOperation(expression2, '+', expression2);
    Expression* expression4 = new BinaryOperation(expression3, '*', expression3);

    std::cout << expression1->Evaluate() << "\n";
    std::cout << expression2->Evaluate() << "\n";
    std::cout << expression3->Evaluate() << "\n";
    std::cout << expression4->Evaluate() << "\n";

    auto printer = new PrintVisitor;

    expression1->Visit(printer); std::cout << "\n";
    expression2->Visit(printer); std::cout << "\n";
    expression3->Visit(printer); std::cout << "\n";
    expression4->Visit(printer); std::cout << "\n";

    delete expression4;

    util::PrintComplete();
}