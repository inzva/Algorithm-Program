
#include <cmath>
#include <iostream>

double p1[3], p2[3], a1[3], a2[3];
int R1, R2;


double f(double t){
    double dist = 0;
    
    for (int i=0; i < 3; i++){
        double x1 = p1[i] + 0.5 * a1[i] * t * t;
        double x2 = p2[i] + 0.5 * a2[i] * t * t;
        
        dist += (x1 - x2) * (x1 - x2);
    }
    
    return sqrt(dist);
    
}

double ternary_search(double left=0, double right=1e5, double eps=1e-9){
    while (right - left > eps){
        double mid1 = left + (right - left) / 3.;
        double mid2 = right - (right - left) / 3.;
        
        if (f(mid1) > f(mid2))
            left = mid1;
        else
            right = mid2;
    }
    return f(left);
}


int main(){
    int T;
    scanf("%d", &T);
    
    while(T--){
        scanf("%d%d", &R1, &R2);
        scanf("%lf%lf%lf", p1, p1+1, p1+2);
        scanf("%lf%lf%lf", a1, a1+1, a1+2);
        scanf("%lf%lf%lf", p2, p2+1, p2+2);
        scanf("%lf%lf%lf", a2, a2+1, a2+2);

        double closest = ternary_search();
        
        if (closest <= R1 + R2)
            printf("YES\n");
        else
            printf("NO\n");
    }
}

