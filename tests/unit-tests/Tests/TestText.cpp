#include <stdafx.h>
#include <util/Text.h>

using namespace Util;

TEST(Text, ConvertWcsFromUtf)
{
    std::wstring wcs{ L"qwerty�����12345" };

    std::string  utf{ Text::Convert::utfFromWcs(wcs) };

    ASSERT_FALSE(utf.empty());

    std::wstring actual{ Text::Convert::wcsFromUtf(utf) };

    EXPECT_EQ(actual, wcs);
}