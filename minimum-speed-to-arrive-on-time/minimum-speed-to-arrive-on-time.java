class Solution {
    public int minSpeedOnTime(int[] dist, double hour) {
        int l = 1, r = 10000000, minSpeed = -1;
        while(l <= r){
            int m = (l+r)/2;
            if(timeRequired(dist, m) <= hour){
                minSpeed = m;
                r = m-1;
            }
            else l = m+1;
        }
        return minSpeed;
    }
    double timeRequired(int[] dist, int speed){
        double time = 0.0;
        for(int i=0; i<dist.length; i++){
            double t = (double) dist[i] / (double) speed;
            time += (i == dist.length-1 ? t : Math.ceil(t));
        }
        return time;
    }
}