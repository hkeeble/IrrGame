/**
 * @file    Voxel.cpp
 * @author  Henri Keeble
 * @brief   Definitions for a class representing an individual voxel.
 * @see Voxel
 */

#include "Voxel.h"

namespace IrrGame
{
    Voxel::Voxel()
    {
        mesh = nullptr;
        meshbuf = nullptr;
        bounds = Cube();
    }

    Voxel::Voxel(Cube cube)
    {
        bounds = cube;

        mesh = new SMesh();
        meshbuf = new SMeshBuffer();
        mesh->addMeshBuffer(meshbuf);
        meshbuf->drop();

        meshbuf->Vertices.reallocate(3);
        meshbuf->Vertices.set_used(3);

        meshbuf->Vertices[0] = S3DVertex(0,0,10,    1,1,0,    video::SColor(255,0,255,255), 0, 1);
        meshbuf->Vertices[1] = S3DVertex(10,0,-10,  1,0,0,    video::SColor(255,255,0,255), 1, 1);
        meshbuf->Vertices[2] = S3DVertex(0,20,0,    0,1,1,    video::SColor(255,255,255,0), 1, 0);

        meshbuf->Indices[0] = 0;
        meshbuf->Indices[1] = 1;
        meshbuf->Indices[2] = 2;

        meshbuf->recalculateBoundingBox();
    }

    SMesh* Voxel::GetMesh()
    {
        return mesh;
    }

    Voxel::~Voxel()
    {
        if(mesh)
            delete mesh;
        if(meshbuf)
            delete meshbuf;
    }
}
