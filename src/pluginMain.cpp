#include "pluginUtils.hpp"

#include <stdio.h>
#include <maya/MFnPlugin.h>
#include <maya/MStreamUtils.h>

// On plug-in initialization we register a new override
MStatus initializePlugin(MObject obj) {
  MStatus status;
  MFnPlugin plugin(obj, "Artineering", "1.0", "Any");

#if defined(NT_PLUGIN)
  std::cout.set_rdbuf(MStreamUtils::stdOutStream().rdbuf());
  std::cerr.set_rdbuf(MStreamUtils::stdErrorStream().rdbuf());
#endif

  utils::setPluginEnv(plugin.name());

  // register plugin elements i.e., command, nodes

  return status;
}


// On plug-in de-initialization we deregister a new override
MStatus uninitializePlugin(MObject obj) {
  MStatus status;
  MFnPlugin plugin(obj);

  // deregister plugin elements i.e., command, nodes

  return status;
}
