#include <bits/stdc++.h>

using namespace std;

struct mirror{
    int x;
    int y;
    string slope;
};

struct vect{
    int xdiff;
    int ydiff;
};

struct point{
    int posx;
    int posy;
};

mirror find_mirror(mirror edges[], vect curr_vect, point currpos, int edges_len){
    unsigned int min_distance = 0xFFFFFFFF;
    int min_index=-1;
    for (int i = 0; i < edges_len; i++){
        int x_diff = edges[i].x - currpos.posx;
        int y_diff = edges[i].y - currpos.posy;
        if (curr_vect.xdiff != 0 && y_diff == 0){
            int mult = x_diff/curr_vect.xdiff;
            if (mult < min_distance && mult > 0){
                min_distance = mult;
                min_index = i;
            }
        }
        else if(curr_vect.ydiff != 0 && x_diff == 0){
            int mult = y_diff/curr_vect.ydiff;
            if (mult < min_distance && mult > 0){
                min_distance = mult;
                min_index = i;
            }
        }
    }
    if (min_index == -1){
        return {0, 0, "none"};
    }
    return edges[min_index];
}

vect find_next_direct(mirror curr, vect prev_vect){
    if (prev_vect.xdiff > 0 && curr.slope == "left"){
        return {0, -1};
    }
    else if (prev_vect.xdiff > 0 && curr.slope == "right"){
        return {0, 1};
    }
    else if (prev_vect.xdiff < 0 && curr.slope == "left"){
        return {0, 1};
    }
    else if (prev_vect.xdiff < 0 && curr.slope == "right"){
        return {0, -1};
    }
    else if (prev_vect.ydiff > 0 && curr.slope == "left"){
        return {-1, 0};
    }
    else if (prev_vect.ydiff > 0 && curr.slope == "right"){
        return {1, 0};
    }
    else if (prev_vect.ydiff < 0 && curr.slope == "left"){
        return {1, 0};
    }
    else if (prev_vect.ydiff < 0 && curr.slope == "right"){
        return {-1, 0};
    }
    else{
        return {0, 0};
    }
}

int main(){

    mirror edges[] = {
        {2, 0, "left"},
        {2, -1, "left"},
        {10, -1, "right"},
        {10, 5, "left"},
        {5, 5, "left"},
        {5, 10, "left"},
        {2, 10, "right"},
        {2, 5, "left"},
        {-10, -10, "right"}
    };

    int edges_len = sizeof(edges)/sizeof(edges[0]);
    vect start_vect = {1, 0};
    point start_pos = {0, 0};

    bool done = false;
    int count = 0;

    while(!done){
        mirror next_mirror = find_mirror(edges, start_vect, start_pos, edges_len);
        vect direction = find_next_direct(next_mirror, start_vect);
        if (next_mirror.slope == "none"){
            done = true;
        }
        else{
            count++;
        }
        start_vect = direction;
        start_pos = {next_mirror.x, next_mirror.y};

        cout << "next mirror: " << "(" << next_mirror.x << ", " << next_mirror.y << ")" << endl;
        cout << "start pos: " << "(" << start_pos.posx << ", " << start_pos.posy << ")" << endl;
        cout << "direction: " << "(" << direction.xdiff << ", " << direction.ydiff << ")" << endl;
    }

    cout << count << endl;

}



