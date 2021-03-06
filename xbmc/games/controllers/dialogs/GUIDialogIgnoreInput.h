/*
 *  Copyright (C) 2017-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "GUIDialogButtonCapture.h"
#include "input/joysticks/DriverPrimitive.h"

#include <string>
#include <vector>

namespace KODI
{
namespace GAME
{
  class CGUIDialogIgnoreInput : public CGUIDialogButtonCapture
  {
  public:
    CGUIDialogIgnoreInput() = default;

    virtual ~CGUIDialogIgnoreInput() = default;

    // specialization of IButtonMapper via CGUIDialogButtonCapture
    bool AcceptsPrimitive(JOYSTICK::PRIMITIVE_TYPE type) const override;

  protected:
    // implementation of CGUIDialogButtonCapture
    virtual std::string GetDialogText() override;
    virtual std::string GetDialogHeader() override;
    virtual bool MapPrimitiveInternal(JOYSTICK::IButtonMap* buttonMap,
                                      IKeymap* keymap,
                                      const JOYSTICK::CDriverPrimitive& primitive) override;
    void OnClose(bool bAccepted) override;

  private:
    bool AddPrimitive(const JOYSTICK::CDriverPrimitive& primitive);

    std::string m_deviceName;
    std::vector<JOYSTICK::CDriverPrimitive> m_capturedPrimitives;
  };
}
}
