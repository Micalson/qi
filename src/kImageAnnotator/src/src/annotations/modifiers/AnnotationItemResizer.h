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

#ifndef KIMAGEANNOTATOR_ANNOTATIONITEMRESIZER_H
#define KIMAGEANNOTATOR_ANNOTATIONITEMRESIZER_H

#include <QGraphicsWidget>

#include "resizeHandles/ResizeHandlesFactory.h"
#include "src/annotations/undo/ResizeCommand.h"

namespace kImageAnnotator {

class AnnotationItemResizer : public QGraphicsWidget
{
Q_OBJECT
public:
	explicit AnnotationItemResizer(AbstractAnnotationItem *item);
    ~AnnotationItemResizer();
    virtual QRectF boundingRect() const override;
    void grabHandle(const QPointF &pos);
    void moveHandle(const QPointF &pos);
    void releaseHandle();
    bool isResizing() const;
    void refresh();
    bool isItemVisible() const;
    Qt::CursorShape cursorForPos(const QPointF &pos);
    Qt::CursorShape cursorForCurrentHandle();

signals:
    void newCommand(ResizeCommand *resize) const;

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

private:
    AbstractItemResizeHandles *mResizeHandles;
    AbstractAnnotationItem *mAnnotationItem;
    int mCurrentHandle;
    QPointF mClickOffset;
};

} // namespace kImageAnnotator

#endif // KIMAGEANNOTATOR_ANNOTATIONITEMRESIZER_H
