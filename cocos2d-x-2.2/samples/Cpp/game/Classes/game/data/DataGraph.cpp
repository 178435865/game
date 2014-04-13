#include "DataGraph.h"
#include "framework/manager/MgrConfig.h"

void DataGraph::loadData(int id)
{
	ConfigGraph* cg=GET_CONFIG(ConfigGraph);
	DataGraph* data=cg->getData(id);
	this->m_iResId=data->m_iResId;
	this->m_iScale=data->m_iScale;
	this->m_iSpeed=data->m_iSpeed;
	this->m_rAttackRect=data->m_rAttackRect;
	this->m_rBeAttackRect=data->m_rBeAttackRect;
	this->m_sArmaturePath=data->m_sArmaturePath;
	this->m_sPlistPath=data->m_sPlistPath;
	this->m_sAnimationName=data->m_sAnimationName;
}
void DataGraph::setData(const Value& json)
{
	m_iResId=json["resId"].asInt();
	m_iScale=json["scale"].asDouble();
	m_iSpeed=json["speed"].asDouble();
	m_sArmaturePath=json["armaturePath"].asString();
	m_sPlistPath=json["plistPath"].asString();
	m_iDefaultIndex=json["defaultIndex"].asInt();
	m_sAnimationName=json["name"].asString();
	string strAttRect=json["atkRect"].asString();
	string strBeAttRect=json["beAtkRect"].asString();
	vector<string> attRectVec=StringHelper::split(strAttRect,",");
	vector<string> beAttRectVec=StringHelper::split(strBeAttRect,",");
	if(attRectVec.size()==4)
	{
		m_rAttackRect=CCRectMake(atoi(attRectVec[0].c_str()),atoi(attRectVec[1].c_str()),atoi(attRectVec[2].c_str()),atoi(attRectVec[3].c_str()));
	}
	else
	{
		m_rAttackRect=CCRectMake(0,0,0,0);
	}
	if(beAttRectVec.size()==4)
	{
		m_rBeAttackRect=CCRectMake(atoi(beAttRectVec[0].c_str()),atoi(beAttRectVec[1].c_str()),atoi(beAttRectVec[2].c_str()),atoi(beAttRectVec[3].c_str()));
	}
	else
	{
		m_rBeAttackRect=CCRectMake(0,0,0,0);
	}
}