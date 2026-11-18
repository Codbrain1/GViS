#pragma once
#include "Common/Structures/SessionStructures.h"

namespace GViS::Core {
class FileSchemeRegistry;
}

namespace GViS::Session {
class FileSchemeRegistrySerializer {
  public:
    static FileSchemeRegistryDTO toDTO(Core::FileSchemeRegistry* registry);
    bool fromDTO(const FileSchemeRegistryDTO& dto, Core::FileSchemeRegistry* registry);
};
} // namespace GViS::Session