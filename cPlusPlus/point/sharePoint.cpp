//**************************
// Author:  yh
// Time:    2021/12/19
//**************************

// shared_ptr-examples.cpp
// The following examples assume these declarations:
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
using namespace std;

/*
按值传递 shared_ptr。 这将调用复制构造函数，增加引用计数，并使被调用方成为所有者。 此操作的开销很小，但此操作的开销可能很大，具体取决于要传递多少 shared_ptr 对象。 当调用方和被调用方之间的（隐式或显式）代码协定要求被调用方是所有者时，请使用此选项。
按引用或常量引用传递 shared_ptr。 在这种情况下，引用计数不会增加，并且只要调用方不超出范围，被调用方就可以访问指针。 或者，被调用方可以决定基于引用创建一个 shared_ptr，并成为一个共享所有者。 当调用方并不知道被调用方，或当您由于性能原因必须传递一个 shared_ptr 且希望避免复制操作时，请使用此选项。
传递基础指针或对基础对象的引用。 这使被调用方能够使用对象，但不会使其能够共享所有权或延长生存期。 如果被调用方通过原始指针创建一个 shared_ptr，则新的 shared_ptr 独立于原始的，并且不会控制基础资源。 当调用方和被调用方之间的协定明确指定调用方保留 shared_ptr 生存期的所有权时，请使用此选项。
在确定如何传递 shared_ptr 时，确定被调用方是否必须共享基础资源的所有权。 “所有者”是只要它需要就可以使基础资源一直有效的对象或函数。 如果调用方必须保证被调用方可以将指针的生命延长到其（函数）生存期以外，则请使用第一个选项。 如果您不关心被调用方是否延长生存期，则按引用传递并让被调用方复制或不复制它。
如果必须为帮助器函数提供对基础指针的访问权限，并且你知道帮助器函数将使用该指针并且将在调用函数返回前返回，则该函数不必共享基础指针的所有权。 它只需在调用方的 shared_ptr 的生存期内访问指针即可。 在这种情况下，按引用传递 shared_ptr 或传递原始指针或对基础对象的引用是安全的。 通过此方式传递将提供一个小的性能好处，并且还有助于您表达编程意图。
有时，例如，在一个 std::vector<shared_ptr<T>> 中，您可能必须将每个 shared_ptr 传递给 lambda 表达式主体或命名函数对象。 如果 lambda 或函数没有存储指针，则将按引用传递 shared_ptr 以避免调用每个元素的复制构造函数。
 */
struct MediaAsset {
    virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset {
    std::wstring artist;
    std::wstring title;

    Song(const std::wstring &artist_, const std::wstring &title_) :
            artist{artist_}, title{title_} {}
};

struct Photo : public MediaAsset {
    std::wstring date;
    std::wstring location;
    std::wstring subject;

    Photo(
            const std::wstring &date_,
            const std::wstring &location_,
            const std::wstring &subject_) :
            date{date_}, location{location_}, subject{subject_} {}
};

void constructShare() {
    // Use make_shared function when possible.
    auto sp1 = make_shared<Song>(L"The Beatles", L"Im Happy Just to Dance With You");

    // Ok, but slightly less efficient.
    // Note: Using new expression as constructor argument
    // creates no named variable for other code to access.
    shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance"));

    // When initialization must be separate from declaration, e.g. class members,
    // initialize with nullptr to make your programming intent explicit.
    shared_ptr<Song> sp5(nullptr);
    //Equivalent to: shared_ptr<Song> sp5;
    //...
    sp5 = make_shared<Song>(L"Elton John", L"I'm Still Standing");

    //Initialize with copy constructor. Increments ref count.
    auto sp3(sp2);

    //Initialize via assignment. Increments ref count.
    auto sp4 = sp2;

    //Initialize with nullptr. sp7 is empty.
    shared_ptr<Song> sp7(nullptr);

    // Initialize with another shared_ptr. sp1 and sp2
    // swap pointers as well as ref counts.
    sp1.swap(sp2);
}



void copyShare() {
    vector<shared_ptr<Song>> v {
            make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"),
            make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"),
            make_shared<Song>(L"Tha ", L"Entre El Mar y Una Estrella")
    };

    vector<shared_ptr<Song>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [] (shared_ptr<Song> s)
    {
        return s->artist.compare(L"Bob Dylan") == 0;
    });

    for (const auto& s : v2)
    {
        wcout << s->artist << L":" << s->title << endl;
    }
}

/*
分别是插入迭代器、流迭代器、反向迭代器和移动迭代器，定义在<iterator>头文件中，
三种插入迭代器（back_inserter,inserter,front_inserter）的区别。
back_inserter：创建一个使用push_back的迭代器
inserter：此函数接受第二个参数，这个参数必须是一个指向给定容器的迭代器。元素将被插入到给定迭代器所表示的元素之前。
front_inserter：创建一个使用push_front的迭代器（元素总是插入到容器第一个元素之前）
由于list容器类型是双向链表，支持push_front和push_back操作，因此选择list类型来试验这三个迭代器。

list<int> lst = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
list<int> lst2 ={10}, lst3={10},lst4={10};
copy(lst.cbegin(), lst.cend(), back_inserter(lst2));
//lst2包含10,1,2,3,4,5,6,7,8,9
copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
//lst3包含1,2,3,4,5,6,7,8,9,10
copy(lst.cbegin(), lst.cend(), front_inserter(lst4));
//lst4包含9,8,7,6,5,4,3,2,1,10
 */
void shareCast() {
    vector<shared_ptr<MediaAsset>> assets {
            make_shared<Song>(L"Himesh Reshammiya", L"Tera Surroor"),
            make_shared<Song>(L"Penaz Masani", L"Tu Dil De De"),
            make_shared<Photo>(L"2011-04-06", L"Redmond, WA", L"Soccer field at Microsoft.")
    };

    vector<shared_ptr<MediaAsset>> photos;
    copy_if(assets.begin(), assets.end(), back_inserter(photos), [] (shared_ptr<MediaAsset> p) -> bool
    {
        // Use dynamic_pointer_cast to test whether
        // element is a shared_ptr<Photo>.
        shared_ptr<Photo> temp = dynamic_pointer_cast<Photo>(p);
        return temp.get() != nullptr;
    });

    for (const auto&  p : photos)
    {
        // We know that the photos vector contains only
        // shared_ptr<Photo> objects, so use static_cast.
        wcout << "Photo location: " << (static_pointer_cast<Photo>(p))->location << endl;
    }
    std::cout << endl;
    vector<shared_ptr<MediaAsset>> Songs;
    copy_if(assets.begin(), assets.end(), back_inserter(Songs), [](shared_ptr<MediaAsset> p)->bool {
        shared_ptr<Song> temp = dynamic_pointer_cast<Song>(p);
        return temp.get() != nullptr;
    });
    for (const auto&  p : Songs)
    {
        // We know that the photos vector contains only
        // shared_ptr<Photo> objects, so use static_cast.
        wcout << "Song title: " << (static_pointer_cast<Song>(p))->title << endl;
    }
}
void shareReloadCompare() {
    // Initialize two separate raw pointers.
    // Note that they contain the same values.
    auto song1 = new Song(L"Village People", L"YMCA");
    auto song2 = new Song(L"Village People", L"YMCA");

    // Create two unrelated shared_ptrs.
    shared_ptr<Song> p1(song1);
    shared_ptr<Song> p2(song2);

    // Unrelated shared_ptrs are never equal.
    wcout << "p1 < p2 = " << std::boolalpha << (p1 < p2) << endl;
    wcout << "p1 == p2 = " << std::boolalpha <<(p1 == p2) << endl;

    // Related shared_ptr instances are always equal.
    shared_ptr<Song> p3(p2);
    wcout << "p3 == p2 = " << std::boolalpha << (p3 == p2) << endl;
}

void printList(list<int> lt) {
    for(auto v : lt) {
        cout << v << " ";
    }
    cout << endl;
}
int main() {
    //copyShare();
    //shareReloadCompare();
    shareCast();
    return 0;
}