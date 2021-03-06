/*
 *    This file is part of ACADO Toolkit.
 *
 *    ACADO Toolkit -- A Toolkit for Automatic Control and Dynamic Optimization.
 *    Copyright (C) 2008-2009 by Boris Houska and Hans Joachim Ferreau, K.U.Leuven.
 *    Developed within the Optimization in Engineering Center (OPTEC) under
 *    supervision of Moritz Diehl. All rights reserved.
 *
 *    ACADO Toolkit is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    ACADO Toolkit is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with ACADO Toolkit; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


/**
 *    \file include/acado/variables_grid/variables_grid.ipp
 *    \author Hans Joachim Ferreau, Boris Houska
 *    \date 10.06.2008
 */


//
// PUBLIC MEMBER FUNCTIONS:
//


BEGIN_NAMESPACE_ACADO


inline double& VariablesGrid::operator()( uint pointIdx, uint rowIdx ){

    return MatrixVariablesGrid::operator()( pointIdx,rowIdx,0 );
}


inline double VariablesGrid::operator()( uint pointIdx, uint rowIdx ) const{

    return MatrixVariablesGrid::operator()( pointIdx,rowIdx,0 );
}



inline VariablesGrid VariablesGrid::operator+(	const VariablesGrid& arg
												) const
{
	VariablesGrid tmp( *this );
	tmp.MatrixVariablesGrid::operator+( arg );
	return tmp;
}


inline VariablesGrid& VariablesGrid::operator+=(	const VariablesGrid& arg
													)
{
	MatrixVariablesGrid::operator+=( arg );
	return *this;
}



inline VariablesGrid VariablesGrid::operator-(	const VariablesGrid& arg
												) const
{
	VariablesGrid tmp( *this );
	tmp.MatrixVariablesGrid::operator-( arg );
	return tmp;
}


inline VariablesGrid& VariablesGrid::operator-=(	const VariablesGrid& arg
													)
{
	MatrixVariablesGrid::operator-=( arg );
	return *this;
}


inline BooleanType VariablesGrid::operator==(	const VariablesGrid& arg
										) const
{
	if( ( Grid::operator==(arg) ) == BT_TRUE)
	{
		bool equal = true;
		VariablesGrid tmp( *this );
		for( uint run1 = 0; run1 < getNumPoints(); run1++ )
		{
			equal = ( equal && (tmp.getMatrix(run1) == arg.getMatrix(run1)) == BT_TRUE) ;

		}

		if(equal)
			 return BT_TRUE;
		else
			 return BT_FALSE;
	}

	return BT_FALSE;
}


CLOSE_NAMESPACE_ACADO


/*
 *	end of file
 */
