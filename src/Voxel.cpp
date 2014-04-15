/**
 * @file    Voxel.cpp
 * @author  Henri Keeble
 * @brief   Definitions for a class representing an individual voxel.
 * @see 	Voxel
 */

#include "Voxel.h"

namespace IrrGame
{
	Voxel::Voxel()
	{
		type = VoxelType::GRASS;
	}
    
    Voxel::Voxel(const VoxelType& type)
	{
		this->type = type;
	}
	
	Voxel::~Voxel()
	{
		// Manages no memory resources
	}
	
	void Voxel::SetType(const VoxelType& type)
	{
		this->type = type;
	}
	
	const VoxelType& Voxel::GetType()
	{
		return type;
	}
	
	void Voxel::Activate()
	{
		active = true;
	}
	
    void Voxel::Deactivate()
    {
    	active = false;
	}
}
