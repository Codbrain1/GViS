#include "ColorMapManagerSerializer.h"
#include "Common/Structures/SessionStructures.h"

namespace GViS::Visualize {

GViS::Session::ColorMapManagerDTO ColorMapManagerSerializer::toDTO() {
    GViS::Session::ColorMapManagerDTO dto;
    dto.colorMaps = GViS::Visualize::ColorMapManager::instance().getAllMaps();
    return dto;
}

void ColorMapManagerSerializer::fromDTO(const GViS::Session::ColorMapManagerDTO& dto) {
    for (const auto map : dto.colorMaps) {
        GViS::Visualize::ColorMapManager::instance().AddCustomMap(map);
    }
}

} // namespace GViS::Visualize