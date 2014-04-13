/**
 * @file    Voxel.h
 * @author  Henri Keeble
 * @brief   Declarations for a class representing an individual voxel.
 */
#ifndef VOXEL_H
#define VOXEL_H

#include <irrlicht.h>
#include "Shapes.h"

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

            /*! Voxel Constructor */
            /**
                @param cube The cube representing the voxel's position in world space and it's bounding box.
             */
            Voxel(Cube cube);

            SMesh* GetMesh();

            virtual ~Voxel();
        private:
            Cube bounds;            /*!< The bounds of the voxel in world space. */
            SMesh* mesh;            /*!< The voxel's mesh pointer. */
            SMeshBuffer* meshbuf;   /*!< Pointer to the voxel's mesh buffer. */
    };
}
#endif // VOXEL_H
