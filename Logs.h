#ifndef _LOGS_H_
#define _LOGS_H_

#include <time.h>
#include <string>

using namespace std;

class Logs {
private:
    bool showDebbug;
    string fileName;

    tm * GetTime();

public:
    Logs();
    Logs(string f, bool b);
    virtual ~Logs();

    void ShowDebbug(bool b) {showDebbug = b;}

    void Debbug1(const char *, int, const char *,...);
    #define Debbug(...) Debbug1(__FILE__, __LINE__, __VA_ARGS__)

    void Log1(const char *,...);
    #define Log(...) Log1(__VA_ARGS__)
};

#endif
