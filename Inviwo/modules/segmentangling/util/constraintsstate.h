#ifndef __CONSTRAINTSSTATE_H__
#define __CONSTRAINTSSTATE_H__

#include <Eigen/Core>
#include <vector>

//#include <utils.h>



#include <igl/marching_tets.h>

struct ConstraintState {
    std::vector<int> m_bone_constraints_idx;
    std::vector<Eigen::RowVector3d> m_bone_constraints_pos;
    std::vector<int> m_orientation_constraints_idx;
    std::vector<Eigen::RowVector3d> m_orientation_constraints_pos;

    std::vector<double> m_level_set_isovalues;
    std::vector<double> m_level_set_distances;

    // Indices of tets which can possibly have rotation constraints
    std::vector<int> m_constrainable_tets_idx;
    std::unordered_map<int, std::tuple<int, double, bool>> m_tet_constraints;

    std::pair<Eigen::Matrix3d, Eigen::RowVector3d> frame_for_tet(const Eigen::MatrixXd& TV,
        const Eigen::MatrixXi& TT,
        const Eigen::VectorXd& isovals,
        int idx, double angle, bool flip_x);

    int num_constraints() const;

    int num_orientation_constraints() const;

    int num_bone_constraints() const;

    int num_constrainable_tets() const;

    void clear_orientation_constraints();

    double update_bone_constraints(const Eigen::MatrixXd& TV,
        const Eigen::MatrixXi& TT,
        const Eigen::VectorXd& isovals,
        const std::array<int, 2>& endpoints,
        int num_verts);


    void update_orientation_constraint(const Eigen::MatrixXd& TV,
        const Eigen::MatrixXi& TT,
        const Eigen::VectorXd& isovals,
        int idx, double angle, bool flipped_x);

    void slim_constraints(Eigen::VectorXi& slim_b, Eigen::MatrixXd& slim_bc, bool only_ends_and_tets);
};

#endif 