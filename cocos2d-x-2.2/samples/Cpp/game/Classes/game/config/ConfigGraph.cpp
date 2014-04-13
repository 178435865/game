#include "game/config/ConfigGraph.h"

#define CONFIG_GRAPH "graphical.json"

void ConfigGraph::loadConfig()
{
	Value json=UtilJson::getJsonFromFile(CONFIG_GRAPH,GONFIG_PATH);
	Value::Members member=json.getMemberNames();
	for(Value::Members::iterator iter=member.begin();iter!=member.end();++iter)
	{
		string str=*iter;
		int id=atoi(str.c_str());
		Value v=json[str];
		DataGraph* data=new DataGraph();
		data->setData(v);
		m_mDataGraph[id]=data;
	}
}
DataGraph* ConfigGraph::getData(int id)
{
	return m_mDataGraph[id];
}