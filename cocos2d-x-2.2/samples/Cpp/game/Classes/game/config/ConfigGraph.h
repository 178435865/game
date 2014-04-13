#ifndef _CONFIG_GRAPH_
#define _CONFIG_CRAPH_
#include "game/data/DataGraph.h"
#include "util/Util.h"
#include "framework/interface/IConfig.h"

class ConfigGraph :public IConfig
{
	public:
		void loadConfig();
		DataGraph* getData(int id);
	private:
		map<int,DataGraph*> m_mDataGraph;
};
#endif

