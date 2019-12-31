/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef KIMAGEANNOTATOR_RESIZEHANDLE_H
#define KIMAGEANNOTATOR_RESIZEHANDLE_H

#include <QRectF>

namespace kImageAnnotator {

class ResizeHandle : public QRectF
{
public:
	ResizeHandle();
	explicit ResizeHandle(int size);
	~ResizeHandle() = default;
	QPointF anchor() const;
	void setAnchor(const QPointF &pos);
	QPointF offset() const;
	void setOffset(const QPointF &offset);

private:
	QPointF mOffset;
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_RESIZEHANDLE_H
