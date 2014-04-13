/**
 * @file    World.h
 * @author  Henri Keeble
 * @brief   Declarations for a class that represents the world scene node.
 * @see     World
 */
#ifndef WORLD_H
#define WORLD_H

#include <irrlicht.h>

#include "Log.h"

using namespace irr;
using namespace scene;
using namespace video;

namespace IrrGame
{
    /** Represents the world scene node. */
    class World
    {
        public:
            World();

            /*! World Constructor */
            /**
                @param scene Pointer to the scene manager for the world to use.
             */
            World(ISceneManager* scene);

            /*! Add a scene mesh node to the world. */
            /**
                @param The mesh to add to the world.
             */
            void AddMeshNode(SMesh* mesh);

            /*! Renders the world. */
            void Render();

            virtual ~World();
        private:
            ISceneManager* scene; /*!< The scene manager the world is using. */
    };
}

#endif // WORLD_H
