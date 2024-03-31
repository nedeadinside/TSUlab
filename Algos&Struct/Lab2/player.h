#ifndef player_h
#define player_h
#endif /* player_h */

#include<fstream>
#include <iostream>
#include <string>

using namespace std;

class player {
public:
    int p_points, p_tasks, p_time, p_unluck, p_id;

    player(int i1, int i2, int i3, int i4, int i5) {
        p_points = i1;
        p_tasks = i2;
        p_time = i3;
        p_unluck = i4;
        p_id = i5;
    }

    bool operator > (player PL) {
        if (p_points != PL.p_points) {
            return p_points > PL.p_points;
        }
        else if (p_tasks != PL.p_tasks) {
            return p_tasks > PL.p_tasks;
        }
        else if (p_time != PL.p_time) {
            return p_time < PL.p_time;
        }
        else if (p_unluck != PL.p_unluck) {
            return p_unluck < PL.p_unluck;
        }
        else { 
            return p_id > PL.p_id;
        }
    }
    
    friend ostream& operator<<(ostream& out, player p1) {
        return out << "points: " << p1.p_points << " tasks: " << p1.p_tasks << " time: " << p1.p_time << " unlucks: " << p1.p_unluck << " id: " << p1.p_id;
    }
    ~player() {}
};