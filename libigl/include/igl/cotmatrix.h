#ifndef IGL_COTMATRIX_H
#define IGL_COTMATRIX_H
#include "igl_inline.h"

#define EIGEN_YES_I_KNOW_SPARSE_MODULE_IS_NOT_STABLE_YET
#include <Eigen/Dense>
#include <Eigen/Sparse>

// History:
//  Used const references rather than copying the entire mesh 
//    Alec 9 October 2011
//  removed cotan (uniform weights) optional parameter it was building a buggy
//    half of the uniform laplacian, please see adjacency_matrix istead 
//    Alec 9 October 2011

namespace igl 
{
  // Constructs the cotangent stiffness matrix (discrete laplacian) for a given
  // mesh (V,F).
  //
  // Templates:
  //   DerivedV  derived type of eigen matrix for V (e.g. derived from
  //     MatrixXd)
  //   DerivedF  derived type of eigen matrix for F (e.g. derived from
  //     MatrixXi)
  //   Scalar  scalar type for eigen sparse matrix (e.g. double)
  // Inputs:
  //   V  #V by dim list of mesh vertex positions
  //   F  #F by simplex_size list of mesh faces (must be triangles)
  // Outputs: 
  //   L  #V by #V cotangent matrix, each row i corresponding to V(i,:)
  //
  // See also: adjacency_matrix
  //
  // Known bugs: off by 1e-16 on regular grid. I think its a problem of
  // arithmetic order in cotangent.h: C(i,e) = (arithmetic)/dblA/4
  template <typename DerivedV, typename DerivedF, typename Scalar>
  IGL_INLINE void cotmatrix(
    const Eigen::MatrixBase<DerivedV> & V, 
    const Eigen::MatrixBase<DerivedF> & F, 
    Eigen::SparseMatrix<Scalar>& L);
}

#ifdef IGL_HEADER_ONLY
#  include "cotmatrix.cpp"
#endif

#endif