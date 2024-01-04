#include "headers/Application.hpp"

#ifdef __linux__
#include <X11/Xlib.h>
#endif


int main() {
#ifdef __linux__
    XInitThreads();
#endif
    Application::run();
    return 0;
}
