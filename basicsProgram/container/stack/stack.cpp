//**************************
// Author:  yh
// Time:    2022/5/9
//**************************


std::deque<int> mydeque (3,100);          // deque with 3 elements
std::vector<int> myvector (2,200);        // vector with 2 elements

std::stack<int> first;                    // empty stack
std::stack<int> second (mydeque);         // stack initialized to copy of deque

std::stack<int,std::vector<int> > third;  // empty stack using vector
std::stack<int,std::vector<int> > fourth (myvector);
//std::stack<int> fourth (myvector);


std::cout << "size of first: " << first.size() << '\n';
std::cout << "size of second: " << second.size() << '\n';
std::cout << "size of third: " << third.size() << '\n';
std::cout << "size of fourth: " << fourth.size() << '\n';
printStack(second);
printStack(fourth);