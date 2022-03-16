/*
    bytearray.h

    This file is part of Kuesa.

    Copyright (C) 2018-2021 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
    Author: Paul Lemire <paul.lemire@kdab.com>

    Licensees holding valid proprietary KDAB Kuesa licenses may use this file in
    accordance with the Kuesa Enterprise License Agreement provided with the Software in the
    LICENSE.KUESA.ENTERPRISE file.

    Contact info@kdab.com if any conditions of this licensing are not clear to you.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef KDUTILS_BYTEARRAY_H
#define KDUTILS_BYTEARRAY_H

#include <vector>
#include <stdint.h>
#include <string>

#include <KDUtils/kdutils_export.h>

namespace KDUtils {

class KDUTILS_EXPORT ByteArray
{
public:
    ByteArray();
    explicit ByteArray(const char *, size_t size = 0);
    explicit ByteArray(const uint8_t *, size_t size);
    explicit ByteArray(const std::vector<uint8_t> &data);
    explicit ByteArray(size_t size, uint8_t c = 0);
    ByteArray(const ByteArray &);
    ~ByteArray();

    ByteArray &operator=(const ByteArray &);
    ByteArray &operator=(const char *);

    ByteArray(ByteArray &&other);
    explicit ByteArray(std::vector<uint8_t> &&data);
    ByteArray &operator=(ByteArray &&other);

    ByteArray mid(size_t pos, size_t len = 0) const;
    ByteArray left(size_t left) const;
    ByteArray &remove(size_t pos, size_t len);
    ByteArray &operator+=(const ByteArray &other);
    void clear();

    size_t size() const;
    void reserve(size_t size);
    void resize(size_t size);
    bool empty() const;
    inline bool isEmpty() const { return empty(); }

    int64_t indexOf(uint8_t) const;

    bool startsWith(const ByteArray &b) const;
    bool endsWith(const ByteArray &b) const;

    inline uint8_t *data() { return m_data.data(); }
    inline const uint8_t *data() const { return m_data.data(); }
    inline const uint8_t *constData() const { return m_data.data(); }
    inline const std::vector<uint8_t> &vector() const { return m_data; }

    std::string toStdString() const { return std::string(m_data.begin(), m_data.end()); }

    ByteArray toBase64() const;
    static ByteArray fromBase64(const ByteArray &base64);

private:
    std::vector<uint8_t> m_data;
};

KDUTILS_EXPORT bool operator==(const ByteArray &a, const ByteArray &b);
KDUTILS_EXPORT bool operator!=(const ByteArray &a, const ByteArray &b);
KDUTILS_EXPORT ByteArray operator+(const ByteArray &a, const ByteArray &b);

} // namespace KDUtils

#endif // KUESA_COREUTILS_BYTEARRAY_H