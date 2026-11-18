#pragma once
#include "Common/Enums/ViewEnums.h"
#include "views_export.h"

namespace GViS::Visualize::Views {
class AbstractView;

namespace ViewFactory {

VIEWS_EXPORT std::shared_ptr<AbstractView> createView(ViewType type, QObject* parent = nullptr);

}; // namespace ViewFactory
} // namespace GViS::Visualize::Views