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

#ifndef KIMAGEANNOTATOR_NUMBERMANAGER_H
#define KIMAGEANNOTATOR_NUMBERMANAGER_H

#include <QObject>

#include "src/annotations/items/AnnotationNumber.h"
#include "src/annotations/core/AbstractBadgeNumberChangeListener.h"

namespace kImageAnnotator {

class NumberManager : public QObject, public AbstractBadgeNumberChangeListener
{
Q_OBJECT
public:
	explicit NumberManager();
	~NumberManager() override = default;
	void addItem(AnnotationNumber *item);
	void reset();
	void firstBadgeNumberChanged(int number) override;

public slots:
	void updateNumbers();

private:
	int mFirstNumber;
	QVector<AnnotationNumber *> mItems;
};

} // namepsace kImageAnnotator

#endif //KIMAGEANNOTATOR_NUMBERMANAGER_H
