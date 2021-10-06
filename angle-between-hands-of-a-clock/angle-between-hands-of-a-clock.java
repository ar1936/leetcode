class Solution {
    public double angleClock(int hour, int minutes) {
        double hours_angle=(hour%12)*30;
        double minutes_angle=minutes*6;
        hours_angle+=(double)minutes*30/60;
        double ans=Math.abs(hours_angle-minutes_angle);
        return Math.min(ans,360-ans);
    }
}