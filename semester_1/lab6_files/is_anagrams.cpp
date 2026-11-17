#include <chrono>
#include <ctime>
#include <format>
#include <fstream>
#include <iomanip>
#include <locale>
#include <map>
#include <string>

std::time_t Now() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(now);
}

auto FormatTime(time_t time, bool is_utc_format) {
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4996)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

    return is_utc_format ? std::put_time(std::gmtime(&time), "%x %X")
                         : std::put_time(std::localtime(&time), "%x %X");

#if defined(_MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
}

void make_log(std::ofstream& logger, const std::string& msg) {
    logger << FormatTime(Now(), true) << " " << msg << std::endl;
}

bool is_anagrams(const std::map<char, int>& seen) {
    for (const std::pair<char, int>& ch : seen) {
        if (ch.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::ofstream flog("log.txt");
    if (!flog) {
        return 1;
    }

    make_log(flog, "opening file \"input.txt\"");
    std::ifstream fin("input.txt");
    if (!fin) {
        make_log(flog, "file \"input.txt\" cannot be open");
        return 1;
    }
    make_log(flog, "file \"input.txt\" has been opened successfully");

    make_log(flog, "opening file \"output.txt\"");
    std::ofstream fout("output.txt");
    if (!fout) {
        make_log(flog, "file \"output.txt\" cannot be open");
        return 1;
    }
    make_log(flog, "file \"output.txt\" has been opened successfully");

    std::string a, b;

    make_log(flog, "reading lines from \"input.txt\"");

    if (!std::getline(fin, a) || !std::getline(fin, b)) {
        make_log(flog, "failed to read two lines");
        fout << "bad input\n";
        return 1;
    }

    make_log(flog, "read a=\"" + a + "\", b=\"" + b);

    if (a.size() != b.size()) {
        make_log(flog, "lengths differ");
        fout << "cannot be anagrams\n";
        return 0;
    }

    std::map<char, int> seen;

    for (int i = 0; i < a.size(); i++) {
        seen[std::tolower(a[i])]++;
        seen[std::tolower(b[i])]--;
    }

    bool res = is_anagrams(seen);

    make_log(flog, std::string("result is: ") + (res ? "true" : "false"));

    make_log(flog, "writing answer to \"output.txt\"");
    fout << (res ? "anagrams" : "not anagrams") << '\n';

    make_log(flog, "program has ended with code 0");
    return 0;
}