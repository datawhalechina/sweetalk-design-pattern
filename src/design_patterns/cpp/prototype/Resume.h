class ICloneable
{
public:
    virtual ICloneable * clone() const = 0;
};