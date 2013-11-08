#ifndef IGL_DRAW_MESH_H
#define IGL_DRAW_MESH_H
#ifndef IGL_NO_OPENGL
#include "igl_inline.h"

#include <Eigen/Dense>

#include "OpenGL_convenience.h"

namespace igl
{
  // Draw OpenGL commands needed to display a mesh with normals
  //
  // Inputs:
  //   V  #V by 3 eigen Matrix of mesh vertex 3D positions
  //   F  #F by 3 eigne Matrix of face (triangle) indices
  //   N  #V by 3 eigen Matrix of mesh vertex 3D normals
  IGL_INLINE void draw_mesh(
    const Eigen::MatrixXd & V,
    const Eigen::MatrixXi & F,
    const Eigen::MatrixXd & N);
  
  // Draw OpenGL commands needed to display a mesh with normals and per-vertex
  // colors
  //
  // Inputs:
  //   V  #V by 3 eigen Matrix of mesh vertex 3D positions
  //   F  #F by 3 eigne Matrix of face (triangle) indices
  //   N  #V by 3 eigen Matrix of mesh vertex 3D normals
  //   C  #V by 3 eigen Matrix of mesh vertex RGB colors
  IGL_INLINE void draw_mesh(
    const Eigen::MatrixXd & V,
    const Eigen::MatrixXi & F,
    const Eigen::MatrixXd & N,
    const Eigen::MatrixXd & C);
  
  // Draw OpenGL commands needed to display a mesh with normals, per-vertex
  // colors and LBS weights
  //
  // Inputs:
  //   V  #V by 3 eigen Matrix of mesh vertex 3D positions
  //   F  #F by 3 eigne Matrix of face (triangle) indices
  //   N  #V by 3 eigen Matrix of mesh vertex 3D normals
  //   C  #V by 3 eigen Matrix of mesh vertex RGB colors
  //   TC  #V by 3 eigen Matrix of mesh vertex UC coorindates between 0 and 1
  //   W  #V by #H eigen Matrix of per mesh vertex, per handle weights
  //   W_index  Specifies the index of the "weight" vertex attribute: see
  //     glBindAttribLocation, if W_index is 0 then weights are ignored
  //   WI  #V by #H eigen Matrix of per mesh vertex, per handle weight ids
  //   WI_index  Specifies the index of the "weight" vertex attribute: see
  //     glBindAttribLocation, if WI_index is 0 then weight indices are ignored
  IGL_INLINE void draw_mesh(
    const Eigen::MatrixXd & V,
    const Eigen::MatrixXi & F,
    const Eigen::MatrixXd & N,
    const Eigen::MatrixXd & C,
    const Eigen::MatrixXd & TC,
    const Eigen::MatrixXd & W,
    const GLuint W_index,
    const Eigen::MatrixXi & WI,
    const GLuint WI_index);
  
  // Draw OpenGL commands needed to display a mesh with normals, per-vertex
  // colors and LBS weights
  //
  // Inputs:
  //   V  #V by 3 eigen Matrix of mesh vertex 3D positions
  //   F  #F by 3 eigne Matrix of face (triangle) indices
  //   N  #V by 3 eigen Matrix of mesh vertex 3D normals
  //   NF  #F by 3 eigen Matrix of face (triangle) normal indices, <0 means no
  //     normal
  //   C  #V by 3 eigen Matrix of mesh vertex RGB colors
  //   TC  #V by 3 eigen Matrix of mesh vertex UC coorindates between 0 and 1
  //   TF  #F by 3 eigen Matrix of face (triangle) texture indices, <0 means no
  //     texture
  //   W  #V by #H eigen Matrix of per mesh vertex, per handle weights
  //   W_index  Specifies the index of the "weight" vertex attribute: see
  //     glBindAttribLocation, if W_index is 0 then weights are ignored
  //   WI  #V by #H eigen Matrix of per mesh vertex, per handle weight ids
  //   WI_index  Specifies the index of the "weight" vertex attribute: see
  //     glBindAttribLocation, if WI_index is 0 then weight indices are ignored
  IGL_INLINE void draw_mesh(
    const Eigen::MatrixXd & V,
    const Eigen::MatrixXi & F,
    const Eigen::MatrixXd & N,
    const Eigen::MatrixXi & NF,
    const Eigen::MatrixXd & C,
    const Eigen::MatrixXd & TC,
    const Eigen::MatrixXi & TF,
    const Eigen::MatrixXd & W,
    const GLuint W_index,
    const Eigen::MatrixXi & WI,
    const GLuint WI_index);

}

#ifdef IGL_HEADER_ONLY
#  include "draw_mesh.cpp"
#endif

#endif
#endif