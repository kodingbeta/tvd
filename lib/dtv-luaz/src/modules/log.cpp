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

#include "middleware.h"
#include "../lua.h"
#include <util/log.h>

namespace luaz {
namespace log {

static int l_log( lua_State *L ) {
	const char *level = luaL_checkstring(L, 1);
	const char *group = luaL_checkstring(L, 2);
	const char *cat = luaL_checkstring(L, 3);
	const char *str = luaL_checkstring(L, 4);
	LOG_LEVEL_TYPE iLevel = util::log::getLevelValue(level);
	if (util::log::canLog( iLevel, group, cat )) {
		util::log::log( iLevel, group, cat, "%s", str );
	}
	return 0;
}

static int l_setLevel( lua_State *L ) {
	const char *group = luaL_checkstring(L, 1);
	const char *cat = luaL_checkstring(L, 2);
	const char *level = luaL_checkstring(L, 3);
	util::log::setLevel( group, cat, level );
	return 0;
}

static const struct luaL_Reg log_methods[] = {
	{ "log",      l_log      },
	{ "setLevel", l_setLevel },
	{ NULL,       NULL       }
};

//	Public methods
void initialize( zapper::Zapper * /*mgr*/ ) {}
void finalize() {}

void start( lua_State *st ) {
	luaL_register( st, "dtvlog", log_methods );
}

void stop() {}

}
}
