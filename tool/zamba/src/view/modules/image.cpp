/*******************************************************************************

  Copyright (C) 2010, 2013 LIFIA - Facultad de Informatica - Univ. Nacional de La Plata

********************************************************************************

  This file is part of DTV-luaz implementation.

    DTV-luaz is free software: you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by the Free
  Software Foundation, either version 2 of the License.

    DTV-luaz is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
  A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License along with
  this program. If not, see <http://www.gnu.org/licenses/>.

********************************************************************************

  Este archivo es parte de la implementación de DTV-luaz.

    DTV-luaz es Software Libre: Ud. puede redistribuirlo y/o modificarlo
  bajo los términos de la Licencia Pública General Reducida GNU como es publicada por la
  Free Software Foundation, según la versión 2 de la licencia.

    DTV-luaz se distribuye esperando que resulte de utilidad, pero SIN NINGUNA
  GARANTÍA; ni siquiera la garantía implícita de COMERCIALIZACIÓN o ADECUACIÓN
  PARA ALGÚN PROPÓSITO PARTICULAR. Para más detalles, revise la Licencia Pública
  General Reducida GNU.

    Ud. debería haber recibido una copia de la Licencia Pública General Reducida GNU
  junto a este programa. Si no, puede verla en <http://www.gnu.org/licenses/>.

*******************************************************************************/

/*
 * image.cpp
 *
 *  Created on: Jun 17, 2011
 *      Author: gonzalo
 */

#include "luawgt.h"

#include "wgt.h"
#include "../widget/image.h"

#include <boost/make_shared.hpp>

namespace wgt {

namespace image {

std::map<WidgetId, ImagePtr> _widgets;

int create(lua_State* L)
{
	int narg = 2;
	const int x = luaL_checkint(L, narg++);
	const int y = luaL_checkint(L, narg++);
	const int w = luaL_checkint(L, narg++);
	const int h = luaL_checkint(L, narg++);
	unsigned short zIndex = (unsigned short)luaL_checkint(L, narg++);
	const colorMap_t colorMap = parseColorTable( L, narg++ );
	const char* path = luaL_checkstring(L, narg++);

	ImagePtr ww = boost::make_shared<Image>(x, y, w, h, colorMap, path);
	ww->zIndex(zIndex);
	WidgetId id = Wgt::view()->addWidget(ww);
	_widgets[id] = ww;

	lua_pushnumber(L, id);
	return 1;
}

int setImage(lua_State* L){
	int narg = 2;
	const WidgetId id      = luaL_checkint(L, narg++);
	const std::string path = luaL_checkstring(L, narg++);

	ImagePtr widget = _widgets[id];
	widget->path(path);

	return 0;
}

void init(lua_State *L){
	const struct luaL_Reg methods[] = {
			{"new",       create},
			{"setImage",  setImage},
			{NULL,  NULL}
	};

	luaL_register(L, "image", methods);
}

} // image

} // wgt
