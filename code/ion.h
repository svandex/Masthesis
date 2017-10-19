#include<iostream>
#include<nilibddc.h>
#include<vector>

struct tdmsAttr{
	unsigned int numberOfProperties;
	char **propertyNames;//Property Names in TDMS file 
	std::vector<DDCDataType> propertyDataType;
};

//Initial Processing of TDMS file and PE file, PE for photoelectric encoder.
class ion{
public:
	ion(const char* p, const char* t);
	ion(const ion&i)=delete;
	~ion();
protected:
	DDCFileHandle file;
	unsigned int numOfCycle;
	tdmsAttr ta;
private:
	const char* pepath;
	const char* tdmspath;
	int ddcError;
};

std::ostream& operator<< (std::ostream& os, const ion& i);//Output all properties in format

struct ionAttr{
	
};

//IO reading from TDMS file and writing cycle data to a file
class ioncyc:public ion{
public:
	ioncyc(const ion& i,unsigned int n);
	ioncyc(const ioncyc& i)=delete;
	void writeTo(const char* w);//save data of single cycle for plotting
private:
	unsigned int numCycle;
};
