//**************************
// Author:  yh
// Time:    2021/11/10
//**************************

#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
    std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

int main()
{
/*    std::shared_ptr<int> p(new int(42));
    process(std::shared_ptr<int>(p));


    std::cout << p.use_count() << "\n";
    auto q = p;
    std::cout << p.use_count() << "\n";
    std::cout << "the int p now points to is:" << *p << "\n";*/

    std::shared_ptr<int> p(new int(42));
    /**
     * @brief   std::shared_ptr<int>(p.get()) construct a temporary shared_ptr and copy it
     *          to the parameter.However it is not a copy of p. As a result, at end of this
     *          main function p will free the memory that has been freed inside process ().
     *          That's why "double freed or corruption" was generated.
     */
    process(std::shared_ptr<int>(p.get()));
    return 0;
}