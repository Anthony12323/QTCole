#include <string>
#include <vector>
#include <chrono>

inline long long systemTimeNanoseconds()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(
	  std::chrono::time_point_cast<std::chrono::milliseconds>(
	    std::chrono::system_clock::now()
	  ).time_since_epoch()    
	).count();
}

inline std::vector<std::string>& getStringData()
{
    static std::vector<std::string> stringDataSet;

    if (stringDataSet.size() == 0)
    {
        char tempSet[6] = "     ";
		
        for (tempSet[0] = 'a'; tempSet[0] <= 'z'; tempSet[0]++)
            for (tempSet[1] = 'a'; tempSet[1] <= 'z'; tempSet[1]++)
                for (tempSet[2] = 'a'; tempSet[2] <= 'z'; tempSet[2]++)
                    for (tempSet[3] = 'a'; tempSet[3] <= 'z'; tempSet[3]++)
                        for (tempSet[4] = 'a'; tempSet[4] <= 'z'; tempSet[4]++)
                            stringDataSet.push_back(std::string(tempSet));
    }
	
    return stringDataSet;
}
