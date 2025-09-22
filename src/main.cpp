#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>
#include <string>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

// Base class
class Object3D {
public:
    string name;
    virtual double volume() const = 0;
    virtual double surfaceArea() const = 0;
    virtual vector<double> boundingBox() const = 0; // minX, maxX, minY, maxY, minZ, maxZ
    virtual ~Object3D() {}
};

// Sphere
class Sphere : public Object3D {
public:
    double x, y, z, r;

    Sphere(string n, double cx, double cy, double cz, double radius) {
        name = n;
        x = cx; y = cy; z = cz; r = radius;
    }

    double volume() const override {
        return (4.0/3.0) * M_PI * r * r * r;
    }

    double surfaceArea() const override {
        return 4 * M_PI * r * r;
    }

    vector<double> boundingBox() const override {
        return {x-r, x+r, y-r, y+r, z-r, z+r};
    }
};

// Cube
class Cube : public Object3D {
public:
    double x, y, z, side;

    Cube(string n, double cx, double cy, double cz, double s) {
        name = n;
        x = cx; y = cy; z = cz; side = s;
    }

    double volume() const override {
        return side * side * side;
    }

    double surfaceArea() const override {
        return 6 * side * side;
    }

    vector<double> boundingBox() const override {
        double half = side/2.0;
        return {x-half, x+half, y-half, y+half, z-half, z+half};
    }
};

// Cylinder
class Cylinder : public Object3D {
public:
    double x, y, z, r, h;

    Cylinder(string n, double cx, double cy, double cz, double radius, double height) {
        name = n;
        x = cx; y = cy; z = cz; r = radius; h = height;
    }

    double volume() const override {
        return M_PI * r * r * h;
    }

    double surfaceArea() const override {
        return 2 * M_PI * r * h + 2 * M_PI * r * r;
    }

    vector<double> boundingBox() const override {
        return {x-r, x+r, y-r, y+r, z, z+h};
    }
};

// Read scene from file
vector<shared_ptr<Object3D>> readScene(const string& filename) {
    vector<shared_ptr<Object3D>> objects;
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error opening file: " << filename << endl;
        return objects;
    }

    string type, name;
    while (fin >> type >> name) {
        if (type == "Sphere") {
            double x, y, z, r;
            fin >> x >> y >> z >> r;
            objects.push_back(make_shared<Sphere>(name, x, y, z, r));
        } else if (type == "Cube") {
            double x, y, z, s;
            fin >> x >> y >> z >> s;
            objects.push_back(make_shared<Cube>(name, x, y, z, s));
        } else if (type == "Cylinder") {
            double x, y, z, r, h;
            fin >> x >> y >> z >> r >> h;
            objects.push_back(make_shared<Cylinder>(name, x, y, z, r, h));
        }
    }
    fin.close();
    return objects;
}

// Write results to file
void writeResults(const string& filename, const vector<shared_ptr<Object3D>>& objects) {
    ofstream fout(filename);
    if (!fout) {
        cerr << "Error writing to file: " << filename << endl;
        return;
    }
    fout << "Object  Volume      SurfaceArea\n";
    fout << "-------------------------------\n";
    for (auto &obj : objects) {
        fout << obj->name << "  "
             << obj->volume() << "  "
             << obj->surfaceArea() << "\n";
    }
    fout.close();
}

// Main
int main() {
    string inputFile = "../data/scene.txt";
    string outputFile = "../data/results.txt";

    auto objects = readScene(inputFile);
    if (objects.empty()) {
        cout << "No objects found in scene." << endl;
        return 0;
    }

    writeResults(outputFile, objects);

    cout << "Results written to " << outputFile << endl;
    return 0;
}
