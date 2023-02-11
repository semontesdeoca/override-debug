#pragma once

#include <maya/MString.h>

class utils {
public:
  static void setPluginEnv(const MString& t_pluginName); ///< Sets the plugin environment
  static MString pluginEnv(MString t_folder);            ///< Gets the plugin environment (path)
private:
  static MString environment_; ///< path where the plugin is located
};
