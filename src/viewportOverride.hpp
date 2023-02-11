#pragma once

#include <maya/MViewport2Renderer.h>

class ViewportOverride : public MHWRender::MRenderOverride {
public:
  ViewportOverride(const MString& pluginName, const MString& viewportOverrideName);
  ~ViewportOverride();

  /// setups the render loop for the frame
  MStatus setup(const MString& destPanel) override;
  /// cleans up the render loop for the next frame
  MStatus cleanup() override;
  /// defines the supported graphics API of the override
  MHWRender::DrawAPI supportedDrawAPIs() const override;

  // LOOP FUNCTIONS
  bool startOperationIterator() override;                  ///< starts operations
  MHWRender::MRenderOperation* renderOperation() override; ///< gets current render operation
  bool nextRenderOperation() override;                     ///< increases the render operation

  /// Gets the render override.
  /// @return A reference to the render override.
  static ViewportOverride& getRenderOverride();

private:
  /// Resets the render operations
  void resetRenderOperations_();

  const MString overrideName_;
  int curRenderOperation_;



};
