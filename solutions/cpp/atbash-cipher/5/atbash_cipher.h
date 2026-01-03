#pragma once
#include <string>
namespace atbash_cipher {
std::string encode (std::string_view abc);
std::string decode (std::string_view zyx);
}  // namespace atbash_cipher
