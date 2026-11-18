#pragma once
#include "Common/Structures/ObjectRegistryStructures.h"

namespace GViS::Physics::Math {
GViS::Core::DataNodeMetaData calculateMetaData(vtkSmartPointer<vtkDataSet> dataSet,
                                               double                      timestamp);
double                       calculateTimestamp(double timestamp);
} // namespace GViS::Physics::Math