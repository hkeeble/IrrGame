/**
 * @file    World.cpp
 * @author  Henri Keeble
 * @brief   Definitions for a class that represents the world scene node.
 * @see     World
 */

#include "World.h"

namespace IrrGame
{
	// Define constants
	const std::string World::TEXTURE_PATH = "data/textures/";
	const std::string World::MODEL_PATH = "data/models/";
	const std::string World::NO_TEXTURE = TEXTURE_PATH + "notexture.bmp";
	const vector3df World::ORIGIN = vector3df(0, 0, 0);

    World::World()
    {
        scene = nullptr;
        driver = nullptr;
    }

    World::~World()
    {
		// Class does not currently manage any resources.
    }

    World::World(ISceneManager* scene, IVideoDriver* driver, int width, int height, int depth, const vector3df& up)
    {
        this->scene = scene;
        this->driver = driver;

		// Add an animated mesh
        IAnimatedMeshSceneNode* node = AddAnimatedMesh("Marvin.md2", "Marvin.jpg");

		// Change some parameters of the added mesh node
        if (node)
        {
            node->setMaterialFlag(EMF_LIGHTING, false);
            node->setMD2Animation(scene::EMAT_RUN);
            node->setAnimationSpeed(10);
        }

        // Initialize a camera
        scene->addCameraSceneNodeFPS();
    }
    
	IAnimatedMeshSceneNode* World::AddAnimatedMesh(const std::string& modelFile, const std::string& textureFile, ISceneNode* parent, const vector3df& position,
		const vector3df& rotation, const vector3df& scale)
	{
		// Create and add a mesh from the given file and texture
		IAnimatedMesh* mesh = scene->getMesh((MODEL_PATH + modelFile).c_str());
		
		if(!mesh)
		{
			Log("Error! Could not load model from \"" + MODEL_PATH + modelFile + "!\n");
			return nullptr;
		}
		
        IAnimatedMeshSceneNode* node = scene->addAnimatedMeshSceneNode(mesh);
        
        if(!node)
        {
        	Log("Error! Failed to create node from mesh loaded from \"" + MODEL_PATH + modelFile + "!\n");
        	return nullptr;
        }
        
        ITexture* texture =  driver->getTexture((TEXTURE_PATH + textureFile).c_str());
        
        if(!texture)
        	Log("Error! Failed to load texture from file \"" + TEXTURE_PATH + textureFile + "!\n");
        
        node->setMaterialTexture(0, texture);
        
        return node;
	}
	
	IMeshSceneNode* World::AddMesh(IMesh* mesh, const std::string& textureFile)
	{
		// Create and add a mesh
		if(!mesh)
		{
			Log("Error! no mesh passed into World::AddMesh!\n");
			return nullptr;
		}
		
        IMeshSceneNode* node = scene->addMeshSceneNode(mesh);
        
        if(!node)
        {
        	Log("Error! Failed to create node mesh!\n");
        	return nullptr;
        }
        
        ITexture* texture =  driver->getTexture((TEXTURE_PATH + textureFile).c_str());
        
        if(!texture)
        	Log("Error! Failed to load texture from file \"" + TEXTURE_PATH + textureFile + "!\n");
        
        node->setMaterialTexture(0, texture);
        
        return node;
	}
	
    void World::Render()
    {
        scene->drawAll();
    }
} 
