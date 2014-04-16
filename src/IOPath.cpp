/**
 * @file   IOPath.cpp
 * @author Henri Keeble
 * @brief  Contains definitions for a class that holds a filepath.
 * @see	   IOPath
 */
 
#include "IO.h"
 
namespace IrrGame
{
		IOPath::IOPath()
		{
			hasFile = false;
			path = "";
			file = FileName();	
		}

		IOPath::IOPath(const std::string& path, const FileName& fileName)
		{
			if(fileName.GetName() == "")
				hasFile = false;
			this->file = fileName;
			this->path = path;
		}
		
		IOPath::~IOPath()
		{
		
		}
		
		void IOPath::Up()
		{
			// Extract individual folders
			std::vector<std::string> folders = splitStr(path, '/');
			
			// Read folders back into path, excluding the last
			path = "";
			for(int i = 0; i < folders.size()-1; i++)
				path += folders[i] + "/";
		}
		
		void IOPath::Down(const std::string& folder)
		{
			path += folder + "/";
		}
		
		void IOPath::AddFile(const FileName& fileName)
		{
			file = fileName;
		}
		
		void IOPath::RemoveFile()
		{
			file = FileName();
			hasFile = false;
		}
		
		const FileName& IOPath::GetFile() const
		{
			return file;
		}
		
		const std::string& IOPath::GetPath() const
		{
			return path;
		}
		
		std::string IOPath::GetFileAndPath() const
		{
			return path + file.GetNameAndExt();
		}
		
		bool IOPath::ContainsFile() const
		{
			return hasFile;		
		}
}
