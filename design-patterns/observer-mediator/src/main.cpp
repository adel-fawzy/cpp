#include "core/App.hpp"
#include <iostream>
#include <thread>
int main()
{
    // App app;
    // app.run();
    std::cout << "Adssel" << std::endl;
    fflush(stdout); // Force output to the terminal

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Adel" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Fawzy" << std::endl;
    // std::cout << "app exiting" << std::endl;
    return 0;
}