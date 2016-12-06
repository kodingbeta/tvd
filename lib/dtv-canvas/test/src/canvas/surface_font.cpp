/*******************************************************************************

  Copyright (C) 2010, 2013 LIFIA - Facultad de Informatica - Univ. Nacional de La Plata

********************************************************************************

  This file is part of DTV-canvas implementation.

    DTV-canvas is free software: you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by the Free
  Software Foundation, either version 2 of the License.

    DTV-canvas is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
  A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License along with
  this program. If not, see <http://www.gnu.org/licenses/>.

********************************************************************************

  Este archivo es parte de la implementación de DTV-canvas.

    DTV-canvas es Software Libre: Ud. puede redistribuirlo y/o modificarlo
  bajo los términos de la Licencia Pública General Reducida GNU como es publicada por la
  Free Software Foundation, según la versión 2 de la licencia.

    DTV-canvas se distribuye esperando que resulte de utilidad, pero SIN NINGUNA
  GARANTÍA; ni siquiera la garantía implícita de COMERCIALIZACIÓN o ADECUACIÓN
  PARA ALGÚN PROPÓSITO PARTICULAR. Para más detalles, revise la Licencia Pública
  General Reducida GNU.

    Ud. debería haber recibido una copia de la Licencia Pública General Reducida GNU
  junto a este programa. Si no, puede verla en <http://www.gnu.org/licenses/>.

*******************************************************************************/

#include "surface.h"
#include "../util.h"
#include "../../../src/canvas.h"
#include "../../../src/surface.h"
#include <algorithm>

// Tests getFont with default font
TEST_F( Surface, font_default ){
	canvas::Rect rect(0, 0, 720, 576);
	canvas::Surface* s = getCanvas()->createSurface( rect );

	ASSERT_TRUE( s != NULL );

	canvas::font::family::Type familiesGet = s->getFont().families();
	ASSERT_TRUE( std::find(familiesGet.begin(), familiesGet.end(), "Tiresias") != familiesGet.end() );
	getCanvas()->destroy( s );
}

// Tests getFont after changing the setted font
TEST_F( Surface, font_getFont_after_changing_font ){
	canvas::Rect rect(0, 0, 720, 576);
	canvas::Surface* s = getCanvas()->createSurface( rect );
	canvas::FontInfo f;

	ASSERT_TRUE( s != NULL );

	canvas::font::family::Type families;
	families.push_back("Otra");
	f.families(families);

	canvas::font::family::Type familiesGet1 = s->getFont().families();
	ASSERT_TRUE( std::find(familiesGet1.begin(), familiesGet1.end(), "Tiresias") != familiesGet1.end() );

	s->setFont(f);

	canvas::font::family::Type familiesGet2 = s->getFont().families();
	ASSERT_TRUE( std::find(familiesGet2.begin(), familiesGet2.end(), "Otra") != familiesGet2.end() );

	getCanvas()->destroy( s );
}
