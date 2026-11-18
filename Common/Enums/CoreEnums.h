#pragma once
#include <QObject>
#include <qtmetamacros.h>

namespace GViS::Core
{
Q_NAMESPACE
enum class TaskPriority
{
  Urgent,
  Bulk,
  Auto
};
Q_ENUM_NS(TaskPriority)
} // namespace GViS::Core