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

#ifndef KIMAGEANNOTATOR_SWITCHER_H
#define KIMAGEANNOTATOR_SWITCHER_H

#include <QStackedWidget>

#include "src/annotations/core/AnnotationArea.h"
#include "src/gui/annotator/AnnotationWidget.h"
#include "src/gui/cropper/CropWidget.h"
#include "src/gui/scaler/ScaleWidget.h"

namespace kImageAnnotator {

class CoreView : public QStackedWidget
{
Q_OBJECT
public:
	explicit CoreView(Config *config);
	~CoreView() override;
	QImage image() const;
	QAction *undoAction();
	QAction *redoAction();
	QSize sizeHint() const;
	void reloadConfig();

signals:
	void imageChanged() const;

public slots:
	void loadImage(const QPixmap &pixmap);
	void insertImageItem(const QPointF &position, const QPixmap &pixmap);
	void showAnnotator();
	void showCropper();
	void showScaler();

private:
	Config *mConfig;
	AnnotationWidget *mAnnotationWidget;
	CropWidget *mCropWidget;
	ScaleWidget *mScaleWidget;
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_SWITCHER_H
