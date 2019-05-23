#include "CSchedule.h"

//----------------------------------------------------------------------------------
// Constructor por defecto
//----------------------------------------------------------------------------------
CSchedule::CSchedule(void)
{
	iIndex = -1;
	iJobs = -1;
	iMachines = -1;
	iRecirc = -1;
	LengthType = (ScheduleLengthType)0;
	iSize = -1;
	SequenceId = nullptr;
}

//----------------------------------------------------------------------------------
// Constructor 
//----------------------------------------------------------------------------------
CSchedule::CSchedule (ScheduleLengthType type, int njobs, int nmachines, int nrecirc)
{
	if (njobs == 0 || nmachines == 0) throw std::exception("[CSchedule::CSchedule]: <njobs, nmachines> parameters have to be different from zero.");

	iIndex		 = -1;
	iJobs			 = njobs;
	iMachines  = nmachines;
	iRecirc		 = nrecirc;
	LengthType = type;
	iSize			 = (type == N_SCHEDULE) ? iJobs : iJobs * iMachines + iRecirc;
	SequenceId = new unsigned[iSize]{0};
}

//----------------------------------------------------------------------------------
// Constructor de copia.
//----------------------------------------------------------------------------------
CSchedule::CSchedule(const CSchedule &obj)
{
	//int jobs, machines, recirc;

	//obj.GetDimension(&jobs, &machines, &recirc);

	iIndex = -1;
	iJobs = obj.iJobs;
	iMachines = obj.iMachines;
	iRecirc = obj.iRecirc;
	LengthType = obj.LengthType;
	//iIndex = -1;
	//iJobs = jobs;
	//iMachines = machines;
	//iRecirc = recirc;
	//LengthType = obj.GetLengthType();
	iSize = (LengthType == N_SCHEDULE) ? iJobs : iJobs * iMachines + iRecirc;

	SequenceId = new unsigned[iSize];
	for (int i = 0; i < iSize; i++) AddToSchedule(obj.GetIdByIndex(i));
}

//----------------------------------------------------------------------------------
// Destructor de clase.
//----------------------------------------------------------------------------------
CSchedule::~CSchedule (void)
{
	delete []SequenceId;	
}

//----------------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------------
void CSchedule::AddToSchedule (unsigned id)
{
	if (iSize == -1) throw std::exception("CSchedule::AddToSchedule(): undefined iSize data member.");

	if (iIndex >= iSize) return;
	
	if (iIndex == -1) iIndex = 0;
	SequenceId[iIndex++] = id;
}

//----------------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------------
void CSchedule::SetIdByIndex(int index, unsigned id)
{
	if (index >= iSize) throw std::exception("CSchedule::SetIdByIndex(): <index> parameter out of range.");

	SequenceId[index] = id;
}

//----------------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------------
void CSchedule::SetDimension(ScheduleLengthType type, int njobs, int nmachines, int nrecirc)
{
	iIndex = -1;
	iJobs = njobs;
	iMachines = nmachines;
	iRecirc = nrecirc;
	LengthType = type;
	iSize = (type == N_SCHEDULE) ? iJobs : iJobs * iMachines + iRecirc;
	if (SequenceId) delete []SequenceId;
	SequenceId = new unsigned[iSize] {0};
}

//----------------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------------
void CSchedule::GetDimension(int *jobs, int *machines, int *recirc)  const
{
	if (jobs)		  *jobs = iJobs;
	if (machines) *machines = iMachines;
	if (recirc)   *recirc = iRecirc;
}

//----------------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------------
unsigned CSchedule::GetIdByIndex (int index) const
{
	if (index >= iSize) throw std::exception("CSchedule::GetIdByIndex(): <index> parameter out of range.");

	return SequenceId[index];
}

//----------------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------------
unsigned CSchedule::GetJobsCount(void) const
{
	return iJobs;
}

//----------------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------------
unsigned CSchedule::GetMachinesCount(void) const
{
	return iMachines;
}

//----------------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------------
ScheduleLengthType CSchedule::GetLengthType(void) const
{
	return LengthType;
}

//----------------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------------
void CSchedule::SwapAtom(unsigned int indexA, unsigned int indexB)
{
	int i, j, tmp;

	// Paso 1. Normalizo los indices de los atomos. Con esto garantizo que siempre 
	//				 esten en el intervalo cerrado [0; iJobs * iMachines + iRecirc].
	i = indexA % (iJobs * iMachines + iRecirc);
	j = indexB % (iJobs * iMachines + iRecirc);

	// Paso 2. Intercambio las posiciones de los atomos.
	tmp = SequenceId[i];
	SequenceId[i] = SequenceId[j];
	SequenceId[j] = tmp;
}

//----------------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------------
void CSchedule::SwapSubsetM(unsigned int subsetA, unsigned int subsetB)
{
	int sA, sB;

	// Paso 1. Normalizo los indices para los subconjuntos de machines.
	subsetA = subsetA % iMachines;
	subsetB = subsetB % iMachines;

	if (subsetA == subsetB) return;

	// Paso 2. Calculo punto de inicio de los subconjuntos.
	sA = subsetA * iJobs;
	sB = subsetB * iJobs;

	// Paso 3. Realizo el intercambio de los atomos que componen subconjunto 
	//				 de machines.
	for (int i = 0; i < iJobs; i++)
	{
		SwapAtom(sA, sB);
		sA++; sB++;
	}
}

//----------------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------------
bool CSchedule::IsComplete(void) const
{
	return iIndex == iJobs;
}

//----------------------------------------------------------------------------------
// 
//----------------------------------------------------------------------------------
void CSchedule::ClearSchedule (void)
{
	iIndex = -1;
	for (unsigned i = 0; i < iSize; i++) SequenceId[i] = 0;
}


//----------------------------------------------------------------------------------
// Sobrecarga del operador Asignacion (=).
//----------------------------------------------------------------------------------
CSchedule &CSchedule::operator = (const CSchedule &obj)
{
	int jobs, machines, recirc;

	obj.GetDimension(&jobs, &machines, &recirc);

	iIndex = -1;
	iJobs = jobs;
	iMachines = machines;
	iRecirc = recirc;
	LengthType = obj.GetLengthType();
	iSize = (LengthType == N_SCHEDULE) ? iJobs : iJobs * iMachines + iRecirc;

	if (SequenceId) delete[]SequenceId;
	SequenceId = new unsigned[iSize];
	for (int i = 0; i < iSize; i++) AddToSchedule(obj.GetIdByIndex(i));

	return (*this);
}

//----------------------------------------------------------------------------------
// Sobrecarga operador Doble Angular izquierdo (<<).
//----------------------------------------------------------------------------------
std::ostream& operator << (std::ostream &stream, const CSchedule &obj)
{
	int jobs, machines, recirc, size;

	obj.GetDimension(&jobs, &machines, &recirc);
	if (jobs == -1 || machines == -1)
	{
		stream << "*-schedule empty-*";
		return stream;
	}

	size = (obj.GetLengthType() == N_SCHEDULE) ? jobs : jobs * machines + recirc;
	for (unsigned i = 0; i < size; i++) stream << obj.GetIdByIndex(i) << "  ";
	
	return stream;
}