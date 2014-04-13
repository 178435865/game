#include "Graph.h"

Graph::~Graph()
{

}
Graph::Graph(int resId)
{
	m_iResId=resId;
	
}

void Graph::initWithResourceID(int resId)
{
	loadData(resId);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(m_sPlistPath.c_str());
	 CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo(m_sArmaturePath.c_str());
	CCArmature::init(getAnimationName().c_str());
	getAnimation()->playByIndex(1);
	setScale(m_iScale);
	getAnimation()->setSpeedScale(m_iSpeed);
}

void Graph::draw()
{
	CCArmature::draw();

	ccDrawColor4B(0,0,255,255);
	ccDrawRect(m_rAttackRect.origin,m_rAttackRect.size);

	ccDrawRect(m_rBeAttackRect.origin,m_rBeAttackRect.size);
}
