using namespace std;

class TestPaper
{
public:
    void testQuestion1();
    void testQuestion2();
    void testQuestion3();

    virtual string answer1() = 0;
    virtual string answer2() = 0;
    virtual string answer3() = 0;
};

class TestPaperA: public TestPaper
{
public:
    string answer1() override;
    string answer2() override;
    string answer3() override;
};

class TestPaperB: public TestPaper
{
public:
    string answer1() override;
    string answer2() override;
    string answer3() override;
};