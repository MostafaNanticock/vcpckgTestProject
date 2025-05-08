#include <fmt/core.h>
#include <zlib.h>

#define FMT_VERSION_MAJOR (FMT_VERSION / 10000)
#define FMT_VERSION_MINOR (FMT_VERSION / 100 % 100)
#define FMT_VERSION_PATCH (FMT_VERSION % 100)

int main()
{
    // Some useless comment
    const std::string fmtVersionString =
        std::to_string(FMT_VERSION_MAJOR) + '.' + std::to_string(FMT_VERSION_MINOR) + '.' + std::to_string(FMT_VERSION_PATCH);

    fmt::print("fmt version is {}\n"
               "zlib version is {}\n",
               fmtVersionString, ZLIB_VERSION);
    return 0;
}
