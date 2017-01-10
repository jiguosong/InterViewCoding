#ifndef distributemachinetoclusters_H_
#define distributemachinetoclusters_H_

#include <vector>
#include <string>
using std::vector;
using std::string;

class distributemachinetoclusters {
public:
	void dummy();
	std::vector<std::pair<int, int>> DistributeBMachinetoNCluster(int B, int N, vector<int> &workload);
private:

};

#endif
