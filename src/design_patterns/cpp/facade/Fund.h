class Stock1
{
public:
    void sell();
    void buy();
};

class Stock2
{
public:
    void sell();
    void buy();    
};

class Stock3
{
public:
    void sell();
    void buy();    
};

class NationalDebt1
{
public:
    void sell();
    void buy();    
};

class Realty1
{
public:
    void sell();
    void buy();    
};

class Fund
{
public:
    Fund()
    {
        m_gu1 = new Stock1();
        m_gu2 = new Stock2();
        m_gu3 = new Stock3();
        m_nd1 = new NationalDebt1();
        m_rt1 = new Realty1();
    }

    void buyFund();
    void sellFund();

private:
    Stock1 * m_gu1;
    Stock2 * m_gu2;
    Stock3 * m_gu3;
    NationalDebt1 * m_nd1;
    Realty1 * m_rt1;
};