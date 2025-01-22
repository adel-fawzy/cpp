#include "core/App.hpp"
#include <iostream>
#include <thread>
int main()
{
    App app;
    app.run();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "App exiting" << std::endl;
    return 0;
}
