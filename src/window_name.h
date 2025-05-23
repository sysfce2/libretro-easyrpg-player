/*
 * This file is part of EasyRPG Player.
 *
 * EasyRPG Player is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Player is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EP_WINDOW_NAME_H
#define EP_WINDOW_NAME_H

// Headers
#include <string>
#include "window_base.h"
#include "string_view.h"

/**
 * Window Name Class.
 */
class Window_Name :	public Window_Base {
public:
	/**
	 * Constructor.
	 */
	Window_Name(int ix, int iy, int iwidth, int iheight);

	/**
	 * Renders the current name on the window.
	 */
	void Refresh();

	void Set(std::string text);
	void Append(std::string_view text);
	void Erase();
	const std::string& Get() const;

	void Update() override;

protected:
	std::string name;
};

inline const std::string& Window_Name::Get() const {
	return name;
}

#endif
