class Work;

class State
{
public:
    virtual void writeProgram(Work * w) = 0;
};

class ForenoonState: public State
{
    void writeProgram(Work * w) override;
};

class NoonState: public State
{
    void writeProgram(Work * w) override;
};

class AfternoonState: public State
{
    void writeProgram(Work * w) override;
};

class EveningState: public State
{
    void writeProgram(Work * w) override;
};

class SleepingState: public State
{
    void writeProgram(Work * w) override;
};

class RestState: public State
{
    void writeProgram(Work * w) override;
};


class Work
{
public:
    Work()
    {
        m_curr = new ForenoonState();
    }
    void setHour(double hour)
    {
        m_hour = hour;
    }
    double getHour()
    {
        return m_hour;
    }
    void setTaskFinished(bool finished)
    {
        m_finished = finished;
    }
    bool getTaskFinished()
    {
        return m_finished;
    }
    void setState(State * state)
    {
        m_curr = state;
    }
    void writeProgram()
    {
        m_curr->writeProgram(this);
    }

private:
    State * m_curr;
    double m_hour;
    bool m_finished;
};

