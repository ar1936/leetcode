class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle=(hour%12)*30;
        double minutes_angle=minutes*6;
        hour_angle+=minutes_angle*30/360;
        double ans= abs(hour_angle-minutes_angle);
        return min(ans,360-ans);
    }
};