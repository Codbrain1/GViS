#pragma once

#include <QByteArray>
#include <QVariantMap>
#include <memory>
#include <optional>

namespace GViS::Session
{

class IProjectFormatCodec
{
public:
  virtual ~IProjectFormatCodec() = default;

  virtual QByteArray encode(const QVariantMap &data) const = 0;
  virtual std::optional<QVariantMap> decode(const QByteArray &data) const = 0;
};

using ProjectFormatCodecPtr = std::unique_ptr<IProjectFormatCodec>;

} // namespace GViS::Session
