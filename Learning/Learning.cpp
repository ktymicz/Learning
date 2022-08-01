
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include "mymoves.h"
#include "Constructors.h"

#include "init_Lambda.h"

// classes
template <typename T>
class Const;



class MyClass
{
public:
    //MyClass() = default;
    MyClass(std::string str="for sth") : val(str) {}
    std::string val;
    std::string value() const { return val; }
   // static int class_size_off() { return sizeof(MyClass); }
   // MyClass(std::string str = "for C") : s(str){}
};

struct MyStruct
{
    //MyStruct() = default;
    std::string val;
    std::string value() const { return val; }
    //static int class_size_off() { return sizeof(MyStruct); }
    MyStruct(std::string str = "for sth") : val(str) {
        std::cout << "MyStruct(), str adress: " << &str << '\n';
    }
};
//template <typename T>
//static std::string mem(const T& t) {return t.}

class MyClassInt
{
public:
    //MyClassInt() = default;
    //MyClass(std::string str) : s(str) {}
    int val;
    int value() const { return val; }
    //static int class_size_off() { return sizeof(MyClass); }
    // MyClass(std::string str = "for C") : s(str){}
};




template <typename T>
class Const
{
public:

   // std::ostringstream  s;
    MyVector<T> v;
    
    /*void insert(const T& t) {
        v.push_back(t);
        s  << "copy,\n t.memory" << &t
           << "t.value: " << t.str() << '\n'
            << "inserted\n v.memory" << & v.end()-1
            << "t.value: " << v.(end()-1).str() << '\n';
    }*/
    void insert(const T& t) {
        //s << "copy," << &t.val << ", "
        //  << "cmemory:" << &t << '\n';
        v.push_back(t);
        /*s << " value: " << v.back().val << ", "
            << " obj_memmory:" << &v.back().val << '\n';*/
    
    }
    void insert(T&& t) {
   
        /*s << "move, " << t.value() << ", "
          << " cmemory:" << &t.val << '\n';*/
        v.push_back(std::move(t));
        /*s   << " value: " <<   v.back().val << ", "
            << " obj_memmory:" << &v.back().val << '\n';*/
   
    }
    // val memory
    //void insert(const T& t) {
    //    s << "copy," << t.value() << ", "
    //      << "cmemory:" << &t.val << '\n';
    //    v.push_back(t);
    //    s << " value: " << v.back().val << ", "
    //        << " obj_memmory:" << &v.back().val << '\n';
    //    
    //}
    //void insert(T&& t) {
    //   
    //    s << "move, " << t.value() << ", "
    //      << " cmemory:" << &t.val << '\n';
    //    v.push_back(std::move(t));
    //    s   << " value: " <<   v.back().val << ", "
    //        << " obj_memmory:" << & v.back().val << '\n';
    //   
    //}
    //std::string memory_info() const{}
};


template <typename T>
class Const2
{
public:

    std::vector<T> v;
    /*static std::ostringstream s;*/
    /*void insert(const T& t) {
        v.push_back(t);
        s  << "copy,\n t.memory" << &t
           << "t.value: " << t.str() << '\n'
            << "inserted\n v.memory" << & v.end()-1
            << "t.value: " << v.(end()-1).str() << '\n';
    }*/

    void insert( const T& t) {
       /* s << "copy," << t.str() << '\n'
            << "cmemory:" << &t.s << '\n';*/
        v.push_back(&t);
        /*s << "obj_memmory:" << (v.at(v.size() - 1)) << '\n';*/

    }
    void insert(T&& t) {

        /*s << "move," << t.str() << '\n'
            << "cmemory:" << &t.s << '\n';*/
        v.push_back(std::move(&t));
        /*s << "obj_memmory:" << (v.at(v.size() - 1)) << '\n';*/

    }
    //std::string memory_info() const{}
};





// functions
void file_RW();
void lambda();
void outate();
void move();
void move20();
void use_class_init_lambda();
void use_move();

int main() {
    //file_RW();
    //outate();
    //lambda();
    //move();
    //MoveSemanticsTest::doTests();
  //  move20();
    //use_class_init_lambda();
    use_move();


}

void use_move()
{
    Moveable mobj0 = Moveable("zero", 0.0);
    Moveable mobj("first", 1);
    Moveable mobj1(mobj);
    Moveable mobj2 = mobj0;
    Moveable mobj3 =  Moveable("three", 3.3);
}

void use_class_init_lambda()
{
    double x{2.5};
    double  x1{ 4.5 };
    double  x2{ 4 };
    //N2 s(x);
    //N2 s1(x1);
    std::cout << "if [One,Ten]? true : false\n";
    OneTen obj(2.5);
    typedef std::vector<std::unique_ptr<OneTen>> vuOneTen;
    vuOneTen container;
    container.push_back(std::make_unique<OneTen>(0.5));
    container.push_back(std::make_unique<OneTen>(-2));
    container.push_back(std::make_unique<OneTen>(10));
    container.push_back(std::make_unique<OneTen>(x));
    container.push_back(std::make_unique<OneTen>(10.4));
    std::cout << obj << "\n2.5=" << 2.5 << '\n';
    //for (auto& v : container)
      //  std::cout << v;
    for (auto& v : container)
        std::cout <<"OneTen adress:" << v << '\n';

    for (auto& v : container)
        std::cout  << *v ;
    
}

void move20()
{
    //Const<MyStruct> cMS;
    //MyStruct ms;
    //ms.val = "for copy";
    //ms.val.resize(2000);

    //MyStruct ms1 = MyStruct();
    //ms1.val = "for move";
    //ms1.val.resize(2000);

    //cMS.insert(ms);
    //cMS.insert(std::move(ms1));
    //cMS.insert(MyStruct());
    //std::cout << cMS.s.str() << '\n';



}
void move()
{
    //Const<std::unique_ptr<MyStruct>> cMS;
    //std::unique_ptr<MyStruct> ms = std::make_unique<MyStruct>();
    //ms->s = "for copy";
    //cMS.insert(ms);
    //std::unique_ptr<MyStruct> ms2 = std::make_unique<MyStruct>();
    //ms2->s = "for move";
    //cMS.insert(ms2);
    //cMS.insert(std::make_unique<MyStruct>());
    //cMS.v.at(cMS.v.size() - 1)->s = "for move";
    //std::cout << cMS.s.str() << '\n';

    // MyClassInt
    
    //Const<MyClassInt> cMS;
    //cMS.v.resize(10);
    //
    //MyClassInt cint;
    //cint.val = 20;
    //MyClassInt cint1;
    //cint1.val = 21;

    //cMS.insert(cint);
    //cMS.insert(std::move(cint1));
    //cMS.insert(std::move(MyClassInt()));
    //std::cout << cMS.s.str();
   // compiles but no moves 
    Const<MyStruct> cMS;
    {
        MyStruct ms = MyStruct("for copy");
        std::cout << "ms adress: " << &ms << " val:" << ms.val << '\n';
        ms.val.resize(20);

        MyStruct ms1;
        ms1.val = "for move";
        std::cout << "ms adress: " << &ms1 << " val:" << ms1.val << '\n';
        // ms1.val.resize(2000);

        cMS.insert(ms);
        cMS.insert(std::move(ms1));
        cMS.insert(MyStruct());
    }

    //std::cout << cMS.s.str() << '\n';
    Const<MyClass> cMC;
    {
    MyClass mc;
    mc.val = ("for copy");
    MyClass mc1;
    mc1.val = ("for move");
    cMC.insert(mc);
    cMC.insert(std::move(mc1));
    cMC.insert(MyClass());
    }
    //std::cout << cMC.s.str() << '\n';
    //for (auto &v : cMC.v)
     //   std::cout << "val: " << v.val << ", adress: " << &v.val << '\n'
      //  << ", adress val: " << &v << '\n';

    std::cout << "class &obj.v, adress: " <<  &cMC.v
        << ", adress: " << (std::string*)  &(cMC.v.at(0).val) << '\n'
        << "val: " << cMC.v.at(1).val
        << ", adress: " <<  &cMC.v.at(1).val << '\n'
        << "val: " << cMC.v.at(2).val
        << ", adress: " <<&cMC.v.at(2).val << '\n';
    std::cout << "static_cast\n" << "class &obj, adress: " << &cMC
        << ", adress: " << (std::string*)&(cMC.v.at(0).val) << '\n'
        << "val: " << cMC.v.at(1).val
        << ", adress  " << static_cast<std::string*>(&cMC.v.at(1).val) << '\n'
        << "val: " << cMC.v.at(2).val
        << ", adress: " << static_cast<std::string*>(&cMC.v.at(2).val) << '\n';

    std::string* sp = &cMC.v.at(0).val;
    std::cout << ", adress: " << sp << '\n';



 /*   Const2<MyClass> c2MC;
    MyClass mc3;
    mc3.s = ("for copy");
    MyClass mc4;
    mc4.s = ("for move");
    c2MC.insert(mc3);
    c2MC.insert(std::move(mc4));
    c2MC.insert(std::move(MyClass()));
    std::cout << c2MC.s.str() << '\n';*/
    
}


//void move()
//{
//    Const<std::unique_ptr<MyStruct>> cMS;
//    std::unique_ptr<MyStruct> ms = std::make_unique<MyStruct>();
//    ms->s = "for copy";
//    std::unique_ptr<MyStruct> ms1 = std::make_unique<MyStruct>();
//    ms1->s = "for move";
//    cMS.insert(ms);
//    cMS.insert(std::move(ms1));
//    cMS.insert(std::make_unique<MyStruct>());
//    std::cout << cMS.s.str() << '\n';
//    Const<MyClass> cMC;
//    MyClass mc("for copy");
//    MyClass mc1("for move");
//    cMC.insert(mc);
//    cMC.insert(mc1);
//    cMC.insert(std::move(MyClass("what, move")));
//
//    std::cout << cMC.s.str() << '\n';
//}

void lambda()
{
    auto s = [](double d) {

        std::ostringstream oss;
        
        int i = int(d * 100) % 100;
        oss << "int(" << d << "*100)%100 : " << i << " -> ";
        if (i >= 10 && i < 100)
            return oss.str() + std::string("i>=10 && i <100\n");
        else if (i >= 0 && i <= 10)
            return oss.str() + std::string("i>=0 && i<10\n");
        else if (i < 0)
        {
            return oss.str() + std::string( "i<0\n");
        }
        else
            return  oss.str() + std::string("i>=100 : impossbile\n");


    };
    std::cout << s(20);
    std::cout << s(10);
    std::cout << s(1);
    std::cout << s(-1);
    std::cout << s(-.1);
    std::cout << s(0.99);
    std::cout << s(0.49);
    std::cout << s(0.09);
}

void outate()
{
    std::string filename("filename5.txt");
    std::fstream os_ate;
    os_ate.open(filename, os_ate.in|os_ate.out | os_ate.ate);
    if(!os_ate.is_open())
    {
        std::cout << "failed to open\n";
    }
    
    os_ate << "some text3;";
    os_ate << "some text4;";
    os_ate.seekp(0, std::ios::beg);
    // it will write to the file from the start, existing data in this bytes is overwrited
    os_ate << "some text1;";
    os_ate << "some text2;"; 
    os_ate.seekp(0, std::ios::end);
    os_ate << "some text5;";
    
    

}

void file_RW()
{
    std::string filename{ "filename5.txt" };
    std::fstream iofs;
    //iofs.open(filename, iofs.out);
   // iofs.close();
   // iofs.open(filename, iofs.in | iofs.out | iofs.ate); // the file need to exist or it will fail to open
    iofs.open(filename, iofs.out | iofs.ate); /* it will create new file if do not exist, 
     or it will destroy the contents and open the file*/
    iofs.seekp( iofs.end);
    //ifs.seekp();
    if (!iofs.is_open())
    {
        std::cout << "failed to open " << filename << '\n';
    }
    
    iofs << "some text;";
    //iofs.seekg(0, std::ios::beg);
    //std::string inF;
   // std::getline(iofs, inF, '\n');
   // std::cout << inF;
}
