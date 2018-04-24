#include <algorithm>
#include <vector>

using namespace std;

struct interval
{
	int start;
	int end;
};

bool compare(struct interval a, struct interval b)
{
	return a.start < b.start;
}

vector<struct interval> mergeInterval(vector<struct interval> intervals)
{
	/* Sort the list by start of the intervals */
	sort (intervals.begin(), intervals.end(), compare);

	/* Compare the intervals and merge */
	vector<struct interval> merged;
	merged.push_back (intervals[0]);
	for (int i = 1; i < intervals.size(); i++)
	{
		if (merged.back().end > intervals[i].start)
		{
			struct interval newInterval = merged.back();
			merged.pop_back();
			newInterval.end = max(newInterval.end, intervals[i].end);
			merged.push_back (newInterval);
		}
		else
			merged.push_back (intervals[i]);
	}

	return merged;
}
