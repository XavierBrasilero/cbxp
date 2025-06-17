#ifndef __CB_EXPLORER_CONTROL_BLOCK_FIELD_FORMATTER
#define __CB_EXPLORER_CONTROL_BLOCK_FIELD_FORMATTER

#include <unistd.h>

#include <cstdint>
#include <iomanip>
#include <sstream>
#include <string>

namespace CBExplorer {
class ControlBlockFieldFormatter {
 private:
  template <typename T>
  static T uint(const void *p_field) {
    T uint_field;
    std::memcpy(reinterpret_cast<char *>(&uint_field), p_field, sizeof(T));
    return uint_field;
  }

 public:
  static const std::string getString(const void *p_field, int length) {
    auto ascii_field_unique_ptr = std::make_unique<char[]>(length);
    std::memcpy(ascii_field_unique_ptr.get(), p_field, length);
    __e2a_l(ascii_field_unique_ptr.get(), length);
    return ascii_field_unique_ptr.get();
  }
  template <typename T>
  static const std::string getHex(const void *p_field) {
    std::ostringstream oss;
    oss << "0x" << std::hex << std::setfill('0');
    oss << std::setw(sizeof(T) * 2)
        << ControlBlockFieldFormatter::uint<T>(p_field);
    return oss.str();
  }
  template <typename T>
  static const std::string getBitmap(const void *p_field) {
    std::ostringstream oss;
    oss << std::bitset<sizeof(T) * 8>{
        ControlBlockFieldFormatter::uint<T>(p_field)};
    return oss.str();
  }
};
}  // namespace CBExplorer

#endif
