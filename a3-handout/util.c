#include "util.h"
#include "sort.h"
#include <math.h>
#include <stdio.h>
#include <assert.h>

// Compute the Euclidean distance between two d-dimensional points 'x'
// and 'y'.  Usual formula:
//
//
// √( ∑ (x[i]-y[i])² )
//
double distance(int d, const double *x, const double *y) {
    double sum = 0.0;
    for (int i = 0; i < d; ++i) {
        sum += pow(x[i] - y[i], 2);
    }
    return sqrt(sum);
}


struct sort_env {
  int d;
  double *points;
  double *query
};


int cmp_distances(const int *ip, const int *jp, struct sort_env* env) {

  int i = *ip;
  int j = *jp;
  double *x = &env->points[i];
  double *y = &env->points[j];
  double *q = &env->query[0];
  int d = env->d;

  double distance_between_i_q = distance(d, x, q);
  double distance_between_j_q = distance(d, y, q);
  if (distance_between_i_q < distance_between_j_q) {
    return -1;
  } else if (distance_between_i_q == distance_between_j_q) {
    return 0;
  } else {
    return 1;
  }
}

int insert_if_closer(int k, int d,
                     const double *points, int *closest, const double *query,
                     int candidate) { 

    struct sort_env env;
    env.d = d;
    env.points = points;
    env.query = query;
    
    hpps_quicksort(closest, k, sizeof(int),
                    (int (*)(const void*, const void*, void*))cmp_distances,
                    &env);
  

      const double *candiate = &points[candidate];
      const double *worst_closest = &points[closest[k-1]];
      const double *q = &query[0];

  if (distance(d, worst_closest,q) > distance(d, candiate,q)) {
    closest[k-1] = candidate;

    hpps_quicksort(closest, k, sizeof(int),
                    (int (*)(const void*, const void*, void*))cmp_distances,
                    &env);

    return 1;
  } else {
      return 0;

  }


 

}

/* int main() {
    const int d = 3; // Dimension of the points
    const int n = 5;
    const int k = 4; // Number of points
    double points[n * d] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 1.0, 2.0, 3.0};
    double query[d] = {1.0, 2.0, 3.0};
    int closest[k] = {3, 1, 2, 5};

    int updated = insert_if_closer(k, d, points, closest, query, 0);

    // Print the updated closest array
    for (int i = 0; i < k; ++i) {
        printf("%d ", closest[i]);
    }
    printf("\n");
    printf("%i, ", updated);

    return 0;
} 
 */


/*
// Calculates the Euclidean distance between two points in d-dimensional space.
// Parameters:
// - d: The number of dimensions.
// - x: Pointer to the first point.
// - y: Pointer to the second point.
// Returns: The Euclidean distance between the two points.
double distance(int d, const double *x, const double *y) {
  assert(0);  
  double dist = 0.0;
  for (int i = 0; i < d; ++i) {
      double diff = x[i] - y[i];
      dist += diff * diff;
  }
  return sqrt(dist);
}

// Inserts a candidate point into the closest array if it is closer to the query point than any existing points.
// Parameters:
// - k: The number of closest points to keep track of.
// - d: The number of dimensions.
// - points: Pointer to the array of points.
// - closest: Pointer to the array of closest points.
// - query: Pointer to the query point.
// - candidate: The index of the candidate point.
// Returns: 1 if the closest array was updated, 0 otherwise.
int insert_if_closer(int k, int d,
                     const double *points, int *closest, const double *query,
                     int candidate) {
  assert(0);
  double candidate_dist = distance(d, &points[candidate * d], query);
  int updated = 0;

  for (int i = 0; i < k; ++i) {
    if (closest[i] == -1) {
        closest[i] = candidate;
        updated = 1;
        break;
    }

    double current_dist = distance(d, &points[closest[i] * d], query);
    if (candidate_dist < current_dist) {
        for (int j = k - 1; j > i; --j) {
            closest[j] = closest[j - 1];
        }
        closest[i] = candidate;
        updated = 1;
        break;
    }
  }

  return updated;
}
*/
