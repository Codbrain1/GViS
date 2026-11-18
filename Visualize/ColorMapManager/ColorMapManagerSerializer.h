#pragma once
#include "Common/Structures/SessionStructures.h"
#include "Visualize/ColorMapManager/ColorMapManager.h"
#include "colormapmanager_export.h"

namespace GViS::Visualize {

class COLORMAPMANAGER_EXPORT ColorMapManagerSerializer {
  public:
    static GViS::Session::ColorMapManagerDTO toDTO();
    static void                              fromDTO(const GViS::Session::ColorMapManagerDTO& dto);
};
} // namespace GViS::Visualize