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

#ifndef MASKEDLABEL_H
#define MASKEDLABEL_H

#pragma once

#include "label.h"

namespace wgt {

class MaskedLabel : public Label
{
	public:
 		MaskedLabel(int x, int y, int w, int h, const colorMap_t &colorMap, std::string text, int fontSize, int alignment, int margin = 0);
 		virtual ~MaskedLabel();
		void draw(View* view);
		bool onDigitPressed(int key);
		void reset();
		std::string rawText();
	private:
		int _keysCount;
		virtual const std::string& maskedText();

};

DEF_SHARED(MaskedLabel);

}

#endif // MASKEDLABEL_H
