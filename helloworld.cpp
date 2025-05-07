#include <fmt/core.h>
#include <crashpad/client/crashpad_client.h>

int main()
{
    fmt::println("Hello World!");

    crashpad::CrashpadClient client;
    fmt::println("client path: %s", client.RegisterWerModule(L"path"));

    return 0;
}
