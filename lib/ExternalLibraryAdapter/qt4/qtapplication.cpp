/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "qtapplication.hpp"

isis::qt4::QtApplication::QtApplication( const char name[] ):
		Application( name )
{}

QApplication& isis::qt4::QtApplication::getQApplication()
{
	LOG_IF( not m_qapp, util::Debug, error ) << "The QApplication was not yet created, you should run init() before using getQApplication.";
	return *m_qapp;
}
bool isis::qt4::QtApplication::init( int argc, char** argv, bool exitOnError )
{
	if ( m_qapp ) {
		LOG( util::Debug, error ) << "The QApplication allready exists. This should not happen. I'll not touch it";
	} else {
		m_argc = argc; // create local copies
		m_argv = argv;
		m_qapp.reset( new QApplication( m_argc, m_argv ) );
	}

	return util::Application::init( argc, argv, exitOnError );
}


