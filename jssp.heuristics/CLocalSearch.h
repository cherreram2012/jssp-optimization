#pragma once
#ifndef CLocalSearch_H
#define CLocalSearch_H

#include <vector>
#include "CNeighborhood.h"
#include "../jssp.model/CSchedule.h"
#include "../jssp.model/CPieceCollection.h"
#include "../jssp.model/CMachineCollection.h"

//enum LocalSearchStrategyEnum { FIRST_IMPROVING, BEST_IMPROVING };

//------------------------------------------------------------------------------
//	ClassName: LocalSearchStrategy
//
//  Description: Abstract base class for Local Search Strategies.
//
//  Revision: 16/05/2019 
//------------------------------------------------------------------------------
class CLocalSearchStrategy
{
	protected:
		CGraphCAPP *Graph;		
		CPieceCollection *CollectionJ;
		CMachineCollection *CollectionM;
		CNeighborhoobStrategy *Neighborhood;

	protected:
		void CheckDataConsistency(void);

	public:
		//--- Constructor and destructor ---//
		CLocalSearchStrategy					( void );
		virtual ~CLocalSearchStrategy ( void );

		//--- Function virtual pure ---//
		virtual CSchedule Execute ( const CSchedule &entry, float *fo = nullptr ) = 0;

		void UserData				  ( CPieceCollection *cJ, CMachineCollection *cM );
		void NeighborStrategy ( CNeighborhoobStrategy *neighbors ); 
};

//------------------------------------------------------------------------------
//	ClassName: CFirstImprovingSearch
//
//  Description: .
//
//  Revision: 16/05/2019 
//------------------------------------------------------------------------------
class CFirstImprovingSearch : public CLocalSearchStrategy {
	public:
		//--- Constructor and destructor ---//
		CFirstImprovingSearch	 ( void );
		~CFirstImprovingSearch ( void );

		virtual CSchedule Execute ( const CSchedule &entry, float *fo = nullptr );
};

//------------------------------------------------------------------------------
//	ClassName: BestImprovingSearch
//
//  Description: .
//
//  Revision: 16/05/2019 
//------------------------------------------------------------------------------
class CBestImprovingSearch : public CLocalSearchStrategy {
	public:
		//--- Constructor and destructor ---//
		CBestImprovingSearch	( void );
		~CBestImprovingSearch ( void );

		virtual CSchedule Execute ( const CSchedule &entry, float *fo = nullptr );
};
#endif