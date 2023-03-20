//**************************
// Author:  yh
// Time:    2021/11/10
//**************************

#ifndef CESSENCE_QUOTE_H
#define CESSENCE_QUOTE_H
#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &b, double p) :
            bookNo(b), price(p) { }

    std::string isbn() const{ return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    void debug() const
    {
        std::cout << "data members of this class:\n"
                  << "bookNo= " <<this->bookNo << " "
                  << "price= " <<this->price<< " ";
    }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};


class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& b, double p, std::size_t q, double disc) :
            Quote(b, p), min_qty(q), discount(disc)  { }

    //double net_price(std::size_t n) const override;

private:
    std::size_t min_qty     = 0;
    double      discount    = 0.0;
};

class Limit_quote : public Quote
{
public:
    Limit_quote();
    Limit_quote(const std::string& b, double p, std::size_t max, double disc):
            Quote(b, p), max_qty(max), discount(disc)    {   }

    double net_price(std::size_t n) const override
    { return n * price * (n < max_qty ? 1 - discount : 1 ); }

    void debug() const override;

private:
    std::size_t max_qty     = 0;
    double      discount    = 0.0;
};
#endif //CESSENCE_QUOTE_H
