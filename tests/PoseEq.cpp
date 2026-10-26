#include "PoseEq.hpp"
#include <ostream>
#include <tuple>

namespace adas {
bool operator==(const Pose& lhs, const Pose& rhs) noexcept
{
    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
}
void PrintTo(const Pose& pose, std::ostream* output)
{
    *output << "(" << pose.x << ", " << pose.y << ", " << pose.heading << ")";
}
}  // namespace adas
