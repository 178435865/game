#ifndef _GRAPH_
#define  _GRAPH_
#include "util/Util.h"
#include "game/data/DataGraph.h"

class Graph :public CCArmature,public DataGraph
{
public:
	virtual ~Graph();
	CC_SYNTHESIZE_READONLY(int,m_iResId,ResId);		//×ÊÔ´id
	virtual void draw();
	virtual bool init(){initWithResourceID(m_iResId);return true;};
protected:
	Graph(int resId);
	void initWithResourceID(int resId);
};
#endif // !_GRAPH_

