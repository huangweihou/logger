#include <condition_variable>
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>
#include <list>

class Log {
    public:
        Log() = default;
        Log(const Log &) = delete;
        Log(Log &&) = default;

        template<class T>
        Log &operator <<(const T &value) {
            std:: cout << value;
            return *this;
        }

        // output manipulators
        Log &operator <<(std::ios &(*pf)(std::ios &)) {
            std::cout << pf;
            return *this;
        }

        Log &operator <<(std::ios_base &(*pf)(std::ios_base &)) {
            std::cout << pf;
            return *this;
        }

        Log &operator <<(std::ostream &(*pf)(std::ostream &)) {
            std::cout << pf;
            return *this;
        }

        Log &operator =(const Log&) = delete;
        Log &operator =(Log&&) = default;
};

int main() {
    Log log;
    log << "abc" << 42 <<  std::endl;
    return 0;
}