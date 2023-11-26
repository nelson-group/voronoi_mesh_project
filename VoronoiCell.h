#include "Point.h"
#include "Halfplane.h"
#include <deque>

#ifndef VoronoiCell_h
#define VoronoiCell_h
//using namespace std;

struct intersection
    {
        Point intersect_pt;
        Halfplane* intersecting_with;
        double dist_to_midpoint; //distance signed relative to half_plane_vec
    };

class VoronoiCell {

public:
    VoronoiCell();
    VoronoiCell(Point* pts, int index, int N_pts);
    ~VoronoiCell();
    int N;
    int index;
    Point seed;
    Point* pts;
    deque<Halfplane> halfplanes;
    deque<Halfplane> edges;
    deque<Point> verticies;
    void intersect_two_halfplanes(Halfplane &hp1, Halfplane &hp2, deque<intersection> &intersections);
    void construct_cell();
    bool check_equidistance_condition(Point* seeds);
    double get_area();
private:
    void generate_halfplane_vector();
    void search_hp_closest_to_seed(Halfplane &first_hp);
    double get_signed_angle(Point u, Point v);


};

#endif