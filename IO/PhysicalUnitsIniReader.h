#pragma once
#include "Common/Enums/IOEnums.h"
#include "Common/Structures/PhysicalStructures.h"
#include <expected>

namespace GViS::IO {
std::expected<Physics::PhysicalUnitsProfile, IO::ReadStatus> importIniFile(const QString& filePath);

} // namespace GViS::IO