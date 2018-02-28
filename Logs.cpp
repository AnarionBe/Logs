#include "Logs.h"
#include <iostream>
#include <fstream>
#include <stdarg.h>

using namespace std;

Logs::Logs() {
	fileName = "./logs.dblogs";
	showDebbug = true;
}

Logs::Logs(string f, bool b) {
	fileName = f;
	showDebbug = b;
}

Logs::~Logs() {

}

tm * Logs::GetTime() {
	time_t t;
	t = time(NULL);
	return localtime(&t);
}

void Logs::Debbug1(const char * pFichier, int ligne, const char *pDebbug,...) {
	if(showDebbug) {
		char buff[255];
	    va_list args;
	    va_start(args, pDebbug);
	    vsprintf(buff, pDebbug, args);
	    va_end(args);
	    cerr << "\033[31m(" << pFichier << " - " << ligne << ") " << buff << "\033[39m" << endl;
	}
}

void Logs::Log1(const char *pLog,...) {
	tm *time = GetTime();
	char *date = new char[255];
	strftime(date, 255, "%c", time);

	char buff[255];
	va_list args;
	va_start(args, pLog);
	vsprintf(buff, pLog, args);
	va_end(args);

	ofstream file(fileName.c_str(), ios::out|ios::app);
	file << "(" << date << ")" << " -> " << buff << "\n";
	file.close();
}
