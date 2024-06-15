#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <string>
#include <map>

template<class T>
class ResourceManager
{
public:
	typedef std::pair<std::string, T*> Resource;
	typedef std::map<std::string, T*> ResourceMap;

private:
	ResourceMap resourceMap;

public:
	ResourceManager()
	{
	}

	~ResourceManager()
	{
		ReleaseAll();
	}

	T* Get(const std::string& strId)
	{
		T* resource = Find(strId);
		if(resource == NULL)
		{
			resource = Load(strId);
			if(resource != NULL)
				resourceMap.insert(Resource(strId, resource));
		}
		return resource;
	}

	void ReleaseAll()
	{
		while(resourceMap.begin() != resourceMap.end())
		{
			delete resourceMap.begin()->second;
			resourceMap.erase(resourceMap.begin());
		}
	}
protected:
	virtual T* Load(const std::string& strId) = 0;

private:
	T* Find(const std::string& strId)
	{
		T* resource = NULL;
		ResourceMap::iterator resourceIter = resourceMap.find(strId);
		if(resourceIter != resourceMap.end())
			resource = resourceIter->second;
		return resource;
	}
};

#endif