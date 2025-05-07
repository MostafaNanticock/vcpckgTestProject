#include "Manager.hpp"

#include <Core.hpp>

#include <iostream>

void Manager::manage()
{
    Core core;
    core.hello();
    std::cout << "Managing with Manager!" << std::endl;
}
