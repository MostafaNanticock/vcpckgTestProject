#include <boost/dll.hpp>
#include <fmt/core.h>
#include <crashpad/client/crashpad_client.h>

int main()
{
    fmt::println("Hello World!");

    crashpad::CrashpadClient client;
    fmt::println("client path: %s", client.RegisterWerModule(L"path"));

    try
    {
        boost::dll::shared_library lib("C:\\Windows\\System32\\kernel32.dll");
        fmt::println(lib.location().string());
        fmt::println(lib.suffix().string());
    }
    catch (...)
    {
    }

    return 0;
}
