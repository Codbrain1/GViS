#pragma once

namespace GViS::Core {
class LogManager {
  public:
    static void setup();
    static void setVerbose(bool enabled);
};
} // namespace GViS::Core