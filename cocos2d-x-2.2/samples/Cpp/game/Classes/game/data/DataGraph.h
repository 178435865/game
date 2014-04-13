#ifndef _DATA_GRAPH_
#define _DATA_GRAPH_
#include "util/Util.h"
#include "IData.h"

class DataGraph : public IData
{
public:
		CC_SYNTHESIZE_READONLY(string,m_sArmaturePath,ArmaturePath);	//骨骼动画路径
		CC_SYNTHESIZE_READONLY(string,m_sPlistPath,PlistPath);	//资源plist
		CC_SYNTHESIZE_READONLY(string,m_sAnimationName,AnimationName);	//动画名字
		CC_SYNTHESIZE_READONLY(float,m_iSpeed,Speed);		//速度
		CC_SYNTHESIZE_READONLY(float,m_iScale,Scale);		
		CC_SYNTHESIZE_READONLY(int,m_iResId,ResId);
		CC_SYNTHESIZE_READONLY(int,m_iDefaultIndex,DefaultIndex);
		CC_SYNTHESIZE_READONLY(CCRect,m_rAttackRect,AttackRect);
		CC_SYNTHESIZE_READONLY(CCRect,m_rBeAttackRect,BeAttackRect);
		void loadData(int id);
		void setData(const Value& json);
};

#endif
