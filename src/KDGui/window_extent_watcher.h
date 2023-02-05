/*
  This file is part of KDUtils.

  SPDX-FileCopyrightText: 2018-2023 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
  Author: Paul Lemire <paul.lemire@kdab.com>

  SPDX-License-Identifier: AGPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#pragma once

#include <stdint.h>

namespace KDGui {

struct WindowExtentWatcher {
    virtual ~WindowExtentWatcher() = default;
    virtual uint32_t width() const = 0;
    virtual uint32_t height() const = 0;
    virtual float scaleFactor() const { return 1; };
};

}; // namespace KDGui
