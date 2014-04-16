/**
 * @file    FileStream.H
 * @author  Henri Keeble
 * @brief   Declarations for an fstream wrapper class.
 */

#ifndef FILESTREAM_H
#define FILESTREAM_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "stringext.h"

namespace IrrGame
{	
	#ifdef _DEBUG
	/** Write data out to the game log and terminal window. */
    extern void Log(const std::string& data);
	#endif // _DEBUG
	
	/** Represents a file. */
	class FileName
	{
	public:
		FileName();
		FileName(const std::string& name, const std::string& ext);
		virtual ~FileName();
		
		/** Retrieve the name of the file. */
		const std::string& GetName() const;
		
		/** Retrieve the extension of the file. */
		const std::string& GetExtension() const;
		
		/** Retrieve the name and extension of the file. */
		std::string GetNameAndExt() const;
		
	private:
		std::string name; /*!< Name of the file. */
		std::string ext;  /*!< Extension used by the file. */
	};
	
	/** Represents a file path. */
	class IOPath
	{
	public:
		IOPath();
		/** Constructs a new path. */
		/**
		 * @param path The folder path.
		 * @param file Name of the file. Leave blank for no file.
		 */
		IOPath(const std::string& path, const FileName& fileName = FileName());
		virtual ~IOPath();
		
		/** Move the path up one level. */
		void Up();
		
		/** Move the path down one level into the specified folder. */
		/**
		 * @param folder The name of the folder to move into, exclude any slashes.
		 */
		void Down(const std::string& folder);
		
		/** Add a file to the path. Overrides any existing file name within the path. */
		/**
		 * @param fileName The filename to add to the path, including the file extension.
		 */
		void AddFile(const FileName& fileName);
		
		/** Removes the current file from this path. */
		void RemoveFile();
		
		/** Retrieve the file contained within the path. Returns null if no path is held. */
		const FileName& GetFile() const;
		
		/** Get the path contained in this path object, without filename. */
		const std::string& GetPath() const;
		
		/** Return the file and path within this path. If there is no file, returns only path. */
		std::string GetFileAndPath() const;
		
		/** Returns whether or not the path contains a file. */
		bool ContainsFile() const;
		
	private:
		std::string path; /*!< The folder path. */
		FileName file; 	  /*!< The file contained in the path. */
		bool hasFile; 	  /*!< Whether or not this path contains a file. */	
	};

	/** Represents a file stream. */
    class FileStream
    {
        public:
            FileStream();
            
            /** Construct a new filestream with the given path. Does not open the stream. */
            /**
             *	@param filePath The path of the file with which to use in the stream.
             */
            FileStream(const IOPath& filePath);
            FileStream(const FileStream& param);
            const FileStream& operator=(const FileStream& param);
            virtual ~FileStream();

			/** Read the next line from the file. */
            std::string ReadLine();
            
            /** Read the next character from the file. */
            char ReadChar();

			/** Write a line to the file. */
            void WriteLine(const std::string& line);
            
            /** Write a string to the file. */
            void Write(const std::string& data);
            
            /** Write a character to the file. */
            void WriteChar(const char& data);

			/** Open the file stream with the current file path. */
            void Open();
            
            /** Close the file stream. */
            void Close();

			/** Returns whether or not the file is open. */
            bool IsOpen() const;
            
            /** Returns whether or not the stream buffer is at the end of the file. */
            bool EndOfFile() const;

			/** Seek to the given data in the file. */
            void Seek(std::string data);

			/** Get the path of the file stream. */
			IOPath GetPath() const;
	
        private:
            std::fstream file /*!< The file stream itself. */;
            IOPath filePath; /*!< The path of the file the stream is using. */

            // Internal copying function
            void cpy(const FileStream& param);
    };
}
#endif // FILESTREAM_H
