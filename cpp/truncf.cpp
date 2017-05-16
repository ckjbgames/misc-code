/*
 * Usage: truncf filename length
 * Truncate a file to a certain length.
 * Dist under the MIT License.
 * ckjbgames 2017
 */
#include<iostream>
#include<fstream>
#include<cstring>
void err() {
	std::cerr << "There was an error with file trunctuation.\n" <<
		"Sorry about that.\n";
	std::exit(1);
}
size_t fsize(std::fstream& f) {
	size_t s;
	f.seekg(0,f.end);
	s = f.tellg();
	f.seekg(0,f.beg);
	return s;
}
void truncf(std::fstream& f, int n, const char* name) {
	char* buf = new char[fsize(f)];
	f.read(buf,fsize(f));
	f.seekg(0,f.beg);
	f.close();
	std::ofstream g(name,std::ofstream::trunc);
	g.write(buf,n);
}
int main(int argc, char* argv[]) {
	if(argc < 3) {
		std::cerr << "You didn't give enough parameters.\n";
		std::exit(1);
	}
	std::fstream f(argv[1],std::fstream::in|std::fstream::out);
	int n = atoi(argv[2]);
	if((n==0)||!f) { 
		std::cerr << "Your argument is invalid.\n";
		std::exit(1);
	}
	try {
		truncf(f,n,argv[1]);
	} catch(std::fstream::failure fail) {
		err();
	}
	return 0;
}
