#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <iostream>
#include <fstream>

int world_size = 128;
int nber = 2000;
int nber_voronoi = 50;
int earth = 3;
unsigned int SEED;

void line(std::vector<std::vector<int> > *pworld) {
  int value = rand_r(&SEED) % 2;
  if (value == 0) {
    value = -1;
  }
  int point1[2];
  point1[0] = rand_r(&SEED)%world_size;
  point1[1] = rand_r(&SEED)%world_size;
  int point2[2];
  point2[0] = rand_r(&SEED)%world_size;
  point2[1] = rand_r(&SEED)%world_size;
  int v1[2];
  v1[0] = point1[0] - point2[0];
  v1[1] = point1[1] - point2[1];
  for (int i(0); i < world_size; i++) {
    for (int j(0); j < world_size; j++) {
      int v2[2];
      v2[0] = i - point1[0];
      v2[1] = j - point1[1];
      int test(v1[0]*v2[1] - v1[1]*v2[0]);
      if (test > 0) {
        (*pworld)[i][j] += value;
        if ((*pworld)[i][j] < 0) {
          (*pworld)[i][j] = 0;
        } else if ((*pworld)[i][j] > 10) {
          (*pworld)[i][j] = 10;
        }
      }
    }
  }
}

void circle(std::vector<std::vector<int> > *pworld) {
  int value = rand_r(&SEED) % 2;
  int radius = rand_r(&SEED) % world_size;
  radius = radius*radius/150 + 10;
  if (value == 0) {
    value = -1;
  }
  int point[2];
  point[0] = rand_r(&SEED)%world_size;
  point[1] = rand_r(&SEED)%world_size;
  for (int i(0); i < world_size; i++) {
    for (int j(0); j < world_size; j++) {
      int test = (i - point[0])*(i - point[0]) +
        (j - point[1])*(j - point[1]);
      if (test < radius) {
        (*pworld)[i][j] += value;
        if ((*pworld)[i][j] < 0) {
          (*pworld)[i][j] = 0;
        } else if ((*pworld)[i][j] > 10) {
          (*pworld)[i][j] = 10;
        }
      }
    }
  }
}

void voronoi(std::vector<std::vector<int> > *pworld) {
  std::vector<std::vector<int> > pts;
  std::vector<int> value;
  for (int i(0); i < nber_voronoi; i++) {
    std::vector<int> pt;
    pt.push_back(rand_r(&SEED)%world_size);
    pt.push_back(rand_r(&SEED)%world_size);
    pts.push_back(pt);
    value.push_back(rand_r(&SEED)%10);
  }
  for (int i(0); i < world_size; i++) {
    for (int j(0); j < world_size; j++) {
      float dist = world_size*world_size;
      int index = 0;
      for (int k(0); k < nber_voronoi; k++) {
        float dist_temp = (i-pts[k][0])*(i-pts[k][0]);
        dist_temp += (j-pts[k][1])*(j-pts[k][1]);
        if (dist_temp < dist) {
          index = k;
          dist = dist_temp;
        }
      }
      (*pworld)[i][j] = value[index];
    }
  }
}

void initialize_world(std::vector<std::vector<int> > *pworld) {
  for (int i(0); i < world_size; i++) {
    pworld->push_back(std::vector<int>(0));
    for (int j(0); j < world_size; j++) {
      (*pworld)[i].push_back(0);
    }
  }
  voronoi(pworld);
}

std::vector<std::vector<int> > collaging() {
  std::vector<std::vector<int> > world;
  initialize_world(&world);
  for (int i(0); i < nber; i++) {
    int test = rand_r(&SEED) % 3;
    if (test <= 1) {
      line(&world);
    } else {
      circle(&world);
    }
  }
  return world;
}

void write_world(std::vector<std::vector<int> > const& world) {
  std::ofstream myfile;
  myfile.open("world.txt");
  for (int i(0); i < world_size; i++) {
    for (int j(0); j < world_size; j++) {
      myfile << world[i][j] << ", ";
    }
    myfile << std::endl;
  }
  myfile.close();
}

bool check_world(std::vector<std::vector<int> > const& world) {
  int counter = 0;
  for (int i(0); i < world_size; i++) {
    for (int j(0); j < world_size; j++) {
      if (world[i][j] < earth) {
        counter++;
      }
    }
  }
  float ratio = static_cast<float>(counter) /
    static_cast<float>(world_size*world_size);
  if (ratio < 0.05 + static_cast<float>(earth)/10.0 &&
      static_cast<float>(earth)/10.0 - 0.05 < ratio) {
    return true;
  } else {
    return false;
  }
}

int main() {
  std::vector<std::vector<int> > world;
  /* initialize random seed: */
  SEED = time(NULL);
  bool enough_earth(false);
  while (!enough_earth) {
    world = collaging();
    enough_earth = check_world(world);
  }

  write_world(world);
  return 0;
}
