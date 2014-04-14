/**
 * @file 	VoxelMap.cpp
 * @author  Henri Keeble
 * @brief   Defines a class used to represent a voxel map.
 * @see 	VoxelMap
 */

#include "VoxelMap.h"

namespace IrrGame
{
 	VoxelMap::VoxelMap()
 	{
 		width = height = depth = 0;
 		InitMap();
	}
 	
 	VoxelMap::VoxelMap(int width, int height, int depth)
 	{
 		this->width = width;
 		this->height = height;
 		this->depth = depth;
 		InitMap();
 	}

 	VoxelMap::VoxelMap(const VoxelMap& param)
 	{
		width = param.width;
		height = param.height;
		depth = param.depth;
		InitMap();
	}
 	
 	VoxelMap& VoxelMap::operator=(const VoxelMap& param)
 	{
 		if(this == &param)
 			return *this;
 		else
 		{
			width = param.width;
			height = param.height;
			depth = param.depth;
			InitMap();
			return *this;
		}
	}
 	
 	void VoxelMap::CreateFlatGround()
 	{
		for(int x = 0; x < width; x++)
		{
			for(int z = 0; z < depth; z++)
				voxels[x][0][z] = VoxelType::GROUND;
		}
 	}
 	
 	void VoxelMap::InitMap()
 	{
 		// Initialize the voxel array
 		voxels.resize(width);
 		for(int i = 0; i < width; i++)
 		{
 			voxels[i].resize(height);
 			
 			for(int j = 0; j < height; j++)
 				voxels[i][j].resize(depth);
 		}
	}
 	
 	void VoxelMap::ClearMap()
 	{
 		/*
 		for(int x = 0; x < voxels.size(); x++)
 		{
 			voxels[x] = VoxelType::GROUND;
 			for(int y = 0; y < voxels[x].size(); y++)
 			{
 				voxels[x][y] = VoxelType::GROUND;
 				for(int z = 0; z < voxels[x][y].size(); z++)
 					voxels[x][y][z] = VoxelType::GROUND;
			}
		}
		*/
	}
 	
 	VoxelMap::~VoxelMap()
 	{
 	
	}
}	
