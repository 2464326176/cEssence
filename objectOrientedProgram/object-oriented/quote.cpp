//**************************
// Author:  yh
// Time:    2021/11/10
//**************************

#include "quote.h"
#include <iostream>
#include <string>
#include <map>
#include <functional>


double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN:" << item.isbn()
       << "# sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

void print_debug(const Quote &q)
{
    q.debug();
}

int main1() {
/*    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.60, 10, 0.3);
    print_total(std::cout, q, 12);
    print_total(std::cout, bq, 12);*/

    Bulk_quote bulk_quote("bulk_quote_1", 10.10, 10, 0.5);
    // The pointer is of static type Quote, but it's dynamic type is Bulk Quote
    // Because of polymorphism the Bulk Quote implementation of the net_price()
    // method gets called.
    Quote *quote_pointer = &bulk_quote;
    quote_pointer->net_price(5);

    // The lvalueAndRvalue is of static type Quote, but it's dynamic type is Bulk Quote
    // Like with the pointer, the Bulk Quote implementation of the net_price()
    // method gets called.
    Quote &quote_reference = bulk_quote;
    quote_reference.net_price(5);

    // The static type of this variable is Quote. Here the Bulk Quote object
    // gets upcasted. The Quote part of bulk_quote gets copied into quote, but
    // the rest is not handled. Because of the cast the Quote implementation of
    // the net_price() method gets called.
    Quote quote = bulk_quote;
    quote.net_price(5);
}

int main()
{
    Quote q("aaa", 10.60);
    Bulk_quote bq("bbb", 111, 10, 0.3);
    Limit_quote lq("ccc", 222, 10, 0.3);

    /** @note   Not dynamic binding!
     *  The codes below are not dynamic binding. The compiler has known what the
     *  r refering to at compile time. As a result, the virtual function debug of
     *  the subobject is called.
     */
    Quote& r = q;
    r.debug();
    std::cout << "\n";
    r = bq;
    r.debug();
    std::cout << "\n";
    r = lq;
    r.debug();
    std::cout << "\n";


    std::cout << "====================\n";

    /** @note   dynamic binding!
     *  The below will happen dynamic binding. The reason might be that while  print_debug
     *  compiling the compiler compile it independly from the rest codes. The compiler has
     *  no idea what the paramter q refering to. Thus compiler will leave the decision to
     *  run time. That is, dynamic binding.
     *
     *  Once dynamic binding happens, the corresponding vertual function in derived class will
     *  be called rather than that of the subobject inside the derived object.
     *
     *  Anyway, the lvalueAndRvalue is essentially an address being passed.
     *
     */
    print_debug(q);
    std::cout << "\n";
    print_debug(lq);
    std::cout << "\n";
    print_debug(bq);
    std::cout << "\n";

    return 0;
}



