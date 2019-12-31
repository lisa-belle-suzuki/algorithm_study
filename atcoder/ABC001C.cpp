# include <iostream>
# include <string>
# include <vector>

using namespace std;

string deg_int_to_dir(int deg_int) {
    if (deg_int >= 112.5 && deg_int < 337.5) {
        return "NNE";
    }else if (deg_int >= 337.5 && deg_int < 562.5) {
        return "NE";
    }else if (deg_int >= 562.5 && deg_int < 787.5) {
        return "ENE";
    }else if (deg_int >= 787.5 && deg_int < 1012.5) {
        return "E";
    }else if (deg_int >= 1012.5 && deg_int < 1237.5) {
        return "ESE";
    }else if (deg_int >= 1237.5 && deg_int < 1462.5) {
        return "SE";
    }else if (deg_int >= 1462.5 && deg_int < 1687.5) {
        return "SSE";
    }else if (deg_int >= 1687.5 && deg_int < 1912.5) {
        return "S";
    }else if (deg_int >= 1912.5 && deg_int < 2137.5) {
        return "SSW";
    }else if (deg_int >= 2137.5 && deg_int < 2362.5) {
        return "SW";
    }else if (deg_int >= 2362.5 && deg_int < 2587.5) {
        return "WSW";
    }else if (deg_int >= 2587.5 && deg_int < 2812.5) {
        return "W";
    }else if (deg_int >= 2812.5 && deg_int < 3037.5) {
        return "WNW";
    }else if (deg_int >= 3037.5 && deg_int < 3262.5) {
        return "NW";
    }else if (deg_int >= 3262.5 && deg_int < 3487.5) {
        return "NNW";
    }else{
        return "N";
    }
}

int dis_to_W(int dis) {
    // cout << "dis = " << dis << endl;
    if (dis >= 0 && dis < 15) {
        return 0;
    }else if (dis < 93) {
        return 1;
    }else if (dis < 201) {
        return 2;
    }else if (dis < 327) {
        return 3;
    }else if (dis < 477) {
        return 4;
    }else if (dis < 645) {
        return 5;
    }else if (dis < 831) {
        return 6;
    }else if (dis < 1029) {
        return 7;
    }else if (dis < 1245) {
        return 8;
    }else if (dis < 1467) {
        return 9;
    }else if (dis < 1707) {
        return 10;
    }else if (dis < 1959) {
        return 11;
    }else{
        return 12;
    }
}

int main(){
    int deg_int, dis;
    cin >> deg_int >> dis;
    if (dis_to_W(dis) == 0) {
        cout << "C 0" << endl;
    } else {
        cout << deg_int_to_dir(deg_int) << " " << dis_to_W(dis) << endl;
    }
    return 0;
}