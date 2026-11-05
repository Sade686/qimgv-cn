#pragma once

#include <QString>
#include <filesystem>

#ifdef _WIN32
    #define StdString std::wstring
    #define CharType wchar_t
#else
    #define StdString std::string
    #define CharType char
#endif

int clamp(int x, int lower, int upper);
int probeOS();
StdString toStdString(QString str);
QString fromStdString(StdString str);

// convert std::filesystem::path to QString correctly on all platforms.
// on Windows generic_string()/string() narrow conversion uses the system ACP
// (e.g. GBK), which mangles non-ASCII names; use the wide variant there.
QString fromFsPath(const std::filesystem::path &path);
