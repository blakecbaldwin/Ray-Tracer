#ifndef OBJ_LOADER_H
#define OBJ_LOADER_H

#include "file_util.h"
#include "Triangle.hpp"

inline std::vector<Triangle> loadObj(const std::string &path, float scale, Vector3 position)
{
  std::vector<Vector3> vertices;
  std::vector<Triangle> triangles;

  for (const std::string &line : readLines(path))
  {
    std::istringstream input(line);
    std::string type;
    input >> type;

    if (type == "v")
    {
      Vector3 vertex;
      if (!(input >> vertex.x >> vertex.y >> vertex.z))
        throw std::runtime_error("Invalid vertex in " + path);
      vertices.push_back(vertex * scale + position);
    }
    else if (type == "f")
    {
      std::vector<int> face;
      std::string part;
      while (input >> part)
      {
        // Only need the vertex number before the first slash
        int index = std::stoi(part.substr(0, part.find('/')));
        if (index <= 0)
          throw std::runtime_error("This loader needs positive vertex numbers");
        face.push_back(index - 1);
      }

      if (face.size() != 3 && face.size() != 4)
        throw std::runtime_error("This loader needs triangle or quad faces");

      triangles.push_back(Triangle{
          vertices.at(face[0]), vertices.at(face[1]), vertices.at(face[2])});

      // Split a quad into two triangles, keeping the same corner order
      if (face.size() == 4)
      {
        triangles.push_back(Triangle{
            vertices.at(face[0]), vertices.at(face[2]), vertices.at(face[3])});
      }
    }
  }
  return triangles;
}

#endif
