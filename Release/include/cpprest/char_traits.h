#include <cstdint>
#include <cstring>
#include <string>

namespace std
{
template<>
struct char_traits<uint8_t>
{
    using char_type = uint8_t;
    using int_type = unsigned int;
    using off_type = std::streamoff;
    using pos_type = std::streampos;
    using state_type = std::mbstate_t;

    static void assign(char_type& c1, const char_type& c2) noexcept { c1 = c2; }

    static bool eq(char_type c1, char_type c2) noexcept { return c1 == c2; }

    static bool lt(char_type c1, char_type c2) noexcept { return c1 < c2; }

    static int compare(const char_type* s1, const char_type* s2, std::size_t n) noexcept
    {
        return std::memcmp(s1, s2, n);
    }

    static std::size_t length(const char_type* s) noexcept
    {
        const char_type* p = s;
        while (*p != 0)
            ++p;
        return p - s;
    }

    static const char_type* find(const char_type* s, std::size_t n, const char_type& a) noexcept
    {
        for (std::size_t i = 0; i < n; ++i)
        {
            if (eq(s[i], a))
            {
                return s + i;
            }
        }

        return nullptr;
    }

    static char_type* move(char_type* s1, const char_type* s2, std::size_t n) noexcept
    {
        return static_cast<char_type*>(std::memmove(s1, s2, n));
    }

    static char_type* copy(char_type* s1, const char_type* s2, std::size_t n) noexcept
    {
        return static_cast<char_type*>(std::memcpy(s1, s2, n));
    }

    static char_type* assign(char_type* s, std::size_t n, char_type a) noexcept
    {
        std::fill_n(s, n, a);
        return s;
    }

    static int_type not_eof(int_type c) noexcept { return c == eof() ? ~eof() : c; }

    static char_type to_char_type(int_type c) noexcept { return static_cast<char_type>(c); }

    static int_type to_int_type(char_type c) noexcept { return static_cast<int_type>(c); }

    static bool eq_int_type(int_type c1, int_type c2) noexcept { return c1 == c2; }

    static int_type eof() noexcept { return static_cast<int_type>(-1); }
};
} // namespace std
