/**
 * @file    Voxel.h
 * @author  Henri Keeble
 * @brief   Declarations for a class representing an individual voxel.
 */
#ifndef VOXEL_H
#define VOXEL_H

#include <irrlicht.h>

#include "Shapes.h"
#include "VoxelType.h"

using namespace irr;
using namespace scene;
using namespace video;

namespace IrrGame
{
    /** Represents an individual voxel. */
    class Voxel
    {
        public:
            Voxel();
            Voxel(const VoxelType& type);
            virtual ~Voxel();
            
            void SetType(const VoxelType& type);
            const VoxelType& GetType();
            
            void Activate();
            void Deactivate();
        private:
        	bool active; /*!< Whether or not the voxel is active. */
        	VoxelType type; /*!< The type of voxel. */
    };
}
#endif // VOXEL_H
