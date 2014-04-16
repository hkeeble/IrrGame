/**
 * @file 	FileName.cpp
 * @author 	Henri Keeble
 * @brief 	Contains definitions for a class representing a file name.
 * @see		FileName
 */
 
 #include "IO.h"
 
namespace IrrGame
{
	FileName::FileName()
	{
		name = "";
		ext = "";
	}
	
	FileName::FileName(const std::string& name, const std::string& ext)
	{
		this->name = name;
		this->ext = ext;
	}
	
	FileName::~FileName()
	{
	
	}
		
	const std::string& FileName::GetName() const
	{
		return name;
	}	
	
		/** Retrieve the extension of the file. */
	const std::string& FileName::GetExtension() const
	{
		return ext;
	}	
	
	std::string FileName::GetNameAndExt() const
	{
		return name + "." + ext;
	}
}
