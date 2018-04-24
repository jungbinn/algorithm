/* 간격(interval)으로 이루어진 배열이 주어지면, 겹치는 간격 원소들을
   합친 새로운 배열을 만드시오. 간격은 시작과 끝으로 이루어져 있으며
   시작은 끝보다 작거나 같습니다. */

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
