#ifndef NLSR_LSA_HPP
#define NLSR_LSA_HPP

#include "nlsr_adjacent.hpp"
#include "nlsr_npl.hpp"
#include "nlsr_adl.hpp"

using namespace std;

class Lsa{
public:
	Lsa()
		: origRouter()
		, lsSeqNo()
		, lifeTime()
	{
	}	


	void setLsType(uint8_t lst)
	{
		lsType=lst;
	}

	uint8_t getLsType()
	{
		return lsType;
	}

	void setLsSeqNo(uint32_t lsn)
	{
		lsSeqNo=lsn;
	}

	uint32_t getLsSeqNo()
	{
		return lsSeqNo;
	}

	string& getOrigRouter()
	{
		return origRouter;
	}

	void setOrigRouter(string& org)
	{
		origRouter=org;
	}

	uint32_t getLifeTime()
	{
		return lifeTime;
	}

	void setLifeTime(uint32_t lt)
	{
		lifeTime=lt;
	}
	string getLsaKey();
protected:
	string origRouter;
	uint8_t lsType;
	uint32_t lsSeqNo;
	uint32_t lifeTime;
};

class NameLsa:Lsa{
public:
	NameLsa()
		: Lsa()
		, npl()
	{
		setLsType(1);
	}


	Npl& getNpl(){
		return npl;
	}

	void addNameToLsa(string& name)
	{
		npl.insertIntoNpl(name);
	}

	string getNameLsaData();
	
private:
	Npl npl;
	
};

class AdjLsa:Lsa{
public:
	AdjLsa()
		: Lsa()
		, adl()
	{
	}

private:
	uint32_t noLink;
	Adl adl;
};

class CorLsa:Lsa{
public:
	CorLsa()
		:Lsa()
	{
	}
private:
	double corRad;
	double corTheta;

};




#endif
