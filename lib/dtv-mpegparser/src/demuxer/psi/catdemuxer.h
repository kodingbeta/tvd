/*******************************************************************************

  Copyright (C) 2010, 2011 LIFIA - Facultad de Informatica - Univ. Nacional de La Plata

********************************************************************************

  This file is part of DTV-connector implementation.

    DTV-connector is free software: you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by the Free
  Software Foundation, either version 2 of the License.

    DTV-connector is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
  A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License along with
  this program. If not, see <http://www.gnu.org/licenses/>.

********************************************************************************

  Este archivo es parte de la implementación de DTV-connector.

    DTV-connector es Software Libre: Ud. puede redistribuirlo y/o modificarlo
  bajo los términos de la Licencia Pública General Reducida GNU como es publicada por la
  Free Software Foundation, según la versión 2 de la licencia.

    DTV-connector se distribuye esperando que resulte de utilidad, pero SIN NINGUNA
  GARANTÍA; ni siquiera la garantía implícita de COMERCIALIZACIÓN o ADECUACIÓN
  PARA ALGÚN PROPÓSITO PARTICULAR. Para más detalles, revise la Licencia Pública
  General Reducida GNU.

    Ud. debería haber recibido una copia de la Licencia Pública General Reducida GNU
  junto a este programa. Si no, puede verla en <http://www.gnu.org/licenses/>.

*******************************************************************************/
#pragma once

#include "psidemuxer.h"
#include "tableinfo.h"
#include "cat.h"

namespace tuner {

class CATDemuxer : public PSIDemuxer {
public:
	CATDemuxer( WORD pid );
	virtual ~CATDemuxer();

	//	Getters
	virtual ID tableID() const;
	virtual DWORD frequency() const;
	virtual bool supportCache() const;

	//  Signal
	typedef boost::function<void ( const boost::shared_ptr<Cat> &cat )> ParsedCallback;
	void onParsed( const ParsedCallback &callback );

protected:
	virtual TableInfo *getTable( BYTE *section );
	virtual void onVersionChanged();
	virtual void onSection( TableInfo *ver, BYTE *section, size_t len );
	virtual void onComplete( TableInfo *ver, BYTE *section, size_t len );

private:
	TableInfo _info;
	ParsedCallback _onParsed;
	desc::ca::Systems _systems;
};

}
