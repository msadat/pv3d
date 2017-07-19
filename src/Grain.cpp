/* Grain production and manipulation
:q
:q
 * first principles calculations.
 *
 * Author: Josh Vita
 * Created: 2017/7
 * Last edited: 2017/7
 */

// TODO: create special Grain class (position, distance(), atoms)

#include <vector>
#include <cmath>
#include "define.h"
#include <iostream>
#include "Tools.h"

using namespace std;

namespace Grain {
    vector<dvec_t> genGrain(dvec_t center, dvec_t dimensions,
            vector<dvec_t> basis, double latConst) {
        /* Generates a grain of the given size, using the given basis. Note that
         * 'basis' is intended to correspond to only one atom type, to be
         * combined
         * later.
         *
         * Args:
         *  center      -   the center of the grain
         *  dimensions  -   xyz size of the grain (same units as latConst)
         *  basis       -   the basis set
         *  latConst    -   the lattice constant of the unit cell
         *
         * Returns:
         *  grain   -   the coordinates of all atoms
         */

        int numCells;
        dvec_t temp;
        vector<dvec_t> grain = basis;

        // For all directions
        for (vector<dvec_t>::size_type i=0; i<dimensions.size(); ++i) {
            numCells = static_cast<int>(ceil(dimensions[i]/latConst));

            // For each cell
            for (int j=1; j<numCells; ++j) {
                // For each atom in basis
                for (vector<dvec_t>::size_type k=0; k<basis.size(); ++k) {
                    temp = basis[k];
                    temp[i] += latConst*j;
                    grain.push_back(temp);
                }
            }
            basis.resize(grain.size());
            basis = grain;
        }

        return grain;
    }
}
