// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef CORE_FXGE_INCLUDE_CFX_FXGEDEVICE_H_
#define CORE_FXGE_INCLUDE_CFX_FXGEDEVICE_H_

#include "core/fxge/include/cfx_renderdevice.h"
#include "core/fxge/include/fx_dib.h"

class SkPictureRecorder;

class CFX_FxgeDevice : public CFX_RenderDevice {
 public:
  CFX_FxgeDevice();
  ~CFX_FxgeDevice() override;

  bool Attach(CFX_DIBitmap* pBitmap,
              bool bRgbByteOrder,
              CFX_DIBitmap* pOriDevice,
              bool bGroupKnockout);
  bool Create(int width,
              int height,
              FXDIB_Format format,
              CFX_DIBitmap* pOriDevice);

#ifdef _SKIA_SUPPORT_
  bool AttachRecorder(SkPictureRecorder* recorder);
  SkPictureRecorder* CreateRecorder(int size_x, int size_y);
  void DebugVerifyBitmapIsPreMultiplied() const override;
#endif

 private:
  bool m_bOwnedBitmap;
};

#endif  // CORE_FXGE_INCLUDE_CFX_FXGEDEVICE_H_
