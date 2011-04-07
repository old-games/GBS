#include "wx_pch.h"

void check_types()
{
    size_check<char, CHAR_SIZE>();
    size_check<short, SHORT_SIZE>();
    size_check<int, INT_SIZE>();
    size_check<uint64, INT64_SIZE>();
}