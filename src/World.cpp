/**
 * @file    World.cpp
 * @author  Henri Keeble
 * @brief   Definitions for a class that represents the world scene node.
 * @see     World
 */

#include "World.h"

namespace IrrGame
{
    World::World()
    {
        scene = nullptr;
    }

    World::~World()
    {

    }

    World::World(ISceneManager* scene)
    {
        this->scene = scene;

        // Add test mesh
        IAnimatedMesh* mesh = scene->getMesh("data/sydney.md2");

        IAnimatedMeshSceneNode* node = scene->addAnimatedMeshSceneNode(mesh);

        if (node)
        {
            node->setMaterialFlag(EMF_LIGHTING, false);
            node->setMD2Animation(scene::EMAT_STAND);
            // node->setMaterialTexture( 0, iVideoDriver->getTexture("data/sydney.bmp") );
        }

        // Initialize a camera
        scene->addCameraSceneNodeFPS();
    }

    void World::AddMeshNode(SMesh* mesh)
    { 
    	scene->addMeshSceneNode(mesh);
    }

    void World::Render()
    {
        scene->drawAll();
    }
}
