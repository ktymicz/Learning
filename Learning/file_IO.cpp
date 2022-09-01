#include "file_IO.h"

void use_ios_ate()
{
	std::string filename("filename10.txt");
	std::fstream ate_fsto(filename, std::ios::ate | std::ios::out);
	if(!ate_fsto.is_open())
		std::cout << "Open file " << filename << "to write failed\n";
	double d = 3.14;
	ate_fsto.seekp(0, std::ios::beg).write(reinterpret_cast<char*> (&d), sizeof d) 
		<< " call to seekp() ,  This text is added in ate openmode\ns";

	ate_fsto.close();

	
	std::ifstream ate_ifst(filename, std::ios::ate | std::ios::in);
	if(!ate_ifst.is_open()) 
		std::cout << "Open file " << filename << "to read failed\n";
	std::cout << "read from file " << filename << " use seekg to beg\n" << "read one\n";

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
	double d1;
	std::string fileText;
	ate_ifst.read(reinterpret_cast<char*> (&d1), sizeof d1);
	if (ate_ifst >> fileText)
		std::cout << d1 << " " << fileText;

}