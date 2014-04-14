/**
 * @file 	VoxelMap.h
 * @author  Henri Keeble
 * @brief   Declares a class used to represent a voxel map.
 * @see 	VoxelMap
 */
 
 #ifndef VOXELMAP_H
 #define VOXELMAP_H
 
 #include <vector>
 
 namespace IrrGame
 {
 	/** Enumeration to represent differet types of voxel. */
 	enum class VoxelType
 	{
 		NONE, /*!< Represents an empty space in the voxel map. */
 		GROUND /*!< A default voxel type. */
	};
 
 	/** Represents a voxel map internally, contains no graphical descriptions. */
 	class VoxelMap
 	{
 	public:
 		VoxelMap();
 		VoxelMap(const VoxelMap& param);
 		VoxelMap& operator=(const VoxelMap& param);
 		VoxelMap(int width, int height, int depth);
 		virtual ~VoxelMap();
 		
 		/** Creates a flat ground plane at the base of the voxel map. */
 		void CreateFlatGround();
 		
 		/** Clears the map, making an empty voxel map. */
 		void ClearMap();
 		
 	private:
 		int width, height, depth;
 		std::vector<std::vector<std::vector<VoxelType>>> voxels; /*!< The voxels contained within this map. */
 		
 		/** Initializes the voxel map with the current width, height and depth. */
 		void InitMap();
	};
 }
 
 #endif // VOXELMAP_H
