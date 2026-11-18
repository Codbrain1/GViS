#pragma once
#include <QList>
#include <QString>
#include <optional>
#include <qcontainerfwd.h>

namespace GViS::Visualize
{
Q_NAMESPACE

enum class EntityType
{
  Unknown,
  Gas,
  Stars,
  DarkMatter,
  Mixed
};
Q_ENUM_NS(EntityType)

inline QString entitytypeToString(EntityType type)
{
  switch (type)
  {
  case GViS::Visualize::EntityType::DarkMatter:
    return "DarkMatter";
  case GViS::Visualize::EntityType::Gas:
    return "Gas";
  case GViS::Visualize::EntityType::Stars:
    return "Stars";
  case GViS::Visualize::EntityType::Mixed:
    return "Mixed";
  default:
    return "Unknown";
  }
}

//=====================From String=========================
inline EntityType entitytypeFromString(const QString &s)
{
  if (s == "DarkMatter")
    return EntityType::DarkMatter;
  if (s == "Gas")
    return EntityType::Gas;
  if (s == "Stars")
    return EntityType::Stars;
  if (s == "Mixed")
    return EntityType::Mixed;
  return EntityType::Unknown;
}
} // namespace GViS::Visualize