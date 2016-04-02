#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <fstream>
using namespace std;
int world_size = 128;
int nber = 2000;
int nber_voronoi = 50;
int earth = 3;

void line(vector<vector<int> >& world) {
  int value = rand() % 2;
  if (value == 0) {
    value = -1;
  }
  int point1[2];
  point1[0] = rand()%world_size;
  point1[1] = rand()%world_size;
  int point2[2];
  point2[0] = rand()%world_size;
  point2[1] = rand()%world_size;
  int v1[2];
  v1[0] = point1[0] - point2[0];
  v1[1] = point1[1] - point2[1];
  for(int i(0); i<world_size; i++){
    for(int j(0); j<world_size; j++){
      int v2[2];
      v2[0] = i - point1[0];
      v2[1] = j - point1[1];
      int test(v1[0]*v2[1] - v1[1]*v2[0]);
      if (test > 0) {
	world[i][j] += value;
	if (world[i][j] < 0) {
	  world[i][j] = 0;
	}
	else if (world[i][j] > 10) {
	  world[i][j] = 10;
	}
      }
    }
  }  
}

void circle(vector<vector<int> >& world) {
  int value = rand() % 2;
  int radius = rand() % world_size;
  radius = radius*radius/150 + 10;
  if (value == 0) {
    value = -1;
  }
  int point[2];
  point[0] = rand()%world_size;
  point[1] = rand()%world_size;
  for(int i(0); i<world_size; i++){
    for(int j(0); j<world_size; j++){
      int test = (i - point[0])*(i - point[0]) + (j - point[1])*(j - point[1]);
      if (test < radius) {
	world[i][j] += value;
	if (world[i][j] < 0) {
	  world[i][j] = 0;
	}
	else if (world[i][j] > 10) {
	  world[i][j] = 10;
	}
      }
    }
  }    
}

void voronoi(vector<vector<int> >& world) {
  vector<vector<int> > pts;
  vector<int> value;
  for(int i(0); i<nber_voronoi; i++) {
    vector<int> pt;
    pt.push_back(rand()%world_size);
    pt.push_back(rand()%world_size);
    pts.push_back(pt);
    value.push_back(rand()%10);
  }
  for(int i(0); i<world_size; i++) {
    for(int j(0); j<world_size; j++) {
      float dist = world_size*world_size;
      int index = 0;
      for(int k(0); k<nber_voronoi; k++) {
	float dist_temp = (i-pts[k][0])*(i-pts[k][0]);
	dist_temp += (j-pts[k][1])*(j-pts[k][1]);
	if (dist_temp < dist) {
	  index = k;
	  dist = dist_temp;
	}
      }
      world[i][j] = value[index];
    }
  }
}

void initialize_world(vector<vector<int> >& world) {
  for(int i(0); i<world_size; i++) {
    world.push_back(vector<int>(0));
    for(int j(0); j<world_size; j++) {
      world[i].push_back(0);
    }
  }
  voronoi(world);
}

vector<vector<int> > collaging() {
  vector<vector<int> > world;
  initialize_world(world);
  for(int i(0); i<nber; i++) {
    int test = rand() % 3;
    if (test <= 1) {
      line(world);
    }
    else {
      circle(world);
    }
  }
  return world;
}

void write_world(vector<vector<int> > const& world) {
  ofstream myfile;
  myfile.open("world.txt");
  for(int i(0); i<world_size; i++) {
    for(int j(0); j<world_size; j++) {
      myfile << world[i][j] << ", ";
    }
    myfile << endl;
  }
  myfile.close();
}

bool check_world(vector<vector<int> > const& world) {
  int counter = 0;
  for(int i(0); i<world_size; i++) {
    for(int j(0); j<world_size; j++) {
      if (world[i][j] < earth) {
	counter++;
      }
    }
  }
  float ratio = float(counter)/float(world_size*world_size);
  if (ratio < 0.05 + float(earth)/10.0 and float(earth)/10.0 - 0.05 < ratio) {
    return true;
  }
  else {
    return false;
  }
}

int main() {

  vector<vector<int> > world;
  /* initialize random seed: */
  srand (time(NULL));
  bool enough_earth (false);
  while (!enough_earth) {
    world = collaging();
    enough_earth = check_world(world);
  }
  write_world(world);

  return 0;
}
