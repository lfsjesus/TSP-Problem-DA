#include "Utils.h"

#include <cmath>

double toRadians(const double& angle) {
    return angle * M_PI / 180.0;
}

double haversineDistance(Vertex* v1, Vertex* v2) {
    double EARTH_RADIUS = 6371.0;

    double lat1 = v1->getLat();
    double lon1 = v1->getLon();

    double lat2 = v2->getLat();
    double lon2 = v2->getLon();

    double lat1Rad = toRadians(lat1);
    double lon1Rad = toRadians(lon1);
    double lat2Rad = toRadians(lat2);
    double lon2Rad = toRadians(lon2);

    double dlat = lat2Rad - lat1Rad;
    double dlon = lon2Rad - lon1Rad;
    double a = pow(sin(dlat / 2), 2) + cos(lat1Rad) * cos(lat2Rad) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;

    return distance;
}
