#include "file_IO.h"

void use_ios_ate()
{
	std::string filename("filename10.txt");
	std::fstream ate_fsto(filename, std::ios::ate | std::ios::out);
	if(!ate_fsto.is_open())
		std::cout << "Open file " << filename << "to write failed\n";
	double d = 3.14;
	ate_fsto.seekp(0, std::ios::beg).write(reinterpret_cast<char*> (&d), sizeof d) // casted into char*
		<< " call to seekp() ,  This text is added in ate openmode\ns";

	ate_fsto.close();

	
	std::ifstream ate_ifst(filename, std::ios::ate | std::ios::in);
	if(!ate_ifst.is_open()) 
		std::cout << "Open file " << filename << "to read failed\n";
	std::cout << "read from file " << filename << " use obj.seekg(0, std::ios::beg);\n" << "read one\n";

	int length = ate_ifst.tellg();
	std::string fileText(length, '\0');
	ate_ifst.seekg(0, std::ios::beg);
	ate_ifst.read(&fileText[0], length);
	std::cout << fileText;
	std::cout << " read two\n";
	ate_ifst.clear();
	ate_ifst.seekg(0, std::ios::beg);
	double d1;
	std::string one_word;
	ate_ifst.read(reinterpret_cast<char*> (&d1), sizeof d1);
	if( ate_ifst >> fileText)
		std::cout << d1 << " " << fileText;
	
	
}
void use_ios_ate_binary()
{
	std::string filename("filename10.txt");
	std::fstream ate_fsto(filename, std::ios::ate | std::ios::out | std::ios::binary);
	if (!ate_fsto.is_open())
		std::cout << "Open file " << filename << "to write failed\n";
	double d = 3.14;
	ate_fsto.seekp(0, std::ios::beg).write(reinterpret_cast<char*> (&d), sizeof d)
		<< " call to seekp() ,  This text is added in ate openmode\n";

	ate_fsto.close();

	std::cout << "read from file " << filename << '\n';
	std::ifstream ate_ifst(filename, std::ios::ate | std::ios::in| std::ios::binary);
	if (!ate_ifst.is_open())
		std::cout << "Open file " << filename << "to read failed\n";
	ate_ifst.seekg(std::ios::beg);
	double d1;
	std::string fileText;
	ate_ifst.read(reinterpret_cast<char*> (&d1), sizeof d1);
	if (ate_ifst >> fileText)
		std::cout << d1 << " " << fileText;

}


void use_ios_ate_Binary_Text()
{
	std::string fileBinary = "use_ate_Binary.txt";
	std::fstream ateb_ofst(fileBinary, std::ios::ate | std::ios::out | std::ios::binary);
	if (!ateb_ofst.is_open())
	{
		std::cerr << "file open " << fileBinary << "to write failed.\n";
	}
	ateb_ofst.seekp(std::ios::beg);
	std::string s = "use_ate_Binary file,\n some info  \r\n";
	ateb_ofst.write(s.c_str(), s.size());
	ateb_ofst.close();

	std::fstream ateb_ifst(fileBinary, std::ios::ate | std::ios::in | std::ios::binary);
	if (!ateb_ifst.is_open())
	{
		std::cerr << "file open " << fileBinary << "to read failed\n";
	}
	int lengthfile = ateb_ifst.tellp();
	std::string fread(lengthfile, '\0');
	ateb_ifst.seekg(std::ios::beg);
	ateb_ifst.read(&fread[0], lengthfile);

	std::cout << "size string: " << s.size() << '\n'
		<< "file length tellp: " << lengthfile << '\n' << fread;

	std::string fileText = "use_ate.txt";
	std::fstream ate_ofst(fileText, std::ios::ate | std::ios::out);
	ate_ofst.seekp(std::ios::beg);
	ate_ofst.write(s.c_str(), s.size());
	ate_ofst.close();
	
	std::fstream ate_ifst(fileText, std::ios::ate | std::ios::in);
	int ate_length = ateb_ifst.tellg();
	std::string read_fate(ate_length,'\0');
	if (!ate_ifst.is_open())
	{
		std::cerr << "file open " << fileText << "to read failed\n";
	}
	ate_ifst.seekg(std::ios::beg);
	ate_ifst.read(&read_fate[0], ate_length);

	std::cout << "read_fate: " << read_fate << ", size: " << read_fate.size() << '\n';

}