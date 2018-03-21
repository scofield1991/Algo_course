#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  int current_point;


  while(segments.size() > 0)
  {
      vector<Segment>::iterator min_segment = segments.begin();
      int min_segment_end = segments.begin()->end;

      for(vector<Segment>::iterator segment = segments.begin(); segment != segments.end(); segment++)
      {
        if(segment->end < min_segment_end)
        {
          min_segment_end = segment->end;
          min_segment = segment;
        }

      }

      current_point = min_segment_end;
      segments.erase(min_segment);
      
      vector<Segment> remaind_segments;

      for(vector<Segment>::iterator segment = segments.begin(); segment != segments.end(); segment++)
      {
        if((segment->start > min_segment_end))   
          remaind_segments.push_back(*segment);

      }
      points.push_back(current_point);
      segments = remaind_segments;
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
