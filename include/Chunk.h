/**
 * @file 	Chunk.h
 * @author 	Henri Keeble
 * @brief 	Contains declarations for a chunk class. A chunk collects together a number of voxels.
 * @see 	Chunk
 */
 
#ifndef CHUNK_H
#define CHUNK_H

#include <irrlicht.h>
#include <vector>

#include "Voxel.h"
#include "TArray3D.h"

using namespace irr;
using namespace scene;
using namespace core;

namespace IrrGame
{
	class Chunk
	{
	public:
		Chunk();
		Chunk(const int& width, const int& height, const int& depth, const float& voxelScale = 1.f);
		Chunk(const Chunk& param);
		const Chunk& operator=(const Chunk& param);
		Voxel* operator()(const int& x, const int& y, const int& z);
		virtual ~Chunk();
		
		/** Returns a pointer to the mesh for this chunk. */
		SMesh* GetMesh() const;
		
		/** Returns whether or not this chunk is active and should be rendered. */
		bool IsActive() const;
		
		/** Returns the scale of the voxels within this chunk. */
		float VoxelScale() const;
		
		/** Activate rendering of this chunk. */
		void Activate();
		
		/** Deactivate rendering of this chunk. */
		void Deactivate();

	private:		
		int width, height, depth;
		TArray3D<Voxel> voxels; /*!< The voxels contained within this chunk. */
		SMesh* mesh; 			/*!< Mesh of the entire chunk. */
		float voxelScale;		/*!< The scale of the voxels within this chunk. */
		bool render;			/*!< Render flag. */
		
		void GenerateMesh();    /*!< Generates a mesh using current voxel data. */
		
		 /*!< Creates vertices for a cube. */
		 /**
		  * @param origin The origin (center) of the cube vertices to create.
		  */
		std::vector<vector3df> CreateCube(const vector3df& origin);
		
		/** Allocates memory for the voxels. */
		void Allocate();
		
		/** Frees all voxels from memory. */
		void Free();
		
		/** Copies voxel data from one chunk into this chunk. */
		void Copy(const Chunk& param);
	};
}

#endif // CHUNK_H
