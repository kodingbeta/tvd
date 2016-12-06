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

#include "timer.h"
#include "system.h"
#include <SDL/SDL.h>

namespace canvas {
namespace sdl {

namespace impl {
	extern System *sys;

static Uint32 sdl_TimerCallback( Uint32 /*interval*/, void* param ) {
	Timer *timer = (Timer *)param;
	if (impl::sys) {
		impl::sys->dispatchTimer( timer );
	}
	return 0;
}

}

Timer::Timer( const canvas::timer::Callback &callback )
	: canvas::Timer( callback ), _timerID(NULL)
{
}

Timer::~Timer()
{
}

bool Timer::attach( util::DWORD ms ) {
	_timerID=SDL_AddTimer( ms, &impl::sdl_TimerCallback, (void *)this );
	return _timerID ? true : false;
}

bool Timer::cancel() {
	SDL_RemoveTimer( _timerID );
	return true;
}

}
}
