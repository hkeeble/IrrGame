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
using namespace core;

namespace IrrGame
{
    /** Represents the world scene node. */
    class World
    {
        public:
            World();

            /*! World Constructor */
            /**
                @param scene 	Pointer to the scene manager for the world to use.
                @param driver 	The video driver used by the world.
                @param up		The up vector used by the world.
             */
            World(ISceneManager* scene, IVideoDriver* driver, int width, int height, int depth, const vector3df& up = vector3df(0, 1, 0));

			/*! Creates and adds an animated mesh node from a mesh and texture. */
			/**
			 * @param mesh 		  The mesh for the node to use.
			 * @param texturePath The name of the texture file.
			 */
			IAnimatedMeshSceneNode* AddAnimatedMesh(const std::string& modelFile, const std::string& textureFile = NO_TEXTURE,
				ISceneNode* parent = nullptr, const vector3df& position = ORIGIN, const vector3df& rotation = vector3df(0, 0, 0), const vector3df& scale = vector3df(1.0f, 1.0f, 1.0f));
		
			/*! Creates and adds a scene node from an SMesh and a texture. */
			/**
			 * @param mesh 		  The mesh to use.
			 * @param textureFile The name of the texture file.
			 */
			IMeshSceneNode* AddMesh(IMesh* mesh, const std::string& textureFile = NO_TEXTURE);
			
            /*! Renders the world. */
            void Render();

            virtual ~World();
        private:
            ISceneManager* scene; /*!< The scene manager the world is using. */
            IVideoDriver* driver; /*!< The video driver being used by the world. */
            
            // World Constants
            static const std::string TEXTURE_PATH; 	/*!< Constant string containing address of the global texture directory. */
			static const std::string MODEL_PATH; 	/*!< Constant string containing address of the global model directory. */
			static const std::string NO_TEXTURE; 	/*!< The path of the texture to use on a mesh if none is supplied. */
			static const vector3df   ORIGIN; 		/*!< Defines the world origin. */
			
			vector3df up; /*!< Up vector being used by this world. */
    };
}

#endif // WORLD_H
