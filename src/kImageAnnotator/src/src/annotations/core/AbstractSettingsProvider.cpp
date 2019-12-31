/*
 * Copyright (C) 2019 Damir Porobic <damir.porobic@gmx.com>
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

#include "AbstractSettingsProvider.h"

namespace kImageAnnotator {

void AbstractSettingsProvider::subscribeToToolChange(AbstractToolChangeListener *listener)
{
	mToolChangeListeners.append(listener);
}

void AbstractSettingsProvider::subscribeToItemSettingsChange(AbstractItemSettingsChangeListener *listener)
{
	mItemSettingsChangeListeners.append(listener);
}

void AbstractSettingsProvider::subscribeToBadgeNumberChange(AbstractBadgeNumberChangeListener *listener)
{
	mBadgeNumberChangeListeners.append(listener);
}

void AbstractSettingsProvider::toolChanged(ToolTypes toolType)
{
	for(auto listener : mToolChangeListeners) {
		listener->toolChanged(toolType);
	}
}

void AbstractSettingsProvider::firstBadgeNumberChanged(int number)
{
	for(auto listener : mBadgeNumberChangeListeners) {
		listener->firstBadgeNumberChanged(number);
	}
}

void AbstractSettingsProvider::itemSettingChanged()
{
	for(auto listener : mItemSettingsChangeListeners) {
		listener->itemSettingsChanged();
	}
}

} // namespace kImageAnnotator
