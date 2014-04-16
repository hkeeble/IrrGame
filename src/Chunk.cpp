/**
 * @file    Chunk.cpp
 * @author  Henri Keeble
 * @brief   Definitions for a single chunk of voxels.
 * @see     World
 */

#include "Chunk.h"

namespace IrrGame
{
	Chunk::Chunk()
	{
		voxels = TArray3D<Voxel>();
		mesh = nullptr;
		voxelScale = 1.f;
		width = height = depth = 0;
	}
		
	Chunk::Chunk(const int& width, const int& height, const int& depth, const float& voxelScale)
	{
		this->width = width;
		this->height = height;
		this->depth = depth;
		this->voxelScale = voxelScale;
		
		// Initialize the voxel array
		voxels = TArray3D<Voxel>(width, height, depth);
		
		// Generate an initial mesh
		GenerateMesh();
	}
		
	bool Chunk::IsActive() const
	{
		return render;
	}
		
	float Chunk::VoxelScale() const
	{
		return voxelScale;
	}
	
	SMesh* Chunk::GetMesh() const
	{
		return mesh;
	}
	
	Chunk::Chunk(const Chunk& param)
	{
		Copy(param);
		GenerateMesh();
	}
	
	const Chunk& Chunk::operator=(const Chunk& param)
	{
		if(this == &param)
			return *this;
		else
		{
			Copy(param);
			GenerateMesh();
		}
	}
	
	void Chunk::Copy(const Chunk& param)
	{
		voxels = param.voxels;
		this->width = param.width;
		this->height = param.height;
		this->depth = param.depth;
		this->voxelScale = param.voxelScale;
	}
	
	Voxel* Chunk::operator()(const int& x, const int& y, const int& z)
	{
		return voxels(x, y, z);
	}
	
	Chunk::~Chunk()
	{
		if(mesh)
			delete mesh;
	}

	void Chunk::Activate()
	{
		render = true;
	}
	
	void Chunk::Deactivate()
	{
		render = false;
	}	
		
	void Chunk::GenerateMesh()
	{
	
	}
	
	std::vector<vector3df> Chunk::CreateCube(const vector3df& origin)
	{
		
	}
}
