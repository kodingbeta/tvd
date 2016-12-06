/*******************************************************************************

  Copyright (c) 2010, 2013 LIFIA - Facultad de Informatica - Univ. Nacional de La Plata
  All rights reserved.

********************************************************************************

  Redistribution and use in source and binary forms, with or without 
  modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the author nor the names of its contributors may
      be used to endorse or promote products derived from this software
      without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

********************************************************************************

  La redistribución y el uso en las formas de código fuente y binario, con o sin
  modificaciones, están permitidos siempre que se cumplan las siguientes condiciones:
    * Las redistribuciones del código fuente deben conservar el aviso de copyright
      anterior, esta lista de condiciones y el siguiente descargo de responsabilidad.
    * Las redistribuciones en formato binario deben reproducir el aviso de copyright
      anterior, esta lista de condiciones y el siguiente descargo de responsabilidad
      en la documentación y/u otros materiales suministrados con la distribución.
    * Ni el nombre de los titulares de derechos de autor ni los nombres de sus
      colaboradores pueden usarse para apoyar o promocionar productos derivados de
      este software sin permiso previo y por escrito.

  ESTE SOFTWARE SE SUMINISTRA POR LIFIA "COMO ESTÁ" Y CUALQUIER GARANTÍA EXPRESA
  O IMPLÍCITA, INCLUYENDO, PERO NO LIMITADO A, LAS GARANTÍAS IMPLÍCITAS DE
  COMERCIALIZACIÓN Y APTITUD PARA UN PROPÓSITO DETERMINADO SON RECHAZADAS. EN
  NINGÚN CASO LIFIA SERÁ RESPONSABLE POR NINGÚN DAÑO DIRECTO, INDIRECTO, INCIDENTAL,
  ESPECIAL, EJEMPLAR O CONSECUENTE (INCLUYENDO, PERO NO LIMITADO A, LA ADQUISICIÓN
  DE BIENES O SERVICIOS; LA PÉRDIDA DE USO, DE DATOS O DE BENEFICIOS; O INTERRUPCIÓN
  DE LA ACTIVIDAD EMPRESARIAL) O POR CUALQUIER TEORÍA DE RESPONSABILIDAD, YA SEA
  POR CONTRATO, RESPONSABILIDAD ESTRICTA O AGRAVIO (INCLUYENDO NEGLIGENCIA O
  CUALQUIER OTRA CAUSA) QUE SURJA DE CUALQUIER MANERA DEL USO DE ESTE SOFTWARE,
  INCLUSO SI SE HA ADVERTIDO DE LA POSIBILIDAD DE TALES DAÑOS.

*******************************************************************************/

#include <util/string.h>
#include <string>
#include <cstdio>

namespace testlog {

	enum colors { red, green, yellow, cyan, gray };

	namespace impl {
		std::string colorCode( colors color ) {
			std::string tmp;
			switch (color) {
				case red: tmp = "31m"; break;
				case green: tmp = "32m"; break;
				case yellow: tmp = "33m"; break;
				case cyan: tmp = "36m"; break;
				case gray: tmp = "37m"; break;
			}
			return tmp;
		}

		static void print( const std::string &str, bool highlight, colors color, FILE *file ) {
			std::string tmp("\x1b[");
			tmp += highlight ? '1' : '0';
			tmp += ';';
			tmp += colorCode( color );

			if (file) {
				fprintf( file, "%s", str.c_str() );
			} else {
				printf("%s%s\x1b[0m", tmp.c_str(), str.c_str());
			}
		}
	}

	void printRed( const std::string &str, FILE *file/*=NULL*/, bool highlight/*=false*/ ) {
		impl::print( str, highlight, red, file);
	}

	void printGreen( const std::string &str, FILE *file/*=NULL*/, bool highlight/*=false*/ ) {
		impl::print( str, highlight, green, file);
	}

	void printYellow( const std::string &str, FILE *file/*=NULL*/, bool highlight/*=false*/ ) {
		impl::print( str, highlight, yellow, file);
	}

	void printCyan( const std::string &str, FILE *file/*=NULL*/, bool highlight/*=false*/ ) {
		impl::print( str, highlight, cyan, file);
	}

	void printGray( const std::string &str, FILE *file/*=NULL*/, bool highlight/*=false*/ ) {
		impl::print( str, highlight, gray, file);
	}

	void printHighlightedGray( const char *format, ... ) {
		va_list args;
		va_start(args, format);
		std::string str = util::format_va( format, args );
		printGray( str, NULL, true);
	}

	void printStepName( const std::string &testName, const std::string &stepName ) {
		printf(" %s.%s\n", testName.c_str(), stepName.c_str());
	}
}