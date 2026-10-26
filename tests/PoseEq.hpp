#pragma once
#include "Executor.hpp"
#include <iosfwd>

namespace adas {
bool operator==(const Pose& lhs, const Pose& rhs) noexcept;
void PrintTo(const Pose& pose, std::ostream* output);
}  // namespace adas
