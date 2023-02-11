#include "viewportOverride.hpp"

ViewportOverride::ViewportOverride(const MString& pluginName, const MString& viewportOverrideName) :
  MRenderOverride(pluginName), overrideName_{viewportOverrideName}, curRenderOperation_{0} {
  cout << "ViewportOverride()" << endl;
}

ViewportOverride::~ViewportOverride() {
  cout << "~ViewportOverride()" << endl;
}

MStatus ViewportOverride::setup(const MString& destPanel) {
  return MS::kSuccess;
}

MStatus ViewportOverride::cleanup() {
  return MS::kSuccess;
}

MHWRender::DrawAPI ViewportOverride::supportedDrawAPIs() const {
  return MHWRender::kOpenGLCoreProfile;
}

bool ViewportOverride::startOperationIterator() {
  return false;
}

MHWRender::MRenderOperation* ViewportOverride::renderOperation() {
  return nullptr;
}

bool ViewportOverride::nextRenderOperation() {
  return false;
}

ViewportOverride& ViewportOverride::getRenderOverride() {
  auto theRenderer = MHWRender::MRenderer::theRenderer();
  auto renderOverride =
    (ViewportOverride*)theRenderer->findRenderOverride("debugOverride");
  return *renderOverride;
}

void ViewportOverride::resetRenderOperations_() {
}
