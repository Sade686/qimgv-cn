#include "stuff.h"
#include <QDir>

int clamp(int x, int lower, int upper) {
    return qMin(upper, qMax(x, lower));
}

// 0 - mac, 1 - linux, 2 - windows, 3 - other
int probeOS() {
#ifdef TARGET_OS_MAC
    return 0;
#elif defined(__linux__) || defined(__FreeBSD__)
    return 1;
#elif defined _WIN32 || defined _WIN64
    return 2;
#else
    return 3;
#endif
}

StdString toStdString(QString str) {
#ifdef _WIN32
    return str.toStdWString();
#else
    return str.toStdString();
#endif
}

QString fromStdString(StdString str) {
#ifdef _WIN32
    return QString::fromStdWString(str);
#else
    return QString::fromStdString(str);
#endif
}

QString fromFsPath(const std::filesystem::path &path) {
#ifdef _WIN32
    // fs paths concatenate with '\' while the rest of the app uses '/'.
    // normalize, otherwise indexOfFile() string comparisons fail.
    return QDir::fromNativeSeparators(QString::fromStdWString(path.wstring()));
#else
    return QString::fromStdString(path.generic_string());
#endif
}
