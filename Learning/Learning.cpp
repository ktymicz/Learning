
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <chrono>
#include <ratio>
#include <exception>

#include "mymoves.h"
#include "Constructors.h"
#include "init_Lambda.h"
#include "file_IO.h"
#include "STL_Planet.h"
#include "Driver.h"
#include "Polymorphism.h"
// functions
void file_RW();
void lambda();
void outate();
void use_class_init_lambda();
void use_move();
void use_move_semantics_Driver();
void use_Chrono();
void use_ate();
void use_ate2();

void use_move_semantics_Stupid_driver();
void use_Polymorphism();
int main()
{
    use_Polymorphism();
    //try {
    //    use_ate(); // out|in|ate
    //    //use_ate2(); // out|ate
    //}
    //catch (std::exception& e)
    //{
    //    std::cerr << e.what();
    //}
    //try
    //{
    //    use_move_semantics_Stupid_driver();
    //}
    //catch (const std::exception& e)
    //{
    //    std::cerr << e.what();
    //}

    //use_Chrono();
//    use_move_semantics_Driver();
    //file_RW();
    //outate();
    //lambda();
   // MoveSemanticsTest::doTests();
  //  use_class_init_lambda();
   // use_move();
    //use_ios_ate();
    //use_ios_ate_binary();
   // use_ios_ate_Binary_Text();

    // make_heap_stl();
    //LOQ::querying_property_stl();
}


void use_Polymorphism()
{
    using namespace Polymorphism;
    Base* p;
    Base* p2;
    p = new Derived();
    p2 = new Base();
    p->foo();
    p2->foo();
}

void use_move_semantics_Stupid_driver()
{
    using namespace Movable;
    Driverp d;
    d.hardp[d.co.hsize - 1] = 33;
    Driverp d2 = std::move(d);
    d = Driverp(d2);
    Driverp d3;
    std::cout << "copy(d2) " << d << "\nmove(d) " << d2 << "\ndefault " << d3;

}

void use_ate2()
{
    std::fstream ofs("wow.txt", std::ios::out | std::ios::ate);
    if (!ofs) throw std::exception("filed to open file\n");
    ofs << "data2..,data1.";
    if (ofs.bad()) throw std::exception("bad after writing to file");

    ofs.close();
}

void use_ate()
{

    std::string filename{ "name.txt" };

    fstream ofs(filename, std::ios_base::ate|std::ios_base::out | std::ios::in);
   if (!ofs) throw std::exception("obj. ofs not created");
    ofs.seekp(0, std::ios_base::end);
    ofs << "data..";
    if (ofs.bad()) throw std::exception("bad");
    ofs.close();
}

void use_Chrono()
{
    using Sec = std::chrono::seconds;
    std::chrono::sys_time d = std::chrono::system_clock::now();
    std::chrono::seconds sec{ 3 };

    std::cout << "what\n ms \ts\n";
    for (auto const p : {544ms, 445ms, 33ms, 44ms})
    {
        while (true)
        {
            auto d2 = std::chrono::system_clock::now();
            if (d2 - d >= sec)
            {
                std::cout << p << '\t' << std::chrono::round<Sec>(d2 - d) << '\n';
                sec++;
                break;
            }
        }
    }
    using rsuck = std::ratio<10>;
    using suck = std::chrono::duration<int64_t, rsuck>;
    suck wsu{ 3 };
    std::cout << (wsu + sec).count() << '\n';
}

void use_move_semantics_Driver()
{
    using namespace Movable;
    Driver m;
    Driver m2{ m };
    Driver m3 = Driver(Driver());
    Driver s;
    s.move(20, 20);
    std::cout << m << m2 << m3 << s;
    
    { 
        Driver moved; 
        s = std::move(moved);
    }
    std::cout << s;
    
    
    int* p = s.hardp.get();
    std::cout << " p " << p;
    int* p2 = s.hardp.release();
    std::cout << " p2 " << p2 << '\n';
    s.hardp.reset(p2);
    std::cout << "reset p2, still points to hardp " << p2 << '\n';
    {
        p = std::move(s.hardp.release());
    }
    s.hardp.reset(std::exchange(p, nullptr));
    std::cout << "reset p with exchange" << p << '\n';
}

void use_move()
{
    //Moveable mobj0 = passM(Moveable("zero", 0.0));
    //Moveable mobj("first", 1);
    //Moveable mobj1(mobj);
    //Moveable mobj2 = mobj0;
    //Moveable mobj3, mobj4;
    //
    //mobj3 = mobj0;
    //mobj4 = passM(Moveable("four", 4.4));
    //Moveable mobj5 = Moveable(passM(Moveable("zero", 0.0)));
    //std::cout << "mobj0:" << mobj0
    //    << "mobj:" << mobj
    //    << "mobj1:" << mobj1
    //    << "mobj2:" << mobj2
    //    << "mobj3:" << mobj3
    //    << "mobj4:" << mobj4
    //    << "mobj5:" << mobj5;
    
    Brush b0;
    Brush b = b0;
    Brush b1 = Brush(Brush::mode::four, "Four");
    Brush b2 = f(Brush(Brush::mode::two, "two"));
    Brush b3 = f(Brush()); 
    Brush b4;
    b4 = f(Brush());
    
    Brush b5 = std::move(r(Brush(Brush::mode::two, "two")));
    Brush b6= Brush((std::move(r(Brush(Brush::mode::two, "two")))));
    Brush b7 = Brush(f(Brush(Brush::mode::two, "two")));
    Brush b8 = r(Brush(Brush::mode::two, "two"));
    Brush b9;
    b9 = r(Brush(Brush::mode::two, "two"));
    Brush b10;
    b10 = std::move(r(Brush(Brush::mode::two, "two")));
    
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
// https://en.cppreference.com/w/cpp/io/basic_filebuf/open
// https://en.cppreference.com/w/cpp/io/ios_base/openmode
{
    std::string filename("filename5.txt");
    std::fstream os_ate;
    os_ate.open(filename, os_ate.in | os_ate.out | os_ate.ate);
    if (!os_ate.is_open())
    {
        std::cout << "failed to open\n";
    }

    os_ate << "This text is going to be destroyed;";
    os_ate.seekp(0, std::ios::beg);
    // it will write to the file from the start, existing data in this bytes is overwrited
    os_ate << "This text still exists after next instruction.;\n";
    os_ate.seekp(0, std::ios::end);
    os_ate << "added to the end of the file;";
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
