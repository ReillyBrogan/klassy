#ifndef breezespinboxengine_h
#define breezespinboxengine_h

/*************************************************************************
 * Copyright (C) 2014 by Hugo Pereira Da Costa <hugo.pereira@free.fr>    *
 *                                                                       *
 * This program is free software; you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation; either version 2 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program; if not, write to the                         *
 * Free Software Foundation, Inc.,                                       *
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 *************************************************************************/

#include "breezebaseengine.h"
#include "breezedatamap.h"
#include "breezespinboxdata.h"

namespace Breeze
{

    //* handle spinbox arrows hover effect
    class SpinBoxEngine: public BaseEngine
    {

        Q_OBJECT

        public:

        //* constructor
        explicit SpinBoxEngine( QObject* parent ):
            BaseEngine( parent )
        {}

        //* destructor
        virtual ~SpinBoxEngine()
        {}

        //* register widget
        virtual bool registerWidget( QWidget* );

        //* state
        virtual bool updateState( const QObject* object, QStyle::SubControl subControl, bool value )
        {
            if( DataMap<SpinBoxData>::Value data = _data.find( object ) )
            {
                return data.data()->updateState( subControl, value );
            } else return false;
        }

        //* true if widget is animated
        virtual bool isAnimated( const QObject* object, QStyle::SubControl subControl )
        {
            if( DataMap<SpinBoxData>::Value data = _data.find( object ) )
            {
                return data.data()->isAnimated( subControl );
            } else return false;

        }

        //* animation opacity
        virtual qreal opacity( const QObject* object, QStyle::SubControl subControl )
        {
            if( DataMap<SpinBoxData>::Value data = _data.find( object ) )
            {
                return data.data()->opacity( subControl );
            } else return AnimationData::OpacityInvalid;
        }

        //* enability
        virtual void setEnabled( bool value )
        {
            BaseEngine::setEnabled( value );
            _data.setEnabled( value );
        }

        //* duration
        virtual void setDuration( int value )
        {
            BaseEngine::setDuration( value );
            _data.setDuration( value );
        }


        public Q_SLOTS:

        //* remove widget from map
        virtual bool unregisterWidget( QObject* object )
        { return _data.unregisterWidget( object ); }

        private:

        //* data map
        DataMap<SpinBoxData> _data;

    };

}

#endif
