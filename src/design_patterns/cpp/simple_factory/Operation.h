#ifndef OPERATION_H
#define OPERATION_H

class Operation
{
public:
    virtual double getResult() const = 0;

    void setNumberA(double numberA) { m_numberA = numberA; }
    void setNumberB(double numberB) { m_numberB = numberB; }

protected:
    double m_numberA;
    double m_numberB;
};

class OperationFactory
{
public:
    static Operation *createOperate(const char operate);
};

#endif