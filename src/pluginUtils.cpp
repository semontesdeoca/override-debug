#include "pluginUtils.hpp"

#include <maya/MGlobal.h>

MString utils::environment_ = "";

MString utils::pluginEnv(MString t_folder) {
  if (t_folder.length() == 0) {
    return environment_;
  }
  return environment_ + "/" + t_folder;
}

void utils::setPluginEnv(const MString& t_pluginName) {
  MString command = "pluginInfo -query -path \"" + t_pluginName + "\";";
  MString pluginDir = MGlobal::executeCommandStringResult(command);
  int mpos = pluginDir.rindexW("plug-in");
  environment_ = pluginDir.substringW(0, mpos - 2);
  cout << "-> Plugin environment set to: " << environment_ << endl;
}
